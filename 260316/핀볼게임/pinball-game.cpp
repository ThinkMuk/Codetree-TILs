#include <iostream>
using namespace std;

int arr[101][101];
int dy[] = {1, 0, -1, 0}; //아래 왼 위 오
int dx[] = {0, -1, 0, 1};
int N;
int dist;

// "/" 일 때 변수
void changeDistOne() {
    if(dist == 3) dist = 2;
    else if (dist == 0) dist = 1;
    else if (dist == 2) dist = 3;
    else if (dist == 1) dist = 0;
}

// "\" 일 때 변수
void changeDistTwo() {
    if(dist == 3) dist = 0;
    else if (dist == 0) dist = 3;
    else if (dist == 2) dist = 1;
    else if (dist == 1) dist = 2;
}

bool inRange(int y, int x) {
    return (1 <= y && y <= N && 1 <= x && x <= N);
}

int simulate(int startR, int startC, int dir) {
    int time = 1;
    int r = startR, c = startC;
    dist = dir;
    while(inRange(r, c)) {
        if(arr[r][c] == 1) changeDistOne();
        else if(arr[r][c] == 2) changeDistTwo();
        r += dy[dist]; c += dx[dist];
        time++;
    }
    return time;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int maxTime = 0;

    for(int j = 1; j <= N; j++)
        maxTime = max(maxTime, simulate(1, j, 0));

    for(int i = 1; i <= N; i++)
        maxTime = max(maxTime, simulate(i, N, 1));

    for(int j = 1; j <= N; j++)
        maxTime = max(maxTime, simulate(N, j, 2));

    for(int i = 1; i <= N; i++)
        maxTime = max(maxTime, simulate(i, 1, 3));

    cout << maxTime << "\n";
}