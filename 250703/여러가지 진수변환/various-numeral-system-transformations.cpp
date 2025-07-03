#include <iostream>

using namespace std;

int N, B;
int ans[20] = {};
int cnt = 0;

int main() {
    cin >> N >> B;

    if(N == 0) {
        cout << 0;
        return 0;
    }

    while(N) {
        ans[cnt] = N % B;
        N /= B;
        cnt++;
    }

    for(int i = cnt-1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}