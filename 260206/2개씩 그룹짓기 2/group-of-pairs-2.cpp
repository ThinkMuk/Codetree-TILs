#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<int> v;
    for(int i = 0; i < N * 2; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        ans = min(ans, v[N + i] - v[i]);
    }
    cout << ans << "\n";
    return 0;
}