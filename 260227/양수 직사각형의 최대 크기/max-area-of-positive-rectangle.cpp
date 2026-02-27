#include <iostream>
using namespace std;

int arr[20][20];

bool isPositive(int syIdx, int sxIdx, int eyIdx, int exIdx) {
    bool complete = true;
    for(int i = syIdx; i <= eyIdx; i++) {
        for(int j = sxIdx; j <= exIdx; j++) {
            if(arr[i][j] < 0) {complete = false; break;}
        }
    }
    return complete;
}

int main() {
    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    int ans = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            //시작 idx i,j
            //끝 idx k,l
            for(int k = i; k < N; k++) {
                for(int l = j; l < M; l++) {
                    if(isPositive(i,j,k,l)) ans = max(ans, (((k+1)-i) * ((l+1)-j)));
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}