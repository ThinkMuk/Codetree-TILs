#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            s[i] = '1';
            
            vector<int> pos;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') {
                    pos.push_back(j);
                }
            }
            
            int minDist = n;
            for (int j = 1; j < pos.size(); j++) {
                minDist = min(minDist, pos[j] - pos[j-1]);
            }
            
            answer = max(answer, minDist);
            
            s[i] = '0';
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}