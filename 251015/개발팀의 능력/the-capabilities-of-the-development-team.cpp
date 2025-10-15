#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> v(5);

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    // Please write your code here.
    int min_dev = INT_MAX;
    for (int a = 0; a < 5; a++) {
        for (int b = a + 1; b < 5; b++) {

            vector<int> rest;
            for(int i = 0; i < 5; i++) {
                if(i == a || i == b)
                    continue;
                rest.push_back(i);
            }

            int fTeam = v[a] + v[b];

            for(int c = 0; c < 3; c++) {
                for(int d = c + 1; d < 3; d++) {
                    int restIdx = 3 - (c + d);
                    int sTeam = v[rest[c]] + v[rest[d]];
                    int tTeam = v[rest[restIdx]];

                    if(fTeam == sTeam || fTeam == tTeam || sTeam == tTeam) continue;

                    int diff = max({fTeam, sTeam, tTeam}) - min({fTeam, sTeam, tTeam});
                    min_dev = min(min_dev, diff);
                }
            }
        }
    }

    cout << (min_dev == INT_MAX ? -1 : min_dev) << "\n";

    return 0;
}