#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[100], B[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int max_ans = 0;
    for(int i = 0; i < N; i++) {
        int ttl = 0;
        vector<int> arr(1001);
        for(int j = 0; j < N; j++) {
            if(i == j)
                continue;
            for(int k = A[j]; k < B[j]; k++)
                arr[k]++;
        }
        for(int j = 0; j <= 1000; j++) {
            if(arr[j] != 0) ttl++;
        }
        max_ans = max(max_ans, ttl);
    }

    cout << max_ans << "\n";

    return 0;
}