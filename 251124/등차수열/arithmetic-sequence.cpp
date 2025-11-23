#include <iostream>
#include <unordered_set>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int a[100];

int main() {
    cin >> n;
    int minRange = INT_MAX;
    int maxRange = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minRange = min(minRange, a[i]);
        maxRange = max(maxRange, a[i]);
    }

    // Please write your code here.
    int ans = 0;
    for(int i = minRange; i <= maxRange; i++) {
        int tmpAns = 0;
        unordered_set<int> u;
        for(int j = 0; j < n; j++) {
            int diff = abs(a[j] - i);
            if(u.find(diff) != u.end()) {
                tmpAns++;
            }
            else {
                u.insert(diff);
            }
        }
        ans = max(ans, tmpAns);
    }

    cout << ans << "\n";
    return 0;
}