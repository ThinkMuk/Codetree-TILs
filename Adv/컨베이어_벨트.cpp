#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.
    for(int i = 0; i < t; i++) {
        int down = u[n - 1];
        int up = d[n - 1];

        //아래에 있는거 위로 올리기
        for(int i = n - 1; i > 0; i--) {
            u[i] = u[i - 1];
        }
        u[0] = up;

        for(int i = n - 1; i > 0; i--) {
            d[i] = d[i - 1];
        }
        d[0] = down;
    }

    for(int i = 0; i < n; i++) {
        cout << u[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
    return 0;
}

