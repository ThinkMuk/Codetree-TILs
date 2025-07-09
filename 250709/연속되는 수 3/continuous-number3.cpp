#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int max = 0;
    for(int i = 0; i < N; i++) {
        if(i == 0 || signbit(arr[i]) == signbit(arr[i-1]))
            cnt++;
        if(signbit(arr[i]) != signbit(arr[i-1])) {
            if(max < cnt)
                max = cnt;
            cnt = 1;
        }
    }

    if(max < cnt)
        max = cnt;

    cout << max;

    return 0;
}