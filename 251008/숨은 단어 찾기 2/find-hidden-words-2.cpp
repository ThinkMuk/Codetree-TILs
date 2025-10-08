#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
char arr[50][50];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; //위에서부터 한바퀴
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inRange(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < M);
}

bool LeeCnt(int y, int x, int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    int cnt = 0;

    while(inRange(ny, nx) && arr[ny][nx] == 'E' && cnt < 2) {
        cnt++;
        ny += dy[dir];
        nx += dx[dir];
    }
    
    return (cnt == 2);
}

int main() {
    cin >> N >> M;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(arr[i][j] != 'L')
                continue;

            for(int k = 0; k < 8; k++) {
                if(LeeCnt(i,j,k))
                    ans++;
            }
        }
    }

    cout << ans;

    return 0;
}