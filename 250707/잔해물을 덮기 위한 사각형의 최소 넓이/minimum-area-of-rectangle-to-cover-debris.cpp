#include <iostream>

using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];

int arr[2001][2001] = {0};
int xMax = -1, xMin = 2001;
int yMax = -1, yMin = 2001;

int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    for(int i = 0; i < 2; i++) {
        for(int j = x1[i]; j < x2[i]; j++) {
            for(int k = y1[i]; k < y2[i]; k++) {
                if(i == 0)
                    arr[j+1000][k+1000] = 1;
                else
                    arr[j+1000][k+1000] = 0;
            }
        }
    }

    for(int i = 0; i < 2001; i++) {
        for(int j = 0; j < 2001; j++) {
            if(arr[i][j] == 1) {
                if(i < yMin) yMin = i;
                if(i > yMax) yMax = i;
                if(j < xMin) xMin = j;
                if(j > xMax) xMax = j;
            }
        }
    }
    
    if(xMax == -1 || yMax == -1)
        cout << 0;
    else
        cout << (xMax - xMin + 1)*(yMax - yMin + 1);

    return 0;
}