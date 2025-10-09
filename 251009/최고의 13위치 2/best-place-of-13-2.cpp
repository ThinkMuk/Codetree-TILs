#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[20][20];
int firstMax = 0;
int secondMax = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    vector<int> arrN(N);
    // Please write your code here.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-2; j++) {
            int cnt = 0;
            for(int k = j; k < j + 3; k++) {
                if(arr[i][k] == 1)
                    cnt++;
            }
            if(firstMax < cnt) {
                secondMax = max(firstMax, secondMax);
                firstMax = cnt;
            }
            else if (secondMax < cnt) {
                secondMax = cnt;
            }
        }
    }

    cout << firstMax + secondMax;

    return 0;
}