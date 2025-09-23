#include <iostream>
using namespace std;

int arr[100][100] = {0,};
int n, m;

int main() {
    cin >> n >> m;

    int cnt = 1;
    int top = 0, bottom = n-1, left = 0, right = m-1;
    int dir = 0; // 아래 0, 오른쪽 1, 위 2, 왼쪽 3

    while(top <= bottom && left <= right) {
        if(dir == 0) { // 아래
            for(int i = top; i <= bottom; i++) {
                arr[i][left] = cnt++;
            }
            left++;
        } else if(dir == 1) { // 오른쪽
            for(int j = left; j <= right; j++) {
                arr[bottom][j] = cnt++;
            }
            bottom--;
        } else if(dir == 2) { // 위
            for(int i = bottom; i >= top; i--) {
                arr[i][right] = cnt++;
            }
            right--;
        } else if(dir == 3) { // 왼쪽
            for(int j = right; j >= left; j--) {
                arr[top][j] = cnt++;
            }
            top++;
        }
        dir = (dir + 1) % 4;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}