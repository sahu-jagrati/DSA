// You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

// You then do the following steps:

// If original is found in nums, multiply it by two (i.e., set original = 2 * original).
// Otherwise, stop the process.
// Repeat this process with the new number as long as you keep finding the number.
// Return the final value of original.

// Example 1:

// Input: nums = [5,3,6,1,12], original = 3
// Output: 24
// Explanation:
// - 3 is found in nums. 3 is multiplied by 2 to obtain 6.
// - 6 is found in nums. 6 is multiplied by 2 to obtain 12.
// - 12 is found in nums. 12 is multiplied by 2 to obtain 24.
// - 24 is not found in nums. Thus, 24 is returned.
// Example 2:

// Input: nums = [2,7,9], original = 4
// Output: 4
// Explanation:
// - 4 is not found in nums. Thus, 4 is returned

#include <bits/stdc++.h>
using namespace std;

int findFinalValue(vector<int> &nums, int original)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  long long answer = original;
  while (mpp.find(answer) != mpp.end())
  {
    answer = 2 * answer;
  }
  return answer;
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

  int original;
  cout << "Enter the value of original number: ";
  cin >> original;
  int result = findFinalValue(nums, original);
  cout << "Original number after multiply by two if found: " << result << endl;
  return 0;
}