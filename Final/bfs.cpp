#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
int visited[10004];

void bfs(int node) {
	visited[node] = 1;
	queue<int>q;
	q.push(node);
	while (!q.empty()) {
		int current = q.front();
		cout << current << " ";
		q.pop();
		for (auto it : adj[current]) {
			if (visited[it] == 0) {
				visited[it] = 1;
				q.push(it);
			}
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m ; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) {
		if (visited[i] == 0) {
			bfs(i);
		}
	}


	return 0;
}
/*
testcase
6 7
1 2
1 3
2 4
2 5
3 5
4 6
5 6
*/