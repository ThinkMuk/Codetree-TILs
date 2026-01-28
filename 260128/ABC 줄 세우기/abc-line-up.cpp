#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<char> v;
    for(int i = 0; i < N; i++) {
        char c; cin >> c;
        v.push_back(c);
    }

    int cnt = 0;
    for(int i = 0; i < N - 1; i++) {
        if(v[i] <= v[i + 1]) continue;
        else {
            while(v[i] > v[i + 1] && i + 1 < N) {
                swap(v[i],v[i + 1]);
                i++; cnt++;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}