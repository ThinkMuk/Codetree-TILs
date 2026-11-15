#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int nums[12];
vector<int> v;
int ans = 0;

//턴의 수 N
//윷놀이 판의 마지막 지점 번호 M
//말의 수 K

void perm(int trial) {
    //어떤 인덱스에 어떤 경우의 수를 넣을지
    if(trial == n) { //만약 모든 턴수가 종료되면
        int tmp = 0;
        for(int t : v) {
            if(t >= m) tmp++;
        }

        ans = max(ans, tmp);
        return;
    }

    //말마다 기회를 하나씩 줌
    for(int i = 0; i < k; i++) {
        v[i] += nums[trial];
        perm(trial + 1);

        //백트래킹
        v[i] -= nums[trial];
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Please write your code here.

    //초기화
    v.clear();
    v.assign(k, 1);
    ans = 0;

    perm(0);

    cout << ans << "\n";

    return 0;
}

