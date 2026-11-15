#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

bool inRange(int tr, int tc) {
    return (0 <= tr && tr < n && 0 <= tc && tc < n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    // Please write your code here.
    //큐브 안에 있는 숫자의 범위만큼 폭발
    //터진 후 중력으로 인해 위에 떠있는 애들은 아래로 하강
    //전체 범위 말고 범위를 (r - (터진범위 / 2) - 1) 부터 (r + 터진범위 / 2) 까지 하면 됨
    int range = grid[r - 1][c - 1];
    int orgR = r - 1;
    int orgC = c - 1;
    
    //폭탄 터트리기

    //세로 폭탄
    for(int i = orgR - (range - 1); i <= orgR + (range - 1); i++) {
        if(!inRange(i, orgC)) continue;
        grid[i][orgC] = 0;
    }
    for(int j = orgC - (range - 1); j <= orgC + (range - 1); j++) {
        if(!inRange(orgR, j)) continue;
        grid[orgR][j] = 0;
    }

    //중력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                for(int k = i; k > 0; --k) {
                    grid[k][j] = grid[k - 1][j];
                    grid[k - 1][j] = 0;
                }
            }
        }
    }
    //임시 검증용
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

