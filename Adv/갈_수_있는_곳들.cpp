#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
vector<vector<bool>> visited;
int ans = 0;

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

void bfs(int sr, int sc) {
    queue<pair<int,int>> q;
    q.push({sr, sc});

    if(!visited[sr][sc]) ans++;
    visited[sr][sc] = true;

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();


        for(int d = 0; d < 4; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];

            if(!inRange(nr, nc) || grid[nr][nc] == 1 || visited[nr][nc]) continue;

            ans++;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
}

int main() {
    cin >> n >> k;

    //k개의 출발점
    //n x n의 보드

    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    // Please write your code here.
    for(int i = 0; i < k; i++) {
        bfs(r[i], c[i]);
    }

    cout << ans << "\n";
    return 0;
}

