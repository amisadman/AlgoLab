#include<bits/stdc++.h>
using namespace std;
vector<int>w;
vector<int>val;
/*
int knapsack(int ind, int maxw, vector<vector<int>>&dp) {
    if (ind == 0) {
        if (w[ind] <= maxw) {
            return val[0];
        }
        else return 0;
    }

    if (dp[ind][maxw] != -1)return dp[ind][maxw];

    int notTake =  0 + knapsack(ind - 1, maxw, dp);
    int take = INT_MIN;
    if (w[ind] <= maxw) take = val[ind] + knapsack(ind - 1, maxw - w[ind], dp);

    return dp[ind][maxw] = max(take , notTake);
}*/

int main() {
    int n, maxw;
    cin >> n >> maxw;
    vector<int> w, val;

    for (int i = 0; i < n; ++i) {
        int wei, v;
        cin >> wei >> v;
        w.push_back(wei);
        val.push_back(v);
    }

    vector<vector<int>> dp(n, vector<int>(maxw + 1, 0));


    for (int weight = 0; weight <= maxw; ++weight) {
        if (w[0] <= weight)
            dp[0][weight] = val[0];
    }

    for (int ind = 1; ind < n; ++ind) {
        for (int weight = 0; weight <= maxw; ++weight) {
            int notTake = dp[ind - 1][weight];
            int take = INT_MIN;
            if (w[ind] <= weight)
                take = val[ind] + dp[ind - 1][weight - w[ind]];

            dp[ind][weight] = max(take, notTake);
        }
    }

    cout << dp[n - 1][maxw];
    return 0;
}
