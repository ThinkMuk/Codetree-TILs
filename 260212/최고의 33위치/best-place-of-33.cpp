#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    int arr[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) 
            cin >> arr[i][j];
    }

    int ans = 0;
    for(int i = 0; i < N-2; i++) {
        for(int j = 0; j < N-2; j++) {
            int cnt = 0;
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 3; l++) {
                    if(arr[i + k][j + l] == 1) cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << "\n";
    return 0;
}