#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<pair<int,int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    int ans = N;

    for (int vx = 0; vx <= 100; vx += 2) {
        for (int hy = 0; hy <= 100; hy += 2) {
            // 4개 구역의 점 개수
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            
            for (int i = 0; i < N; i++) {
                int x = points[i].first;
                int y = points[i].second;
                
                if (x < vx && y < hy) q3++;
                else if (x < vx && y > hy) q2++;
                else if (x > vx && y < hy) q4++;
                else if (x > vx && y > hy) q1++;
            }
            
            int maxCount = max({q1, q2, q3, q4});
            ans = min(ans, maxCount);
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}