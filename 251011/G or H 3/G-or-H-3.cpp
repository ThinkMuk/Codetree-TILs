#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
char x[101];

int main() {
    cin >> N >> K;
    int max_idx = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int a; char b;
        cin >> a >> b;
        x[a] = b;
        max_idx = max(max_idx, a);
    }

    // Please write your code here.
    for(int i = 1; i <= max_idx - K; i++) {
        int ttl = 0;
        for(int j = 0; j <= K; j++) {
            if(x[i+j] == 'G')
                ttl += 1;
            else if(x[i+j] == 'H')
                ttl += 2;
        }
        ans = max(ans, ttl);
    }

    cout << ans;

    return 0;
}