#include <iostream>
#include <vector>
using namespace std;

int N, M;
int r[10000], c[10000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;

int main() {
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        cin >> r[i] >> c[i];
    }

    for (int i = 0; i < M; i++) {
        int x = r[i] - 1;
        int y = c[i] - 1;

        if (arr[x][y] == 0) {
            arr[x][y] = 1;
        }

        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (arr[nx][ny] == 1) cnt++;
            }
        }

        if (cnt == 3) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}