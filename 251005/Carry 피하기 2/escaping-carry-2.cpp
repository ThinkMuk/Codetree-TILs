#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool noCarry(int a, int b, int c) {
    while (a > 0 || b > 0 || c > 0) {
        int sum = (a % 10) + (b % 10) + (c % 10);
        if (sum >= 10) return false;
        a /= 10;
        b /= 10;
        c /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) 
        cin >> v[i];

    int max_num = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (noCarry(v[i], v[j], v[k])) {
                    int ttl = v[i] + v[j] + v[k];
                    max_num = max(max_num, ttl);
                }
            }
        }
    }

    cout << max_num;

    return 0;
}