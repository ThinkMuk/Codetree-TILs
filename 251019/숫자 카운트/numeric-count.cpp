#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int a[10], b[10], c[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    // Please write your code here.
    int possibleCnt = 0;
    
    for(int i = 111; i <= 999; i++) {

        int d1 = i / 100;
        int d2 = ((i % 100) - (i % 10)) / 10;
        int d3 = i % 10;

        if(d1 == 0 || d2 == 0 || d3 == 0) continue;

        bool valid = true;
        for(int j = 0; j < n; j++) {
            int h1 = a[j] / 100;
            int h2 = ((a[j] % 100) - (a[j] % 10)) / 10;
            int h3 = a[j] % 10;

            int hint[3] = {h1, h2, h3}; bool usedHint[3] = {false, false, false};
            int ans[3] = {d1, d2, d3}; bool usedAns[3] = {false, false, false};

            int cnt1 = 0;
            for(int k = 0; k < 3; k++) {
                if(ans[k] == hint[k]) {
                    cnt1++;
                    usedAns[k] = true;
                    usedHint[k] = true;
                }
            }

            int cnt2 = 0;
            for(int k = 0; k < 3; k++) {
                if(usedAns[k]) continue;
                for(int l = 0; l < 3; l++) {
                    if(!usedHint[l] && l != k && ans[k] == hint[l]) {
                        cnt2++; usedHint[l] = true;
                        break;
                    }
                }
            }

            if(cnt1 != b[j] || cnt2 != c[j]) {
                valid = false;
                break;
            }
        }
        if(valid) possibleCnt++;
    }

    cout << possibleCnt;

    return 0;
}