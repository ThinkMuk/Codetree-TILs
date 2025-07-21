#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int dir(char d) {
    if(d == 'R') return 0;
    else if(d == 'D') return 1;
    else if(d == 'L') return 2;
    else if(d == 'U') return 3;
}

int main() {
    cin >> n >> t; // N x N 배열, t초 동안 이동
    cin >> r >> c >> d; // r, c 초기 값, 초기 구슬 방향 설정 d

    int numDir = dir(d);
    r -= 1;
    c -= 1;

    for(int i = 0; i < t; i++) {
        int tmpR = r + dx[numDir];  // r은 행, dx는 행 변화
        int tmpC = c + dy[numDir];  // c는 열, dy는 열 변화

        if(inRange(tmpR, tmpC)) {
            r += dx[numDir];
            c += dy[numDir];
        } else { //부딪혔을 때
            numDir = (numDir + 2) % 4;
        }
    }

    cout << r+1 << " " << c+1;

    return 0;
}