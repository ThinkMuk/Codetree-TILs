#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<string> grid;
int ans = 0;

void dfs(int r, int c, int cnt) {
    if (r == R - 1 && c == C - 1) {
        if (cnt == 4) ans++;
        return;
    }

    char cur = grid[r][c];

    for (int dr = 1; r + dr < R; dr++) {
        for (int dc = 1; c + dc < C; dc++) {
            int nr = r + dr;
            int nc = c + dc;

            if (grid[nr][nc] == cur) continue;
            if (cnt + 1 > 4) continue;

            dfs(nr, nc, cnt + 1);
        }
    }
}

int main() {
    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char ch;
            cin >> ch;
            grid[i].push_back(ch);
        }
    }

    dfs(0, 0, 1);

    cout << ans << "\n";
    return 0;
}