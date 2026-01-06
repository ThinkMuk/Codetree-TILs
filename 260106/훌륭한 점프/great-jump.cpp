#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N, K; cin >> N >> K;
    vector<int> v(101);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<int> dp(101, INT_MAX);
    dp[1] = v[1];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K && i + j <= N; j++) {
            int nxt = i + j;
            dp[nxt] = min(dp[nxt], max(dp[i], v[nxt]));
        }
    }

    cout << dp[N] << "\n";
    return 0;
}