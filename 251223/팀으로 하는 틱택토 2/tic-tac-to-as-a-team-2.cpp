#include <iostream>
using namespace std;

int main() {
    int board[3][3];
    for(int i = 0; i < 3; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < 3; j++) {
            board[i][j] = tmp[j] - '0';
        }
    }

    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = i + 1; j <= 9; j++) {
            // 가로줄 3개 체크
            for(int k = 0; k < 3; k++) {
                bool valid = true;
                bool hasI = false, hasJ = false;
                for(int l = 0; l < 3; l++) {
                    if(board[k][l] == i) hasI = true;
                    else if(board[k][l] == j) hasJ = true;
                    else valid = false;
                }
                if(valid && hasI && hasJ) ans++;
            }

            // 세로줄 3개 체크
            for(int k = 0; k < 3; k++) {
                bool valid = true;
                bool hasI = false, hasJ = false;
                for(int l = 0; l < 3; l++) {
                    if(board[l][k] == i) hasI = true;
                    else if(board[l][k] == j) hasJ = true;
                    else valid = false;
                }
                if(valid && hasI && hasJ) ans++;
            }
            
            // 주대각선 체크
            {
                bool valid = true;
                bool hasI = false, hasJ = false;
                for(int k = 0; k < 3; k++) {
                    if(board[k][k] == i) hasI = true;
                    else if(board[k][k] == j) hasJ = true;
                    else valid = false;
                }
                if(valid && hasI && hasJ) ans++;
            }

            // 역대각선 체크
            {
                bool valid = true;
                bool hasI = false, hasJ = false;
                for(int k = 0; k < 3; k++) {
                    if(board[k][2-k] == i) hasI = true;
                    else if(board[k][2-k] == j) hasJ = true;
                    else valid = false;
                }
                if(valid && hasI && hasJ) ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}