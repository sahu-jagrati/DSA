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

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.

#include <bits/stdc++.h>
using namespace std;

// by using hashmap but it takes space
// if we are using ordered map then it takes O(logn) for insert/access
// we are using unordered map so it takes O(1) as an average for insert/access
// t.c-O(n*1)+O(mpp size)
// s.c-O(mpp size)
// as almost all elts appear twice except once so mpp size=(n/2)+1, where n is size of nums
int singlenumber(vector<int> &nums)
{
  unordered_map<int, int> mpp; // stores (value,frequency)
  for (int x : nums)
  {
    mpp[x]++;
  }
  int ans;
  for (auto it : mpp)
  {
    if (it.second == 1)
    {
      ans = it.first;
      break;
    }
  }
  return ans;
}

// t.c-O(n)
// s.c-O(1) where n is length of array
//  we can also done it by hashmap but it take extra space so we using XOR operation

// we want to find out elt that appears once and we know other elts appear twice so
// we know a^a=0
// and 0^b=b
// so for elts that appear twice xor=0 and when take xor of 0 with elt that appear once it give that elt so answer=0^b=b

// example: nums=[4,1,2,1,2]
// so if we take XOR of all numbers then: 4^1^2^1^2 so 2^2=0 and 1^1=0 so we get : 4^0^0 which is 4 appears once
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
  cout << singlenumber(nums) << endl;
  int result = singleNumber(nums);
  cout << result << endl;
  return 0;
}