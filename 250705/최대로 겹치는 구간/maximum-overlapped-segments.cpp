#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];
int ans[100] = {0,};
int maximum = 0;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        for(int j = x1[i]; j <= x2[i]; j++) {
            ans[j]++;
        }
    }

    for(int i = 0; i < 100; i++) {
        if (ans[i] > maximum) {
            maximum = ans[i];
        }
    }

    cout << maximum;

    return 0;
}