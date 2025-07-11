#include <iostream>

using namespace std;

int N, M, K;
int student[10000];
int ans[101];

int main() {
    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++) {
        cin >> student[i];
    }

    for(int i = 1; i <= M; i++) {
        ans[student[i]]++;
        if(ans[student[i]] >= K) {
            cout << student[i];
            return 0;
        }
    }

    cout << -1;

    return 0;
}