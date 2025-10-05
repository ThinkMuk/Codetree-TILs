#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    int cntC = 0, cntO = 0, cntW = 0;
    int res = 0;

    for(char c : str) {
        if(c == 'C') cntC++;
        else if(c == 'O') cntO += cntC;
        else if(c == 'W') res += cntO;
    }

    cout << res;

    return 0;
}