#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int grid[100][100];
vector<vector<bool>> visited;
int pop = 0;
int maxDestroy = 0;

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

int bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int cnt = 0;
    int block = grid[r][c];

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        cnt++;

        for(int d = 0; d < 4; d++) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];

            if(!inRange(nr, nc) || visited[nr][nc] || grid[nr][nc] != block) continue;

            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    visited.assign(n, vector<bool>(n, false));
    // Please write your code here.
    //터지게 되는 블럭의 개수, 가장 큰 블럭의 크기 구하기
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j]) continue;

            int destroy = bfs(i, j);
            //만약 destroy 4개 이상이면 pop 1회 증가
            if(destroy >= 4) pop++;
            //maxDestory 최대 비교
            maxDestroy = max(maxDestroy, destroy);
        }
    }

    cout << pop << " " << maxDestroy << "\n";

    return 0;
}

