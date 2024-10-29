#include<bits/stdc++.h>
using namespace std;

vector<int>weight;
vector<int>values;


int knapsack(int indx, int maxW, vector<vector<int>>&memo) {
	if (indx == 0) {
		if (weight[indx] <= maxW) {
			return values[0];
		} else return 0;
	}

	if (memo[indx][maxW] != -1) return memo[indx][maxW];

	int notTake = 0 + knapsack(indx - 1, maxW, memo);
	int take = INT_MIN;
	if (weight[indx] <= maxW) {
		take = values[indx] + knapsack(indx - 1, maxW - weight[indx], memo);
	}
	return memo[indx][maxW] =  max(take, notTake);

}

void knapsackSolve() {
	int n, maxW; cin >> n >> maxW;
	for (int i = 0; i < n; i ++) {
		int w, v; cin >> w >> v;
		weight.push_back(w);
		values.push_back(v);
	}
	vector<vector<int>>memo(n, vector<int>(maxW + 1, -1));
	cout << knapsack(n - 1, maxW, memo) << endl;
}
int main() {

	int t; cin >> t;
	while (t--) {
		knapsackSolve();
		weight.clear();
		values.clear();
	}


	return 0;
}
/*
testcase
3

3 8
3 30
4 50
5 60

6 15
6 5
5 6
6 4
6 6
3 5
7 2

5 5
1 1000
1 1000
1 1000
1 1000
1 1000

*/