#include <iostream>

using namespace std;

int n, m;
int arr[100][100];

bool inRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    cin >> n >> m;

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int dir_num = 0;
    int x = 0; int y = 0;

    arr[x][y] = 1;

    for(int i = 2; i <= n * m; i++) {
        int nx = x + dx[dir_num], ny = y + dy[dir_num];

        if(!inRange(nx,ny) || arr[nx][ny] != 0)
            dir_num = (dir_num + 1) % 4;
        
        x = x + dx[dir_num]; y = y + dy[dir_num];
        arr[x][y] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}