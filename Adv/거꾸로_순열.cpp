#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

//next_permutation 연습해보기 + sort

int main() {
    cin >> n;

    vector<int> v;
    vector<vector<int>> ans;
    // Please write your code here.
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    while(true) {
        vector<int> tmp;
        for(int i = 0; i < v.size(); i++) {
            tmp.push_back(v[i]);
        }
        ans.push_back(tmp);
        if(!next_permutation(v.begin(), v.end())) break;
    }

    sort(ans.begin(), ans.end(), greater<>());

    for(vector<int> t : ans) {
        for(int tt : t) cout << tt << " ";
        cout << "\n";
    }

    return 0;
}

