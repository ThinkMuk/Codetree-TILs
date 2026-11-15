#include <iostream>
#include <climits>

using namespace std;

int n, m, k;
int grid[101][101];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    //1 x M 크기의 블럭이 떨어짐
    // 블럭이 떨어지는 도중 단 한곳에라도 이미 격자판 위에 놓여있던 블럭과 맞닿으면 멈춤
    //격자의 크기를 나타내는 N
    //블록의 크기를 나타내는 M
    //블록이 떨어질 위치에 대한 정보 K
    //K번째 열부터 K + M - 1번째 열까지 공간 차지
    //1,1부터 시작

    //아래에서 위로 내려오며 최대 높이 파악
    int minR = n + 1;
    for(int c = k; c <= k + m - 1; c++) {
        for(int r = n; r > 0; --r) {
            if(grid[r][c] == 1) {
                minR = min(minR, r);
            }
        }
    }

    //최대 높이 위에 블럭 얹기
    for(int i = k; i <= k + m - 1; i++) {
        grid[minR - 1][i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

