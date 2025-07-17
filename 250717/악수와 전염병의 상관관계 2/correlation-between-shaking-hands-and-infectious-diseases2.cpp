#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, K, P, T;
int t[250], x[250], y[250];
vector<pair<int,int>> meetings(251, {0,0}); // 한 시점당 하나의 악수만 저장

int main() {
    cin >> N >> K >> P >> T;

    for (int i = 0; i < T; i++) {
        cin >> t[i] >> x[i] >> y[i];
        meetings[t[i]] = {x[i], y[i]};
    }

    vector<pair<bool, int>> devs(N + 1, {false, 0});
    devs[P].first = true;

    for (int sec = 1; sec <= 250; sec++) {
        int a = meetings[sec].first;
        int b = meetings[sec].second;

        if (a == 0 && b == 0) continue; // 악수 없음

        bool a_infected = devs[a].first;
        bool b_infected = devs[b].first;

        if (a_infected && !b_infected && devs[a].second < K) {
            devs[b].first = true;
            devs[a].second++;
        } else if (b_infected && !a_infected && devs[b].second < K) {
            devs[a].first = true;
            devs[b].second++;
        } else if (a_infected && b_infected && devs[a].second < K || devs[b].second < K) {
            devs[a].second++;
            devs[b].second++;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << (devs[i].first ? 1 : 0);
    }

    return 0;
}