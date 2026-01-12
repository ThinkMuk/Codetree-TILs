#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int diff = v[N - 1] - v[0] - 17;

    int a = diff / 2;
    int b = diff - a;

    int ans = (a * a) + (b * b);
    cout << ans << "\n";
    return 0;
}