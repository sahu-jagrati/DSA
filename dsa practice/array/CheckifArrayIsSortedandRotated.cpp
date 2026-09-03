// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

// we use brute force
// Brute force and check if it is possible for a sorted array to start from each position.

// done by me

void reverse(vector<int> &arr, int start, int end)
{
  while (start < end)
  {
    int var = arr[start];
    arr[start] = arr[end];
    arr[end] = var;
    start++;
    end--;
  }
}
// x is an index from where we rotate the array
vector<int> rotatedAti(vector<int> &arr, int x)
{
  int n = arr.size();
  reverse(arr, 0, x - 1);
  reverse(arr, x, n - 1);
  reverse(arr, 0, n - 1);
  return arr;
}
bool check(vector<int> &nums)
{
  int n = nums.size();
  vector<int> temp = nums; // this for checking nums in last after sorted rotation
  sort(temp.begin(), temp.end());
  for (int i = 0; i < n; i++)
  {
    vector<int> arr = temp; // this because we check for each index rotation so
    if (nums == rotatedAti(arr, i))
    {
      return true;
    }
  }
  return false;
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
  cout << check(nums);
  return 0;
}