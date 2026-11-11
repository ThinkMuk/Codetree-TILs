#include <iostream>
#include <vector>

using namespace std;

int n, m;
int A, B;

//N개의 정점, M개의 간선
//정점 A에서 B까지의 최단 거리와 ** 경로 **
//주어지는 간선은 ** 양방향 **

const int INF = 1e9;

//간선이 적혀있는 grid
vector<vector<int>> grid;
//확정된 노드인지
vector<bool> visited;
//최솟값 거리 기록
vector<int> dp;


int main() {
    cin >> n >> m;

    //초기화
    grid.assign(n + 1, vector<int>(n + 1, INF));
    visited.assign(n + 1, false);
    dp.assign(n + 1, INF);

    //간선 입력
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        grid[a][b] = min(grid[a][b], c);
        grid[b][a] = min(grid[b][a], c);    
    }

    cin >> A >> B;

    dp[A] = 0;

    //흠 여기서 최단거리를 어떻게 알아내지
    //정답 vector을 만들어두기
    //각 노드별로 최소를 어떤 경로를 구했는지 저장할 예정
    vector<vector<int>> v(n + 1);

    //각 노드들에 본인 노드 넣어두기
    for(int i = 1; i <= n; i++) {
        v[i].push_back(i);
    }
    //min_val 확정(true)로 만들기전에 저장해두기?

    // Please write your code here.
    //n회 반복
    for(int i = 1; i <= n; i++) {
        int min_val = -1;
        //가장 작은 노드 고르기
        for(int j = 1; j <= n; j++) {
            //이미 확정된 노드라면 건너뛰기
            if(visited[j]) continue;
            if(min_val == -1 || dp[min_val] > dp[j]) min_val = j;
        }

        //최솟값 전염시키기
        for(int j = 1; j <= n; j++) {
            if(grid[min_val][j] == INF) continue;
            //만약 새로운 노드값이 기존보다 더 적다면
            int nd = dp[min_val] + grid[min_val][j];

            if(nd < dp[j]) {
                dp[j] = nd;
                //기존에 지나왔던 경로로 본인 노드 갱신
                v[j] = v[min_val];
                //후에 자기 노드까지 넣어주기
                v[j].push_back(j);
            }
        }

        visited[min_val] = true;
    }

    cout << dp[B] << "\n";
    for(int t : v[B]) {
        cout << t << " ";
    }
    cout << "\n";
    
    return 0;
}
