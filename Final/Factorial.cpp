#include<bits/stdc++.h>
using namespace std;
const int N = 10004;
long long factorial[N + 1];

long long fact(int n) {
	if (n == 0 || n == 1) return 1;

	if (factorial[n] != -1) return factorial[n];

	return factorial[n] = n * fact(n - 1);
}

int main() {
	memset(factorial, -1, sizeof(factorial));

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		cout << fact(n) << endl;
	}


	return 0;
}