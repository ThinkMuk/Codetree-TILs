#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a[100][100];

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        pair<int,int> p = q.front();

        //도착지면 바로 종료
        if(p.first == n - 1 && p.second == m - 1) {
            cout << 1 << "\n";
            return 0;
        }

        q.pop();

        for(int d = 0; d < 4; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];

            if(!inRange(nr, nc) || visited[nr][nc] || a[nr][nc] == 0) continue;

            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    cout << 0 << "\n";

    return 0;
}

