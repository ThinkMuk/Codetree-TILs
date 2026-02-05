#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<int> neg; vector<int> pos;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if(tmp >= 0)
            pos.push_back(tmp);
        else
            neg.push_back(tmp);
    }

    sort(pos.begin(),pos.end(),greater<>());
    sort(neg.begin(),neg.end());

    int ans;
    if(pos.size() + neg.size() == 3) {
        if(pos.size() == 2)
            ans = pos[0] * pos[1] * neg[0];
        else
            ans = pos[0] * neg[0] * neg[1];
    }
    else {
        int num1 = INT_MIN; int num2 = INT_MIN;
        if(!pos.empty() && !neg.empty()) {
            if(pos.size() > 2) {
                num1 = pos[0] * pos[1] * pos[2];
            }
            if(!pos.empty() && neg.size() > 1) {
                num2 = pos[0] * neg[0] * neg[1];
            }
            ans = max(num1, num2);
        }
        else {
            if(pos.empty())
                ans = neg[neg.size()-1] * neg[neg.size()-2] * neg[neg.size()-3];
            else
                ans = pos[0] * pos[1] * pos[2];
        }
    }

    cout << ans << "\n";
    return 0;
}
