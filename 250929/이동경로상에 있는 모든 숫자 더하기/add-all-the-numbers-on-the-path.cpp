#include <iostream>
#include <string>

using namespace std;

int N, T;
string str;
int board[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int dir = 0;

void changeDir(char d) {
    if(d == 'R') {
        dir = (dir + 1) % 4;
    }
    else if (d == 'L') {
        dir = (dir + 3) % 4;
    }
}

bool inRange(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

int main() {
    int ans = 0;
    cin >> N >> T;
    cin >> str;

    int x = (N-1) / 2, y = (N-1) / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    ans += board[x][y];

    for(char c : str) {
        if(c == 'F') {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(inRange(nx,ny)) {
                x += dx[dir];
                y += dy[dir];
                ans += board[y][x];
            }
        }
        else {
            changeDir(c);
        }
    }

    cout << ans << "\n";

    return 0;
}