#include <iostream>
#include <algorithm>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
    }

    int maxWork = 0;
    
    for (int temp = 0; temp <= 1000; temp++) {
        int totalWork = 0;
        
        for (int i = 0; i < N; i++) {
            if (temp < Ta[i]) {
                totalWork += C;
            } else if (temp <= Tb[i]) {
                totalWork += G;
            } else {
                totalWork += H;
            }
        }

        maxWork = max(maxWork, totalWork);
    }

    cout << maxWork << '\n';

    return 0;
}