#include <iostream>
#include <algorithm>
using namespace std;

int arr[200][200];
int N,M;

int base[2][3][2] = {
        {{0,0}, {1,0}, {1,1}}, //L자
        {{0,0}, {0,1}, {0,2}},//I자
};

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    int ans = 0;

    //도형 교체
    for(int b = 0; b < 2; b++) {
        for(int flip = 0; flip < 2; flip++) {
            int shape[3][2];
            //선언
            for(int k = 0; k < 3; k++) {
                shape[k][0] = base[b][k][0];
                shape[k][1] = flip ? -base[b][k][1] : base[b][k][1];
            }

            for(int rot = 0; rot < 4; rot++) {
                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < M; j++) {
                        int sum = 0;
                        bool valid = true;
                        for(int k = 0; k < 3; k++) {
                            int ni = i + shape[k][0];
                            int nj = j + shape[k][1];
                            if(0 > ni || ni >= N || 0 > nj || nj >= M) {
                                valid = false; break;
                            }
                            sum += arr[ni][nj];
                        }
                        if(valid) ans = max(ans, sum);
                    }
                }
                for(int k = 0; k < 3; k++) {
                    int r = shape[k][0], c = shape[k][1];
                    shape[k][0] = c;
                    shape[k][1] = -r;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}