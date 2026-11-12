#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long n, m;
long long arr[100000];
long long mx = 0;

//n개의 물건 m개의 통로를 통해 통과
//m개의 통로를 통과하는 시간은 각각 다름
//n개의 물건을 모두 통과시키는데 걸리는 최소 시간

//이동하고 있다면 그동안 다른 물건은 못들어감

//검증 방법은 mid 값을 기준으로 소요시간들을 각각 나누어보고
//그 나누어진 시간의 총합이 n을 충족하는지 보면 될 것 같음

//여기서 n보다 많으면
//시간이 너무 많이 주어져있다는거니까
//그럼 hi = mid
//만약 n보다 적으면
//lo = mid

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    // Please write your code here.
    long long lo = 1;
    long long hi = mx * n;
    while(lo < hi) {
        long long mid = (lo + hi) / 2;
        long long val = 0;
        for(int i = 0; i < m; i++) {
            val += (mid / arr[i]);
        }

        if(val >= n) hi = mid;
        else lo = mid + 1;
    }

    // //나머지가 남을 것 같은데
    // long long sub = LLONG_MAX;
    // for(int i = 0; i < m; i++) {
    //     long long t = lo % arr[i];
    //     sub = min(sub, t);
    // }

    // long long ans = lo - sub;

    //lo가 hi보다 커지기 시작하는 순간까지 가면 최소의 값을 찾을 수 있음 따라서 굳이 나머지 계산을 안해도 됨

    cout << lo << "\n";

    return 0;
}
