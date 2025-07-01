#include <iostream>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int num_of_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    int day1 = 0;
    int day2 = 0;

    for(int i = 1; i <= m1; i++) {
        day1+=num_of_days[i];
    }
    day1+=d1;

    for(int i = 1; i <= m2; i++) {
        day2+=num_of_days[i];
    }
    day2+=d2;

    int ans = day2-day1;

    cout << ans;

    return 0;
}