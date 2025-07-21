#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool inRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int dir(char d) {
    if(d == 'U')
        return 3;
    else if (d == 'D')
        return 1;
    else if (d == 'R')
        return 0;
    else if (d == 'L')
        return 2;
}

int main() {
    cin >> n >> t; // N x N 배열, t초 동안 이동
    cin >> r >> c >> d; // r, c 초기 값, 초기 구슬 방향 설정 d

    int numDir = dir(d);
    r -= 1;
    c -= 1;

    for(int i = 0; i < t; i++) {
        int tmpR = c + dx[numDir];
        int tmpC = r + dy[numDir];

        if(inRange(tmpC, tmpR)) {
            c += dx[numDir];
            r += dy[numDir];
        }
        //0 <= x && x < n && 0 <= y && y < n
        else if(!inRange(tmpC, tmpR)) { //부딪혔을 때
            numDir = (numDir+2) % 4;
        }
    }

    cout << r+1 << " " << c+1;

    return 0;
}