// You are given an array of positive integers nums, and a positive integer k.

// You are allowed to perform an operation once on nums, where in each operation you can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty.

// You need to find the x-value of nums, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x when divided by k.

// Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.

// A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

// A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

// Note that the prefix and suffix to be chosen for the operation can be empty.

// Example 1:

// Input: nums = [1,2,3,4,5], k = 3

// Output: [9,2,4]

// Explanation:

// For x = 0, the possible operations include all possible ways to remove non-overlapping prefix/suffix that do not remove nums[2] == 3.
// For x = 1, the possible operations are:
// Remove the empty prefix and the suffix [2, 3, 4, 5]. nums becomes [1].
// Remove the prefix [1, 2, 3] and the suffix [5]. nums becomes [4].
// For x = 2, the possible operations are:
// Remove the empty prefix and the suffix [3, 4, 5]. nums becomes [1, 2].
// Remove the prefix [1] and the suffix [3, 4, 5]. nums becomes [2].
// Remove the prefix [1, 2, 3] and the empty suffix. nums becomes [4, 5].
// Remove the prefix [1, 2, 3, 4] and the empty suffix. nums becomes [5].
// Example 2:

// Input: nums = [1,2,4,8,16,32], k = 4

// Output: [18,1,2,0]

// Explanation:

// For x = 0, the only operations that do not result in x = 0 are:
// Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
// Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
// Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
// For x = 1, the only possible operation is:
// Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
// For x = 2, the possible operations are:
// Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
// Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
// For x = 3, there is no possible way to perform the operation.
// Example 3:

// Input: nums = [1,1,2,1,1], k = 2

// Output: [9,6]

// Constraints:

// 1 <= nums[i] <= 10^9
// 1 <= nums.length <= 10^5
// 1 <= k <= 5

#include <bits/stdc++.h>
using namespace std;

// first we understand the problem:
// What does the operation mean?
// suppose we have: nums=[1,2,3,4,5]
// In one operation, we can:
// remove some elements from the front (prefix)
// remove some elements from the back (suffix)
// but you cannot remove everything
// so some continuous subarray must remain

// If we remove:
// prefix=[1,2]
// suffix=[4,5]
// then the remaining array is: [3]

// So every possible operation corresponds to choosing one non-empty contiguous subarray.

// Importang think:
// Instead of thinking: "Which prefix and suffix should I remove?"
// We have to think: "Which non-empty subarray should remain?"

// For: nums=[1,2,3,4,5]
// some possible remaining subarrays are:
// [1]
// [2]
// [3]
// [4]
// [5]

// [1,2]
// [2,3]
// [3,4]
// [4,5]

// [1,2,3]
// [2,3,4]
// [3,4,5]

// [1,2,3,4]
// [2,3,4,5]

// [1,2,3,4,5]

// There are: (n)(n+1)/2 possible non-empty subarrays.
// For n=5: 5*6/2=15
// so there are 15 possible operations.

// What is the x-value?
// For every remaining subarray, calculate:
// product of its lets % k
// Then count how many times each remainder occurs.
// When we divide by k then possible remainders are 0..(k-1)
// The naswer array has size k, where result[0] represents no. of remainging subarray whose product of its elts % k = remainder=0 , similarly result[k-1] represents no. of remainging subarray whose product of its elts % k = remainder = k-1.

// for k=3 possible remainders are: 0,1,2
// so:
// result[0]= number of subarrays whose product % 3==0
// result[1] = number of subarrays whose product % 3 == 1
// result[2] = number of subarrays whose product % 3 == 2

// suppose we have : nums=[1,2,3,4,5] and k=3
// We need to consider all 15 subarrays.
// Length 1
// [1] → 1 % 3 = 1
// [2] → 2 % 3 = 2
// [3] → 3 % 3 = 0
// [4] → 4 % 3 = 1
// [5] → 5 % 3 = 2

// Counts so far:

// remainder 0 → 1
// remainder 1 → 2
// remainder 2 → 2
// Length 2
// [1,2] → 1×2 = 2 → 2 % 3 = 2

