#include <iostream>

using namespace std;

int n, t;
int arr[1000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || (arr[i] > t) == (arr[i-1] > t))
            cnt++;
        else {
            if(max < cnt)
                max = cnt;
            cnt = 1;
        }
    }

    if(max < cnt)
        max = cnt;

    if(max == 1)   
        cout << 0;
    else
        cout << max;

    return 0;
}