#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[10][10];
int visitedR[10];
int visitedC[10];
vector<pair<int,int>> v;
int ans = 0;

//N개의 칸 색칠
//행과 열에 정확히 1개의 색칠된 칸만
//색칠된 칸에 적힌 수들의 합 중 가능한 최댓값

//r, c를 선택했다면
//r행, c행은 이제 선택지에 없음
//[N][N] 2차원 배열로 경우의 수 완탐하면 될 것 같음
// N개를 다 채울때까지 반복하면 될 듯
//합쳐지는 과정에서 순서는 중요하지 않음 (3 + 5 + 2) 나 (2 + 5 + 3)이나
//그럼 조합으로 진행해도 되지 않나?

//종료조건: N개 연산 채울때까지 (조합)
//visited 배열 2개로 진행 방문한 요소는 visited = true
//for문..을 어떻게 해야하지 (2차원 for문은 아닌 것 같은데)

void sol(int depth) {
    //모든 좌표를 정했을 때 종료
    if(depth == n) {
        //컴파일
        // for(pair<int,int> p : v) {
        //     cout << grid[p.first][p.second] << " ";
        // }
        // cout << "end\n";

        //전체 합 구하기
        int ttl = 0;
        for(pair<int,int> p: v) {
            ttl += grid[p.first][p.second];
        }

        //최대값 구하기
        ans = max(ans, ttl);

        return;
    }

    for(int c = 0; c < n; c++) {
        if(visitedC[c]) continue;

        visitedC[c] = true;
        v.push_back({depth, c});

        sol(depth + 1);

        v.pop_back();
        visitedC[c] = false;
    }

    // for(int r = 0; r < n; r++) {
    //     //이미 방문한 행이면 건너뛰기
    //     if(visitedR[r]) continue;
    //     for(int c = 0; c < n; c++) {
    //         //이미 방문한 열이면 건너뛰기
    //         if(visitedC[c]) continue;
            
    //         visitedR[r] = true;
    //         visitedC[c] = true;
    //         v.push_back({r, c});

    //         sol(depth + 1);

    //         //백트레킹
    //         visitedR[r] = false;
    //         visitedC[c] = false;
    //         v.pop_back();
    //     }
    // }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    sol(0);

    cout << ans << "\n";

    return 0;
}

