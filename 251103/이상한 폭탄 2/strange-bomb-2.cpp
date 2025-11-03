#include <iostream>

using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    int biggest_num = 0;
    for(int i = 0; i < N; i++) {
        bool boom = false;
        for(int j = 1; j <= K; j++) {
            if(i-j >= 0 && num[i-j] == num[i]) {
                boom = true;
                break;
            }
            if(N > i+j && num[i+j] == num[i]) {
                boom = true;
                break;
            }
        }
        if(boom == true) {
            biggest_num = max(biggest_num, num[i]);
        }
    }

    cout << biggest_num << "\n";

    return 0;
}