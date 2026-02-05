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

    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end(),greater<>());

    int ans;
    if(pos.size() + neg.size() == 3) {
        if(pos.size() == 2)
            ans = pos[pos.size()-1] * pos[pos.size()-2] * neg[neg.size()-1];
        else
            ans = pos[pos.size()-1] * neg[pos.size()-1] * neg[neg.size()-2];
    }
    else {
        int num1 = INT_MIN; int num2 = INT_MIN;
        if(pos.size() > 2) {
            num1 = pos[pos.size()-1] * pos[pos.size()-2] * pos[pos.size()-3];
        }
        if(!pos.empty() && neg.size() > 1) {
            num2 = pos[pos.size()-1] * neg[neg.size()-1] * neg[neg.size()-2];
        }
        ans = max(num1, num2);
    }

    cout << ans << "\n";
    return 0;
}