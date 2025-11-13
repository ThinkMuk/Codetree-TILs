#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B;
vector<pair<int,int>> v;

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        int P, S;
        cin >> P >> S;
        v.push_back({P, S});
    }

    int ans = 0;

    for(int i = 0; i < N; i++) {
        vector<int> costs;
        for(int j = 0; j < N; j++) {
            if(j == i) {
                costs.push_back(v[j].first / 2 + v[j].second);
            } else {
                costs.push_back(v[j].first + v[j].second);
            }
        }
        sort(costs.begin(), costs.end());

        int cnt = 0, ttl = 0;
        for(int cost : costs) {
            if(ttl + cost > B) break;
            ttl += cost;
            cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans << "\n";
    return 0;
}