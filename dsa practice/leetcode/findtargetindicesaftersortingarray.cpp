// You are given a 0-indexed integer array nums and a target element target.

// A target index is an index i such that nums[i] == target.

// Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity-O(n)+O(nlogn)(for sorting)  // but in question say after sorted the array find target indices so you don't have to consider sorting time
// space complexity-O(ans.size())
vector<int> targetIndices(vector<int> &nums, int target)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == target)
    {
      ans.push_back(i);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int target;
  cin >> target;
  vector<int> result = targetIndices(nums, target);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
