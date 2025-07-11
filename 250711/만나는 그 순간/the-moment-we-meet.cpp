#include <iostream>

using namespace std;

int n, m;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];
bool meet = false;
int A[1000000] = {0};
int B[1000000] = {0};
int moveIdxA = 0, moveIdxB = 0;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];

    for (int i = 0; i < m; i++) cin >> d2[i] >> t2[i];

    for(int i = 0; i < n; i++) {
        if(d[i] == 'L') {
            for(int j = moveIdxA; j < moveIdxA + t[i]; j++) {
                if(j == 0)
                    A[j] = -1;
                A[j] = A[j-1] - 1;
            }
        }
        else {
            for(int j = moveIdxA; j < moveIdxA + t[i]; j++) {
                if(j == 0)
                    A[j] = 1;
                A[j] = A[j-1] + 1;
            }
        }
        moveIdxA+=t[i];
    }

    for(int i = 0; i < m; i++) {
        if(d2[i] == 'L') {
            for(int j = moveIdxB; j < moveIdxB + t2[i]; j++) {
                if(j == 0)
                    B[j] = -1;
                B[j] = B[j-1] - 1;
            }
        }
        else {
            for(int j = moveIdxB; j < moveIdxB + t2[i]; j++) {
                if(j == 0)
                    B[j] = 1;
                B[j] = B[j-1] + 1;
            }
        }
        moveIdxB+=t2[i];
    }

    for(int i = 0; i < 1000000; i++) {
        if(A[i] == B[i]) {
            cout << i + 1;
            meet = true;
            break;
        }
    }

    if(meet==false)
        cout << -1;

    return 0;
}