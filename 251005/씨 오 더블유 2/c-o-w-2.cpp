#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;
    bool tglC = false, tglO = false, tglW = false;
    int cntC = 0, cntO = 0, cntW = 0;

    for(char c : str) {
        if(c == 'C' && tglO == false && tglW == false) {
            cntC++;
            tglC = true;
        }
        else if (c == 'O' && tglC == true && tglW == false) {
            cntO++;
            tglO = true;
        }
        else if (c == 'W' && tglC == true && tglC == true) {
            cntW++;
            tglW = true;
        }
    }

    cout << cntC * cntO * cntW;

    return 0;
}