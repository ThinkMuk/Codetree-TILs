#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, u, d;
int grid[8][8];

//정해진 좌표들을 넣는 곳
vector<pair<int,int>> selected;
//결정된 도시들 방문한 board
vector<vector<bool>> board;

int ans = 0;

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//범위 내에 속하는지
bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

//bfs
//bfs내에서 방문하는 도시들은 board에서 true 진행
void bfs(int r, int c) {
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push({r, c});
    visited[r][c] = true;
    board[r][c] = true;

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nr = p.first + dr[dir];
            int nc = p.second + dc[dir];
            
            //범위 안에 속해있지 않거나, 이미 방문했다면
            if(!inRange(nr, nc) || visited[nr][nc]) continue;
            //만약 u 이상, d 이하가 아니라면
            int diff = abs(grid[p.first][p.second] - grid[nr][nc]);
            if(u <= diff && diff <= d) {
                visited[nr][nc] = true;
                board[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

//조합 선택 (중복 불가)
void solve(int depth, int start) {
    if(depth == k) { //도시를 모두 골랐을 때
        //고른 시작지마다 bfs 실행
        //라벨링 할 board 생성
        board.assign(n, vector<bool>(n, false));

        for(pair<int,int> p : selected) {
            bfs(p.first, p.second);
        }
        //board에서 변환된 true board들 카운트해서 max 비교
        int cnt = 0;

        for(vector<bool> v : board) {
            for(bool b : v) {
                if(b) cnt++; 
            }
        }

        ans = max(ans, cnt);
        return;
    }

    for(int i = start; i < n * n; i++) {
        int r = i / n;
        int c = i % n;

        selected.push_back({r, c});
        solve(depth + 1, i + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    // 각 칸마다 하나의 도시가 있음
    // 각 도시마다 높이 정보가 주어짐
    // "k개의 도시를 겹치지 않게 고름"
    // k개의 도시로부터 갈 수 있는 다른 도시의 수를 최대화
    //두 도시간의 높이의 차가 U이상 D 이하인 경우만 이동 가능
    solve(0, 0);

    cout << ans << "\n";
    return 0;
}
