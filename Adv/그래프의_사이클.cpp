//UNION-FIND
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[100000], to[100000];
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return (parent[x] = find(parent[x]));
}

bool Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    //서로 같지 않으면, pb의 부모를 pa로 연결
    if (pa != pb) {
        parent[pb] = pa;
        return false;
    }
    return true;
}

// Please write your code here.
//1번부터 N번까지 N개 정점으로 이루어진 그래프
//1번부터 M번까지 M개 간선

int main() {
    cin >> n >> m;

    //자기 자신노드를 부모로 설정해두기
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        //서로 같은 부모를 가지고 있다면
        if (Union(a, b)) {
            cout << i << "\n";
            return 0;
        }

        //Union이 false 값이라면 (처음 연결하는 값이라면) 계속 진행
    }

    cout << "happy\n";
    return 0;
}
