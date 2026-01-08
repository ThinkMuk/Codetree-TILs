#include <iostream>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    string seat; cin >> seat;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(seat[i] == '0') {
            seat[i] = '1';
            for(int j = i + 1; j < N; j++) {
                if(seat[j] == '0') {
                    seat[j] = '1';
                    
                    int minDist = INT_MAX;
                    int lastOne = -1;
                    for(int k = 0; k < N; k++) {
                        if(seat[k] == '1') {
                            if(lastOne != -1)
                                minDist = min(minDist, k - lastOne);
                            lastOne = k;
                        }
                    }
                    
                    ans = max(ans, minDist);
                    seat[j] = '0';
                }
            }
            seat[i] = '0';
        }
    }

    cout << ans << "\n";
    return 0;
}