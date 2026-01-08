#include <iostream>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    string seat; cin >> seat;

    //가장 가까운 두 사람간의 거리를 최대로
    int ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        if(seat[i] == '0') {
            seat[i] = '1';
            for(int j = 0; j < N; j++) {
                if(seat[j] == '0') {
                    seat[j] = '1';
                    int cnt = 0, tmp = 0;
                    bool firstAppear = false;
                    for(int k = 0; k < N; k++) {
                        if(seat[k] == '1') {
                            firstAppear = true;
                            if(cnt != 0)
                                tmp = max(tmp, cnt);
                            cnt = 0;
                        }
                        else
                            if(firstAppear) cnt++;
                    }
                    ans = min(ans, tmp);
                    seat[j] = '0';
                }
            }
            seat[i] = '0';
        }
    }

    cout << ans << "\n";
    return 0;
}