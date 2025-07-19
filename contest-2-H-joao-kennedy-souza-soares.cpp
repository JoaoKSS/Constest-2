#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int nVertices, nArestas, nGovernos;
    cin >> nVertices >> nArestas >> nGovernos;

    vector<bool> eGovernamental(nVertices + 1, false);
    vector<int> nosGovernos(nGovernos);
    for (int i = 0; i < nGovernos; i++) {
        cin >> nosGovernos[i];
        eGovernamental[nosGovernos[i]] = true;
    }

    vector<vector<int>> adj(nVertices + 1);
    for (int i = 0; i < nArestas; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visitado(nVertices + 1, false);
    vector<long long> tamanhosCompGoverno;
    long long totalNaoGovernos = 0;

    for (int i = 1; i <= nVertices; i++) {
        if (!visitado[i]) {
            queue<int> fila;
            visitado[i] = true;
            fila.push(i);

            long long tamComp = 0;
            bool temGoverno = false;
            while (!fila.empty()) {
                int u = fila.front(); fila.pop();
                tamComp++;
                if (eGovernamental[u]) {
                    temGoverno = true;
                }
                for (int v : adj[u]) {
                    if (!visitado[v]) {
                        visitado[v] = true;
                        fila.push(v);
                    }
                }
            }

            if (temGoverno) {
                tamanhosCompGoverno.push_back(tamComp);
            } else {
                totalNaoGovernos += tamComp;
            }
        }
    }

    sort(tamanhosCompGoverno.begin(), tamanhosCompGoverno.end());
    if (!tamanhosCompGoverno.empty()) {
        tamanhosCompGoverno.back() += totalNaoGovernos;
    }

    long long arestasMax = 0;
    for (long long c : tamanhosCompGoverno) {
        arestasMax += c * (c - 1) / 2;
    }

    long long resposta = arestasMax - nArestas;
    cout << resposta << endl;

    return 0;
}
