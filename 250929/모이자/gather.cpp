#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int answer = INT_MAX;
    for (int i = 0; i < n; i++) {
        int dist = 0;
        for (int j = 0; j < n; j++) {
            dist += A[j] * abs(i - j);
        }
        answer = min(answer, dist);
    }
    cout << answer << "\n";

    return 0;
}