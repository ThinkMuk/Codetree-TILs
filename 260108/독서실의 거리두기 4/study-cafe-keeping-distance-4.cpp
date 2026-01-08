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
            for(int j = 0; j < N; j++) {
                if(seat[j] == '0') {
                    seat[j] = '1';
                    int cnt = 0; int tmp = INT_MAX;
                    for(int k = 0; k < N; k++) {
                        if(seat[k] == '1') {
                            if(cnt != 0)
                                tmp = min(tmp, cnt);
                            cnt = 1;
                        }
                        else
                            cnt++;
                    }
                    ans = max(ans, tmp);
                    seat[j] = '0';
                }
            }
            seat[i] = '0';
        }
    }

    cout << ans << "\n";
    return 0;
}