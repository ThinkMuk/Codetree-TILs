#include <iostream>
#include <cmath>
using namespace std;

string a;
int ans = 0;
int num = 0;
bool allZero = true;

int main() {
    cin >> a;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '0') {
            a[i] = '1';
            allZero = false;
            break;
        }
    }

    if(allZero == true) {
        for(int i = a.size()-1; i >= 0; --i) {
                if(a[i] == '1') {
                    a[i] = '0';
                break;
            }
        }
    }

    for(int i = a.size() - 1; i >= 0; --i) {
        int tmp = a[i] - '0';
        if(tmp == 0) {
            num++;
        }
        else {
            ans += pow(2,num);
            num++;
        }
        
    }

    cout << ans << "\n";

    return 0;
}