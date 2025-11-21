#include <iostream>
#include <vector>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    int cnt = 0;
    for(int i = X; i <= Y; i++) {
        int num = i;
        vector<int> arr(10, 0);
        
        while(num) {
            int comp = num % 10;
            arr[comp]++;
            num /= 10;
        }

        int duplicateCount = 0;
        bool diffNum = false; bool mainNum = false;
        
        for(int t : arr) {
            if(t != 0) {
                duplicateCount++;
                
                if(t == 1)
                    mainNum = true;
                else
                    diffNum = true;
            }
        }
        
        if(duplicateCount == 2 && diffNum == true && mainNum == true)
            cnt++;
    }

    cout << cnt << "\n";
    return 0;
}