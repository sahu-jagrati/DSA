// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
// Example 2:

// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
// Explanation:
// For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// -1000 <= nums1[i], nums2[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();
  int m = nums2.size();
  unordered_map<int, int> mpp1;
  unordered_map<int, int> mpp2;

  for (int i = 0; i < n; i++)
  {
    mpp1[nums1[i]]++;
  }
  for (int i = 0; i < m; i++)
  {
    mpp2[nums2[i]]++;
  }
  vector<vector<int>> answer(2);
  for (auto it : mpp1)
  {
    if (!mpp2.count(it.first))
      answer[0].push_back(it.first); // we have to push distinct integers so duplicates are not allowed, so we have no requirement to check it.second
  }
  for (auto it : mpp2)
  {
    if (!mpp1.count(it.first))
      answer[1].push_back(it.first); // we have to push distinct integers so duplicates are not allowed, so we have no requirement to check it.second
  }
  return answer;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums1[i];
  }
  vector<int> nums2(n);
  for (int i = 0; i < m; i++)
  {
    cin >> nums2[i];
  }

  vector<vector<int>> answer = findDifference(nums1, nums2);
  for (auto it1 : answer)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}