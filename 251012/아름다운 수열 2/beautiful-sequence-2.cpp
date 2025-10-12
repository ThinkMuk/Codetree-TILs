#include <iostream>
#include <map>

using namespace std;

int N, M;
int A[100], B[100];


int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    map<int, int> freqA, freqB;
    int ans = 0;

    for(int i = 0; i < M; i++) freqB[B[i]]++;

    for(int i = 0; i < M; i++) freqA[A[i]]++;

    if(freqA == freqB)
        ans++;

    for(int i = M; i < N; i++) {
        freqA[A[i]]++;
        freqA[A[i-M]]--;

        if(freqA[A[i-M]] == 0)
            freqA.erase(A[i-M]);

        if(freqA == freqB)
            ans++;
    }

    cout << ans;
    
    return 0;
}