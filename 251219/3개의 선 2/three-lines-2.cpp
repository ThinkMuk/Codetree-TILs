#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<pair<int,int>> points;

bool solve(vector<bool>& covered, int lines) {
    if (lines == 0) {
        for (int i = 0; i < N; i++) {
            if (!covered[i]) return false;
        }
        return true;
    }
    
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (!covered[i]) {
            idx = i;
            break;
        }
    }
    
    if (idx == -1) return true; 

    vector<bool> newCovered = covered;
    for (int i = 0; i < N; i++) {
        if (points[i].first == points[idx].first) {
            newCovered[i] = true;
        }
    }
    if (solve(newCovered, lines - 1)) return true;
    
    newCovered = covered;
    for (int i = 0; i < N; i++) {
        if (points[i].second == points[idx].second) {
            newCovered[i] = true;
        }
    }
    if (solve(newCovered, lines - 1)) return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    points.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    vector<bool> covered(N, false);
    
    if (solve(covered, 3)) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    
    return 0;
}