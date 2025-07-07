#include <iostream>

using namespace std;

int x1[3], y1[3];
int x2[3], y2[3];

int arr[2001][2001] = {0};
int ans = 0;

int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];

    for(int i = 0; i < 3; i++) {
        for(int j = x1[i]; j < x2[i]; j++) {
            for(int k = y1[i]; k < y2[i]; k++) {
                if(i != 2)
                    arr[j+1000][k+1000] = 1;
                else
                    arr[j+1000][k+1000] = 0;

            }
        }
    }

    for(int i = 0; i < 2001; i++) {
        for(int j = 0; j < 2001; j++) {
            if(arr[i][j] == 1)
                ans++;
        }
    }

    cout << ans;

    return 0;
}