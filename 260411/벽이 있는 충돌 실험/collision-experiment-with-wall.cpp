#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0};  // U, D, R, L
int dy[] = {0, 0, 1, -1};
int opposite[] = {1, 0, 3, 2};

struct Marble {
    int x, y, dir;
    bool alive;
};

int N, M;
vector<Marble> marbles;

int dirToIdx(char d) {
    if (d == 'U') return 0;
    if (d == 'D') return 1;
    if (d == 'R') return 2;
    return 3;
}

void moveAll() {
    for (auto& m : marbles) {
        if (!m.alive) continue;

        int nx = m.x + dx[m.dir];
        int ny = m.y + dy[m.dir];

        if (nx < 1 || nx > N || ny < 1 || ny > N) {
            m.dir = opposite[m.dir];
        } else {
            m.x = nx;
            m.y = ny;
        }
    }
}

void checkCollision() {
    vector<vector<vector<int>>> grid(N + 1, vector<vector<int>>(N + 1));

    for (int i = 0; i < (int)marbles.size(); i++) {
        if (!marbles[i].alive) continue;
        grid[marbles[i].x][marbles[i].y].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j].size() >= 2) {
                for (int idx : grid[i][j]) {
                    marbles[idx].alive = false;
                }
            }
        }
    }
}

int solve() {
    int MAX_STEP = N * N * 4;

    for (int step = 0; step < MAX_STEP; step++) {
        moveAll();
        checkCollision();
    }
    int cnt = 0;
    for (const auto& m : marbles) {
        if (m.alive) cnt++;
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        marbles.clear();

        for (int i = 0; i < M; i++) {
            Marble m;
            char d;
            cin >> m.x >> m.y >> d;
            m.dir = dirToIdx(d);
            m.alive = true;
            marbles.push_back(m);
        }

        cout << solve() << "\n";
    }

    return 0;
}