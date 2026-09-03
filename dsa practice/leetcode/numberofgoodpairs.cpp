// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j

// Example 1:

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
// Example 2:

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
  int n = nums.size();
  int cnt = 0;
  // i<j
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] == nums[j])
        cnt++;
    }
  }
  return cnt;
}
int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  int result = numIdenticalPairs(nums);
  cout << "Number of pairs: " << result << endl;
  return 0;
}