#include <iostream>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 1;
    int max = 1;
    for(int i = 0; i < N; i++) {
        if(i == 0 || arr[i] == arr[i-1])
            cnt++;
        if(arr[i] != arr[i-1]) {
            if(max < cnt)
                max = cnt;
            cnt = 1;
        }
    }

    cout << max;

    return 0;
}