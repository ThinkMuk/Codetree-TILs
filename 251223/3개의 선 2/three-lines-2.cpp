#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int x[20], y[20];
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = 0;

    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            for(int k = 0; k <= 10; k++) {
                bool success = true;

                for(int l = 0; l < N; l++) {
                    if(x[l] == i || x[l] == j || x[l] == k) continue;
                    success = false;
                }
                if(success) ans = 1;

                success = true;
                for(int l = 0; l < N; l++) {
                    if(x[l] == i || x[l] == j || y[l] == k) continue;
                    success = false;
                }
                if(success) ans = 1;

                success = true;
                for(int l = 0; l < N; l++) {
                    if(x[l] == i || y[l] == j || y[l] == k) continue;
                    success = false;
                }
                if(success) ans = 1;

                success = true;
                for(int l = 0; l < N; l++) {
                    if(y[l] == i || y[l] == j || y[l] == k) continue;
                    success = false;
                }
                if(success) ans = 1;

            }
        }
    }
    cout << ans << "\n";
    return 0;
}