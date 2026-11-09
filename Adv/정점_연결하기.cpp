//UNION-FIND
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> parent;

int find(int x) {
    //루트는 부모가 자기 자신을 가르킴
    //따라서 이 코드는 "루트에 도달시"와 동일
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    //만약 둘이 부모가 다르면 합하기
    //b의 부모는 이제 a임 (하나로 연결)
    if(pa != pb) parent[pb] = pa;
}

int main() {
    cin >> n;

    parent.resize(n + 1);

    //각 node의 parent 놓기
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    // Please write your code here.
    //1번부터 n번까지 n-1개의 간선 존재
    //간선 하나가 사라져 n-2개
    //하나를 추가해서 간선 구하기
    //모든 정점이 연결되어야 함

    //간선이 많다면 그런 간선들의 양 끝 정점의 순서쌍 중 사전순으로 가장 앞선 순서쌍 출력

    int f = 1, s = -1;
    for(int i = 2; i <= n; i++) {
        if(find(f) != find(i)) {
            s = i; break;
        }
    }

    cout << f << " " << s << "\n";
    return 0;
}
