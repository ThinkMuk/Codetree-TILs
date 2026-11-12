#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.

    //먼저 가장 큰수부터 구하기 (5가 더 많을수록 최소 동전이 되니까)
    int five = n / 5;
    int two = (n % 5) / 2;
    
    int cnt = 0;

    //5 동전이 0이 될때까지 계속 반복해보기 (혹시나 2로 나누어 떨어지는 수의 경우까지 생각)
    while(five >= 0) {
        //일치하게 되면 5가 가장 많을 때 최저 동전이니까 탈출
        if((five * 5) + (two * 2) == n) break;
        five--;
        cnt++;
        two = ((n % 5) + (cnt * 5)) / 2;
    }
    
    if(five == -1) cout << -1 << "\n";
    else cout << five + two << "\n";

    return 0;
}
