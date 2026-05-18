#include <iostream>
using namespace std;

int K, N;
int arr[8];

void solve(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i];
            if (i < N - 1) cout << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= K; i++) {
        arr[depth] = i;
        solve(depth + 1);
    }
}

int main() {
    cin >> K >> N;
    solve(0);
    return 0;
}