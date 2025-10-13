#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
char alpha[101];

int main() {
    cin >> N;

    int maxIdx = 0;
    int minIdx = INT_MAX;
    for (int i = 0; i < N; i++) {
        int idx; char c;
        cin >> idx >> c;
        alpha[idx] = c;
        maxIdx = max(maxIdx, idx);
        minIdx = min(minIdx, idx);
    }

    int ans = 0;
    for(int i = 2; i <= (maxIdx - minIdx + 1); i++) {
        for(int j = minIdx; j <= maxIdx; j++) {
            int G = 0; int minG = INT_MAX; int maxG = 0;
            int H = 0; int minH = INT_MAX; int maxH = 0;
            for(int k = j; k < j + i; k++) {
                if(alpha[k] == 'G') {
                    G++;
                    minG = min(minG, k); maxG = max(maxG, k);
                }
                else if (alpha[k] == 'H') {
                    H++;
                    minH = min(minH, k); maxH = max(maxH, k);
                }
            }

            if(H == 0 && G != 1) ans = max(ans, maxG - minG);
            else if (G == 0 && H != 1) ans = max(ans, maxH - minH);
            else if (G == H) {
                int mx = max(maxG, maxH);
                int mn = min(minG, minH);
                ans = max(ans, mx - mn);
            }
        }
    }

    cout << ans;

    return 0;
}