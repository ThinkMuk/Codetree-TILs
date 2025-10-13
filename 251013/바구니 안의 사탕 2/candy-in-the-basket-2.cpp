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
        candy[tmp2] += tmp1;
        mx = max(mx, tmp2);
    }

    // Please write your code here.
    for (int i = 1; i <= mx; i++) {
        int left = max(1, i - K);
        int right = min(mx, i + K);
        int ttl = 0;

        for (int j = left; j <= right; j++)
            ttl += candy[j];

        ans = max(ans, ttl);
    }

    cout << ans;

    return 0;
}