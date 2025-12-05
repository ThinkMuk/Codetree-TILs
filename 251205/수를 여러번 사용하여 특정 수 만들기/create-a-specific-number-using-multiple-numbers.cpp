#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    // Please write your code here.
    int A, B, C;
    cin >> A >> B >> C;

    bool limit = false;
    int mx = 0;
    for(int i = 0; (A * i) < C; i++) {
        for(int j = 0; (B * j) < C; j++) {
            if((A*i) + (B*j) > C) {
                limit = true; break;
            }
            mx = max(mx, (A*i) + (B*j));
        }
    }

    cout << mx << "\n";
    return 0;
}