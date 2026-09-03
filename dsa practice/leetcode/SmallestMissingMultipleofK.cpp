// Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

// A multiple of k is any positive integer divisible by k.

// Example 1:

// Input: nums = [8,2,3,4,6], k = 2

// Output: 10

// Explanation:

// The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

// Example 2:

// Input: nums = [1,4,7,10,15], k = 5

// Output: 5

// Explanation:

// The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100
// 1 <= k <= 100

#include <bits/stdc++.h>
using namespace std;

// In starting I'm confusing about for multiples of k upto which I have to run a loop because multiples of k are infinite so we cannot run loop from 1 to how much for checking that multiple exist in nums or not means we cannot say anything about upper bound of multiples of k.

// But later we realized that there is no need for an upper bound. We can simply checking until we find a missing multiple means we have to simply check in  hashset that multiple exist or not from i=1 se here condition for loop is st.count(k*i) if it is then i++ or if not then return k*i

// we use unordered set for checking elt exist or not

// as we used unoredered st so it takes O(1) as average for each elt so for total it is O(n*1)
// we have n elts so total t.c-O(n)(for insert in st)+O(n)(for while loop in worst case when in nums all elts are multiple of k then we pass through all elts)
// t.c-O(n)
// s.c-O(n)for st
int missingMultiple(vector<int> &nums, int k)
{
  unordered_set<int> st;
  for (int x : nums)
  {
    st.insert(x);
  }
  int i = 1; // for multiple if k
  // loop run unitl  multiple of k present in nums when not present it is stop and that is our answer and it is smalles t multiple because I start from i=1
  while (st.count(k * i))
  {
    i++; // simply increase i because that multiple exist so we check for next
  }
  return k * i; // smallest missing multiple
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int k;
  cin >> k;
  cout << " Smallest missing multiple of k : " << missingMultiple(nums, k);
  return 0;
}