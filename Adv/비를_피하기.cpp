#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, h, m;
int grid[100][100];
vector<pair<int,int>> person;
vector<vector<int>> board;

    //정수 0,1,2,3으로만 이루어진 n자 격자
    //H명 겹치지 않게 서있음
    //비를 피할 수 있는 공간 M개
    //0은 해당칸이 이동할 수 있는곳
    //1은 벽 (이동 불가능)
    //2 해당칸에 사람 서있음
    //3 비를 피할 수 있는 공간

    //bfs로 풀자
    //별도 bfs함수에 (r, c) 시작으로 넣고 하면 될 듯
    //queue를 tuple로 만들어서 이전에 움직인 cnt를 저장한 상태로 진행하면 될듯
    //마지막에 queue가 비를 피하는 위치를 도달했다면 (좌표가 3이면)
    //cnt를 출력하면 됨
    //bfs니까 따로 min값 비교 안해도 될 듯
    //저장은 별도 2차원 board에서 진행 (-1로 초기화)

    //출력할때는
    // grid 2이 아니라면 0 출력
    // grid가 2이라면 board에서 해당 좌표의 값 출력

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

void bfs(int r, int c) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    //r, c, 걸어다닌 걸이
    queue<tuple<int,int,int>> q;
    q.push({r, c, 0});
    visited[r][c] = true;

    while(!q.empty()) {
        tuple<int,int,int> t = q.front();
        q.pop();
        
        //3에 도달했을 때
        //bfs이기 때문에 가장 먼저 도착했을 것
        if(grid[get<0>(t)][get<1>(t)] == 3) {
            board[r][c] = get<2>(t);
            return;
        }

        for(int d = 0; d < 4; d++) {
            int nr = get<0>(t) + dr[d];
            int nc = get<1>(t) + dc[d];
            //범위 안에 존재하지 않거나, 방문했으면 continue
            if(!inRange(nr, nc) || visited[nr][nc]) continue;
            //벽이면 막힘
            if(grid[nr][nc] == 1) continue;

            q.push({nr, nc, get<2>(t) + 1});
            visited[nr][nc] = true;
        }
    }
}

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    //초기화
    board.assign(n, vector<int>(n, -1));

    // Please write your code here.

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                person.push_back({i, j});
            }
        }
    }

    for(pair<int,int> p : person) {
        bfs(p.first, p.second);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) cout << board[i][j] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
