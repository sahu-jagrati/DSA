// You are given a 1-indexed array of distinct integers nums of length n.

// You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

// If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
// The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

// Return the array result.

// Example 1:

// Input: nums = [2,1,3]
// Output: [2,3,1]
// Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1].
// In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (2 > 1), append nums[3] to arr1.
// After 3 operations, arr1 = [2,3] and arr2 = [1].
// Hence, the array result formed by concatenation is [2,3,1].
// Example 2:

// Input: nums = [5,4,3,8]
// Output: [5,3,4,8]
// Explanation: After the first 2 operations, arr1 = [5] and arr2 = [4].
// In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (5 > 4), append nums[3] to arr1, hence arr1 becomes [5,3].
// In the 4th operation, as the last element of arr2 is greater than the last element of arr1 (4 > 3), append nums[4] to arr2, hence arr2 becomes [4,8].
// After 4 operations, arr1 = [5,3] and arr2 = [4,8].
// Hence, the array result formed by concatenation is [5,3,4,8].

// Constraints:

// 3 <= n <= 50
// 1 <= nums[i] <= 100
// All elements in nums are distinct.

#include <bits/stdc++.h>
using namespace std;

// brute force solution that I think
// simply do stepwise whatever question says

// and given array has distinct elts

// t.c-O(n)(for making arr1 and arr2)+O(n)(for appending arr1 and arr2 in result array)=O(2n)=O(n)
// s.c-O(n)(by combining both arr1 and arr2)+O(n)(for result array which is required)
vector<int> resultArray(vector<int> &nums)
{
  int n = nums.size();
  // make two arrays
  vector<int> arr1;
  vector<int> arr2;
  // push nums[0] in arr1 and push nums[1] in arr2 A.T.Q
  arr1.push_back(nums[0]);
  arr2.push_back(nums[1]);
  // track the last elt of both arrays
  int last1 = nums[0]; // initially
  int last2 = nums[1];

  // traverse given nums array from index 2 to n-1
  for (int i = 2; i < n; i++)
  {
    // last elt of arr1 is greater than last elt of arr2 then push current elt in arr1 otherwise in arr2
    if (last1 > last2)
    {
      arr1.push_back(nums[i]);
      // update last elt of arr1
      last1 = nums[i];
    }
    else
    {
      arr2.push_back(nums[i]);
      last2 = nums[i];
    }
  }
  vector<int> result;
  // append arr1 into result array
  for (int i = 0; i < arr1.size(); i++)
  {
    result.push_back(arr1[i]);
  }
  // append arr2 into result array
  for (int i = 0; i < arr2.size(); i++)
  {
    result.push_back(arr2[i]);
  }
  return result;
}

// better solution
// we take only one subarray arr2 and for arr1 we directly store it in result array
// track last elt for both subarray arr1 and arr2
// we know in arr1 first elt is nums[0] and we know also we append arr1 first in result array than arr2 so we can push nums[0] in result array directly means elt of arr1 directly push in result array
// after the traversing nums array we have to add only arr2 in result array because we add arr1 directly in result array when we traverse the nums array

// so by this solution we don't have to use separate arr1
// and don't run separate loop for append arr1 in result array
// t.c-O(n)(for traversing given array)+O(arr2.size)(for add it in result array)=O(n)
// s.c-O(arr2.size)+O(n)(for result array which is required)
vector<int> resultarray(vector<int> &nums)
{
  int n = nums.size();
  // we take only one subarray arr2 and for arr1 we directly store it in result array
  vector<int> arr2;
  vector<int> result;
  // track last elt for both subarray arr1 and arr2
  int last1 = nums[0];
  int last2 = nums[1];
  // we know in arr1 first elt is nums[0] and we know also we append arr1 first in result array than arr2 so we can push nums[0] in result array means elt of arr1 directly push in result array
  result.push_back(nums[0]); // for arr1 push directly
  arr2.push_back(nums[1]);
  // we go from index 2 to n-1
  for (int i = 2; i < n; i++)
  {
    if (last1 > last2)
    {
      // means we have to push elt in arr1 so here we push elt directly in result because we append arr1 first in result array than arr2 so
      result.push_back(nums[i]);
      last1 = nums[i];
    }
    else
    {
      // push in arr2
      arr2.push_back(nums[i]);
      last2 = nums[i];
    }
  }
  // now we have to add only arr2 in result array because we add arr1 directly in result array above
  for (int i = 0; i < arr2.size(); i++)
  {
    result.push_back(arr2[i]);
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  // given array has distinct elts
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  // vector<int> ans = resultArray(nums);
  vector<int> ans = resultarray(nums);
  for (int it : ans)
  {
    cout << it << " ";
  }
  return 0;
}