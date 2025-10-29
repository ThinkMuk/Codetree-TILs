#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int N, B;

int main() {
    cin >> N >> B;
    vector<int> P;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        P.push_back(tmp);
    }
    sort(P.begin(),P.end());
    // Please write your code here.
    int max_ans = 0;
    for(int i = N - 1; i >= 0; --i) {
        int cnt = 0;
        int ttl = 0;
        for(int j = 0; j < N; j++) {
            if(i == j)
                ttl += (P[j] / 2);
            else
                ttl += P[j];
            if(ttl <= B)
                cnt++;
            else
                break;
        }
        max_ans = max(max_ans, cnt);
    }

    cout << max_ans << "\n";

    return 0;
}