#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dr[] = {-1, 1, 0, 0}; // U D R L
int dc[] = {0, 0, 1, -1};

int opposite(int d) {
    // U<->D, R<->L
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    return 2;
}

int charToDir(char c) {
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'R') return 2;
    return 3;
}

struct Ball {
    int r, c, d;
    bool alive;
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<Ball> balls(M);
        for (int i = 0; i < M; i++) {
            char ch;
            cin >> balls[i].r >> balls[i].c >> ch;
            balls[i].r--; balls[i].c--;
            balls[i].d = charToDir(ch);
            balls[i].alive = true;
        }

        // 최대 2*(N-1) 스텝이면 모든 충돌 발생
        int maxStep = 2 * (N - 1);

        for (int step = 0; step < maxStep; step++) {
            // 이동
            for (auto& b : balls) {
                if (!b.alive) continue;
                int nr = b.r + dr[b.d];
                int nc = b.c + dc[b.d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    b.d = opposite(b.d); // 벽 방향 반전, 위치 유지
                } else {
                    b.r = nr;
                    b.c = nc;
                }
            }

            // 충돌 체크
            vector<vector<int>> grid(N, vector<int>(N, 0));
            for (auto& b : balls) {
                if (b.alive) grid[b.r][b.c]++;
            }
            for (auto& b : balls) {
                if (b.alive && grid[b.r][b.c] >= 2) {
                    b.alive = false;
                }
            }
        }

        int ans = 0;
        for (auto& b : balls) if (b.alive) ans++;
        cout << ans << "\n";
    }

    return 0;
}