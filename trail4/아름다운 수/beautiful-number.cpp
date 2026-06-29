#include <iostream>
using namespace std;

int N, ans = 0;

void solve(int pos) {
    if (pos == N) {
        ans++;
        return;
    }
    for(int d = 1; d <= 4; d++) {
        if(pos + d <= N)
            solve(pos + d);
    }
}

int main() {
    // Please write your code here.
    cin >> N;
    solve(0);
    
    cout << ans << "\n";
    return 0;
}