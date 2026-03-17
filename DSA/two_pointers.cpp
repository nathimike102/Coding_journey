/*Two Pointers
============

-> widely used in CP
-> Optimization Technique
-> most two pointer problems can also be solved by binary search
-> useful for interviews
                                                                                                                        

// "TLE-Eliminators = youtube"

problems:

given 2 sorted arrays of size n & m, for each element in 1st array find number of elements smaller than that 2nd array.

1 4 5 9 11

2 3 6 7 10

Good segment Technique Type 1
-> lets define a good segement as a subarray that follows a particular property.
-> now ask yourself, can you prove that all segments enclosed within good segemnet are also good segements, which means all the subarrays enclosed are in a good subarray are also follwoing the property.

Q. Given an array of size N, +ve elements. Find out the length of the longet subarray with sum <= k;

i/p
a = [10, 5, 2, 7, 1, 9]
k = 15


Good segmet Tecnique Type 2
-> lets define a good segement as a subarray that follows a particular property.
-> now ask yourself, can you prove that all enclosing a good segment are also good, means all subarrays enclosing a good subarray also follow property.
*/