#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int a[100][100];
vector<vector<int>> visited;

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

int main() {
    int ans = -1;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    visited.assign(n, vector<int>(m, false));
    queue<tuple<int,int,int>> q;
    visited[0][0] = true;
    q.push({0, 0, 0});

    while(!q.empty()) {
        tuple<int,int,int> p = q.front();

        //목적지 도착 시
        if(get<0>(p) == n - 1 && get<1>(p) == m-1) {
            ans = get<2>(p);
            break;
        }

        q.pop();

        for(int d = 0; d < 4; d++) {
            int nr = get<0>(p) + dr[d];
            int nc = get<1>(p) + dc[d];
            
            if(!inRange(nr, nc) || visited[nr][nc]) continue;
            if(a[nr][nc] == 0) continue;

            visited[nr][nc] = true;
            q.push({nr, nc, get<2>(p) + 1});
        }
    }

    cout << ans << "\n";

    return 0;
}

