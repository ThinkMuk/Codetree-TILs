#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N; cin >> N;
    int x[100], y[100];
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = INT_MAX;
    for(int i = 0; i <= 100; i += 2) {
        for(int j = 0; j <= 100; j += 2) {
            int a = 0; int b = 0; int c = 0; int d = 0;
            for(int k = 0; k < N; k++) {
                //1사분면
                if(x[k] > i && y[k] > j) a++;
                //2사분면
                if(x[k] < i && y[k] > j) b++;
                //3사분면
                if(x[k] < i && y[k] < j) c++;
                //4사분면
                if(x[k] > i && y[k] < j) d++;
            }
            int tmpMx = max({a,b,c,d});
            ans = min(ans, tmpMx);
        }
    }

    cout << ans << "\n";
    return 0;
}