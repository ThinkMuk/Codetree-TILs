#include <iostream>
#include <vector>
using namespace std;

int K,N;
vector<int> ans;

bool checkAns() {
    bool isAns = true;
    for(int i = 1; i < N - 1; i++) {
        int node = ans[i];
        if(ans[i - 1] == node && ans[i + 1] == node) isAns = false;
    }
    return isAns;
}

void printAns() {
    if(!checkAns()) return;
    for(int c : ans)
        cout << c << " ";
    cout << "\n";
}

void solve(int cur) {
    if(cur == N) {
        printAns();
        return;
    }

    for(int select = 1; select <= K; select++) {
        ans.push_back(select);
        solve(cur + 1);
        ans.pop_back();
    }

    return;

}

int main() {
    // Please write your code here.
    cin >> K >> N;
    solve(0);
    return 0;
}