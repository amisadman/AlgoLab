#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10005];
int visited[10005];

void dfs(int node) {
	int current = node;
	cout << current << " ";
	visited[node] = 1;
	for (auto it : adj[node]) {
		if (visited[it] == 0) {
			dfs(it);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}

	return 0;
}