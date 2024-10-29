#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int low, int high) {

	int pivot = arr[low];
	int i = low;
	int j = high;
	while (i < j) {
		while (arr[i] <= pivot and i <= high - 1) {
			i ++;
		}
		while (arr[j] > pivot and j >= low + 1) {
			j--;
		}
		if (i < j)swap(arr[i], arr[j]);
	}

	swap(arr[low], arr[j]);
	return j;
}
void quickSort(vector<int>&arr, int low, int high) {

	if (low < high) {
		int ptIndx = partition(arr, low, high);
		quickSort(arr, low, ptIndx - 1);
		quickSort(arr, ptIndx + 1, high);
	}
}
void quickSortSolve() {
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int t; cin >> t;
	while (t--) {
		quickSortSolve();
	}

	return 0;
}
/*
testcase
9
5
4 1 3 9 7
5
1 2 3 4 5
5
5 4 3 2 1
7
3 5 2 3 8 5 3
1
42
4
10 5 8 3
3
7 1 6
4
1000000 500000 10000000 250000
5
7 7 7 7 7
*/