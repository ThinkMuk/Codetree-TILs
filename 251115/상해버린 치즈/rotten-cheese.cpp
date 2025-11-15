#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    
    vector<tuple<int, int, int>> eat(D);
    for (int i = 0; i < D; i++) {
        int p, m, t;
        cin >> p >> m >> t;
        eat[i] = {p, m, t};
    }
    
    vector<pair<int, int>> sick(S);
    for (int i = 0; i < S; i++) {
        int p, t;
        cin >> p >> t;
        sick[i] = {p, t};
    }
    
    int ans = 0;
    
    // 각 치즈가 상했다고 가정
    for (int badCheese = 1; badCheese <= M; badCheese++) {
        bool possible = true;
        
        // 치즈가 상했을 때 모든 아픈 사람 정보와 일치하는지 확인
        for (auto [sickPerson, sickTime] : sick) {
            bool ateBadCheese = false;
            
            // 아픈 사람이 상한 치즈를 아프기 전에 먹었는지 체크
            for (auto [p, m, t] : eat) {
                if (p == sickPerson && m == badCheese && t < sickTime) {
                    ateBadCheese = true;
                    break;
                }
            }
            
            // 아픈 사람인데 상한 치즈를 먹지 않았다면 탈출해서 다른 치즈 시작
            if (!ateBadCheese) {
                possible = false;
                break;
            }
        }
        
        if (!possible) continue;
        
        // 상한 치즈 먹은 사람 계산
        vector<bool> ateBad(N + 1, false);
        for (auto [p, m, t] : eat) {
            if (m == badCheese) {
                ateBad[p] = true;
            }
        }
        
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (ateBad[i]) count++;
        }
        
        ans = max(ans, count);
    }
    
    cout << ans << '\n';
    
    return 0;
}