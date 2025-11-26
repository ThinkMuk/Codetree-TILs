#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y;
    int ans = 0;
    cin >> x >> y;

    // Please write your code here.
    for(int i = x; i <= y; i++) {
        int num = i;
        vector<int> digit(10,0);
        int len = 0;
        while(num) {
            digit[num % 10]++;
            len++;
            num /= 10;
        }

        bool interesting = false;

        for(int j = 0; j < 10; j++) {
            if(digit[j] == len - 1)
                interesting = true;
        }

        if(interesting)
            ans++;
    }

    cout << ans << "\n";
    return 0;
}