// [2,3] → 2×3 = 6 → 0

// [3,4] → 3×4 = 12 → 0

// [4,5] → 4×5 = 20 → 2

// Add:

// 0 → 2 more
// 1 → 0
// 2 → 2 more

// Now:

// 0 → 3
// 1 → 2
// 2 → 4
// Length 3
// [1,2,3]
// product = 6
// 6 % 3 = 0

// [2,3,4]
// product = 24
// 24 % 3 = 0

// [3,4,5]
// product = 60
// 60 % 3 = 0

// Now:

// 0 → 6
// 1 → 2
// 2 → 4
// Length 4
// [1,2,3,4]
// product = 24
// 24 % 3 = 0

// [2,3,4,5]
// product = 120
// 120 % 3 = 0

// Now:

// 0 → 8
// 1 → 2
// 2 → 4
// Length 5
// [1,2,3,4,5]
// product = 120
// 120 % 3 = 0

// Final:

// 0 → 9
// 1 → 2
// 2 → 4

// Therefore:

// result = [9,2,4]

// explanation of questions example
// Why does result[0]=9?
// Notice that every subarray containing 3 has product divisible by 3.
// There are 9 subarrays containing index of 3:
// [3]

// [2,3]
// [3,4]

// [1,2,3]
// [2,3,4]
// [3,4,5]

// [1,2,3,4]
// [2,3,4,5]

// [1,2,3,4,5]
// Therefore: result[0]=9
// This is exactly What the explanation means by:
// "possible operations include all possible ways to remove prefix/suffix that do not remove nums[2]==3"
// here nums[2]is 3.

// Understanding their explanation for x=1
// They say: remove the empty prefix and the suffix[2,3,4,5].
// Original=[1,2,3,4,5]
// remove:
// prefix=[]
// suffix=[2,3,4,5]
// remaining: [1]
// product=1
// so: 1%3=1
// therefore this contributes to: result[1]

// second: remove prefix [1,2,3] and suffix [5]
// so remaining=[4]
// product=4
// so: 4%3==1
// so this is another contribution to result[1]
// therefore: result[1]=2

// understanding x=2
// They give four examples:
// case1: remove empty prefix and suffix [3,4,5]
// remaining=[1,2]
// product=2
// so: 2%3=2

// Case2: remove prefix [1] and suffix [3,4,5]
// remaining: [2]
// product=2
// so: 2%3=2

// case3: remove prefix [1,2,3] and suffix empty
// remaining:[4,5]
// product=20
// so: 20%3=2

// case4: rmeove prefix [1,2,3,4] and suffix empty
// remaining: [5]
// product=5
// so: 5%3==2

// so there are 4 subarrays giving remainder 2:
// [1,2]
// [2]
// [4,5]
// [5]
// hence: result[2]=4

// We can completely reframe the problem as:

// Find the product modulo k of every non-empty contiguous subarray, and count how many subarrays produce each remainder.

// So the originally wording about removing prefixes and suffixes is basically another way of saying: Choose any non-empty contiguous subarray.

// for example: nums=[1,2,3,4,5]
// choose: [2,3,4]
// is equivalent to:
// remove prefix=[1]
// remove suffix=[5]

// the only requirement is : remaining subarrays is not empty
// SO if n=5, the 15 possible remaining subarrays are exactly the 15 possible operations.

// What do we ultimately need to calculate?

// For every subarray: nums[l....r]

// calculate: product(nums[l...r])%k

// and increment
// result[remainder]++

// for example: nums=[1,2,3,4,5], k=3
// we eventually get: remainder: 0,1,2
// so result size=3 with result[0],result[1],result[2]
// and we get result=[9,2,4] where result[0]=9,result[1]=2,result[2]=4
// and notice: 9+2+4=15 which equals the total number of non-empty subarrays: 5*6/2

// so our brute force is to generate all non-empty subarrays and calculate product of them then %k and increments result[remainder]++

// brute force: generate all subarrays:

