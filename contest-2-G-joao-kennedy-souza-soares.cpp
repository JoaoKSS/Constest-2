#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        const int dx[4] = { -1, 1, 0, 0 };
        const int dy[4] = { 0, 0, -1, 1 };
        long long best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    long long volume = 0;
                    queue<pair<int,int>> q;
                    visited[i][j] = true;
                    q.emplace(i, j);

                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        volume += a[x][y];
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                                && a[nx][ny] > 0
                                && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.emplace(nx, ny);
                            }
                        }
                    }

                    best = max(best, volume);
                }
            }
        }

        cout << best << endl;
    }
    return 0;
}
