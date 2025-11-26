#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    vector<int> H;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        H.push_back(tmp);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int ttl = 0;
        if(H[0] > i)
            ttl++;

        for(int j = 1; j < N; j++) {
            if(H[j] > i && H[j - 1] <= i)
                ttl++;
        }
        ans = max(ans, ttl);
    }

    cout << ans << "\n";
    return 0;
}