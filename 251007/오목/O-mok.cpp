#include <iostream>
#include <vector>
using namespace std;

int board[19][19];
int dy[4] = {-1, 0, 1, 1};
int dx[4] = {1, 1, 1, 0};

bool inRange(int y, int x) {
    return (0 <= y && y < 19 && 0 <= x && x < 19);
}

int cntStone(int y, int x, int dir, int color) {
    int cnt = 1;
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    while(inRange(ny,nx) && board[ny][nx] == color) {
        cnt++;
        ny += dy[dir];
        nx += dx[dir];
    }

    return cnt;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    for (int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(board[i][j] == 0)
                continue;
            
            int color = board[i][j];

            for(int k = 0; k < 4; k++) {
                int prevY = i - dy[k];
                int prevX = j - dx[k];

                if(!inRange(prevY, prevX) && color == board[prevY][prevX])
                    continue;
                
                int cnt = cntStone(i, j, k, color);

                if(cnt == 5) {
                    int ansY = i + (dy[k] * 2);
                    int ansX = j + (dx[k] * 2);

                    cout << color << "\n";
                    cout << ansY + 1 << " " << ansX + 1 << "\n";

                    return 0;
                }
            }
        }
    }
    return 0;
}