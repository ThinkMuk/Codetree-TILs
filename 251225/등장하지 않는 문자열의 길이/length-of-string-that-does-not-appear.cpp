#include <iostream>
#include <map>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    
    for(int len = 1; len <= N; len++) {
        map<string, int> cnt;
        bool duplicate = false;
        
        for(int i = 0; i + len <= N; i++) {
            string sub = S.substr(i, len);
            cnt[sub]++;
            if(cnt[sub] >= 2) {
                duplicate = true;
                break;
            }
        }
        
        if(!duplicate) {
            cout << len << "\n";
            return 0;
        }
    }
    
    cout << N + 1 << "\n";
    return 0;
}