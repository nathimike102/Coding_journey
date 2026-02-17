sliding window
================

invertible -> sum, xor
e.g sum -= a[i], sum += a[i]

non-invertible -> or, min, max, gcd, mex, median

1. prefix/suffix
store prefix or for each segment of the window length, left to right i%k==0 
store suffix or for each segment of the window length, right to left i%k == k-1 
or = p[i] | s[i-k+1]
time = O(N)
space = O(N)

2. agg queue
using two stack as a queue
in stack and out stack.
