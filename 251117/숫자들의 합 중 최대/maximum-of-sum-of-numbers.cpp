#include <iostream>
#include <algorithm>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int ans = 0;
    for(int i = X; i <= Y; i++) {
        int ttl = 0;
        int tmp = i;
        
        while(tmp) {
            ttl += (tmp % 10);
            tmp /= 10;
        }
        ans = max(ans, ttl);
    }

    cout << ans << "\n";

    return 0;
}