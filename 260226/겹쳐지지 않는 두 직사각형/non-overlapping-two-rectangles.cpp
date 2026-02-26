#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M;
vector<vector<int>> psum;

int getSum(int r1, int c1, int r2, int c2) {
    return psum[r2+1][c2+1] - psum[r1][c2+1] - psum[r2+1][c1] + psum[r1][c1];
}

bool noOverlap(int ar1, int ac1, int ar2, int ac2,
               int br1, int bc1, int br2, int bc2) {
    if (ar2 < br1) return true;  // A가 B 위에
    if (br2 < ar1) return true;  // A가 B 아래에
    if (ac2 < bc1) return true;  // A가 B 왼쪽에
    if (bc2 < ac1) return true;  // A가 B 오른쪽에
    return false;
}

int main() {
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    // 2D prefix sum
    psum.assign(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            psum[i][j] = arr[i-1][j-1] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];

    int ans = INT_MIN;

    for (int ar1 = 0; ar1 < N; ar1++)
      for (int ac1 = 0; ac1 < M; ac1++)
        for (int ar2 = ar1; ar2 < N; ar2++)
          for (int ac2 = ac1; ac2 < M; ac2++)
            for (int br1 = 0; br1 < N; br1++)
              for (int bc1 = 0; bc1 < M; bc1++)
                for (int br2 = br1; br2 < N; br2++)
                  for (int bc2 = bc1; bc2 < M; bc2++)
                    if (noOverlap(ar1, ac1, ar2, ac2, br1, bc1, br2, bc2))
                        ans = max(ans, getSum(ar1, ac1, ar2, ac2) + getSum(br1, bc1, br2, bc2));

    cout << ans << endl;
    return 0;
}