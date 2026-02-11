#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> v[i][j];

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for(int i = 0; i < M; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(v[j][i] > 0) dp[j + 1][i + 1] = ++cnt;
            else {
                cnt = 0;
                dp[j + 1][i + 1] = cnt;
            }
        }
    }

    int maxArea = -1;

    for(int row = 1; row <= N; row++) {
        stack<int> s;

        for(int i = 1; i <= M + 1; i++) {
            int h = (i == M + 1) ? 0 : dp[row][i];

            while(!s.empty() && dp[row][s.top()] > h) {
                int idx = s.top();
                s.pop();

                int barHeight = dp[row][idx];
                int width;
                if(s.empty())
                    width = i - 1;
                else
                    width = i - s.top() - 1;
                int tmpArea = barHeight * width;
                maxArea = max(maxArea, tmpArea);
            }
            s.push(i);
        }
    }
    cout << maxArea << "\n";

    return 0;
}