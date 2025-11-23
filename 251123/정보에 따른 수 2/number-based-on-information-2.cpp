#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int T, a, b;
vector<int> S;
vector<int> N;

int main() {
    cin >> T >> a >> b;

    for (int i = 0; i < T; i++) {
        char c; int x;
        cin >> c >> x;
        if(c == 'S')
            S.push_back(x);
        else
            N.push_back(x);
    }

    // Please write your code here.
    int special = 0;
    for(int i = a; i <= b; i++) {
        int d1 = INT_MAX; int d2 = INT_MAX;
        for(int tmp : S) {
            d1 = min(d1, abs(i - tmp));
        }
        for(int tmp : N) {
            d2 = min(d2, abs(i - tmp));
        }
        if(d1 <= d2)
            special++;
    }

    cout << special << "\n";

    return 0;
}