// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:

// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// brute force: by using XOR because given that  every elt appear exactly twice except for one elemnt that appears once so if we take XOR of all elts then a^a=0 and 0^b=b so we get b because for elts that appear twice xor=0 and when we take xor of 0 with single appear elt then we get single appear elt

// t.c-O(n)
// s.c-O(1)
int singleElement(vector<int> &nums)
{
  int n = nums.size();
  int XorOfAll = 0;
  for (int i = 0; i < n; i++)
  {
    XorOfAll ^= nums[i];
  }
  return XorOfAll;
}

// but A.T.Q we have to solve this in O(logn)and O(1) space
// as given we have sorted array so we can use binary search 
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  // where every element appears exactly twice, except for one element which appears exactly once.
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << singleElement(nums);
  return 0;
}