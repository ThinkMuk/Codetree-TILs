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
        v[i].first /= 2;
        for(int j = N - 1; j >= 0; --j) { //인원 카운트
            ttl += (v[j].first + v[j].second);
            if(ttl >= B)
                break;
            cnt++;
        }
        ans = max(ans, cnt);
        v[i].first *= 2;
    }

    cout << ans << "\n";

    return 0;
}