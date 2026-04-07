#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;

// 방향 U->0, D->1, R->2, L->3
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

int opposite(int d) {
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    return 2;
}

char dirChar[] = {'U', 'D', 'R', 'L'};
int charToDir(char c) {
    for (int i = 0; i < 4; i++)
        if (dirChar[i] == c) return i;
    return -1;
}

struct Ball {
    int r, c, d;
    bool alive;
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        vector<Ball> balls(M);
        for (int i = 0; i < M; i++) {
            char ch;
            cin >> balls[i].r >> balls[i].c >> ch;
            balls[i].r--; balls[i].c--;
            balls[i].d = charToDir(ch);
            balls[i].alive = true;
        }

        // 최대 4 x N x N번 시뮬
        int maxStep = 4 * N * N + 10;

        for (int step = 0; step < maxStep; step++) {
            // 살아있는 구슬 없으면 종료
            int aliveCount = 0;
            for (auto& b : balls) if (b.alive) aliveCount++;
            if (aliveCount == 0) break;

            // 1. 각 구슬 이동 시도
            for (auto& b : balls) {
                if (!b.alive) continue;
                int nr = b.r + dr[b.d];
                int nc = b.c + dc[b.d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    // 벽에 부딪힘: 방향 반전, 이동 안 함
                    b.d = opposite(b.d);
                } else {
                    b.r = nr;
                    b.c = nc;
                }
            }

            // 2. 충돌 체크 - 같은 위치에 2개 이상이면 모두 제거
            // 위치별로 구슬 수집
            map<pair<int,int>, vector<int>> pos;
            for (int i = 0; i < M; i++) {
                if (balls[i].alive) {
                    pos[{balls[i].r, balls[i].c}].push_back(i);
                }
            }
            for (auto& [p, idxs] : pos) {
                if (idxs.size() >= 2) {
                    for (int idx : idxs) balls[idx].alive = false;
                }
            }
        }

        int ans = 0;
        for (auto& b : balls) if (b.alive) ans++;
        cout << ans << "\n";
    }

    return 0;
}