#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    vector<pair<long long, long long>> intervals;
    vector<vector<int>> adj;

    int n;
    cin >> n;

    for (int qi = 0; qi < n; qi++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x, y;
            cin >> x >> y;

            intervals.emplace_back(x, y);
            int idx = intervals.size() - 1;
            adj.emplace_back();

            for (int i = 0; i < idx; i++) {
                long long a = intervals[i].first;
                long long b = intervals[i].second;

                if ((a < x && x < b) || (a < y && y < b)) {
                    adj[idx].emplace_back(i);
                }

                if ((x < a && a < y) || (x < b && b < y)) {
                    adj[i].emplace_back(idx);
                }
            }
        }
        else if (type == 2) {
            int a, b;
            cin >> a >> b;

            a--; b--;

            vector<bool> visited(intervals.size(), false);
            queue<int> q;
            q.push(a);
            visited[a] = true;

            bool reachable = false;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == b) {
                    reachable = true;
                    break;
                }
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            if (reachable)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
