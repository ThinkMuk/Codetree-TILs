#include <iostream>
using namespace std;

int n, t;
int arr[1000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > t) {
            cnt++;
            if (cnt > ans) ans = cnt;
        } else {
            cnt = 0;
        }
    }

    cout << ans;
    return 0;
}