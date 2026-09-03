// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

// Constraints:

// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// if array has no zero, having only +ve elt then we are able to reach last index
// if array has zero then we have to cross zero for reaching last index

// t.c-O(n) n is size of array
// s.c-O(1)
// we use maxindex to get max of (maximum jump of each elt )
bool canJump(vector<int> &nums)
{
  int n = nums.size();
  int maxIndex = 0; //  max of (for each elt maximum index we can go)
  for (int i = 0; i < n; i++)
  {
    // that we can go max upto maxIndex after that we can go so we are not able to reach last index
    if (i > maxIndex)
      return false;
    maxIndex = max(maxIndex, i + nums[i]);
    // when maxindex>n means we are able to reach last index so break
    if (maxIndex > n)
      break;
  }
  return true;
}

int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt of an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  bool answer = canJump(nums);
  cout << "Is possible to reach last index or not: " << answer << endl;
  return 0;
}