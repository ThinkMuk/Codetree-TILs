#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int grid[20][20];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];

    int ans = 0;
    for(int dist = 0; dist <= N; dist++) {
        //중심점 기준 탐색
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int gold = 0;
                for(int k = 0; k < N; k++) {
                    for(int l = 0; l < N; l++) {
                        if(abs(k - i) + abs(l - j) <= dist)
                            if(grid[k][l] == 1) gold++;
                    }
                }
                if(gold * M >= dist * dist + (dist+1) * (dist+1))
                    ans = max(ans, gold);
            }
        }
    }
    cout << ans << "\n";
}