#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int goal; cin >> goal;
    //거리, 속도
    vector<vector<int>> dp(10001, vector<int>(150, INT_MAX));
    dp[1][1] = 1;

    for(int i = 2; i <= 10000; i++) {
        for(int j = 1; j < 150; j++) {
            int prev1 = (i - (j-1) >= 0 && j-1 >= 1) ? dp[i - (j-1)][j-1] : INT_MAX;
            int prev2 = (i - j >= 0) ? dp[i - j][j] : INT_MAX;
            int prev3 = (i - (j+1) >= 0 && j+1 < 150) ? dp[i - (j+1)][j+1] : INT_MAX;

            if(prev1 == INT_MAX && prev2 == INT_MAX && prev3 == INT_MAX)
                dp[i][j] = INT_MAX;
            else
                dp[i][j] = min({prev1, prev2, prev3}) + 1;
        }
    }

    cout << dp[goal][1] << "\n";
    return 0;
}