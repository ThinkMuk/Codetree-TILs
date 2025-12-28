#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int tmpMax = 0;
        int nxtIdx = v[i];
        for(int j = 0; j < M; j++) {
            tmpMax += nxtIdx;
            nxtIdx = v[nxtIdx - 1];
        }
        ans = max(ans, tmpMax);
    }

    cout << ans << "\n";
    return 0;
}