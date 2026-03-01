#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;

    int minAns = INT_MAX;
    for(int i = 0; i < s.size(); i++) {
        char c = s.back();
        char prev = s.front(); int cnt = 1;
        string v;
        v += prev;
        for(int j = 1; j < s.size(); j++) {
            if(prev == s[j]) cnt++;
            else {
                v += to_string(cnt);
                cnt = 1;
                prev = s[j];
                v += prev;
            }
        }
        v += to_string(cnt);

        int tmpLen = v.size();
        minAns = min(minAns, tmpLen);

        s.pop_back();
        s.insert(s.begin(),c);
    }

    cout << minAns << "\n";
}