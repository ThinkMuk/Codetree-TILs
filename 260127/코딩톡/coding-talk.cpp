#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    // Please write your code here.
    int N, M, p;
    vector<pair<char, int>> v;
    map<char, bool> m;
    cin >> N >> M >> p;

    char user = 'A';
    for(int i = 0; i < N; i++) {
        m[user] = false;
        user++;
    }

    for(int i = 0; i < M; i++) {
        char c; int u;
        cin >> c >> u;
        v.push_back({c, u});
    }

//    int remain = N - v[p - 1].second;
    for(int i = p - 1; i < N; i++) {
        m[v[i].first] = true;
//        remain--;
    }

    for(auto iter : m) {
        if(!iter.second)
            cout << iter.first << " ";
    }
    cout << "\n";

    return 0;
}