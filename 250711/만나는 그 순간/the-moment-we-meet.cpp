#include <iostream>
using namespace std;

int n, m;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];

int A[1000000], B[1000000];
int idxA = 0, idxB = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];
    for (int i = 0; i < m; i++) cin >> d2[i] >> t2[i];

    int pos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t[i]; j++) {
            A[idxA++] = pos;
            pos += (d[i] == 'L' ? 1 : -1);
        }
    }

    pos = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < t2[i]; j++) {
            B[idxB++] = pos;
            pos += (d2[i] == 'L' ? 1 : -1);
        }
    }

    int maxTime = max(idxA, idxB);

    for (int i = 1; i < maxTime; i++) {
        if (A[i] == B[i]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}