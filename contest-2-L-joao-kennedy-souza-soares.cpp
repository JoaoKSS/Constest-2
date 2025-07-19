#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> dp0(n + 2, 0), dp1(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp0[i] = a[i] + dp1[i + 1];
            if (i + 1 < n) {
                dp0[i] = min(dp0[i], a[i] + a[i + 1] + dp1[i + 2]);
            }

            dp1[i] = dp0[i + 1];
            if (i + 1 < n) {
                dp1[i] = min(dp1[i], dp0[i + 2]);
            }
        }
        
        cout << dp0[0] << endl;
    }
    return 0;
}
