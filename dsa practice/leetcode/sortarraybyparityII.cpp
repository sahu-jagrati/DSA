// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

// Return any answer array that satisfies this condition.

// Example 1:
// Input: nums = [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

// Example 2:
// Input: nums = [2,3]
// Output: [2,3]

// Constraints:

// 2 <= nums.length <= 2 * 104
// nums.length is even.
// Half of the integers in nums are even.
// 0 <= nums[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n++n) where n is array size
// s.c-O(n/2)*2 for odd and even array
vector<int> sortArrayByParityII(vector<int> &nums)
{
  int n = nums.size();
  vector<int> evenArray;
  vector<int> oddArray;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] % 2 == 0)
      evenArray.push_back(nums[i]);
    else if (nums[i] % 2 != 0)
      oddArray.push_back(nums[i]);
  }
  int i = 0, j = 0;
  for (int k = 0; k < n; k++)
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
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> answer = sortArrayByParityII(nums);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}