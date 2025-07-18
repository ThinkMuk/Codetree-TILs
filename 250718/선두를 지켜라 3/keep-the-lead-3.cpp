#include <iostream>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];
int A[1000001];
int B[1000001];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> v[i] >> t[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> v2[i] >> t2[i];
    }

    int aTime = 1;
    //A 값 계산
    for (int i = 0; i < N; i++) {
        for(int j = aTime; j < aTime + t[i]; j++) {
            A[j] = v[i] + A[j-1];
        }
        aTime += t[i];
    }

    int bTime = 1;
    //B 값 계산
    for (int i = 0; i < M; i++) {
        for(int j = bTime; j < bTime + t2[i]; j++) {
            B[j] = v2[i] + B[j-1];
        }
        bTime += t2[i];
    }

    int startIdx = 0;
    while(A[startIdx] == B[startIdx]) startIdx++;

    int honor = 0; //0은 A,B 동점, 1은 A, 2는 B
    int ans = 0;
    for(int i = startIdx; i < aTime; i++) {
        if((honor == 1 || honor == 2) && A[i] == B[i]) {
            honor = 0;
            ans++;
        }
        else if ((honor == 0 || honor == 2) && A[i] > B[i]) {
            honor = 1;
            ans++;
        }
        else if ((honor == 0 || honor == 1) && A[i] < B[i]) {
            honor = 2;
            ans++;
        }
    }

    cout << ans;

    return 0;
}