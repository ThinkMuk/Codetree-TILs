#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<bool>& cup, int num1, int num2) {
    int tmp = cup[num1];
    cup[num1] = cup[num2];
    cup[num2] = tmp;
}

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<pair<int,int>> exchange;
    vector<int> numCheck;
    for(int i = 0; i < N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        exchange.push_back({a, b});
        numCheck.push_back(c);
    }

    int ans = 0;
    for(int i = 1; i <= 3; i++) {
        vector<bool> cup(4); cup[i] = true;
        int point = 0;
        for(int j = 0; j < N; j++) {
            auto[a, b] = exchange[j];
            swap(cup, a, b);
            if(cup[numCheck[j]]) point++;
        }
        ans = max(ans, point);
    }

    cout << ans << "\n";
    return 0;
}