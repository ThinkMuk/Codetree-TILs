#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    // Please write your code here.
    int ans = 0;
    for(int i = x; i <= y; i++) {
        int tmp = i;
        vector<int> num;
        while(tmp) {
            num.push_back(tmp % 10);
            tmp /= 10;
        }
        int len = num.size() - 1;
        int j = 0;
        bool isBalanced = true;
        while(j < (len - j)) {
            if(num[j] != num[len - j]) {
                isBalanced = false;
                break;
            }
            j++;
        }
        if(isBalanced) ans++;
    }
    cout<< ans << "\n";
    return 0;
}