// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n+n+1)=O(n)
// s.c-O(n+1)=O(n) for range array it is variable space because whenever nums change size also change

// done by me fully
vector<int> findDuplicates(vector<int> &nums)
{
  int n = nums.size();
  vector<int> range(n + 1, 0); // we don't write int range[n+1]={0}; because in this variable size can not be initialized so we use vector for initialized variable sized array
  for (int i = 0; i < n; i++)
    range[nums[i]]++;
  vector<int> result;
  for (int i = 0; i < range.size(); i++)
  {
    if (range[i] == 2)
      result.push_back(i);
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n); // each elt in nums appears once or twice
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> answer = findDuplicates(nums);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}