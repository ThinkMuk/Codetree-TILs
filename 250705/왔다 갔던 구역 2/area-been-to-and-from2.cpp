#include <iostream>

using namespace std;

int n;
int x[100];
char dir[100];
int startIdx = 1000;
int arr[2001] = {0,};
int ans = 0;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    for(int i = 0; i < n; i++) {
        if(dir[i] == 'R') {
            for(int j = 0; j < x[i]; j++) {
                arr[startIdx]++;
                startIdx++;
            }
        } else {
            for(int j = 0; j < x[i]; j++) {
                arr[startIdx]++;
                startIdx--;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2001; i++) {
        if (arr[i] >= 2)
            ans++;
    }

    cout << ans;

    return 0;
}