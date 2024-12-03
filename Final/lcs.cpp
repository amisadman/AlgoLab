#include<bits/stdc++.h>
using namespace std;

int lcs(int index1, int index2, string &s1, string &s2, vector<vector<int>>&dp) {
	if (index1 < 0 || index2 < 0) {
		return 0;
	}
	if (dp[index1][index2] != -1) return dp[index1][index2];

	if (s1[index1] == s2[index2]) return dp[index1][index2] =  1 + lcs(index1 - 1, index2 - 1, s1, s2, dp);

	return dp[index1][index2] = max(lcs(index1 - 1, index2, s1, s2, dp), lcs(index1, index2 - 1, s1, s2, dp));
}

void print_lcs(int index1, int index2, string &s1, string &s2, vector<vector<int>>&dp) {
	string lcs_str = "";
	while (index1 >= 0 and index2 >= 0) {
		if (s1[index1] == s2[index2]) {
			lcs_str += s1[index1];
			index1--;
			index2--;
		}
		else if (dp[index1 - 1][index2] >= dp[index1][index2 - 1]) {
			index1--;
		}
		else index2--;
	}

	reverse(lcs_str.begin(), lcs_str.end());
	cout << lcs_str << endl;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();

	vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));


	int s = lcs(m - 1, n - 1, s1, s2, dp);
	cout << s << endl;


	print_lcs(m - 1, n - 1, s1, s2, dp);

	return 0;
}
/*
testcase
BDCABA
ABCBDAB
*/
