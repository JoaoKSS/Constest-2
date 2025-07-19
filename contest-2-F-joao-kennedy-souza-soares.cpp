#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ax, ay;
    cin >> ax >> ay;
    int bx, by;
    cin >> bx >> by;
    int cx, cy;
    cin >> cx >> cy;

    const int dx[8] = { -1, -1, -1,  0,  0,  1,  1,  1 };
    const int dy[8] = { -1,  0,  1, -1,  1, -1,  0,  1 };

    auto is_attacked = [&](int x, int y) -> bool {
        if (x == ax || y == ay) return true;                      
        if (abs(x - ax) == abs(y - ay)) return true;              
        return false;
    };

    vector< vector<bool> > visited(n+1, vector<bool>(n+1, false));
    queue< pair<int,int> > q;

    visited[bx][by] = true;
    q.push(make_pair(bx, by));

    bool can_reach = false;
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        if (x == cx && y == cy) {
            can_reach = true;
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (visited[nx][ny] || is_attacked(nx, ny)) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }

    if (can_reach)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
