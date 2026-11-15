#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
int grid[20][20];
int ans = 0;

//1은 폭탄이 놓인 칸
//3가지 중 정확히 하나의 폭탄을 선택, 초토화 되는 칸들의 합집합의 크기를 최대화

//1은 세로직선, 2는 상하좌우, 3은 대각선 폭탄

//상하좌우 폭탄
int br[4] = {-1, 1, 0, 0};
int bc[4] = {0, 0, -1, 1};

//대각선 폭탄
int bbr[4] = {-1, -1, 1, 1};
int bbc[4] = {-1, 1, 1, -1};

vector<tuple<int,int,int>> cord;

//범위 안에 속하는지
bool inRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

void bomb(tuple<int,int,int> t, vector<vector<int>>& v) {
    int r = get<0>(t);
    int c = get<1>(t);
    v[r][c] = 1;

    //1번폭탄
    if(get<2>(t) == 1) {        
        for(int i = 1; i <= 2; i++) {
            int nr = r + i;
            int nnr = r - i;

            if(inRange(nr, c)) v[nr][c] = 1;
            if(inRange(nnr, c)) v[nnr][c] = 1;
        }
    }
    //2번폭탄
    else if (get<2>(t) == 2) {
        for(int d = 0; d < 4; d++) {
            int nr = r + br[d];
            int nc = c + bc[d];

            if(!inRange(nr, nc)) continue;

            v[nr][nc] = 1;
        }
    }
    //3번폭탄
    else if (get<2>(t) == 3) {
        for(int d = 0; d < 4; d++) {
            int nr = r + bbr[d];
            int nc = c + bbc[d];

            if(!inRange(nr, nc)) continue;

            v[nr][nc] = 1;
        }
    }
}

void perm(int degree) {
    //모든 좌표 폭탄이 결정됐다면
    if(degree == cord.size()) {
        //임시 보드 생성
        vector<vector<int>> v(n, vector<int>(n, 0));

        //보드에 폭탄 터트리기
        for(tuple<int,int,int> t: cord) {
            bomb(t, v);
        }

        //터진 영역 카운트
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 1) cnt++;
            }
        }

        ans = max(ans, cnt);
        return;
    }

    for(int i = 1; i <= 3; i++) {
        //1번 폭탄
        get<2>(cord[degree]) = i;
        perm(degree + 1);
        //백트래킹
        get<2>(cord[degree]) = 0;        
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) cord.push_back({i, j, 0});
        }
    }

    perm(0);

    cout << ans << "\n";

    return 0;
}

