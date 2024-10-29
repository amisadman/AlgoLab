#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int low, int mid, int high) {
	vector<int>temp;
	int left = low;
	int right = mid + 1;

	while (left <= mid and right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			right++;
		}
	}

	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}
	while (right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	for (int i = low; i <= high; i ++) {
		arr[i] = temp[i - low];
	}
}

void mergeSort(vector<int>&arr, int low, int high) {
	if (high == low) return;

	int mid = (high + low) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}

void mergeSortSolve() {
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int t; cin >> t;
	while (t--) {
		mergeSortSolve();
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
