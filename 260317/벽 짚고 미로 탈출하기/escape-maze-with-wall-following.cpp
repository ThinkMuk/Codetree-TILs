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

// 1 앞이 벽 -> 반시계 회전 (이동 없음)
// 2 앞이 격자 밖 -> 탈출
// 3 앞이 빈 칸 -> 이동(cnt++) 후 오른쪽에 벽이 없으면 시계 회전

int main() {
    cin >> N;
    int r, c; cin >> r >> c;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int cnt = 0;
    int d = 0;

    for(int step = 0; step < N * N * 8; step++) {
        int ny = r + dy[d], nx = c + dx[d];

        if(isWall(ny, nx)) {
            d = (d + 3) % 4; // 반시계 90도 회전
        }
        else if(!inRange(ny, nx)) {
            cnt++;
            cout << cnt << "\n";
            return 0;
        }
        else {
            r = ny; c = nx;
            cnt++;
            // 이동 후 오른쪽에 벽이 없으면 시계 90도 회전
            if(!isWall(r + dy[(d+1)%4], c + dx[(d+1)%4]))
                d = (d + 1) % 4;
        }
    }

    cout << -1 << "\n";
    return 0;
}