// t.c-O(n^2)
// s.c-O(k)result array

vector<long long> resultArray(vector<int> &nums, int k)
{
  int n = nums.size();
  vector<long long> result(k);
  // generate all non-empty subarrays
  for (int i = 0; i < n; i++)
  {
    long long product = 1;
    for (int j = i; j < n; j++)
    {
      product *= nums[j];
      long long remainder = product % k;
      result[remainder]++;
    }
  }
  return result;
}

// brute force gives signed integer overflow for very large integer multiplication

// the problem in brute force is that we repeatedly calculate products for many subarrays, giving O(n^2) subarrays

// The DP idea is: instead of explicitly storing every subarray, store how many subarrays ending at the current index have each possible remainder.

// optimized solution:
// Hint 1
// Use dynamic programming.
// Hint 2
// Define dp[i][r] as the count of subarrays ending at index i whose product modulo k equals r.
// Hint 3
// Compute dp[i][r] for each index i in nums and sum over all indices to get the final counts for each remainder.

// Hint:
// when an array product is P and remainder is r when divided by k (i.e P%k=r) and now if we add an element x in the array then the new remainder becomes r*(x%k)%k

// using the above formula we can make a transition at each index to extend a subarray from previous index which has a remainder of j and after extending the remainder becomes j*(nums[i]%k)%k

// What does dp[i][r] mean?
// dp[i][r] means Number of subarrays ending at index i whose product%k==r

// let's say we have nums=[1,2,3], k=3
// at index=0: the only subarray ending at index 0 is: [1]
// product=1
// remainder: 1%3==1
// therefore: dp[0][1]=1
// and dp[0]=[0,1,0]
// meaning:
// remainder 0: 0 subarrays
// remainder 1: 1 subarray
// remainder 2: 0 subarrays

// now index=1: we have: [1,2]
// subarrays ending at index 1 are:
// [2]
// [1,2]

// Lets' calculate:
// [2]: product=2, remainder=2%3=2
// [1,2]: product=2,remainder=2
// so: dp[1]=[0,0,2]
// There are 2 subarrays ending at index1, and both have remainder 2.

// But how can we get this from the previous Dp instead of explicitly generating [2] and [1,2]?

// Where does the transition come from?
// Suppose we already know: dp[i-1][r] which represents subarrays ending at i-1.

// Now we add: nums[i] to the end of every one of those subarrays.
// for example: at index 1:
// previous subarray: [1]
// its remainder is : 1
// Adds nums[1]=2:
// [1]->[1,2]
// New product remainder: (1*2)%3=2
// so: dp[0][1]=1
// contributes to: dp[1][2]
// means only remainder change but we get number of subarrays that we have previous so we have add nums[i] in them and we have these subarrays upto index i also with new remainder

// But there's one more subarray
// When we are at index i, there is always a new subarray consisting of only nums[i].
// AT index 1: [2]
// its remainder is: 2%3=2
// so we add: dp[1][2]++
// Therefore: dp[1][2]=2
// One comes from: [2]
// and one comes from:[1,2]

// DP transition:
// Suppose: dp[i-1][r]=count
// These are subarrays ending at i-1 with product remainder r.

// When we append nums[i]:
// new product=old product*nums[i]
// Therefore: new remainder=(r*nums[i])%k
// so: dp[i][newRemainder]+=dp[i-1][r]; because we add nums[i] in all subarrays that at index i-1 so count of subarrays that at index i = count of subarrays at index i-1 by appending i with one more separately subarray [nums[i]] only so when we take count of subarrays ending at index i-1 so by appending nums[i] remainder only change count remain same
// And separately: dp[i][nums[i]%k]++   because [nums[i]] is a new subarray

// let's do the complete example:
// nums=[1,2,3]
// k=3

// i=0: single elt:[1]
// 1%3=1
// so: dp[0]=[0,1,0]

