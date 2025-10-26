#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x[100];
int y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if ((x[i] == x[j] && y[i] != y[j] && y[i] == y[k]) ||
                    (x[i] == x[k] && y[i] != y[k] && y[i] == y[j]) ||
                    (x[j] == x[k] && y[j] != y[k] && y[j] == y[i])) {
                    int width = max({x[i], x[j], x[k]}) - min({x[i], x[j], x[k]});
                    int height = max({y[i], y[j], y[k]}) - min({y[i], y[j], y[k]});
                    mx = max(mx, width * height);
                }
            }
        }
    }
    cout << mx << "\n";
    return 0;
}