#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int N, S;
int arr[100];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sub_min = INT_MAX;
    // Please write your code here.
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j)
                continue;
            int ttl = 0;
            for(int k = 0; k < N; k++) {
                if(k == i || k == j)
                    continue;
                ttl += arr[k];
            }

            sub_min = min(sub_min, abs(ttl - S));
        }
    }

    cout << sub_min;
    
    return 0;
}