#include <iostream>
#include <climits>
using namespace std;

int arr[101][101];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int startIdx = K;
    int endIdx = K + M - 1;

    bool possible = true;
    int minHeight = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = startIdx; j <= endIdx; j++) {
            if(arr[i][j] == 1)
                possible = false;
        }
        if(possible)
            minHeight = max(minHeight, i);
    }

    for(int i = startIdx; i <= endIdx; i++)
        arr[minHeight][i] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}