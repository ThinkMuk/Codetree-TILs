//그리디
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

//하나의 회의실
//N개의 회의 요청
//각 회의는 시작 시간, 끝 시간 주어져 있음
//한 회의 시작시 도중에 그만 둘 수 없음
//끝나는 직후 동시에 회의 시작 가능 (같은 초)
//취소하는 회의 개수를 최소화 해, 원할하게 진행
//즉, 주어진 시간 내 최대 회의

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    // Please write your code here.
    //최대한 많은 회의를 하기 위해선 끝나는 시간이 짧은 순대로 배치하는게 좋음
    //전체 회의 - 최대 회의
    //를 진행하면 최소로 빼야 하는 회의를 구할 수 있음
    cin >> n;

    //input 받기
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v.push_back({s, e});
    }

    //내림차순 정렬
    sort(v.begin(), v.end(), cmp);

    //연결되는 회의 개수
    int cnt = 1;
    //고정되는 idx(끝나는 시간)
    int sIdx = 0;
    //다음 회의 시작 idx
    int nIdx = 1;

    //nIdx가 끝 Idx까지 모두 탐색했을 때
    while (nIdx < n) {
        if (v[sIdx].second <= v[nIdx].first) {
            cnt++;
            //새로 시작하는 인덱스로 이동
            sIdx = nIdx;
            //끝나는 인덱스는 그 다음으로
            nIdx++;
        }
        else {
            //다음 회의는 맞출 수 있는지 보기
            nIdx++;
        }
    }

    //전체 회의 - 최대 회의
    cout << n - cnt << "\n";

    // 컴파일
    // for(pair<int,int> p : v) {
    //     cout << p.first << " " << p.second << "\n";
    // }
    return 0;
}
