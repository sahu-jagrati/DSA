// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

// Constraints:

// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.

// Follow up: Could you find an O(nums1.length + nums2.length) solution?

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n*m) in worst case
// s.c-O(m)(for mpp storing nums2 elt )+O(n)(for ans array which is required)
vector<int> nextGreaterElt(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();
  int m = nums2.size();
  unordered_map<int, int> mpp; // store <value,index> for nums2 arrray so we get index easily in nums2 array when we want nums1[i]==nums2[j]
  for (int i = 0; i < m; i++)
  {
    mpp[nums2[i]] = i;
  }
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++)
  {
    int value = nums1[i];
    int index = mpp[nums1[i]]; // here we get the index of value= nums1[i] in nums2 by using map
    // and after that index we start to seach for next first greater elt in nums2
    // we do index+1 because we want  next first greater elt in nums2
    for (int j = index + 1; j < m; j++)
    {
      if (nums2[j] > value)
      {
        ans[i] = nums2[j];
        break; // we break because we want first greater elt that appear in nums2
      }
    }
  }
  return ans;
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
  vector<int> nums2(m);
  for (int i = 0; i < m; i++)
  {
    cin >> nums2[i];
  }
  vector<int> ans = nextGreaterElt(nums1, nums2);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}
