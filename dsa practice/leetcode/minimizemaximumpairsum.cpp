// The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

// For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
// Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

// Each element of nums is in exactly one pair, and
// The maximum pair sum is minimized.
// Return the minimized maximum pair sum after optimally pairing up the elements.

// Example 1:

// Input: nums = [3,5,2,3]
// Output: 7
// Explanation: The elements can be paired up into pairs (3,3) and (5,2).
// The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
// Example 2:

// Input: nums = [3,5,4,2,4,6]
// Output: 8
// Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
// The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.

// Constraints:

// n == nums.length
// 2 <= n <= 10^5
// n is even.
// 1 <= nums[i] <= 10^5

// question is saying you have to minimize the worst (largest) pair sum
// What the question is saying (understanding only 👀)

// You’re given:

// An array nums

// The length of nums is even

// You must divide all elements into pairs (a, b)

// Rules:

// Every element must be used exactly once

// Each pair has a pair sum = a + b

// For a given pairing, look at the maximum of all pair sums

// Your goal is to pair the elements in such a way that this maximum pair sum is as small as possible

// Finally:

// Return that minimum possible maximum pair sum

// Key idea (conceptually)

// You’re not minimizing the total sum
// You’re not minimizing each pair individually

// 👉 You are minimizing the worst (largest) pair sum

// Example understanding

// If
// nums = [1, 2, 3, 4, 5, 4]

// You can pair in many ways:

// Bad pairing:
// (5,4) → 9, (4,3) → 7, (2,1) → 3
// max = 9

// Better pairing:
// (1,5) → 6, (2,4) → 6, (3,4) → 7
// max = 7

// So the answer would be 7.

// One-line intuition 💡

// Pair smallest with largest, second smallest with second largest, and so on — this balances the sums and keeps the maximum as low as possible

#include <bits/stdc++.h>
using namespace std;

int minPairSum(vector<int> &nums)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int maxSum = 0;
  int i = 0, j = n - 1;
  while (i < j)
  {
    maxSum = max(maxSum, nums[i] + nums[j]);
    i++;
    j--;
  }
  return maxSum; // after minimize it
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
  int answer = minPairSum(nums);
  cout << "Minimize Maximum pair sum is: " << answer << endl;
  return 0;
}