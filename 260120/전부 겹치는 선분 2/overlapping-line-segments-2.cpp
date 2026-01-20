#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N; cin >> N;
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    bool isSuccess = false;
    for(int i = 0; i < N; i++) {
        int max_x1 = 0;
        int min_x2 = INT_MAX;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;

            //시작점 중 가장 뒤에 있는 좌표, 끝점 중 가장 앞에 있는 좌표
            max_x1 = max(max_x1, v[j].first);
            min_x2 = min(min_x2, v[j].second);
        }

        if(min_x2 >= max_x1) isSuccess = true;
    }
    if(isSuccess)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}