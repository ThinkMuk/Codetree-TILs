#include <iostream>
using namespace std;

int n;
int color[300001] = {0,}; // 0빈칸, 1검정, 2하양, 3회색
int black_cnt[300001] = {0,};
int white_cnt[300001] = {0,};
   
int main() {
    cin >> n;
   
    int curIdx = 150000;
    for (int i = 0; i < n; i++) {
        int x;
        char dir;
        cin >> x >> dir;
   
        for (int j = 0; j < x; j++) {
            //색칠하기
            if (dir == 'R') { // 검정
                black_cnt[curIdx]++;
                color[curIdx] = 1;
            } else { // 하양
                white_cnt[curIdx]++;
                color[curIdx] = 2;
            }

            //회색 분류
            if (black_cnt[curIdx] >= 2 && white_cnt[curIdx] >= 2) {
                color[curIdx] = 3;
            }
   
            if (dir == 'R') curIdx++;
                else curIdx--;
            }

            //루프를 돌고 나면 한 번 더 가있으므로 다시 원위치 시키기
            if (dir == 'R') curIdx--;
            else curIdx++;
        }
   
        int whiteAns = 0, blackAns = 0, greyAns = 0;
        for(int i = 0; i < 300001; i++) {
           if(color[i] == 1) blackAns++;
            else if (color[i] == 2) whiteAns++;
            else if (color[i] == 3) greyAns++;
        }
   
        cout << whiteAns << " " << blackAns << " " << greyAns;
   
        return 0;
}