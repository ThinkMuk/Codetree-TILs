#include <iostream>
#include <string>

using namespace std;

string commands;

int distX[4] = {0, 1, 0, -1}; int distY[4] = {1, 0, -1, 0};
int dist = 0;
int cnt = 0;
int x = 0, y = 0;

int main() {
    cin >> commands;

    for(char c : commands) {
        if (c == 'F') {
            x += distX[dist]; y += distY[dist];
            cnt++;
        }
        else if (c == 'L') {
            dist = (dist + 4 - 1) % 4;
            cnt++;
        }
        else if (c == 'R') {
            dist = (dist + 1) % 4;
            cnt++;
        }
        if (x == 0 && y == 0) {
            cout << cnt;
            return 0;
        }
    }

    cout << -1;

    return 0;
}