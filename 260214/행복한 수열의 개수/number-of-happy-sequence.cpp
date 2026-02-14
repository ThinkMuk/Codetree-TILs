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
        bool isHappy = false;
        for(int j = 1; j < N; j++) {
            if(arr[i][j] == arr[i][j-1])
                cnt++;
            else
                cnt = 1;
            if(cnt >= M) isHappy = true;
        }
        if(isHappy) ans++;
    }

    //열 기준 검사
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        bool isHappy = false;
        for(int j = 1; j < N; j++) {
            if(arr[j][i] == arr[j-1][i])
                cnt++;
            else
                cnt = 1;
            if(cnt >= M) isHappy = true;
        }
        if(isHappy) ans++;
    }

    cout << ans << "\n";
    return 0;
}