#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string A;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    int num_of_days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string date[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

    int dateCnt = 0;
    for(int i =0 ;i < 7;i++) {
        if(date[i] == A) {
            dateCnt = i;
            break;
        }
    }

    int day1 = 0;
    for(int i = 1; i < m1; i++) {
        day1+=num_of_days[i];
    }
    day1+=d1;

    int day2 = 0;
    for(int i = 1; i < m2; i++) {
        day2+=num_of_days[i];
    }
    day2+=d2;

    int diff = day2-day1;
    int count = diff/7;
    int dateCntCal = diff%7;


    if(dateCntCal >= dateCnt) {
        count++;
    }

    cout << count;

    return 0;
}