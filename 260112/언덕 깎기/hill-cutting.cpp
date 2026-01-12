#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    int ans = INT_MAX;
    
    for (int low = 0; low <= 83; low++) {
        int high = low + 17;

        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] < low) {
                int diff = low - h[i];
                cost += diff * diff;
            } else if (h[i] > high) {
                int diff = h[i] - high;
                cost += diff * diff;
            }
        }
        
        ans = min(ans, cost);
    }
    
    cout << ans << "\n";
    return 0;
}