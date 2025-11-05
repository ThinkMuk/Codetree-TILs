#include <iostream>
#include <vector>
using namespace std;

bool isOverlap(pair<int,int> s1, pair<int,int> s2) {
    return !(s1.second < s2.first || s2.second < s1.first);
}

int main() {
    int N;
    cin >> N;
    
    vector<pair<int,int>> segments(N);
    
    for(int i = 0; i < N; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    int count = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {

                vector<pair<int,int>> remaining;
                for(int idx = 0; idx < N; idx++) {
                    if(idx != i && idx != j && idx != k) {
                        remaining.push_back(segments[idx]);
                    }
                }
                
                bool valid = true;
                for(int a = 0; a < remaining.size() && valid; a++) {
                    for(int b = a + 1; b < remaining.size(); b++) {
                        if(isOverlap(remaining[a], remaining[b])) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if(valid) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}