// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

// Example 1:

// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
// Example 2:

// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// Example 3:

// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4
// 1 <= x <= 10^9

#include <bits/stdc++.h>
using namespace std;

// first we understand the problem:
// In one operation, we can remove only one elt either from the leftmost or rightmost side and we can remove that elt only if it is smaller of equal to x.
// After removing an elt, the array becomes smaller,so the next leftmost/rightmost elts may be different.

// example: nums=[1,1,4,2,3] and x=5
// We need to remove elts whose sum is exactly 5.

// The best choice is:
// first we remove 3
// After removing 3: nums=[1,1,4,2] and x=5-3=2
// Then remove 2 from the right we get: nums=[1,1,4] and x=2-2=0
// So: 2 operations minimum required to reduce x to 0.

// For removing an elt, we cannot choose an arbitrary elt.
// example: [1,1,4,2,3] and we choose 4 which is in the middle, so we cannot directly remove it.

// We would first have to remove everything before it from the left: remove 1 , then remove 1 or everything after it from the right: remove 3, then remove 2, only then could 4 become removable.

// So we cannot choose any arbitrary elt for removal, we can either remove leftmost elt or rightmost elt.

// The key observation:
// Suppose we remove some elts from the left and some from the right.

// for example: [1,1,4,2,3]
// remove 1,1 from left and remove 3 from right

// The elts we don't remove must always form one continuous subarray in the middle.

// example: remove -> [1,1] [4,2] [3] <- remove
//                          remaining

// If removed elts have sum x, then:
// sum(removed elt)=x
// And: sum(remaining elts)=totalSum - x

// So instead of thinking: "Which elts should I remove from the two ends? "

// We can think: "What is the longest continuous subarray whose sum is totalSum-x?" we can think this because we don't remove any arbitrary elt, we remove either left or right elt so remaining elts always continous.

// Then: minimum removals = n - length_of_longest_Subarray_With_Sum = totalSUm-x
// because we want minimum operations and in one operation we can remove only one elt so for removing minimum number of elts , we have maximum number of remaining elts means length of longest continuous subarray with sum=totalSum-x will be larget for getting minimum operations.

// example:
// nums=[1,1,4,2,3]
// totalSum=11
// x=5
// remainingSUm=11-5=6

// longest subarray with sum 6: [1,1,4]=6
// its length is 3.
// therefore, minimumOperations=5-3=2

// SO instead of thinking about what we subtract and what we remove from both ends, we think about the remaining elts that should be maximum in numbers because removal elts shouls be minimum in number so we find longest continous subarray whose sum = totalSUm-x for that we are using sliding window

// edge case:
// i) if remainingSum < 0 then we cannot get negative sum from positive elts so in that case we retun -1
// ii) if remaining sum ==0 means totalSum == x means we have to remove all elts from nums to get x so in that case minimum operations = length of given array = n
// iii) if we don't get any subarray with remainingSUm then also we return -1.

// t.c-O(n)(for total sum loop)+O(n)(sliding window loop in worst case)=O(2n)
// s.c-O(1)
int minOperations(vector<int> &nums, int x)
{
  int n = nums.size();
  int totalSum = 0;
  for (int i = 0; i < n; i++)
  {
    totalSum += nums[i];
  }
  // sum of remaining elts which are remained after removing elts whose sum = x
  int remainingSum = totalSum - x;
  // if remainingSum < 0 then we cannot get negative sum from positive elts so in that case we retun -1
  if (remainingSum < 0)
  {
    return -1;
  }
  // when totalSum == x means we have to remove all elts from nums to get x so in that case minimum operations = length of given array = n
  if (remainingSum == 0)
  {
    return n;
  }

  // we are using silding window to get longest continuous subarray whose sum=remainingSum
  int l = 0, r = 0;
  int sum = 0;
  int lengthOfLongestRemainingSubarray = INT_MIN;
  while (r < n)
  {
    sum += nums[r];
    while (sum > remainingSum)
    {
      sum -= nums[l];
      l++;
    }
    if (sum == remainingSum)
    {
      lengthOfLongestRemainingSubarray = max(lengthOfLongestRemainingSubarray, r - l + 1);
    }
    r++;
  }
  // if we don't get any subarray with remainingSUm then also we return -1.
  if (lengthOfLongestRemainingSubarray == INT_MIN)
  {
    return -1;
  }
  // minimumOperations = n - length of longest subarray with sum=remainingsum=totalSUm-x
  return (n - lengthOfLongestRemainingSubarray);
}

// SO notice that instead of thinking what question says we have to also think in a way that we can solve this question in other way also

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int x;
  cin >> x;
  cout << minOperations(nums, x);
  return 0;
}