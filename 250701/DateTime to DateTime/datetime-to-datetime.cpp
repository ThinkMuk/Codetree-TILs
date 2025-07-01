#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    int time1 = (11*24*60) + (11*60) + 11;

    if(a <= 11) {
        if (b <= 11) {
            if (c < 11) {
                cout << "-1";
                return 0;
            }
        }
    }
    
    int time2 = (a*24*60) + (b*60) + c;

    int ans = time2 - time1;

    cout << ans;

    return 0;
}