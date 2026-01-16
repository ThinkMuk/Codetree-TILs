#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, L;

bool isValid(int val) {
    int success = 0;
    int near = 0;

    for(int t : v) {
        if(t >= val) success++;
        else if (t + 1 >= val) near++;
    }

    int nearVal = (near > L) ? L : near;

    return val <= success + nearVal;
}

int main() {
    // Please write your code here.
    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    int maxNum = 0;
    for(int i = 0; i <= 100; i++) {
        if(isValid(i))
            maxNum = i;
    }

    cout << maxNum << "\n";

    return 0;
}