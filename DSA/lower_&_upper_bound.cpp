/*
Upper and Lower Bound in Binary Search

-> upper_bound: returns the index of the first element that is greater than the target value.
    if(arr[mid] <= target){
        left = mid + 1;
    }
    else{
        right = mid - 1;
    }
-> lower_bound: returns the index of the first element that is greater than or equal to the target value.
    if(arr[mid] >= target){
        right = mid - 1;
    }
    else{
        left = mid + 1;
    }

cpp(stl)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    auto lower = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    auto upper = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    cout << "Lower bound index: " << lower << endl;
    cout << "Upper bound index: " << upper << endl;
    return 0;
}

Longest Increasing Subsequence (LIS) using Binary Search
The longest increasing subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. The
LIS problem can be solved using dynamic programming with a time complexity of O(n^2), but it can be optimized to O(n log n) using binary search.

// O(n^2) solution using recursion
#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int prev, vector<int>& nums, int n) {
    if (idx == n)
        return 0;
    int notTake = solve(idx + 1, prev, nums, n);
    int take = 0;
    if (nums[idx] > prev)
        take = 1 + solve(idx + 1, nums[idx], nums, n);
    return max(take, notTake);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int ans = solve(0, -1e5, nums, n);
    return ans;
}

// O(n log n) solution using binary search
#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        if(i == 0){
            temp.push_back(nums[i]);
        }
        else {
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
    }
    return temp.size();
}
*/
