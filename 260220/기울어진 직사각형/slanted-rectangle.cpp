#include <iostream>
using namespace std;

int N;
int grid[21][21];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];
    
    // 방향: 1=(-1,+1), 2=(-1,-1), 3=(+1,-1), 4=(+1,+1)
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {1, -1, -1, 1};
    
    int ans = 0;
    
    for(int d1 = 1; d1 < N; d1++){
        for(int d2 = 1; d2 < N; d2++){
            int steps[] = {d1, d2, d1, d2};
            
            for(int sr = 0; sr < N; sr++){
                for(int sc = 0; sc < N; sc++){
                    bool visited[21][21] = {};
                    int r = sr, c = sc;
                    bool ok = true;
                    
                    for(int dir = 0; dir < 4 && ok; dir++){
                        for(int s = 0; s < steps[dir]; s++){
                            if(r < 0 || r >= N || c < 0 || c >= N){
                                 ok = false; break; 
                            }
                            visited[r][c] = true;
                            r += dr[dir];
                            c += dc[dir];
                        }
                    }
                    if(!ok) continue;
                    
                    int sum = 0;
                    for(int i = 0; i < N; i++)
                        for(int j = 0; j < N; j++)
                            if(visited[i][j])
                                sum += grid[i][j];
                    
                    ans = max(ans, sum);
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}