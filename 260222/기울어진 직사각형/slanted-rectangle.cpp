#include <iostream>
using namespace std;

int N;

bool inRange(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

int main() {
    cin >> N;
    int arr[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    //방향 설정
    int dy[4] = {-1, -1, 1, 1};
    int dx[4] = {1, -1, -1, 1};

    int ans = 0;
    for(int i = 1; i <= N; i++) { //1,3 대각선 범위
        for(int j = 1; j <= N; j++) { //2, 4 대각선 범위
            //범위 탐색
            for(int k = 0; k < N; k++) {
                for(int l = 0; l < N; l++) {
                    //연산 진행
                    int cnt = 0;
                    int ttlDir[4] = {i, j, i, j};
                    int tmpX = l; int tmpY = k;
                    bool isPossible = true;

                    for(int dir = 0; dir < 4; dir++) {
                        for(int tmp = 0; tmp < ttlDir[dir]; tmp++) {
                            if(inRange(tmpX, tmpY)) {
                                cnt += arr[tmpY][tmpX];
                            }
                            else {
                                isPossible = false;
                                break;
                            }
                            tmpX += dx[dir]; tmpY += dy[dir];
                        }
                        if(!isPossible) break;
                    }

                    if(isPossible) ans = max(ans, cnt);
                }
            }
        }
    }
    cout << ans << "\n";
}