#include <iostream>
#include <cstring>
using namespace std;

int N;
int grid[51][51];
int tmp[51][51];

//십자모양 터트리기 함수
void explode(int y, int x) {
    int k = tmp[y][x];
    tmp[y][x] = 0;
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for(int d = 0; d < 4; d++) {
        for(int i = 1; i < k; i++) {
            int ny = y + dy[d] * i;
            int nx = x + dx[d] * i;
            if(1 <= ny && ny <= N && 1 <= nx && nx <= N)
                tmp[ny][nx] = 0;
        }
    }
}

//중력 적용 함수
void gravity() {
    for(int x = 1; x <= N; x++) {
        int bottom = N;
        for(int y = N; y >= 1; y--) {
            if(tmp[y][x] != 0) {
                int val = tmp[y][x];
                tmp[y][x] = 0;
                tmp[bottom][x] = val;
                bottom--;
            }
        }
    }
}

//짝 구하기 함수
int countPairs() {
    int cnt = 0;
    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= N; x++) {
            if(tmp[y][x] == 0) continue;
            if(x + 1 <= N && tmp[y][x] == tmp[y][x+1]) cnt++;
            if(y + 1 <= N && tmp[y][x] == tmp[y+1][x]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> grid[i][j];

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            memcpy(tmp, grid, sizeof(grid));
            explode(i,j);
            gravity();
            ans = max(ans, countPairs());
        }
    }

    cout << ans << "\n";
    return 0;
}