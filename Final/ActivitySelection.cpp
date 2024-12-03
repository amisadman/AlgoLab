#include<bits/stdc++.h>
using namespace std;

void activitySelection() {
	int n; cin >> n;
	vector<pair<int, int>>activity(n);
	for (int i = 0; i < n; i ++) {
		cin >> activity[i].first >> activity[i].second;
	}

	sort(activity.begin(), activity.end(), [](pair<int, int>a, pair<int, int>b) {
		return a.second < b.second;
	});

	vector<int>selected = { 0};
	int lastactivity = 0;
	for (int i = 1; i < n; i ++) {
		if (activity[i].first >= activity[lastactivity].second) {
			selected.push_back(i);
			lastactivity = i;
		}
	}
	for (auto it : selected) {
		cout << activity[it].first << " " << activity[it].second << endl;
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		activitySelection();
		cout << endl;
	}

	return 0;
}
/*
testcase
3
4
1 3
8 9
0 5
5 6
3
2 3
3 4
1 2
1
5 10
*/

