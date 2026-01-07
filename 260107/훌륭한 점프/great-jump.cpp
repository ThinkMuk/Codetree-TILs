#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> v;
    v.push_back(-1);
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    //최댓값이 최소가 하는 프로그램
    vector<int> dp(N + 1, INT_MAX);
    dp[1] = v[1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; i + j <= N && j <= K; j++) {
            int nxt = i + j;
            dp[nxt] = min(dp[nxt], max(v[nxt -1], v[nxt]));
        }
    }
    cout << dp[N] << "\n";
}