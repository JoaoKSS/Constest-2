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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        // dp[i] pontuação máxima 
        vector<long long> dp(n);
        long long max_score = 0;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = a[i];
            int jump = i + a[i];
            if (jump < n) {
                dp[i] += dp[jump]; // reutiliza pontuação 
            }
            max_score = max(max_score, dp[i]);
        }
        cout << max_score << endl;
    }

    return 0;
}
