// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true

// Example 2:
// Input: nums = [1,0,1,1], k = 1
// Output: true

// Example 3:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

// Constraints:
// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// 0 <= k <= 10^5

#include <bits/stdc++.h>
using namespace std;

// naive solution- but for large array this give time limit exceed
// t.c-O(n^2)
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if ((nums[i] == nums[j]) && (abs(i - j) <= k))
        return true;
    }
  }
  return false;
}

// optimal solution- using hashmap

// lastIndex.count(nums[i])- checks whether nums[i] exists or not Returns 1 → key is present
// Returns 0 → key is NOT present
// ⚠️ Because a map cannot have duplicate keys, count() is never more than 1.

// t.c-O(n)
// s.c-O(n)
bool containDuplicate(vector<int> &nums, int k)
{
  int n = nums.size();
  unordered_map<int, int> lastIndex; // store value,lastindex of value means last time when it show
  for (int i = 0; i < n; i++)
  {
    // count() function gives key exist in map or not
    // if nums[i] is exists in map it means it already found before so if ( current index - already find index )<=k then true
    if (lastIndex.count(nums[i]))
    {
      if (i - lastIndex[nums[i]] <= k)
        return true;
    }
    lastIndex[nums[i]] = i;
  }
  return false;
}

// another solution-sliding window+set

// t.c-O(n)
// s.c-O(k)
bool duplicates(vector<int> &nums, int k)
{
  unordered_set<int> window;

  for (int i = 0; i < nums.size(); i++)
  {
    if (window.count(nums[i]))
      return true;

    window.insert(nums[i]);

    // when set size >k
    if (window.size() > k)
    {
      window.erase(nums[i - k]);
    }
  }
  return false;
}
// Why nums[i - k]?

// When i becomes greater than k, the window size becomes k + 1,
// so we must remove the element that is too far away.

// That element is at index:

// i - k

// So:

// window.erase(nums[i - k]);

// means
// ➡️ remove the element that is k positions behind the current index

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int k;
  cin >> k;
  // bool answer = containDuplicate(nums, k);
  bool answer = duplicates(nums, k);
  cout << answer << endl;
  return 0;
}