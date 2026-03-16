#include <iostream>
using namespace std;

int arr[101][101];
int dy[] = {1, 0, -1, 0}; //아래 왼 위 오
int dx[] = {0, -1, 0, 1}; //아래 왼 위 오
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

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int maxTime = 0;
    int startY = 1; int startX = 1;
    //4방향 진행
    for(int i = 0; i < 4; i++) {
        int d = (3 + i) % 4;
        for(int j = 1; j < N; j++) {
            int time = 1;
            int r = startY; int c = startX;
            dist = i;
            while(inRange(r,c)) {
                if(arr[r][c] == 1) changeDistOne();
                else if (arr[r][c] == 2) changeDistTwo();
                r += dy[dist]; c += dx[dist];
                time++;
            }
            maxTime = max(maxTime, time);
            startX += dx[d];
            startY += dy[d];
        }
    }

    cout << maxTime << "\n";
    // 1번은 /
    // 2번은 \

}