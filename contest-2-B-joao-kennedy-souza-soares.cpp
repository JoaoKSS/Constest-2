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

    int res = 0;
    for(int i = 1; i <= n; ++i){
        int count = 0;
        int cur = i;
        while(cur != -1){
            count++;
            cur = f[cur];
        }
        res = max(res, count);
    }

    cout << res << endl;
    return 0;
}
