#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool inRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                if(inRange(i+dx[k], j+dy[k]) && grid[i+dx[k]][j+dy[k]] == 1)
                    cnt++;
            }
            if(cnt >= 3)
                ans++;
        }
    }

    cout << ans;
    
    return 0;
}