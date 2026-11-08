#include <iostream>
#include <vector>
#include <queue>
#define INF 10000

using namespace std;

int n, k;
int grid[100][100];
vector<vector<int>> ans;

// 상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    ans.assign(n, vector<int>(n, INF));
    queue<pair<int, int>> q;

    // 모든 시작점(2)을 큐에 삽입
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }

    // BFS
    // 시작점을 서로 다르게 하는것이 아니라, 애초에 bfs는 인접한 곳은 가깝기 때문에 굳이 적을때의 탐색을 할 필요 없음
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];

            if(!inRange(nr, nc)) continue;
            if(grid[nr][nc] != 1) continue;

            // 이미 방문한 곳이면 넘어감
            if(ans[nr][nc] != INF) continue;

            ans[nr][nc] = ans[p.first][p.second] + 1;
            q.push({nr, nc});
        }
    }

    // 출력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                cout << -1 << " ";
            }
            else if(ans[i][j] == INF) {
                cout << -2 << " ";
            }
            else {
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
