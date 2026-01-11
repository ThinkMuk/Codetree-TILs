#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int N, K; cin >> N >> K;
    unordered_map<int, vector<int>> m;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        m[tmp].push_back(i);
    }

    int maxCnt = 0;
    int ans = -1;
    for(auto [val, bomb] : m) {
        sort(bomb.begin(), bomb.end());
        int tmpCnt = 0;
        for(int j = 0; j < bomb.size() - 1; j++) {
            if(bomb[j] + K >= bomb[j + 1]) tmpCnt++;
        }
        if(maxCnt <= tmpCnt) {
            if(maxCnt == tmpCnt) ans = max(ans, val);
            else ans = val;
            maxCnt = tmpCnt;
        }
    }

    cout << ans << "\n";
    return 0;
}