// i=1:
// start with the single elt subarray:[2]
// 2%3=2
// so initially: dp[1]=[0,0,1]
// Now take every remainder from dp[0]
// we have: dp[0][1]=1
// append 2: new remainder=(old remainder*nums[1])%k=(1*2)%3=2
// therefore:dp[1][2]+=1
// now: dp[1]=[0,0,2]
// these two are:
// [2]      → remainder 2
// [1,2]    → remainder 2

// i=2
// nums[2]=3
// first create the single elt subarray: [3]
// 3%3=0
// so initially: dp[2]=[1,0,0]
// Now process dp[1]: dp[1]=[0,0,2]
// We have 2 subarrays whose remainder is 2:
// [2], [1,2]
// append 3 to both:
// [2,3],[1,2,3]
// Their new remainder: (old remainder*nums[2])%k=(2*3)%3=0
// so: dp[2][0]+=2
// now: dp[2]=[3,0,0]
// These are: [3],[2,3],[1,2,3] all have product divisible by 3

// Where does the final result come from?
// The question doesn't only want subarrays ending at particular index.
// It wants all subarrays.
// So after calculating each dp[i], add it to result.
// for example:
// dp[0]=[0,1,0]
// dp[1]=[0,0,2]
// dp[2]=[3,0,0]
// Add them:
// result[0]=0+0+3=3
// result[1]=1+0+0=1
// result[2]=0+2+0=2
// Therefore: result=[3,1,2]
// Let's verify the 6 subarrays:

// [1]       → 1
// [2]       → 2
// [3]       → 0
// [1,2]     → 2
// [2,3]     → 0
// [1,2,3]   → 0

// Counts:

// 0 → 3
// 1 → 1
// 2 → 2

// t.c-O(n*k)
// s.c-O(n*k)(for dp)+O(k)(for result)
vector<long long> result_Array(vector<int> &nums, int k)
{
  int n = nums.size();
  // initially count =0
  vector<vector<long long>> dp(n, vector<long long>(k, 0));
  vector<long long> result(k, 0);

  for (int i = 0; i < n; i++)
  {
    // subarray containing only nums[i]
    int remainder = nums[i] % k;
    dp[i][remainder]++;
    // Extend all subarrays ending at i-1 by adding nums[i] in them
    if (i > 0)
    {
      // for all remainders
      for (int r = 0; r < k; r++)
      {
        if (dp[i - 1][r] == 0)
          continue;
        int newRemainder = (r * 1LL * (nums[i] % k)) % k;
        dp[i][newRemainder] += dp[i - 1][r];
      }
    }
    // add dp[i] to the final answer
    for (int r = 0; r < k; r++)
    {
      result[r] += dp[i][r];
    }
  }
  return result;
}

// we can make it O(k) memory
// because dp[i] only depends on dp[i-1] so we don't need the entire 2D array.
// so we do space optimization
// use:
// vector<long long>prev(k)
// vector<long long>curr(k);

vector<long long> ResultArray(vector<int> &nums, int k)
{
  int n = nums.size();
  // previous 1d array
  vector<long long> prev(k, 0);
  // answer array
  vector<long long> result(k, 0);
  for (int i = 0; i < n; i++)
  {
    // current 1d array
    vector<long long> curr(k, 0);
    // subarray containing only nums[i]
    int remainder = nums[i] % k;
    curr[remainder]++;
    // Extend all subarrays ending at i-1 by adding nums[i] in them means previous array
    // extend previous subarrays
    // for all remainders
    for (int r = 0; r < k; r++)
    {
      int newRemainder = (r * 1LL * (nums[i] % k)) % k;

      curr[newRemainder] += prev[r]; // means All the subarrays that ended at the previous index with remainder r can be extended by the current number. Their new remainder is newRemainder, so add their count there."
    }
    // add current subarrays to answer because we don't store all arrays
    for (int r = 0; r < k; r++)
    {
      result[r] += curr[r];
    }
    prev = curr;
  }
  return result;
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
  int k;
  cin >> k;
  // vector<long long> ans = resultArray(nums, k);
  //  vector<long long> ans = result_Array(nums, k);
  vector<long long> ans = ResultArray(nums, k);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}