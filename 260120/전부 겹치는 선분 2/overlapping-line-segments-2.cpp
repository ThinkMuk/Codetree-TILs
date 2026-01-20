#include <iostream>
#include <vector>
#include <queue>
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

    bool isSuccess = false;
    for(int i = 0; i < N; i++) {
        int stk = 0; int cur = 0;
        priority_queue<int, vector<int>, greater<>> pq;

        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            pq.push(v[j].second);
            if(!pq.empty() && cur > pq.top()) {
                stk--; pq.pop();
            }
            cur = v[j].first;
            stk++;
            if(stk == N - 1) isSuccess = true;
        }
    }
    if(isSuccess)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}