#include <iostream>

using namespace std;

string N;
int decimal = 0;
int ans[20] = {};
int cnt = 0;

int main() {
    cin >> N;

    for(char c : N) {
        decimal = decimal * 2 + (c-'0');
    }

    decimal *= 17;

    if(decimal == 0) {
        cout << 0;
        return 0;
    }

    while(decimal) {
        ans[cnt] = decimal%2;
        decimal /= 2;
        cnt++;
    }

    for(int i = cnt-1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}