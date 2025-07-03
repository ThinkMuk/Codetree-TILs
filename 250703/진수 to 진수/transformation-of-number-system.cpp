#include <iostream>

using namespace std;

int a, b;
string n;
int change = 0;

int ans[20] = {};
int cnt = 0;

int main() {
    cin >> a >> b;
    cin >> n;

    for(int i = 0; i < n.length(); i++) {
        change = change * a + (n[i]-'0');
    }

    if(change == 0) {
        cout << 0;
        return 0;
    }

    while(change) {
        ans[cnt] = change%b;
        change /= b;
        cnt++;
    }

    for(int i = cnt-1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}