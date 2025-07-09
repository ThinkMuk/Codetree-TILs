#include <iostream>

using namespace std;

int n, t;
int arr[1000];

bool comp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 1;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if(i == 0)
            continue;
        else {
            if(comp(arr[i],t) == comp(arr[i-1],t))
                cnt++;
            else {
                if(ans < cnt)
                    ans = cnt;
                cnt = 1;
            }
        }
    }

    if(ans < cnt)
        ans = cnt;

    if(ans == 1)
        cout << 0;
    else
        cout << ans;
        
    return 0;
}