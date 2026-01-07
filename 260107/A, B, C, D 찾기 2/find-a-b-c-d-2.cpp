#include <iostream>
#include <set>
using namespace std;

int main() {
    // Please write your code here.
    multiset<int> s;
    for(int i = 0; i < 15; i++) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }

    int A = *s.begin(); s.erase(s.begin());
    int B = *s.begin(); s.erase(s.begin());

    s.erase(s.find(A + B));

    int C = *s.begin(); s.erase(s.begin());

    s.erase(s.find(A + C));
    s.erase(s.find(B + C));
    s.erase(s.find(A + B + C));

    int D = *s.begin();

    cout << A << " " << B << " " << C << " " << D;

    return 0;
}