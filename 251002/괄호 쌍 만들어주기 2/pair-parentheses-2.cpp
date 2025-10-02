#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int n = A.size();
    int cnt = 0;

    // '))' cnt
    int closePairs = 0;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == ')' && A[i+1] == ')')
            closePairs++;
    }

    // '((' 찾으면서 뒤에 있는 '))' 개수 더하기
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == '(' && A[i+1] == '(') {
            cnt += closePairs;
        }
        if (A[i] == ')' && A[i+1] == ')') {
            closePairs--;
        }
    }

    cout << cnt << "\n";
    return 0;
}