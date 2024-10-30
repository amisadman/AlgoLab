#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coin(n);

    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    vector<vector<int>> dp(n, vector<int>(target + 1, 1e9));


    for (int t = 0; t <= target; ++t) {
        if (t % coin[0] == 0) {
            dp[0][t] = t / coin[0];
        } else {
            dp[0][t] = 1e9;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int t = 0; t <= target; ++t) {
            int notTake = dp[i - 1][t];
            int take = INT_MAX;
            if (coin[i] <= t) {
                take = 1 + dp[i][t - coin[i]];
            }
            dp[i][t] = min(take, notTake);
        }
    }

    int result = dp[n - 1][target];
    if (result >= 1e9) cout << -1;
    else cout << result << endl;

    return 0;
}
