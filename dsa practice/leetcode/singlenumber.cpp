// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:
// Input: nums = [1]
// Output: 1

#include <bits/stdc++.h>
using namespace std;

// t.c-O(N)
// s.c-O(1) where N is length of array
//  we can also done it by hashmap but it take extra space so use this
int singleNumber(vector<int> &nums)
{
  int n = nums.size();
  int XOR = 0;
  for (int i = 0; i < n; i++)
  {
    XOR = XOR ^ nums[i];
  }
  return XOR;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt of array(all elt are exact twice in array except one elt): ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int result = singleNumber(nums);
  cout << result << endl;
  return 0;
}