#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;

vector<int> belmon_fort(int V, vector<vector<int>>& edges, int S) {
	vector<int>dist(V, INF);
	dist[S] = 0;
	for (int i = 0; i < V - 1; ++i) {
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int w = it[2];
			if (dist[u] != INF and dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}
	for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int w = it[2];
		if (dist[u] != INF and dist[u] + w < dist [v]) {
			cout << "This graph has a Negative weigth cycle" << endl;
			return{ -1};
		}
	}
	return dist;
}
int main() {
	int V, E, S;
	cin >> V >> E >> S;
	vector<vector<int>>edges(E, vector<int>(3));

	for (int i = 0; i < E; ++i) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}
	vector<int>dist = belmon_fort(V, edges, S);
	for (auto it : dist) {
		if (it == INF) {
			cout << "INF" << " ";
		}
		else cout << it << " ";
	}


	return 0;
}
/*
testcase
5 8 0
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
*/
/*
negative cycle
4 4 0
0 1 1
1 2 -1
2 3 -1
3 1 -1
*/