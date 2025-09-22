#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<string> board;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    board.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    cin >> K;

    int x, y, dir;

    if (K <= N) { // 위쪽
        x = 0; y = K - 1; dir = 0;
    } else if (K <= 2 * N) { // 오른쪽
        x = K - N - 1; y = N - 1; dir = 3;
    } else if (K <= 3 * N) { // 아래쪽
        x = N - 1; y = 3 * N - K; dir = 2;
    } else { // 왼쪽
        x = 4 * N - K; y = 0; dir = 1;
    }

    int cnt = 0;
    while (x >= 0 && x < N && y >= 0 && y < N) {
        char m = board[x][y];
        cnt++;

        if (m == '/') {
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else dir = 0;
        } else { // '\'
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else dir = 2;
        }

        x += dx[dir];
        y += dy[dir];
    }

    cout << cnt << "\n";
    return 0;
}