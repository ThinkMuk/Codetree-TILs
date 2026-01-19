#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    // Please write your code here.
    int N, K; cin >> N >> K;
    vector<int> v;
    vector<int> candidates;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        candidates.push_back(tmp);
        candidates.push_back(tmp - K);
    }
    
    int ans = INT_MAX;
    for(int low : candidates) {
        int hi = low + K;

        int ttl = 0;
        for(int i = 0; i < N; i++) {
            int diff = 0;
            if(low > v[i])
                diff = low - v[i];
            else if (v[i] > hi)
                diff = v[i] - hi;
            ttl += diff;
        }
        ans = min(ans, ttl);
    }

    cout << ans << "\n";

    return 0;
}