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
        if(d1 == d2 || d2 == d3 || d1 == d3) continue;

        bool valid = true;
        for(int j = 0; j < n; j++) {
            int h1 = a[j] / 100;
            int h2 = ((a[j] % 100) - (a[j] % 10)) / 10;
            int h3 = a[j] % 10;

            int cnt1 = 0;
            if(d1 == h1) cnt1++;
            if(d2 == h2) cnt1++;
            if(d3 == h3) cnt1++;

            int cnt2 = 0;
            if((d1 != h1) && (d1 == h2 || d1 == h3)) cnt2++;
            if((d2 != h2) && (d2 == h1 || d2 == h3)) cnt2++;
            if((d3 != h3) && (d3 == h1 || d3 == h2)) cnt2++;

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
