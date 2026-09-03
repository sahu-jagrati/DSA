// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

// Constraints:

// 0 <= n <= 105

// Follow up:

// It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
// Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

#include <bits/stdc++.h>
using namespace std;

// using Brian Kernighan's Algorithm

int cntSetBit(int num)
{
  int cnt = 0;
  while (num != 0)
  {
    num = num & (num - 1);
    cnt++;
  }
  return cnt;
}

// t.c-
// for each number i, complexity=O(number of set bits in i)
// worst case:
// each number has upto 32 bits
// and we have 1 to n numbers means total n numbers
// total complexity= approx.O(32*n)- which is basically O(n) in worst case
// in average case O(nlogn) approx

// s.c-O(n+1) for ans array which is required
vector<int> countingBits(int n)
{
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    ans[i] = cntSetBit(i);
  }
  return ans;
}

// optimal dp solution
// (i&1)-here i is individual number
// If last bit is 1 → add 1
// If last bit is 0 → add 0

// i>>1- removes last bit
// i>>1=i/2

// DP approach:
// Reuse previously computed answers
// So it avoids recomputation.

// t.c-O(n)
// s.c-O(n+1) for ans array which is required
vector<int> cntBits(int n)
{
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    ans[i] = ans[i >> 1] + (i & 1);
  }
  return ans;
}