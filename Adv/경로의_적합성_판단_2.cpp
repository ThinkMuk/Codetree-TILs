//UNION_FIND
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int path[100001];
vector<int> parent;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa != pb) parent[pb] = pa;
}

int main() {
    cin >> n >> m >> k;

    parent.resize(n + 1);

    for(int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    for (int i = 1; i <= k; i++) {
        cin >> path[i];
    }

    // Please write your code here.
    //n개의 node, m개의 edge (양방향 그래프)
    //순서의 길이 k

    //x, y는 연결되어 있다는 것을 의미
    //k개의 점으로 이루어진 순서가 그래프 위에서 순서대로 이동을 할 수 있는지
    //가능하면 1, 불가능하면 0

    int ans = 1;
    for(int i = 1; i < k; i++) {
        if(find(path[i]) == find(path[i + 1])) continue;
        else {cout << 0 << "\n"; return 0;}
    }

    cout << ans << "\n";
    return 0;
}
