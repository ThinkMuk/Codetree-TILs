#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];
int ans[101] = {0,};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        for(int j = x1[i]; j <= x2[i]; j++) {
            ans[j]++;
        }
    }

    int maximum = 0;
    for(int i = 0; i < 101; i++) {
        if (maximum < ans[i]) {
            maximum = ans[i];
        }
    }

    cout << maximum;

    return 0;
}