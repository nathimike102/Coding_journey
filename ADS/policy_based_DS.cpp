/*
Policy Based DataStructure

Problem

perform the following Q queries on an initially Empty Set.

1 X -> insert X element in the set
2 X -> Remove X from the set
3 X -> print No. of elements smaller than X in the current set
4 X -> print element present at the Xth index in the Current set

constraints
-10^9 <= X <= 10^9
1 <= Q <= 10^5

---------------------------------------------------------------------------

Using a Vector

1 X -> insert X element in the set
O(N) if we want to keep it sorted

finding may take O(log(N)) but for insert O(N)

2 X -> Remove X from the set
O(N) to remove the element at any arbitrary index

3 X -> print No. of elements smaller than X in the current set
O(logN) Binary search

4 X -> print element present at the Xth index in the Current set
O(1) index Access

let us find the time complexity
what is we are doing on Q quarries
then O(Q) * O(N) it is not good

---------------------------------------------------------------------------

Using a Set


1 X -> Insert X element in the set
O(log(N))


2 X -> Remove X from the set
O(log(N))

3 X -> print No. of elements smaller than X in the current set
O(N) cannot Binary search on a set

4 X -> print element present at the Xth index in the Current set
O(N) no concept of index in a set

over all time complexity is O(Q) * O(N)

---------------------------------------------------------------------------


Ordered Set to the rescue

provides all the features of a traditional set and additional features

->finding No. of elements smaller than X in the set
A. order_of_key(X) -> O(logN)

->finding the element present at the Xth index in the set
*A.find_by_order(X) -> O(logN)
*/

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

int main() {
	pbds A; // declaration

	// Inserting elements - 1st query
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);
	A.insert(2);  // ordered set only contains unique values

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << endl;

	// finding kth element - 4th query
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X - 3rd query
	cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
	cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
	cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl; // 0
	cout << endl;

	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
	cout << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
	cout << endl;

	// // Remove elements - 2nd query
	A.erase(1);
	A.erase(11); // element that is not present is not affected

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;

}