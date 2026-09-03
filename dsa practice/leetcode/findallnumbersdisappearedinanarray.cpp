// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// Example 2:

// Input: nums = [1,1]
// Output: [2]

#include <bits/stdc++.h>
using namespace std;

// as we use unordered map so insertion and finding take O(1) in average or O(n)in worst case
// or if we use map then it take O(log(n))
// t.c-O(n*1) for insertion in mpp+O(hashmap size*1)for finding
// s.c-O(hashmap size) + ans size (but this only store answer not solve problem)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++)
  {
    if (mpp[i] == 0)
    {
      ans.push_back(i);
    }
  }
  return ans;
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
  vector<int> result = findDisappearedNumbers(nums);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}