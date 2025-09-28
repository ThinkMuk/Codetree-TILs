#include <iostream>

using namespace std;

int n, m;

int main() {
    char arr[101][101];
    cin >> n >> m;
    
    int top = 0, bottom = n-1, left = 0, right = m-1;
    int alphabet = 'A';
    int count = 1;
    int status = 0; // 0: 오른쪽, 1:아래, 2:왼쪽, 3:위

    while(top <= bottom && left <= right) {
        if(status == 0) { // 오른쪽
            for(int i = left; i <= right; i++) {
                arr[top][i] = alphabet;
                alphabet = 'A' + (count % 26);
                count++;
            }
            top++;
        }
        else if (status == 1) { //아래
            for(int i = top; i <= bottom; i++) {
                arr[i][right] = alphabet;
                alphabet = 'A' + (count % 26);
                count++;
            }
            right--;
        }
        else if (status == 2) { //왼쪽
            for(int i = right; i >= left; i--) {
                arr[bottom][i] = alphabet;
                alphabet = 'A' + (count % 26);
                count++;
            }
            bottom--;
        }
        else if (status == 3) { //위
            for(int i = bottom; i >= top; i--) {
                arr[i][left] = alphabet;
                alphabet = 'A' + (count % 26);
                count++;
            }
            left++;
        }

        status = (status + 1) % 4;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
