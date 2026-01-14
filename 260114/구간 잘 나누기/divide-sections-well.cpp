#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

bool canDivide(int maxSum) {
    int cnt = 1;
    int ttl = 0;
    
    for(int i = 0; i < N; i++) {
        if(ttl + v[i] > maxSum) {
            cnt++;
            ttl = v[i];
        }
        else
            ttl += v[i];
    }
    
    return cnt <= M;
}

int main() {
    //구간 합들 중 최댓값이 최소
    cin >> N >> M;

    int lo = 0, hi = 0;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        lo = max(tmp, lo);
        hi += tmp;
        v.push_back(tmp);
    }

    int ans = hi;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        
        if(canDivide(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    cout << ans << "\n";
}