#include <iostream>
#include <set>
using namespace std;

int main() {
    int T; cin >> T;
    string N; cin >> N;
    set<string> s;
    char firstChar;

    string tmp = "";
    int idx = 0;
    for(char c : N) {
        if(idx == 0) firstChar = c;
        tmp += c;
        if(idx != 0 && firstChar == c) break;
        if(!s.count(tmp)) s.insert(tmp);
        idx++;
    }

    string tmp2 = "";
    int ans = 0;
    for(int i = idx; i < T; i++) {
        tmp2 += N[i];
        if(s.count(tmp2)) ans++;
    }

    cout << ans + 1 << "\n";

    return 0;
}