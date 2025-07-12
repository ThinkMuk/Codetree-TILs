#include <iostream>

using namespace std;

int n, m;
int t[50000];
char d[50000];
int t_b[50000];
char d_b[50000];
int A[1000000] = {0};
int B[1000000] = {0};
int AIdx = 1; int BIdx = 1;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> t_b[i] >> d_b[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = AIdx; j < AIdx + t[i]; j++) {
            A[j] = (d[i] == 'L') ? A[j - 1] - 1 : A[j - 1] + 1;
        }
        AIdx += t[i];
    }

    for(int i = 0; i < m; i++) {
        for(int j = BIdx; j < BIdx + t_b[i]; j++) {
            B[j] = (d_b[i] == 'L') ? B[j - 1] - 1 : B[j - 1] + 1;
        }
        BIdx += t_b[i];
    }

    int maxIdx = max(AIdx, BIdx);

    for(int i = AIdx; i <= maxIdx; i++)
        A[i] = A[AIdx - 1];
    for(int i = BIdx; i <= maxIdx; i++)
        B[i] = B[BIdx - 1];

    int ans = 0;

    if (A[0] == B[0])
        ans++;

    for(int i = 1; i <= maxIdx; i++) {
        if(A[i] == B[i] && A[i - 1] != B[i - 1]) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
