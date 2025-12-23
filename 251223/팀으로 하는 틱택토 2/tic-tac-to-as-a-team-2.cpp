#include <iostream>
using namespace std;

int board[3][3];

bool check(int a, int b, int c, int i, int j) {
    bool allValid = (a == i || a == j) && (b == i || b == j) && (c == i || c == j);
    bool hasI = (a == i || b == i || c == i);
    bool hasJ = (a == j || b == j || c == j);
    return allValid && hasI && hasJ;
}

bool teamWins(int i, int j) {
    // 가로
    for(int k = 0; k < 3; k++)
        if(check(board[k][0], board[k][1], board[k][2], i, j)) return true;
    // 세로
    for(int k = 0; k < 3; k++)
        if(check(board[0][k], board[1][k], board[2][k], i, j)) return true;
    // 대각선
    if(check(board[0][0], board[1][1], board[2][2], i, j)) return true;
    if(check(board[0][2], board[1][1], board[2][0], i, j)) return true;
    
    return false;
}

int main() {
    for(int i = 0; i < 3; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < 3; j++) {
            board[i][j] = tmp[j] - '0';
        }
    }

    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = i + 1; j <= 9; j++) {
            if(teamWins(i, j)) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}