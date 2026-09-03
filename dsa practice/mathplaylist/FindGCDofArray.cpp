// Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

// Example 1:

// Input: nums = [2,5,6,9,10]
// Output: 2
// Explanation:
// The smallest number in nums is 2.
// The largest number in nums is 10.
// The greatest common divisor of 2 and 10 is 2.
// Example 2:

// Input: nums = [7,5,6,8,3]
// Output: 1
// Explanation:
// The smallest number in nums is 3.
// The largest number in nums is 8.
// The greatest common divisor of 3 and 8 is 1.
// Example 3:

// Input: nums = [3,3]
// Output: 3
// Explanation:
// The smallest number in nums is 3.
// The largest number in nums is 3.
// The greatest common divisor of 3 and 3 is 3.

// Constraints:

// 2 <= nums.length <= 1000
// 1 <= nums[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// solution I
// using built-in gcd function which uses the Euclidean Algorithm
// Time Complexity
// If the two numbers are a and b (a ≥ b), then
// O(log(min(a,b)))
// 	​
// or equivalently,

// O(log(max(a,b)))

// since the logarithms differ only by a constant factor.

// Why?
// The Euclidean algorithm repeatedly performs:
// gcd(a, b)
// = gcd(b, a % b)

// Each iteration significantly reduces the size of the numbers. In the worst case (when the inputs are consecutive Fibonacci numbers), the number of iterations is proportional to the number of digits of the smaller number.

// t.c-O(nlogn)(for sorting)+O(log(nums[0]))(for gcd calculating)
// s.c-O(1)
int findgcd(vector<int> &nums)
{
  int n = nums.size();
  // we sort to get mini and maxi elt
  sort(nums.begin(), nums.end());
  return __gcd(nums[0], nums[n - 1]);
}

// solution II
// t.c-O(n)(for getting mini and maxi)+O(log(mini))(for gcd calculation)
// s.c-O(1)
int findGcd(vector<int> &nums)
{
  int n = nums.size();
  int mini = nums[0], maxi = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > maxi)
      maxi = nums[i];
    else if (nums[i] < mini)
      mini = nums[i];
  }
  return __gcd(mini, maxi);
}

// solution III
// t.c-O(n)+O(mini)
// s.c-O(1)
int findGCD(vector<int> &nums)
{
  int n = nums.size();
  int mini = nums[0], maxi = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > maxi)
      maxi = nums[i];
    else if (nums[i] < mini)
      mini = nums[i];
  }
  int gcd = 1;
  for (int i = 2; i <= mini; i++)
  {
    if (mini % i == 0 && maxi % i == 0)
      gcd = i;
  }
  return gcd;
}

// or we can find gcd by recursive or Eucledian solution
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << findgcd(nums) << endl;
  cout << findGcd(nums) << endl;
  cout << findGCD(nums) << endl;
  return 0;
}