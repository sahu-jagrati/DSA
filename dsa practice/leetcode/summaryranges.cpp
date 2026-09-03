// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b

// Example 1:

// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"
// Example 2:

// Input: nums = [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: The ranges are:
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"

// Constraints:

// 0 <= nums.length <= 20
// -2^31 <= nums[i] <= 2^31 - 1
// All the values of nums are unique.
// nums is sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

// whole code is done by me
// i am happy

// t.c-O(n)
//  s.c-ans size
vector<string> summaryRanges(vector<int> &nums)
{

  int n = nums.size();

  vector<string> ans;
  if (n == 0)
    return ans;
  int a = nums[0], b = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (nums[i] == nums[i - 1] + 1)
    {
      b = nums[i];
    }
    else if (nums[i] != nums[i - 1] + 1)
    {
      if (a != b)
      {
        ans.push_back(to_string(a) + "->" + to_string(b));
      }
      else
      {
        ans.push_back(to_string(a));
      }
      a = b = nums[i]; // start new range
    }
  }
  // for push last range
  if (a != b)
  {
    ans.push_back(to_string(a) + "->" + to_string(b));
  }
  else
  {
    ans.push_back(to_string(a));
  }
  return ans;
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
  vector<string> answer = summaryRanges(nums);
  for (auto it : answer)
  {
    cout << it << "  ";
  }
  cout << endl;
  return 0;
}