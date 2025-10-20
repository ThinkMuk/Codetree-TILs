#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int ability[6];

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
    }

    // Please write your code here.
    vector<pair<int,int>> teams;
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++) {
            teams.push_back({i, j});
        }
    }

    int team_min = INT_MAX;
    for(int i = 0; i < teams.size(); i++) {
        for(int j = i + 1; j < teams.size(); j++) {
            for(int k = j + 1; k < teams.size(); k++) {
                set<int> s = {teams[i].first, teams[i].second,
                            teams[j].first, teams[j].second,
                            teams[k].first, teams[k].second};
                if(s.size() < 6) continue;
                
                int sum1 = ability[teams[i].first] + ability[teams[i].second];
                int sum2 = ability[teams[j].first] + ability[teams[j].second];
                int sum3 = ability[teams[k].first] + ability[teams[k].second];

                int min_val = min({sum1, sum2, sum3});
                int max_val = max({sum1, sum2, sum3});

                int val = max_val - min_val;

                team_min = min(team_min, val);
            }
        }
    }

    cout << team_min;
    return 0;
}