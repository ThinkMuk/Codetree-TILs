#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N, M; cin >> N >> M;
    int arr[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    int ans = 0;

    //행 기준 검사
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        int prevNum = -1;
        for(int j = 0; j < N; j++) {
            if(prevNum == arr[i][j])
                cnt++;
            else {
                prevNum = arr[i][j];
                cnt = 1;
            }
        }
        if(cnt >= M) ans++;
    }

    //열 기준 검사
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        int prevNum = -1;
        for(int j = 0; j < N; j++) {
            if(prevNum == arr[j][i])
                cnt++;
            else {
                prevNum = arr[j][i];
                cnt = 1;
            }
        }
        if(cnt >= M) ans++;
    }

    cout << ans << "\n";
    return 0;
}