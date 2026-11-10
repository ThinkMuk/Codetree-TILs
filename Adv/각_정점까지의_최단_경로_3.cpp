//Dijkstra
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000

using namespace std;

int n, m;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;

int main() {
    cin >> n >> m;

    //N개의 노드, M개의 edge
    //1번 정점에서 다른 모든 정점으로 가는 최단 경로를 구하는 프로그램 작성

    graph.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, false);
    dist.assign(n + 1, INF);

    //graph에 연결노드, 가중치 입력
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = z;
    }

    // Please write your code here.

    //시작하는 노드 0으로 설정
    dist[1] = 0;

    //노드를 전체 탐색 (한바퀴씩 정점 한개씩 확정짓기)
    for (int i = 1; i <= n; i++) {
        int min_index = -1;
        //이번에 확정지을 노드 탐색
        for (int j = 1; j <= n; j++) {
            //이미 확정되어 있는 노드라면 지나가기 (최소값이 이미 확정되어 있음)
            if (visited[j]) continue;
            if (min_index == -1 || dist[min_index] > dist[j]) {
                min_index = j;
            }
        }
        //확정 지을 노드를 미리 true 값 전환
        visited[min_index] = true;

        //확정된 간선을 기준으로 최저값 전파하기
        for (int j = 1; j <= n; j++) {
            //간선 존재하지 않으면 continue
            if(graph[min_index][j] == 0) continue;

            //존재한다면 dist에 지금의 최저값 집어넣기
            dist[j] = min(dist[j], dist[min_index] + graph[min_index][j]);
        }
    }

    for(int i = 1; i <=n; i++) {
        if(dist[i] == 0) continue;
        if(dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
