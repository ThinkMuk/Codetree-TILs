#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
int arr[21][21];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    vector<pair<int,int>> marbles(M);
    for(int i = 0; i < M; i++)
        cin >> marbles[i].first >> marbles[i].second;

    for(int t = 0; t < T; t++) {
        vector<pair<int,int>> next(marbles.size());

        for(int i = 0; i < marbles.size(); i++) {
            int r = marbles[i].first, c = marbles[i].second;
            int bestVal = -1, br = r, bc = c;

            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
                if(arr[nr][nc] > bestVal) {
                    bestVal = arr[nr][nc];
                    br = nr;
                    bc = nc;
                }
            }

            next[i] = {br, bc};
        }

        vector<bool> alive(marbles.size(), true);
        for(int i = 0; i < next.size(); i++) {
            if(!alive[i]) continue;
            bool collision = false;

            for(int j = i + 1; j < next.size(); j++) {
                if(!alive[j]) continue;
                if(next[i] == next[j]) {
                    alive[j] = false;
                    collision = true;
                }
            }
            
            if(collision) alive[i] = false;
        }

        vector<pair<int,int>> survived;
        for(int i = 0; i < next.size(); i++) {
            if(alive[i]) survived.push_back(next[i]);
        }
        marbles = survived;
    }

    cout << marbles.size() << "\n";
    return 0;
}