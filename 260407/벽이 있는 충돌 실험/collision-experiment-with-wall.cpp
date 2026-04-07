#include <iostream>
#include <vector>
#include <map>
using namespace std;
using namespace std;

int dr[] = {-1, 1, 0, 0}; // U D R L
int dc[] = {0, 0, 1, -1};

int opposite(int d) {
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

string getState(const vector<Ball>& balls) {
    string s = "";
    for (auto& b : balls) {
        if (b.alive)
            s += to_string(b.r) + "," + to_string(b.c) + "," + to_string(b.d) + "|";
    }
    return s;
}

int simulate(int N, vector<Ball> balls) {
    set<string> seen;
    int prevAlive = -1;

    while (true) {
        // 살아있는 구슬 수가 바뀌면 seen 리셋
        int curAlive = 0;
        for (auto& b : balls) if (b.alive) curAlive++;
        
        if (curAlive == 0) return 0;
        
        if (curAlive != prevAlive) {
            seen.clear();
            prevAlive = curAlive;
        }

        string state = getState(balls);
        if (seen.count(state)) break; // 주기 감지 -> 더 이상 충돌 없음
        seen.insert(state);

        // 이동
        for (auto& b : balls) {
            if (!b.alive) continue;
            int nr = b.r + dr[b.d];
            int nc = b.c + dc[b.d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                b.d = opposite(b.d);
            else {
                b.r = nr;
                b.c = nc;
            }
        }

        // 충돌 체크
        vector<vector<int>> grid(N, vector<int>(N, 0));
        for (auto& b : balls)
            if (b.alive) grid[b.r][b.c]++;
        for (auto& b : balls)
            if (b.alive && grid[b.r][b.c] >= 2)
                b.alive = false;
    }

    int ans = 0;
    for (auto& b : balls) if (b.alive) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<Ball> balls(M);
        for (int i = 0; i < M; i++) {
            char ch;
            cin >> balls[i].r >> balls[i].c >> ch;
            balls[i].r--;
            balls[i].c--;
            balls[i].d = charToDir(ch);
            balls[i].alive = true;
        }

        cout << simulate(N, balls) << "\n";
    }

    return 0;
}