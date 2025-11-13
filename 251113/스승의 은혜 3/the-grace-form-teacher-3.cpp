#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B;
vector<pair<int,int>> v;

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        int P, S;
        cin >> P >> S;
        v.push_back({P, S});
    }
    
    sort(v.begin(), v.end(), greater<>());
    int ans = 0;
    // Please write your code here.
    for(int i = 0; i < N; i++) { //큰 순서로 하나씩 반값일때
        int cnt = 0; int ttl = 0;
        vector<pair<int,int>> temp = v;
        temp[i].first /= 2;
        sort(temp.begin(), temp.end());
        
        for(int j = 0; j < N; j++) { //인원 카운트
            int cost = temp[j].first + temp[j].second;
            if(ttl + cost > B) break;
            ttl += cost;
            cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << "\n";

    return 0;
}