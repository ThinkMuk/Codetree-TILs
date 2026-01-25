#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<int> v1; vector<int> v2;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v2.push_back(tmp);
    }

    int cnt = 0; int remain = 0;
    for(int i = 0; i < N; i++) {
        if(v1[i] + remain > v2[i]) {
            remain = (v1[i] + remain) - v2[i];
            cnt += remain;
        }
        else
            remain = 0;
    }

    cout << cnt << "\n";
    return 0;
}