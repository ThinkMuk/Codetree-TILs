#include <iostream>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int n;
int a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_int = INT_MAX;

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        int ttl = 0;
        int cnt = 0;
        for(int j = i; j < n + i; j++) {
            int idx = j % n;
            ttl += a[idx] * cnt;
            cnt++;
        }

        min_int = min(min_int, ttl);
    }

    cout << min_int << "\n";

    return 0;
}