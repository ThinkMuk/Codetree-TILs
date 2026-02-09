#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<pair<int,int>> v;

    for(int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    int ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        bool isComplete = true;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        int prevNum = -1;

        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            minNum = min(minNum, v[j].first);
            maxNum = max(maxNum, v[j].second);
            if(prevNum != -1 && prevNum < v[j].first - 1) {
                isComplete = false;
                break;
            }
            prevNum = max(prevNum, v[j].second);
        }
        if(isComplete)
            ans = min(ans, maxNum - minNum);
    }

    cout << ans << "\n";

    return 0;
}