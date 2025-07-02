#include <iostream>
#include <string>

using namespace std;

int main() {
    string binary;
    cin >> binary;

    int ans = 0;
    for (char c : binary) {
        ans = ans * 2 + (c - '0');
    }

    cout << ans;

    return 0;
}