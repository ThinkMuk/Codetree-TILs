#include <iostream>
#include <cstring>
using namespace std;

int n;
int grid[51][51];
int tmp[51][51];

// 십자 모양으로 제거
void explode(int r, int c) {
    int k = tmp[r][c];
    tmp[r][c] = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
        for (int i = 1; i < k; i++) {
            int nr = r + dr[d] * i;
            int nc = c + dc[d] * i;
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                tmp[nr][nc] = 0;
            }
        }
    }
}

void gravity() {
    // 각 열마다 중력 적용
    for (int c = 1; c <= n; c++) {
        int bottom = n;
        for (int r = n; r >= 1; r--) {
            if (tmp[r][c] != 0) {
                int val = tmp[r][c];
                tmp[r][c] = 0;
                tmp[bottom][c] = val;
                bottom--;
            }
        }
    }
}

int countPairs() {
    int cnt = 0;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (tmp[r][c] == 0) continue;
            // 중복 방지용 오른쪽, 아래쪽만 체크
            if (c + 1 <= n && tmp[r][c] == tmp[r][c + 1]) cnt++;
            if (r + 1 <= n && tmp[r][c] == tmp[r + 1][c]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 격자 복사
            memcpy(tmp, grid, sizeof(grid));
            explode(i, j);
            gravity();
            ans = max(ans, countPairs());
        }
    }

    cout << ans << endl;
    return 0;
}