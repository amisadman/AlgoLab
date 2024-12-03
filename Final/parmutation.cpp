#include <bits/stdc++.h>
using namespace std;

void generatePermutations(int index, vector<int>& nums, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); ++i) {
        swap(nums[index], nums[i]);
        generatePermutations(index + 1, nums, result);
        swap(nums[index], nums[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> permutations;
    generatePermutations(0, arr, permutations);

    for (auto perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
testcase :
3
1 2 3
*/
