# Number of k-good subarrays

https://codeforces.com/problemset/problem/1982/E

- time limit per test: 2 seconds
- memory limit per test: 256 megabytes

Let $bit(x)$ denote the number of ones in the binary representation of a non-negative integer $x$.

A subarray of an array is called $k$-good if it consists only of numbers with no more than $k$ ones in their binary representation, i.e., a subarray $(l,r)$ of array $a$ is good if for any $i$ such that $l\leq i\leq r$ condition $bit(a_i)\leq k$ is satisfied.

You are given an array $a$ of length $n$, consisting of consecutive non-negative integers starting from 0, i.e., $a_i=i$ for $0\leq i\leq n−1$ (in 0-based indexing). You need to count the number of $k$-good subarrays in this array.

As the answer can be very large, output it modulo $10^9+7$.

### Input

Each test consists of multiple test cases. The first line contains an integer $t$ $(1\leq t\leq 10^4)$ — the number of test cases. The following lines describe the test cases.

The single line of each test case contains two integers $n$, $k$ $(1\leq n\leq 10^{18},1\leq k\leq 60)$.

### Output
For each test case, output a single integer — the number of $k$-good subarrays modulo $10^9+7$.
