#include <iostream>
using namespace std;

int n;
int arr[3001] = {0,};
int curIdx = 1500;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        char dir;
        cin >> x >> dir;

        if (dir == 'R') {
            for (int j = 0; j < x; j++) {
                arr[curIdx]++;
                curIdx++;
            }
        } else {
            for (int j = 0; j < x; j++) {
                arr[curIdx]++;
                curIdx--;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3001; i++) {
        if (arr[i] >= 2)
            ans++;
    }

    cout << ans;

    return 0;
}