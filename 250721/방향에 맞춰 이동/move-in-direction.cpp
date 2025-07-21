#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];
int x = 0, y = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
    }

    for(int i = 0; i < n; i++) {
        if(dir[i] == 'W')
            x -= dist[i];
        else if (dir[i] == 'S')
            y -= dist[i];
        else if (dir[i] == 'N')
            y += dist[i];
        else if (dir[i] == 'E')
            x += dist[i];
    }

    cout << x << " " << y;

    return 0;
}