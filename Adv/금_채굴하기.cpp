#include <iostream>
#include <cmath>

using namespace std;

//더 최적화 할 방법은 없을지 생각해보기
//멘헤튼 거리를 통해 마름모를 쉽게 구할 수 있음
// abs(r - i) + abs(c - j) < K (r, c는 중심 좌표)

int n, m;
int grid[20][20];

//마름모 탐색
int search(int r, int c, int K) {
    int gold = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int area = abs(r - i) + abs(c - j);

            if(area < K + 1 && grid[i][j] == 1) gold++;
        }
    }

    return gold;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    // 채굴에 드는 비용은 K^2 + (K + 1)^2 
    // 금 한개의 가격은 M
    // 손해를 보지 않으며 "채굴할 수 있는 가장 많은 금의 개수" 출력
    
    // 범위 크기

    int ans = 0;
    for(int k = 0; k < n + 1; k++) {
        //좌표마다 탐색
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int g = search(i, j, k);

                if(pow(k, 2) + pow(k + 1, 2) <= g * m) ans = max(ans, g);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

