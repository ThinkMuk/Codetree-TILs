#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int abilities[6];

int getDiff(int i, int j, int k) {
    int num1 = i + j + k;
    int num2 = 0;
    for(int m = 0; m < 6; m++) 
        num2 += abilities[m];
    num2 -= num1;

    return abs(num1 - num2);
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
    }

    int min_diff = INT_MAX;
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++) {
            for(int k = j + 1; k < 6; k++) {
                min_diff = min(min_diff, getDiff(i,j,k));
            }
        }
    }

    cout << min_diff;

    return 0;
}