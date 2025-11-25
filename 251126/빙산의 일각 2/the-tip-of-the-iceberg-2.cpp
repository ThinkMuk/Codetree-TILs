#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int h[100];

int main() {
    cin >> n;

    int maxH = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        maxH = max(maxH, h[i]);
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i <= maxH; i++) {
        int cnt = 0;
        bool isGround = false;
        for(int j = 0; j < n; j++) {
            if(i >= h[j]) {
                if(isGround) {
                    cnt++;
                }
                isGround = false;
            }
            else
                isGround = true;
            if(j == n - 1 && isGround)
                cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
    return 0;
}