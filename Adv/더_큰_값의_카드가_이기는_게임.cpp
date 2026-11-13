//순열로 풀면 되지 않을까 하지만
//N의 값으로 인해 시간초과 날 확률 높음
//그리디로 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> a;
vector<int> b;
vector<bool> selected;

//A와 B 카드게임중
//1부터 2N까지번호가 쓰인 2N카드 존재
//A와 B는 카드를 N개씩 나눠가짐
//한 번에 카드를 한 장씩 내는데, 더 큰 값을 가진 사람이 점수 1점
//N회 반복
//B는 이미 정해져있고, A가 얻을 수 있는 점수의 최댓값

//B가 내는 카드의 범위가 큰 것 같은데

int main() {
    cin >> N;

    selected.assign((N * 2) + 1, false);

    //인덱스 1로 맞추기
    b.push_back(-1);
    //b 카드 입력받기
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
        selected[tmp] = true;
    }

    //a 카드도 정해주기
    //인덱스 1로 맞추기
    a.push_back(-1);
    for (int i = 1; i <= 2 * N; i++) {
        if (!selected[i]) a.push_back(i);
    }

    // Please write your code here.
    //A가 이길 수 있는 최대의 수는 흐음
    //1 4 6
    //2 3 5
    //a와 b를 정렬 후 순차적으로 비교하면서 a가 더 크면 점수 추가
    //a가 더 작으면 클때까지 인덱스 추가
    //a모두 탐색을 마치면 종료

    int aIdx = 1;
    int bIdx = 1;

    int wins = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    //a모두 탐색을 마쳤을 때
    while (aIdx <= N) {
        if (a[aIdx] > b[bIdx]) {
            // cout << a[aIdx] << " " << b[bIdx] << " " << bIdx << "\n";
            wins++; //a가 더 크다면
            aIdx++; bIdx++;
        }
        else {
            while (a[aIdx] < b[bIdx]) aIdx++;
        }
    }

    cout << wins << "\n";

    return 0;
}
