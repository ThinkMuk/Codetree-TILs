#include <iostream>

using namespace std;

int N, K;
int A[100], B[100];
int ans[100] = {0,};
int maximum = 0;

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }

    for(int i = 0; i < K; i++) {
        for(int j = A[i]; j <= B[i]; j++) {
            ans[j]++;
        }
    }

    for(int i = 0; i <= N; i++) {
        if(maximum < ans[i]) {
            maximum = ans[i];
        }
    }

    cout << maximum;

    return 0;
}