// You are given a 0-indexed integer array nums of size n.

// Define two arrays leftSum and rightSum where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

// Example 1:

// Input: nums = [10,4,8,3]
// Output: [15,1,11,22]
// Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
// The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
// Example 2:

// Input: nums = [1]
// Output: [0]
// Explanation: The array leftSum is [0] and the array rightSum is [0].
// The array answer is [|0 - 0|] = [0].

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// brute force solution
// t.c-O(n^2)
// s.c-O(1) because ans array is required which is output
vector<int> leftRightDifference(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n);
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += nums[i];
  for (int i = 0; i < n; i++)
  {
    int leftSum = totalSum, rightSum = totalSum;
    if (i == 0)
    {
      leftSum = 0;
      rightSum = rightSum - nums[0];
    }
    else if (i == n - 1)
    {
      leftSum = leftSum - nums[n - 1];
      rightSum = 0;
    }
    else
    {
      // for rightsum we have to subtract left elt including current i
      for (int j = 0; j <= i; j++)
      {
        rightSum -= nums[j];
      }
      // for leftsum we have to subtract right elt including current i
      for (int j = i; j < n; j++)
      {
        leftSum -= nums[j];
      }
    }
    ans[i] = abs(leftSum - rightSum);
  }
  return ans;
}
// My brute force solution has O(n²) time complexity because for every index i, we're again traversing part of the array to calculate leftSum and rightSum.

// optimize solution-prefix sums
// leftSum=sum of elts before i
// rightSum=totalSum-leftSum-nums[i]
// so we have to just maintain leftSum
// t.c-O(n)
// s.c-O(1) because ans array is required which is output
vector<int> leftRightSumDifference(vector<int> &nums)
{
  int n = nums.size();
  int totalSum = 0;
  for (int x : nums)
    totalSum += x;
  vector<int> ans(n);
  int leftSum = 0;
  for (int i = 0; i < n; i++)
  {
    int rightSum = totalSum - leftSum - nums[i];
    ans[i] = abs(leftSum - rightSum);
    leftSum += nums[i];
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
  vector<int> ans = leftRightDifference(nums);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}

// A useful pattern to remember is:

// rightSum = totalSum - leftSum - nums[i];
// leftSum += nums[i];

// Whenever you need "sum on left" and "sum on right" for every index.