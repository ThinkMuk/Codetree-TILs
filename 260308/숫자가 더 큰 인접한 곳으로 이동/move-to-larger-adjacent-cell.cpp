#include <iostream>
using namespace std;

int N;
int r,c;
int arr[100][100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
    cin >> N >> r >> c;
    for(int i = 1; i <= N ; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];
    bool isComplete = true;

    while(isComplete) {
        cout << arr[r][c] << " ";
        isComplete = false;
        for(int d = 0; d < 4; d++) {
            int ny = r + dy[d];
            int nx = c + dx[d];

            if(1 <= ny && ny <= N && 1 <= nx && nx <= N) {
                if(arr[ny][nx] > arr[r][c]) {
                    isComplete = true;
                    r = ny; c = nx;
                    break;
                }
            }
        }
    }

    return 0;
}