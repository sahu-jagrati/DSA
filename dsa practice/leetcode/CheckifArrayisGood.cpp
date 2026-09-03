// You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

// base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

// Return true if the given array is good, otherwise return false.

// Note: A permutation of integers represents an arrangement of these numbers.

// Example 1:

// Input: nums = [2, 1, 3]
// Output: false
// Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. However, base[3] has four elements but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
// Example 2:

// Input: nums = [1, 3, 3, 2]
// Output: true
// Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. It can be seen that nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]). Therefore, the answer is true.
// Example 3:

// Input: nums = [1, 1]
// Output: true
// Explanation: Since the maximum element of the array is 1, the only candidate n for which this array could be a permutation of base[n], is n = 1. It can be seen that nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.
// Example 4:

// Input: nums = [3, 4, 4, 1, 2, 1]
// Output: false
// Explanation: Since the maximum element of the array is 4, the only candidate n for which this array could be a permutation of base[n], is n = 4. However, base[4] has five elements but array nums has six. Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. So the answer is false.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= num[i] <= 200

#include <bits/stdc++.h>
using namespace std;

// here we first sort the given array
// and get the largest elt of an array which is at the last index after sorting
// we try to get largest elt because base[n] is in the form of [1,2,,,,n-1,n,n] and the length of array is n+1 so largest elt is equal to the n so that's why we find largest elt
// after that we check if given array size is less than maxelt+1 so we return false no need to check further
// if it is fulfill then we check array has each elt of base[n]

bool isGood(vector<int> &nums)
{
  int m = nums.size();
  sort(nums.begin(), nums.end());
  int maxelt = nums[m - 1];
  if (m != maxelt + 1)
    return false;
  // we go till m-3 because upto that we search like 1,2,,,n-1
  // and for m-2 and m-1 it should be n so we check it separately
  // we check this after sorting
  for (int i = 0; i < m - 2; i++)
  {
    if (nums[i] != (i + 1))
      return false;
  }
  // check for last two elts
  if (nums[m - 2] != maxelt || nums[m - 1] != maxelt)
    return false;
  return true;
}

int main()
{
  int m;
  cin >> m;
  vector<int> nums(m);
  for (int i = 0; i < m; i++)
  {
    cin >> nums[i];
  }
  cout << isGood(nums);
  return 0;
}