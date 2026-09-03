// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

// Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

#include <bits/stdc++.h>
using namespace std;

// we have sorted array in increasing order and we want sorted array after squares in increasing order so we use two pointer approach

vector<int> sortedSquares(vector<int> &nums)
{
  int n = nums.size();
  int l = 0, r = n - 1;
  vector<int> ans;
  while (l <= r)
  {
    int squ_l = pow(nums[l], 2);
    int squ_r = pow(nums[r], 2);
    if (squ_l < squ_r)
    {
      ans.push_back(squ_r);
      r--;
    }
    else if (squ_l > squ_r)
    {
      ans.push_back(squ_l);
      l++;
    }
    // when both are equals
    else
    {
      if (l != r)
      {
        ans.push_back(squ_l);
        ans.push_back(squ_r);
      }
      else
      {
        ans.push_back(squ_l);
      }
      l++;
      r--;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> answer = sortedSquares(arr);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}