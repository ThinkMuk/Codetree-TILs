#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    
    vector<vector<int>> devRank(K, vector<int>(N + 1));
    
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            devRank[k][tmp] = i + 1;
        }
    }
    
    int cnt = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            bool aAlwaysBetter = true;
            bool bAlwaysBetter = true;
            
            for (int k = 0; k < K; k++) {
                if (devRank[k][a] >= devRank[k][b]) {
                    aAlwaysBetter = false;
                }
                if (devRank[k][b] >= devRank[k][a]) {
                    bAlwaysBetter = false;
                }
            }
            
            if (aAlwaysBetter || bAlwaysBetter) {
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}