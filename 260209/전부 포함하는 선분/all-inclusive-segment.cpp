#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    int ans = INT_MAX;
    
    //가장 작은 시작점 제거
    int min_start_idx = 0;
    for(int i = 1; i < N; i++) {
        if(v[i].first < v[min_start_idx].first)
            min_start_idx = i;
    }
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i = 0; i < N; i++) {
        if(i == min_start_idx) continue;
        minVal = min(minVal, v[i].first);
        maxVal = max(maxVal, v[i].second);
    }
    ans = min(ans, maxVal - minVal);
    
    //가장 큰 끝점 제거
    int max_end_idx = 0;
    for(int i = 1; i < N; i++) {
        if(v[i].second > v[max_end_idx].second)
            max_end_idx = i;
    }
    
    minVal = INT_MAX;
    maxVal = INT_MIN;
    for(int i = 0; i < N; i++) {
        if(i == max_end_idx) continue;
        minVal = min(minVal, v[i].first);
        maxVal = max(maxVal, v[i].second);
    }
    ans = min(ans, maxVal - minVal);
    
    cout << ans << "\n";
    return 0;
}