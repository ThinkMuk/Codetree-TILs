#include <iostream>
#include <queue>

using namespace std;

int n;
int r, c;
int a[101][101];
int visited[101][101] = {false, };

//상,하,좌,우 우선순위
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int tr, int tc) {
    return(1 <= tr && tr <= n && 1 <= tc && tc <= n);
}

int main() {
    cin >> n >> r >> c;
    //시작위치 r, c
    //격자의 크기 N
    //1,1 부터 시작함

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    queue<pair<int,int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        cout << a[p.first][p.second] << " ";

        for(int d = 0; d < 4; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];
            
            if(!inRange(nr, nc)) continue;
            if(visited[nr][nc]) continue;

            if(a[nr][nc] > a[p.first][p.second]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
                break;
            }
        }
    }

    return 0;
}
