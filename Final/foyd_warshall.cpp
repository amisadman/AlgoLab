#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;

void foyd_warshall(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j ++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = INF;
			}
		}
	}

	for (int k = 0; k < n; k ++) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (matrix[i][k] < INF and matrix[k][j] < INF) {
					matrix[i][j] = min(matrix[i][j] ,
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		if (matrix[i][i] < 0)cout << "This graph contains a negative cycle" << endl;

	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j ++) {
			if (matrix[i][j] == INF) {
				cout << "INF" << " ";
			}
			else cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
int main() {
	int n; cin >> n;
	vector<vector<int>>matrix(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}
	foyd_warshall(matrix);

	return 0;
}
/*
testcase
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0
*/