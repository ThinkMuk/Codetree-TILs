#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    // Please write your code here.
    for(int i = 0; i <= n-k; i++) {
        int ttl = 0;
        for(int j = 0; j < k; j++) {
            ttl += arr[i+j];
        }
        ans = max(ans, ttl);
    }

    cout << ans;

    return 0;
}