#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> p(N);
    set<pair<int,int>> s;

    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
        s.insert(p[i]);
    }

    int mx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x1 = p[i].first, y1 = p[i].second;
            int x2 = p[j].first, y2 = p[j].second;

            if (x1 != x2 && y1 != y2) {
                if (s.count({x1, y2}) || s.count({x2, y1})) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    mx = max(mx, area);
                }
            }
        }
    }

    cout << mx << "\n";
}