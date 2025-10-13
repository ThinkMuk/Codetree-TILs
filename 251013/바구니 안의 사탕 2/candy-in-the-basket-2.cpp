#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int candy[10001];

int main() {
    cin >> N >> K;
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int tmp1; int tmp2;
        cin >> tmp1 >> tmp2;
        candy[tmp2] = tmp1;
        mx = max(mx, tmp2);
    }

    // Please write your code here.
    for (int i = N ; i < mx - N; i++) {
        int ttl = 0;
        ttl += candy[i];
        for(int j = 1; j <= N; j++) {
            ttl += candy[i+j];
            ttl += candy[i-j];
        }
        ans = max(ans, ttl);
    }

    cout << ans;

    return 0;
}