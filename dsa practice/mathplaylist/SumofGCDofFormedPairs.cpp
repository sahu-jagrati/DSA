// You are given an integer array nums of length n.

// Construct an array prefixGcd where for each index i:

// Let mxi = max(nums[0], nums[1], ..., nums[i]).
// prefixGcd[i] = gcd(nums[i], mxi).
// After constructing prefixGcd:

// Sort prefixGcd in non-decreasing order.
// Form pairs by taking the smallest unpaired element and the largest unpaired element.
// Repeat this process until no more pairs can be formed.
// For each formed pair, compute the gcd of the two elements.
// If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
// Return an integer denoting the sum of the GCD values of all formed pairs.

// The term gcd(a, b) denotes the greatest common divisor of a and b.

// Example 1:

// Input: nums = [2,6,4]

// Output: 2

// Explanation:

// Construct prefixGcd:

// i	nums[i]	mxi	prefixGcd[i]
// 0	2	2	2
// 1	6	6	6
// 2	4	6	2
// prefixGcd = [2, 6, 2]. After sorting, it forms [2, 2, 6].

// Pair the smallest and largest elements: gcd(2, 6) = 2. The remaining middle element 2 is ignored. Thus, the sum is 2.

// Example 2:

// Input: nums = [3,6,2,8]

// Output: 5

// Explanation:

// Construct prefixGcd:

// i	nums[i]	mxi	prefixGcd[i]
// 0	3	3	3
// 1	6	6	6
// 2	2	6	2
// 3	8	8	8
// prefixGcd = [3, 6, 2, 8]. After sorting, it forms [2, 3, 6, 8].

// Form pairs: gcd(2, 8) = 2 and gcd(3, 6) = 3. Thus, the sum is 2 + 3 = 5.

// Constraints:

// 1 <= n == nums.length <= 10^5
// 1 <= nums[i] <= 10​​​​​​​^9

#include <bits/stdc++.h>
using namespace std;

// this problem done by me own without any hint
long long gcdSum(vector<int> &nums)
{
  int n = nums.size();
  // for 0th index max elt is itself so
  int mx = nums[0];
  vector<int> prefixGcd(n);
  prefixGcd[0] = __gcd(nums[0], mx); // built-in gcd function we used here
  for (int i = 1; i < n; i++)
  {
    // we have to take mx=max(nums[0],....,nums[i]) so if next elt is greater than current mx then mx update otherwise mx is same so
    if (nums[i] > mx)
      mx = nums[i]; // we check for each index
    prefixGcd[i] = __gcd(nums[i], mx);
  }
  sort(prefixGcd.begin(), prefixGcd.end());
  long long sum = 0;
  // as prefixGcd is now sorted so for pairing (smallest,largest) we use two pointers approach
  int i = 0, j = n - 1;
  // we go upton i<j not i<=j because we want pair of(smallest,largest) not for same index
  while (i < j)
  {
    long long gcd = __gcd(prefixGcd[i], prefixGcd[j]);
    sum += gcd;
    i++;
    j--;
  }
  return sum;
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
  cout << gcdSum(nums) << endl;
  return 0;
}