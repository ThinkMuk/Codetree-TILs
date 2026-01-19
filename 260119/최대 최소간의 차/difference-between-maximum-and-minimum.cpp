#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    // Please write your code here.
    int N, K; cin >> N >> K;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        int low = v[i];
        int hi = low + K;

        int ttl = 0;
        for(int j = 0; j < N; j++) {
            int diff = 0;
            if(low > v[j] || v[j] > hi)
                diff = min(abs(v[j] - low), abs(v[j] - hi));
            ttl += diff;
        }
        ans = min(ans, ttl);
    }

    cout << ans << "\n";

    return 0;
}