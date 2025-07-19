#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }

    for (int i = 1; i <= n; ++i) {
        int j = f[i]; // A -> B
        int k = f[j]; // B -> C
        int l = f[k]; // C -> A
        if (l == i) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
