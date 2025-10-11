#include <iostream>

using namespace std;

int N;
int arr[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += arr[j];
            int len = j - i + 1;

            if (sum % len == 0) {
                int avg = sum / len;
                for (int k = i; k <= j; k++) {
                    if (arr[k] == avg) {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}