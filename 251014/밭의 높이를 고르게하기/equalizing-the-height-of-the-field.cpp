#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int N, H, T;
int arr[100];
int cost[100];

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cost[i] = abs(H-arr[i]);
    }

    int min_ans = INT_MAX;
    // Please write your code here.
    for(int i = 0; i <= N - T; i++) {
        int ttl = 0;
        for(int j = 0; j < T; j++) {
            ttl += cost[i + j];
        }
        min_ans = min(min_ans, ttl);
    }

    cout << min_ans;

    return 0;
}