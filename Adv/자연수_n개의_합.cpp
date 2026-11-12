//이진탐
#include <iostream>

using namespace std;

long long s;

int main() {
    cin >> s;

    // Please write your code here.
    //N까지 자연수 합이 S 이하
    //N의 최대값은?

    long long left = 1;
    long long right = min(s, 2000000000LL);
    while(left <= right) {
        long long mid = (left + right) / 2;
        //중간보다 커 작어?
        //가우스 사용
        long long ttl = mid * (mid + 1) / 2;

        //중간보다 크다면
        if(ttl > s) {
            //right를 mid로
            right= mid - 1;
        }
        //중간보다 작다면
        else if (ttl <= s) {
            left = mid + 1;
        }
    }

    cout << right << "\n";

    return 0;
}
