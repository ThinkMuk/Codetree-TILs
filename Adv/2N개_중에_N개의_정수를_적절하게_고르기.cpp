#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int num[20];
vector<vector<int>> v;
int ans = INT_MAX;
    //2개 그룹으로 짝지을 수 있는 방법?
    //n개의 그룹들이 존재
    //n개의 그룹중 어디를 갈 지 고민
    //만약 n개를 넘으면 백트래킹?

void sol(int depth) {
    if(depth == n * 2) { //모두 다 달성하면

        //컴파일
        // for(vector<int> vv : v) {
        //     for(int t : vv) {
        //         cout << t << " ";
        //     }
        //     cout << "\n";
        // }

        //각자 차 계산
        int sub = 0;
        int sum[2] = {0, };
        for(int i = 0; i < 2; i++) {
            for(int t : v[i]) {
                sum[i] += t;
            }
        }

        sub = abs(sum[0] - sum[1]);

        //최소값 계산
        ans = min(ans, sub);
        return;
    }

    for(int i = 0; i < 2; i++) {
        if(v[i].size() >= n) continue;

        v[i].push_back(num[depth]);
        sol(depth + 1);
        v[i].pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }
    v.resize(2);
    // Please write your code here.
    sol(0);

    cout << ans << "\n";

    return 0;
}

