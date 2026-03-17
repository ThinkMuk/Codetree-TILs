#include <iostream>
using namespace std;

int N;
char arr[101][101];

int dy[] = {0, 1, 0, -1}; //오 아래 왼 위
int dx[] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return (1 <= y && y <= N && 1 <= x && x <= N);
}

bool isWall(int y, int x) {
    return inRange(y, x) && arr[y][x] == '#';
}

int main() {
    cin >> N;
    int c, r; cin >> c >> r;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int cnt = 0;
    int d = 0;
    int maxStep = N * N * 4;

    for(int step = 0; step < maxStep; step++) {
        int ny = r + dy[d], nx = c + dx[d];

        if(isWall(ny, nx)) { //앞이 벽 -> 반시계 90 회전
            d = (d + 3) % 4;
        }
        else if(!inRange(ny, nx)) { // 1.격자 밖 -> 탈출
            cnt++;
            cout << cnt << endl;
            return 0;
        }
        else {
            // 이동 가능한 빈 칸
            // 이동했다고 가정한 위치(ny, nx)에서 오른쪽 체크
            int rd = (d + 1) % 4; // 오른쪽 방향 (시계 90도)
            if(isWall(ny + dy[rd], nx + dx[rd])) {
                // 2. 오른쪽에 벽 있음 -> 그냥 이동
                r = ny; c = nx;
                cnt++;
            }
            else {
                // 3. 오른쪽에 벽 없음
                // 한 칸 이동
                r = ny; c = nx;
                cnt++;
                // 시계 90도 회전
                d = (d + 1) % 4;
                // 한 칸 더 전진
                ny = r + dy[d]; nx = c + dx[d];
                if(!inRange(ny, nx)) {
                    cnt++;
                    cout << cnt << "\n";
                    return 0;
                }
                r = ny; c = nx;
                cnt++;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}