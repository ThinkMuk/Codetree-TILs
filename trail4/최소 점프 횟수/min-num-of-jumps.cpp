#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[10];
int N;
int ans = INT_MAX;

void solve(int idx, int jumps) {
    if (idx == N - 1) {
        ans = min(ans, jumps);
        return;
    }
    if (jumps >= ans) return;

    for (int step = 1; step <= arr[idx] && idx + step < N; step++) {
        solve(idx + step, jumps + 1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    solve(0, 0);

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}