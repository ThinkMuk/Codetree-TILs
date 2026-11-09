#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, k;
int grid[100][100];
//출발 좌표와 도착좌표
int r1, c1, r2, c2;

int ans = INT_MAX;

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//범위 내에 속하는지
bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

//돌맹이 저장해두는 곳
//돌맹이 좌표만 저장해두고, 부순 바위는 직접 grid에 적용시킬거임
vector<pair<int, int>> rocks;

//선택된 바위마다 진행할 bfs의 board (visited 그래서 필요없음)
vector<vector<int>> board;

int bfs(int r, int c) {
    board.assign(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    q.push({r, c});
    board[r][c] = 0;

    //만약 목적지에 도달했다면 (r2, c2)
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = p.first + dr[dir];
            int nc = p.second + dc[dir];

            //범위 밖을 벗어났거나 이미 방문했다면
            if (!inRange(nr, nc) || board[nr][nc] != -1) continue;
            //돌맹이라면
            if (grid[nr][nc] == 1) continue;

            //목적지에 도달했을 때
            if (nr == r2 && nc == c2) {
                //+1 해서 return 하기
                return (board[p.first][p.second] + 1);
            }

            //board 최신화, q에 넣기
            board[nr][nc] = board[p.first][p.second] + 1;
            q.push({nr, nc});
        }
    }

    //도달하는 것이 불가능하다면
    return -1;
}

void comb(int depth, int start) {
    //돌맹이들 모두 선택했으면
    if (depth == k) {
        int dist = bfs(r1, c1);
        if(dist != -1)
            ans = min(ans, dist);
    }

    for (int i = start; i < rocks.size(); i++) {
        //돌맹이 삭제
        grid[rocks[i].first][rocks[i].second] = 0;
        comb(depth + 1, i + 1);
        //백트래킹
        grid[rocks[i].first][rocks[i].second] = 1;
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    // Please write your code here.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) rocks.push_back({i, j});
        }
    }

    //K개의 벽을 적절하게 없앰
    //도착점까지 도달하는데 걸리는 최소 시간

    //없앨 벽 K 조합으로 선택
    //BFS진행, **최소 시간** 을 출력하는 것이기 때문에 bfs를 통해 board에 기록
    //board에 기록된 좌표도달시 탈출
    comb(0, 0);
    cout << ((ans == INT_MAX) ? -1 : ans) << "\n";

    return 0;
}
