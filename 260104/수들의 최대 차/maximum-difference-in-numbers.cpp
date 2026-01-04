#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int N, K; cin >> N >> K;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = i; j < N; j++) {
            if(v[j] - v[i] > K) break;
            cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
    return 0;
}