#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, L;

bool isValid(int val) {
    int cnt = 0;
    for(int i : v) {
        if(val <= i) cnt++;
    }
    return val <= cnt;
}

int main() {
    // Please write your code here.
    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    int maxNum = 0;
    for(int i = 0; i < v.size(); i++) {
        int val = v[i] + ((L > 0) ? 1 : 0);

        v[i] = val;
        if(isValid(val))
            maxNum = max(maxNum, val);
        v[i] = val - 1;
    }

    cout << maxNum << "\n";

    return 0;
}