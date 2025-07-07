#include <iostream>

using namespace std;

int n;
int x;
char dir;

int arr[300001] = {0}; //0: null, 1:흰색, 2:검은색
int curIdx = 150000;
int white, black = 0;

//왼쪽 흰색, 오른쪽 검은색
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> dir;
        if(dir == 'L') { //왼쪽
            for(int j = 0; j < x; j++) {
                arr[curIdx] = 1;
                curIdx--;
            }
            curIdx++; //한칸씩 앞으로 가니까 다시 정상화
        } else { //오른쪽
            for(int j = 0; j < x; j++) {
                arr[curIdx] = 2;
                curIdx++;
            }
            curIdx--;
        }
    }

    for (int i = 0; i < 300001; i++) {
        if(arr[i] == 1)
            white++;
        else if (arr[i] == 2)
            black++;
    }

    cout << white << " " << black;

    return 0;
}