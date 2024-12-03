#include<bits/stdc++.h>
using namespace std;

const int N = 10004;
int fibonacci[N + 1];

int fib(int n) {
	if (n == 0) return 0;
	if (n == 1)return 1;

	if (fibonacci[n] != -1) return fibonacci[n];

	return fibonacci[n] = fib(n - 1) + fib(n - 2);
}

void fibSeries(int n) {

	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 0; i <= n; i++) {
		cout << fibonacci[i] << " ";
	}
	cout << endl;
}

int main() {
	memset(fibonacci, -1, sizeof(fibonacci));
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		cout << fib(n) << endl;
		fibSeries(n);
	}

	return 0;
}