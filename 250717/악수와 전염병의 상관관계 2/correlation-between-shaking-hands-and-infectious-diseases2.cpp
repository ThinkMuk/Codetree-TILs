#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, K, P, T;
int t[250], x[250], y[250];
vector<pair<int,int>> meetings[251];

int main() {
    cin >> N >> K >> P >> T;

    for (int i = 0; i < T; i++) {
        cin >> t[i] >> x[i] >> y[i];
        meetings[t[i]].push_back({x[i], y[i]});
    }

    vector<pair<bool, int>> devs(N + 1, {false, 0});
    devs[P].first = true;

    for (int sec = 1; sec <= 250; sec++) {
        for (auto meet : meetings[sec]) {
            //a: 접촉1, b: 접촉2
            int a = meet.first;
            int b = meet.second;

            bool a_infected = devs[a].first;
            bool b_infected = devs[b].first;

            if (a_infected && !b_infected && devs[a].second < K) {
                devs[b].first = true;
                devs[a].second++;
            } else if (b_infected && !a_infected && devs[b].second < K) {
                devs[a].first = true;
                devs[b].second++;
            }
            else if (a_infected && b_infected && devs[a].second < K && devs[b].second < K) {
                devs[a].second++;
                devs[b].second++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << (devs[i].first ? 1 : 0);
    }

    return 0;
}