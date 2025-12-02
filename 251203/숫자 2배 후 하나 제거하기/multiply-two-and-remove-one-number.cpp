#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> arr;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    int min_diff = INT_MAX;
    for(int i = 0; i < N; i++) {
        arr[i] *= 2;

        for(int j = 0; j < N; j++) {
            int remains[N - 1] = {};
            int cnt = 0;

            for(int k = 0; k < N; k++) {
                if(k != j)
                    remains[cnt++] = arr[k];
            }

            int sum_diff = 0;
            for(int k = 0; k < N - 2; k++) {
                sum_diff += abs(remains[k + 1] - remains[k]);
            }

            min_diff = min(min_diff, sum_diff);
        }

        arr[i] /= 2;
    }

    cout << min_diff << "\n";
    return 0;
}