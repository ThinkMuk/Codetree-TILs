#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int n;
int x[100];
int y[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int min_ans = INT_MAX;

    for (int skip = 1; skip <= n - 2; skip++) {
        int ttl = 0;
        int prevX = x[0], prevY = y[0];

        for (int j = 1; j < n; j++) {
            if (j == skip) continue;
            ttl += abs(x[j] - prevX) + abs(y[j] - prevY);
            prevX = x[j];
            prevY = y[j];
        }

        min_ans = min(min_ans, ttl);
    }

    cout << min_ans << "\n";
    return 0;
}