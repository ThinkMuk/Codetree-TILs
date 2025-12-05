#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    // Please write your code here.
    int ans = 0;

    for(int i = 0; i * A <= C; i++) {
        int cnt = A * i;

        int num_b = (C - cnt) / B;

        cnt += num_b * B;
        ans = max(ans, cnt);
    }

    cout << ans << "\n";

    return 0;
}