#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        char c = A[i];
        if (c == '(') {
            for(int j = i; j < A.size(); j++) {
                if (A[j] == ')')
                    ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}