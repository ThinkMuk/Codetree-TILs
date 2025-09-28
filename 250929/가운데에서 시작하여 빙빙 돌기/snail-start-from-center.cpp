#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = n * n;
    int dir = 0;

    while(top <= bottom && left <= right) {
        if(dir == 0) {
            for(int i = right; i >= left; --i) {
                grid[bottom][i] = num;
                num--;
            }
            bottom--;
        }
        else if (dir == 1) {
            for(int i = bottom; i >= top; --i) {
                grid[i][left] = num;
                num--;
            }
            left++;
        }
        else if (dir == 2) {
            for(int i = left; i <= right; i++) {
                grid[top][i] = num;
                num--;
            }
            top++;
        }
        else if (dir == 3) {
            for(int i = top; i <= bottom; i++) {
                grid[i][right] = num;
                num--;
            }
            right--;
        }

        dir = (dir + 1) % 4;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
