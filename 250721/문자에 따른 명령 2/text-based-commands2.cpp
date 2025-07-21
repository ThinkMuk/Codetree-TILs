#include <iostream>

using namespace std;

string dirs;
int x = 0, y = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin >> dirs;

    int dir = 3;
    for(char a: dirs) {
        if(a == 'L') {
            dir = (dir-1 + 4) % 4;
        }
        else if (a == 'R') {
            dir = (dir+1) % 4;
        }
        else if (a == 'F') {
            x += dx[dir];
            y += dy[dir];
        }
    }

    cout << x << " " << y;

    return 0;
}