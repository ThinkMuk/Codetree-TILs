#include <iostream>
#include <algorithm>

using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int max_ans = 0;
    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j+1 == i || j-1 == i || j == i) {
                continue;
            }
            max_ans = max(max_ans, numbers[i] + numbers[j]);
        }
    }

    cout << max_ans;

    return 0;
}