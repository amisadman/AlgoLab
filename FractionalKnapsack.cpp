#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {

	double r1 = (double)a.first / a.second;
	double r2 = (double)b.first / b.second;
	return r1 > r2;

}

double fractionalKnapsack(vector<pair<int, int>>&items, int maxW) {
	sort(items.begin(), items.end(), cmp);

	double maxProfit = 0.0;
	for (auto& item : items) {
		int value = item.first;
		int weight = item.second;

		if (maxW == 0) break;

		if (weight <= maxW) {
			maxW -= weight;
			maxProfit += value;
		}
		else {
			maxProfit += value * ((double)maxW / weight);
			maxW = 0;
		}
	}
	return maxProfit;


}

void fractionalKnapsackSolve() {
	int n, maxW; cin >> n >> maxW;
	vector<pair<int, int>>items;

	for (int i = 0; i < n; ++i)
	{
		int val, w; cin >> val >> w;
		items.push_back({val, w});
	}
	double maxProfit = fractionalKnapsack(items, maxW);
	cout << fixed << setprecision(2) << "Maximum profit: " << maxProfit << endl;
}
int main() {
	fractionalKnapsackSolve();


	return 0;
}
/*
3 50
60 10
100 20
120 30
*/
