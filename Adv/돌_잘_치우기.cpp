#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];
int ans = 0;

//1이 돌을 의미
//M개의 돌만 적절하게 치워 K개의 시작점으로부터 상하좌우 인접한 곳으로만 이동, 도달 가능한 칸의 수를 최대로
//격자 크기 N
//시작점의 수 K
//치워야 할 돌 M

//흠 무슨 돌을 치워야할지 고민이네
//돌을 치우는 모든 경우의 수를 하면 시간 초과가 나지 않을까
//근데 돌의 개수가 8개인걸 보니까 2^8 정도로 충분히 해볼만함

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//도달 가능한 칸의 최대 수이기 때문에 visited로 방문만 기록
vector<vector<bool>> visited;
//돌맹이 저장
vector<pair<int,int>> rocks;

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

//bfs 탐색
void bfs(int r, int c) {
    queue<pair<int,int>> q;

    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];

            //범위 안이 아니거나, 이미 방문했거나
            if(!inRange(nr, nc) || visited[nr][nc]) continue;
            //만약 벽이라면
            if(grid[nr][nc] == 1) continue;

            //방문 갱신 및 queue에 push
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

//조합으로 부술 돌 정하기
//depth는 고른 개수, 
void destroy(int depth, int start) {
    //치울 돌들 다 결정되면
    if(depth == m) {
        //방문하면 자연수로, 미방문시 -1
        visited.assign(n, vector<bool>(n, false));

        for(int i = 0; i < k; i++)
            bfs(r[i], c[i]);
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    //돌 개수만큼 진행
    for(int i = start; i < rocks.size(); i++) {
        int rr = rocks[i].first;
        int rc = rocks[i].second;

        grid[rr][rc] = 0;
        //부수기로 결정했을 때
        destroy(depth + 1, i + 1);
        //결정하지 않았을 때
        grid[rr][rc] = 1;
    }
}

int main() {
    cin >> n >> k >> m;

    //좌표 저장
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    //시작 위치 저장
    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    //돌 좌표 저장
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) rocks.push_back({i, j});
        }
    }

    // Please write your code here.
    // 1. 각 시작 좌표마다 반복할것
    // 2. 부술 돌맹이 조합
    // 3. bfs 진행
    destroy(0, 0);

    cout << ans << "\n";

    return 0;
}
