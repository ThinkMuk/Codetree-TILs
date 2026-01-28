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
    bool isOrdered = false;
    while(!isOrdered) {
        int i = 0;
        while(i + 1 < N) {
            if(v[i] <= v[i + 1]) i++;
            else {
                int tmp = i;
                while(v[tmp] > v[tmp + 1] && tmp + 1 < N) {
                    swap(v[tmp],v[tmp + 1]);
                    tmp++; cnt++;
                }
                break;
            }
            if(i + 1 >= N) isOrdered = true;
        }
    }

    cout << cnt << "\n";
    return 0;
}