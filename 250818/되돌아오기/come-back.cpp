#include <iostream>
using namespace std;

int N;
char dir[100];
int dist[100];
int arr[20001][20001];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dir[i] >> dist[i];
    }

    int cnt = 0;
    int x = 10000, y = 10000;
    arr[x][y] = cnt;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < dist[i]; j++) {
            cnt++;
            if (dir[i] == 'N') y++;
            else if (dir[i] == 'E') x++;
            else if (dir[i] == 'W') x--;
            else if (dir[i] == 'S') y--;

            if (x == 10000 && y == 10000) {
                cout << cnt;
                return 0;
            }

            arr[x][y] = cnt + 1;
        }
    }

    cout << -1;
    return 0;
}