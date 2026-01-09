#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<int> v;
    int firstNum = -1;
    for(int i = 0; i < N - 1; i++) {
        int tmp; cin >> tmp;
        if(i == 0) firstNum = tmp;
        v.push_back(tmp);
    }

    for(int i = 1; i < firstNum; i++) {
        vector<int> ans;
        set<int> s;
        bool isSeq = true;
        ans.push_back(i); s.insert(i);
        for(int j = 0; j < N - 1; j++) {
            int nxt = v[j] - ans[j];
            if(nxt <= 0 || s.count(nxt)) {
                isSeq = false;
                break;
            }
            else {
                ans.push_back(nxt); s.insert(nxt);
            }
        }
        if(isSeq) {
            for(int t : ans) cout << t << " ";
            cout << "\n"; break;
        }
    }
    return 0;
}