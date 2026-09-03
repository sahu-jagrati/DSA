// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space

// Example 1:
//  Input: nums = [1,3,4,2,2]
//  Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

// Example 3:
// Input: nums = [3,3,3,3,3]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

// t.c-o(n)+O(nlog(n))(for sorting)
// s.c-o(1)
int duplicateNUmber(vector<int> &nums)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int i = 0;
  for (int j = 1; j < n; j++)
  {
    if (nums[j] != nums[i])
    {
      int temp = nums[i + 1];
      nums[i + 1] = nums[j];
      nums[j] = temp;
      i++;
    }
  }
  return nums[i + 1]; // return duplicate elt
}

int main()
{
  int size;
  cout << "Enter the size of array: ";
  cin >> size;
  vector<int> nums(size);
  cout << "Enter the elt of an array: ";
  for (int i = 0; i < size; i++)
  {
    cin >> nums[i];
  }
  int result = duplicateNUmber(nums);
  cout << result << endl;
  return 0;
}