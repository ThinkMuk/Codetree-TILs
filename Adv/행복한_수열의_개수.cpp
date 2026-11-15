#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int happyNum = -1;
        int maxCnt = 0;

        for(int j = 0; j < n; j++) {
            if(happyNum != grid[i][j]) {
                happyNum = grid[i][j];
                cnt = 1;
            }
            else cnt++;

            maxCnt = max(maxCnt, cnt);
        }
        if(maxCnt >= m) ans++;
    }

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int happyNum = -1;
        int maxCnt = 0;

        for(int j = 0; j < n; j++) {
            if(happyNum != grid[j][i]) {
                happyNum = grid[j][i];
                cnt = 1;
            }
            else cnt++;

            maxCnt = max(maxCnt, cnt);
        }
        if(maxCnt >= m) ans++;
    }

    cout << ans << "\n";

    return 0;
}

