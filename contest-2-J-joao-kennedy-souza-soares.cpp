#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<vector<int>> filhos(n + 1);
        int raiz = 1;

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (p[i] == i) {
                raiz = i;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != raiz) {
                filhos[p[i]].push_back(i);
            }
        }

        vector<int> pesado(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            if (!filhos[u].empty()) {
                pesado[u] = filhos[u][0];
            }
        }

        vector<bool> inicio(n + 1, false);
        inicio[raiz] = true;
        for (int u = 1; u <= n; u++) {
            if (u == raiz) continue;
            int par = p[u];
            if (pesado[par] != u) {
                inicio[u] = true;
            }
        }

        vector<vector<int>> caminhos;
        for (int u = 1; u <= n; u++) {
            if (!inicio[u]) continue;
            vector<int> caminho;
            int cur = u;
            while (cur != 0) {
                caminho.push_back(cur);
                cur = pesado[cur];
            }
            caminhos.push_back(caminho);
        }

        cout << caminhos.size() << endl;
        for (const auto& cam : caminhos) {
            cout << cam.size() << endl;
            for (int v : cam) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
