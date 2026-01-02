#include <iostream>
#include <map>
using namespace std;

int main() {
    // Please write your code here.
    map<pair<int,int>, int> cnt;
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        if(a > b) swap(a, b);
        cnt[{a, b}]++;
    }

    int maxCnt = 0;
    for(auto t : cnt) {
        maxCnt = max(maxCnt, t.second);
    }

    cout << maxCnt << "\n";
    return 0;
}