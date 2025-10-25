#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int min_ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int tmp = pow(x[i] - x[j],2) + pow(y[i] - y[j],2);
            min_ans = min(min_ans, tmp);
        }
    }

    cout << min_ans << "\n";

    return 0;
}