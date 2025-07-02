#include <iostream>

using namespace std;

int n;
int cnt = 0;
int digits[20] = {};

int main() {
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    while(n) {
        digits[cnt] = n % 2;
        n /= 2;
        cnt++;
    }

    for(int i = cnt - 1; i >= 0; i--) {
        cout << digits[i];
    }

    return 0;
}