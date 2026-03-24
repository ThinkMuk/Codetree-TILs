#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M, T;

int dy[] = {-1, 1, 0, 0}; // U, D, R, L
int dx[] = {0, 0, 1, -1};

int dirIdx(char d) {
    if(d == 'U') return 0;
    if(d == 'D') return 1;
    if(d == 'R') return 2;
    return 3;
}

char revDir(char d) {
    if(d == 'U') return 'D';
    if(d == 'D') return 'U';
    if(d == 'R') return 'L';
    return 'R';
}

struct Marble {
    int r, c, w, id;
    char d;
    bool alive;
};

int main() {
    cin >> N >> M >> T;
    vector<Marble> marbles(M);
    for(int i = 0; i < M; i++) {
        cin >> marbles[i].r >> marbles[i].c >> marbles[i].d >> marbles[i].w;
        marbles[i].id = i + 1;
        marbles[i].alive = true;
    }

    for(int t = 0; t < T; t++) {
        // 1) 이동
        for(auto& m : marbles) {
            if(!m.alive) continue;
            int di = dirIdx(m.d);
            int nr = m.r + dy[di];
            int nc = m.c + dx[di];
            if(nr < 1 || nr > N || nc < 1 || nc > N) {
                // 벽에 부딪히면 방향만 반전, 위치는 그대로 (1초 소모)
                m.d = revDir(m.d);
            } else {
                // 범위 안이면 실제로 이동
                m.r = nr;
                m.c = nc;
            }
        }

        // 2) 합치기 - map 사용
        map<pair<int,int>, vector<int>> grid;
        for(int i = 0; i < M; i++) {
            if(!marbles[i].alive) continue;
            // 살아있는 구슬만 자기 좌표에 등록
            grid[{marbles[i].r, marbles[i].c}].push_back(i);
        }
        for(auto& [pos, idxs] : grid) {
            if(idxs.size() <= 1) continue; // 1개 이하면 충돌 없음

            // 오름차순으로 push했으므로 마지막이 가장 큰 idx = 가장 큰 id
            int best = idxs.back();

            // 같은 칸의 모든 구슬 무게를 합산
            int totalW = 0;
            for(int idx : idxs) {
                totalW += marbles[idx].w;
                if(idx != best) marbles[idx].alive = false; // best 외에는 제거
            }
            marbles[best].w = totalW; //best 합산 무게로 적용
        }
    }

    int cnt = 0, maxW = 0;
    for(auto& m : marbles) {
        if(m.alive) {
            cnt++;
            maxW = max(maxW, m.w);
        }
    }
    cout << cnt << " " << maxW << "\n";
    return 0;
}