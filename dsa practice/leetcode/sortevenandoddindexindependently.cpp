// You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:

// Sort the values at odd indices of nums in non-increasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
// Sort the values at even indices of nums in non-decreasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
// Return the array formed after rearranging the values of nums.

// Example 1:

// Input: nums = [4,1,2,3]
// Output: [2,3,4,1]
// Explanation:
// First, we sort the values present at odd indices (1 and 3) in non-increasing order.
// So, nums changes from [4,1,2,3] to [4,3,2,1].
// Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
// So, nums changes from [4,1,2,3] to [2,3,4,1].
// Thus, the array formed after rearranging the values is [2,3,4,1].
// Example 2:

// Input: nums = [2,1]
// Output: [2,1]
// Explanation:
// Since there is exactly one odd index and one even index, no rearrangement of values takes place.
// The resultant array formed is [2,1], which is the same as the initial array.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n+2*(mlogm)+n) where n is array size and m=n/2
// s.c-O(n/2)*2 for odd and even array
vector<int> sortEvenOdd(vector<int> &nums)
{
  int n = nums.size();
  vector<int> evenArray;
  vector<int> oddArray;
  // run n times
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      evenArray.push_back(nums[i]);
    else if (i % 2 != 0)
      oddArray.push_back(nums[i]);
  }
  // if evenarray.size=n/2 then let n/2=m
  // O(mlogm)
  sort(evenArray.begin(), evenArray.end());
  // if oddarray.size=n/2 then let n/2=m
  // O(mlogm)
  sort(oddArray.begin(), oddArray.end(), greater<int>());
  int i = 0, j = 0;
  // run n times
  for (int k = 0; k < nums.size(); k++)
  {
    if (k % 2 == 0)
    {
      nums[k] = evenArray[i];
      i++;
    }
    else if (k % 2 != 0)
    {
      nums[k] = oddArray[j];
      j++;
    }
  }
  return nums;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array such that odd index has odd value and even index has even value: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> answer = sortEvenOdd(nums);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}