#include <iostream>

using namespace std;

int n;
int x1[10], y1[10];
int x2[10], y2[10];
int arr[201][201];
int blue = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++)
            arr[i][j] = -1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = x1[i]; j < x2[i]; j++) {
            for(int k = y1[i]; k < y2[i]; k++) {
                arr[j+100][k+100] = (i%2);
            }
        }
    }

    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            if(arr[i][j] == 1)
                blue++;
        }
    }

    cout << blue;

    return 0;
}