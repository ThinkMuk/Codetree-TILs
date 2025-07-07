#include <iostream>

using namespace std;

int N;
int x[100], y[100];
int arr[201][201] = {0};
int ans = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = x[i]; j < x[i]+8; j++) {
            for(int k = y[i]; k < y[i]+8; k++) {
                arr[j][k] = 1;
            }
        }
    }

    for(int i = 0; i < 201; i++) {
        for(int j = 0; j < 201; j++) {
            if(arr[i][j] == 1)
                ans++;
        }
    }

    cout << ans;

    return 0;
}