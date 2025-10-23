#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int min_ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        int min_x = INT_MAX; int min_y = INT_MAX;
        int max_x = 0; int max_y = 0;

        for(int j = 0; j < N; j++) {
            if(i == j) continue;
             min_x = min(min_x, x[j]); min_y = min(min_y, y[j]);
             max_x = max(max_x, x[j]); max_y = max(max_y, y[j]);
        }

        int tmp = (max_x - min_x) * (max_y - min_y);
        min_ans = min(min_ans, tmp);
    }

    cout << min_ans << "\n";

    return 0;
}