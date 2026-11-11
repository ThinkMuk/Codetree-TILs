#include <iostream>
#include <vector>
#define INF 100000000

using namespace std;

int n, m;
int A, B;

//1부터 N까지
//N개의 정점
//M개의 간선
//주어진 정점과 간선의 그래프는 양방향
//A부터 B까지의 최단 거리 구하기

//연결 간선 표시
vector<vector<int>> grid;
//확정된 노드인지
vector<bool> visited;
//최단 거리 노드 기록
vector<int> nodes;

int main() {
    cin >> n >> m;

    //초기화
    grid.assign(n + 1, vector<int>(n + 1, INF));
    visited.assign(n + 1, false);
    nodes.assign(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        //양방향이기 때문
        grid[a][b] = min(grid[a][b], c);
        grid[b][a] = min(grid[b][a], c);
    }

    cin >> A >> B;

    // Please write your code here.

    //시작하는 node의 거리는 0
    nodes[A] = 0;

    //모든 노드 돌기
    for(int i = 1; i <= n; i++) {
        int min_val = -1;
        //1. nodes들 중 가장 작은 거리 구하기
        for(int j = 1; j <= n; j++) {
            //이미 확정된 노드라면 건너뛰기
            if(visited[j]) continue;
            if(min_val == -1 || nodes[min_val] > nodes[j])
                min_val = j;
        }

        //2. 작은거리 기준으로 다음값 전염
        for(int j = 1; j <= n; j++) {
            if(grid[min_val][j] == INF) continue;
            nodes[j] = min(nodes[j], nodes[min_val] + grid[min_val][j]);
        }

        visited[min_val] = true;
    }

    cout << nodes[B] << "\n";

    return 0;
}
