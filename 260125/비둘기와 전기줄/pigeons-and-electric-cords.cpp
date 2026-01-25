#include <iostream>
#include <map>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    map<int,int> m;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        if(m.count(a)) {
            if(m[a] != b) {
                cnt++;
                m[a] = b;
            }
        }
        else
            m[a] = b;
    }

    cout << cnt << "\n";
    return 0;
}