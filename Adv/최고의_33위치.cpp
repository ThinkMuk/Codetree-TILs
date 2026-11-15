#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

bool inRange(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    // Please write your code here.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cnt = 0;
            bool isAble = true;
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    int sr = i + r;
                    int sc = j + c;

                    if(!inRange(sr, sc)) {
                        isAble = false; break;
                    }
                    
                    if(grid[sr][sc] == 1) cnt++;
                }
                if(!isAble) break;
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << "\n";
    return 0;
}

