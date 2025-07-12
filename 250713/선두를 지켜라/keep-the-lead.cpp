#include <iostream>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];
int A[1000000] = {0};
int B[1000000] = {0};
int AIdx = 1, BIdx = 1;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> v[i] >> t[i];

    for (int i = 0; i < M; i++) cin >> v2[i] >> t2[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < t[i]; j++) {
            A[AIdx] = A[AIdx-1] + v[i];
            AIdx++; 
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < t2[i]; j++) {
            B[BIdx] = B[BIdx-1] + v2[i];
            BIdx++; 
        }
    }

    int minIdx = min(AIdx, BIdx);
    int ans = 0;
    int i = 1;

    while (i < minIdx && A[i] == B[i]) i++;
    bool head = (A[i] > B[i]);

    for(i = i+1; i < minIdx; i++) {
        if(head && A[i] < B[i]) {
            head = false;
            ans++;
        }
        else if(!head && A[i] > B[i]) {
            head = true;
            ans++;
        }
    }

    cout << ans;

    return 0;
}