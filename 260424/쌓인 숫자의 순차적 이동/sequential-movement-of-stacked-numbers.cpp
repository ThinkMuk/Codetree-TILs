#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> grid[21][21];
map<int, pair<int,int>> pos;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void move(int num) {
    auto [r, c] = pos[num];
    
    auto& stk = grid[r][c];
    int idx = -1;
    for (int i = 0; i < (int)stk.size(); i++) {
        if (stk[i] == num) { idx = i; break; }
    }
    
    int bestVal = -1, br = -1, bc = -1;
    for (int d = 0; d < 8; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (grid[nr][nc].empty()) continue;

        int maxVal = *max_element(grid[nr][nc].begin(), grid[nr][nc].end());
        
        if (maxVal > bestVal) {
            bestVal = maxVal;
            br = nr; bc = nc;  // bc = bc 오타 수정
        }
    }
    
    if (br == -1) return;
    
    vector<int> moving(stk.begin(), stk.begin() + idx + 1);
    stk.erase(stk.begin(), stk.begin() + idx + 1);
    grid[br][bc].insert(grid[br][bc].begin(), moving.begin(), moving.end());
    
    for (int v : moving) {
        pos[v] = {br, bc};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v; cin >> v;
            grid[i][j].push_back(v);
            pos[v] = {i, j};
        }
    }
    
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        move(num);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j].empty()) {
                cout << "None\n";
            } else {
                for (int k = 0; k < (int)grid[i][j].size(); k++) {
                    if (k) cout << ' ';
                    cout << grid[i][j][k];
                }
                cout << '\n';
            }
        }
    }
    
    return 0;
}