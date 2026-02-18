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
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
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