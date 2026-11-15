#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, t;
int a[20][20];
queue<pair<int,int>> cords;

//상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//2개 이상의 구슬 위치가 동일하다면 구슬이 사라짐
//격자의 크기 N, 구슬의 개수 M, 시간을 나타내는 T
//r,c가 구슬의 위치

bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        cords.push({r - 1, c - 1});
    }

    // Please write your code here.
    for(int time = 0; time < t; time++) {
        vector<vector<int>> tmp(n, vector<int>(n, 0));

        //현재 살아있는 구슬의 개수
        int sz = cords.size();

        for(int i = 0; i < sz; i++) {
            pair<int,int> p = cords.front();
            cords.pop();

            int r = p.first;
            int c = p.second;

            int maxVal = -1;
            int mr = -1, mc = -1;

            //상하좌우 탐색
            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(!inRange(nr, nc)) continue;

                if(maxVal < a[nr][nc]) {
                    maxVal = a[nr][nc];
                    mr = nr;
                    mc = nc;
                }
            }

            //이동한 위치에 구슬 개수 추가
            if(mr != -1 && mc != -1) {
                tmp[mr][mc]++;
            }
        }

        //구슬 충돌 여부 확인
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                //구슬이 하나만 존재하면 생존
                if(tmp[i][j] == 1) {
                    cords.push({i, j});
                }

                //구슬이 2개 이상이면 소멸
            }
        }
    }

    cout << cords.size() << "\n";

    return 0;
}
