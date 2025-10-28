#include <iostream>

using namespace std;

int N;
int s[100], e[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i];
    }

    // Please write your code here.
    // 겹칠려면 s[i], e[i] 사이에 s[j], e[j] 가 있어야함
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        bool isCrossed = false;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;

            if((s[i] - s[j]) * (e[i] - e[j]) < 0) {
                isCrossed = true; break;
            }
        }
        if(!isCrossed) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}