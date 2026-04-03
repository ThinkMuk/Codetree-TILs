#include <iostream>
using namespace std;

int n, m;
int grid[20][20];
int pr[401], pc[401]; // pos[val] = (r, c)

int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            pr[grid[i][j]] = i;
            pc[grid[i][j]] = j;
        }
    
    while(m--){
        for(int val = 1; val <= n * n; val++){
            int r = pr[val], c = pc[val];
            int maxVal = -1, mr = -1, mc = -1;
            
            for(int d = 0; d < 8; d++){
                int nr = r + dr[d], nc = c + dc[d];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                if(grid[nr][nc] > maxVal){
                    maxVal = grid[nr][nc];
                    mr = nr; mc = nc;
                }
            }
            // 조건 없이 항상 교환
            pr[maxVal] = r; pc[maxVal] = c;
            pr[val] = mr; pc[val] = mc;
            grid[r][c] = maxVal;
            grid[mr][mc] = val;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j) cout << ' ';
            cout << grid[i][j];
        }
        cout << '\n';
    }
}