#include <iostream>
#include <vector>
using namespace std;

int K,N;
vector<int> ans;

bool checkAns() {
    int f_node = ans.front();
    bool isAns = false;
    for(int i = 1; i < ans.size(); i++)
        if(ans[i] != f_node) isAns = true;
    
    return isAns;
}

void printAns() {
    if((ans.size() != 1) && (!checkAns())) return;
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