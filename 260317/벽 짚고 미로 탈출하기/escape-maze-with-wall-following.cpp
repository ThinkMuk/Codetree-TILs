#include <iostream>
using namespace std;

int N;
char arr[101][101];

int dr[] = {0, 1, 0, -1}; //오 아래 왼 위
int dc[] = {1, 0, -1, 0};

bool inRange(int r, int c) {
    return (1 <= r && r <= N && 1 <= c && c <= N);
}

bool isWall(int r, int c) {
    return inRange(r, c) && arr[r][c] == '#';
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
        int nr = r + dr[d], nc = c + dc[d];

        if(isWall(nr, nc)) {
            d = (d + 3) % 4; // 반시계 90도 회전
        }
        else if(!inRange(nr, nc)) {
            cnt++;
            cout << cnt << "\n";
            return 0;
        }
        else {
            r = nr; c = nc;
            cnt++;
            // 이동 후 오른쪽에 벽이 없으면 시계 90도 회전
            if(!isWall(r + dr[(d+1)%4], c + dc[(d+1)%4]))
                d = (d + 1) % 4;
        }
    }

    cout << -1 << "\n";
    return 0;
}