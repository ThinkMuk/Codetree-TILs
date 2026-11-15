#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> cords;
vector<bool> selected;
int ans = -1;

//수직선상 N개의 선분
// **겹치지 않고** 고를 수 있는 가장 많은 선분의 수
// 끝점 공유 또한 겹친것으로 생각

//회고: 이 문제는 그리디로도 풀이가 가능함
//시작점이 빠르다고 많은 개수를 선택하진 못하지만, 끝점이 빠른것부터 선택하면 많이 선택할 수 있음
//따라서 sort를 진행하고, 이전 선분과 겹치지 않는지 검증만 진행하게 되면 O(NlogN)까지 가능

void perm(int depth) {
    if(depth == n) { //모든 경우를 다 선택했을 때
        bool isLine = true;

        for(int i = 0; i < n; i++) {
            if(!selected[i]) continue;

            for(int j = i + 1; j < n; j++) {
                if(i == j) continue;
                if(!selected[j]) continue;

                //겹친다면 false (이 규칙을 사용할려면 오름차순은 필수)
                if(cords[i].second >= cords[j].first) {
                    return;
                }
            }
        }

        int cnt = 0;
        for(bool b : selected) {
            if(b) cnt++;
        }

        ans = max(ans, cnt);
        return;
    }

    selected[depth] = true;
    perm(depth + 1);

    selected[depth] = false;
    perm(depth + 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        cords.push_back({a, b});
    }
    
    //초기화
    selected.assign(n, false);

    // Please write your code here.
    //비교는 어떻게 진행을 할까
    //사용하기로 한 선분들과
    //주어진 선분과 비교하는게 좋을 것 같음
    
    //오름차순으로 정렬을 위해 sort진행
    sort(cords.begin(), cords.end());
    perm(0);

    cout << ans << "\n";
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n;
// vector<pair<int,int>> cords;
// int ans = 0;

// // 끝점을 기준으로 오름차순 정렬
// bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
//     if(a.second == b.second) {
//         return a.first < b.first;
//     }
//     return a.second < b.second;
// }

// int main() {
//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         int a, b;
//         cin >> a >> b;
//         cords.push_back({a, b});
//     }

//     // 끝점 기준 오름차순 정렬
//     sort(cords.begin(), cords.end(), cmp);

//     // 마지막으로 선택한 선분의 끝점
//     int lastEnd = -1;

//     for(int i = 0; i < n; i++) {
//         // 이전 선분과 겹치지 않는다면 선택
//         if(cords[i].first > lastEnd) {
//             ans++;
//             lastEnd = cords[i].second;
//         }
//     }

//     cout << ans << "\n";

//     return 0;
// }
