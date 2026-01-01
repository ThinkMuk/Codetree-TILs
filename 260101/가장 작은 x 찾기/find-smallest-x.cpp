#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i = 1; i <= 10000; i++) {
        int num = i * 2;
        bool isAns = true;
        for(auto [a, b] : v) {
            if(num < a || b < num) {
                isAns = false;
                break;
            }
            num *= 2;
        }
        if(isAns) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}