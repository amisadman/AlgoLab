#include<bits/stdc++.h>
using namespace std;
vector<int>coins;

int minCoin(int indx, int target, vector<vector<int>>&dp) {
	if (indx == 0) {
		if (target % coins[0] == 0) return target / coins[0];
		else return 1e9;
	}

	if (dp[indx][target] != -1) return dp[indx][target];

	int notTake = 0 + minCoin(indx - 1, target, dp);
	int take = INT_MAX;
	if (coins[indx] <= target) {
		take = 1 + minCoin(indx, target - coins[indx], dp);
	}
	return dp[indx][target] = min(take, notTake);
}

void minCoinSolve() {
	int n, target; cin >> n >> target;
	for (int i = 0; i < n; ++i)
	{
		int tmp; cin >> tmp;
		coins.push_back(tmp);
	}
	vector<vector<int>>dp(n, vector<int>(target + 1, -1));
	int min = minCoin(n - 1, target, dp);
	if (min != 1e9) cout << min << endl;
	else cout << "Not Possible" << endl;

}
int main() {
	int t; cin >> t;
	while (t--) {
		minCoinSolve();
		coins.clear();
	}

	return 0;
}
/*
testcase
8
3 11
1 5 7
3 9
3 5 7
2 10
2 5
3 8
1 4 5
2 7
3 5
1 6
2
2 100
1 10
0 10
*/