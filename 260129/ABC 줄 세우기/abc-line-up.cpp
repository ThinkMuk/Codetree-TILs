#include <iostream>
using namespace std;

#define MAX_N 26

int N;
char arr[MAX_N + 1];
int ans = 0;

int main() {
    // Please write your code here.
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    for(int i = 1; i <= N; i++) {
        char target = 'A' + i - 1;

        int idx = 0;
        for(int j = 1; j <= N; j++)
            if(arr[j] == target) idx = j;
        
        for(int j = idx - 1; j >= i; j--) {
            swap(arr[j], arr[j + 1]);
            ans++;
        }
    }

    cout << ans;
    return 0;
}
