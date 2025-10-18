#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

int dist(int a, int b, int N) {
    int diff = abs(a - b);
    return min(diff, N - diff);
}

bool isOpen(int x, int y, int z, int a, int b, int c, int N) {
    return (dist(x, a, N) <= 2 &&
            dist(y, b, N) <= 2 &&
            dist(z, c, N) <= 2);
}

int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    // Please write your code here.
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(isOpen(i,j,k,a1,b1,c1,N) || isOpen(i,j,k,a2,b2,c2,N))
                    cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}