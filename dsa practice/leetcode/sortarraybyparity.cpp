// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

// Example 1:
// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

// Example 2:
// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 5000
// 0 <= nums[i] <= 5000

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
  int n = nums.size();
  int i = 0;
  vector<int> ans;
  while (i < n)
  {
    if (nums[i] % 2 == 0)
    {
      ans.push_back(nums[i]);
    }
    i++;
  }
  i = 0;
  while (i < n)
  {
    if (nums[i] % 2 != 0)
    {
      ans.push_back(nums[i]);
    }
    i++;
  }
  return ans;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> answer = sortArrayByParity(nums);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}