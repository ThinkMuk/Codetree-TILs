#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[20][20];
bool visited[20][20];
int firstMax = 0;
int secondMax = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    int firstRow = -1, firstStart = -1;
    // Please write your code here.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-2; j++) {
            int cnt = 0;
            for(int k = j; k < j + 3; k++) {
                if(arr[i][k] == 1)
                    cnt++;
            }
            if(cnt > firstMax) {
                firstMax = cnt;
                firstRow = i;
                firstStart = j;
            }
        }
    }

    if(firstRow != -1 && firstStart != -1) {
        for(int k = firstStart; k < firstStart + 3; k++)
            visited[firstRow][k] = true;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-2; j++) {
            int cnt = 0;
            for(int k = j; k < j + 3; k++) {
                if(!visited[i][k] && arr[i][k] == 1)
                    cnt++;
            }
            secondMax = max(secondMax, cnt);
        }
    }

    cout << firstMax + secondMax;

    return 0;
}