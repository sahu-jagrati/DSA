// given an array 'arr', partition it into two subsets(possible empty) such that their union is the original array. Let the sum of the elts of these two subsets be 'S1' and 'S2'.
// Given a difference 'D', count the number of partitions in which 'S1' is greater than or equal to 'S2' and the difference between 'S1' and 'S2' is equal to 'D'. Since the answer may be too large, return it modulo '10^9 +7'.

// If 'Pi_Sj' denotes the subset 'j' for partition 'i'. Then, two partitions P1 and P2 are considered different if:
// i) P1_S1 != P2_S1 i.e at least one of the elt sof P1_S1 is different from P2_S2.

// ii) P1_S1==P2_S2, but the indices set represented by P1_S1 != indices set of P2_S1. Here, the indices set of P1_S1 is formed by taking the indices of the elts from which the subset if formed.

// in simple way
// Given an array with N positive integers and an integer D, count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.

// examples-
// Input: arr = [1, 1, 2, 3], diff = 1
// Output: 3
// Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3].
// Input:  arr = [1, 2, 3, 4], diff = 2
// Output: 2
// Explanation: The subsets are [1, 3] and [2, 4], [1, 2, 3] and [4].

// so basically we have an array and we divide the array into two subsets so
// the sum of elts of subset1 is S1 and the sum of elts of subset2 is S2 such that S1>=S2 and S1-S2=D where D is the given difference so we have to count how many different subsets can you divide them into such that this is above mention is true.

// example-arr={5,2,6,4} and D=3
// so if I divide array into two subsets then possiblility can be
// i) subset1-{6,4} with S1=10 and subset2={5,2}with S2=7 so S1-S2=10-7=3=D

// it is similar to problem PartitionEqualSubsetSum only difference here is we have to check S1-S2=D where S1>=S2

// now what is the problem telling us to? problem telling is to find how many subsets are there which have a difference S1-S2=D where S1>=S2

// so can I say that S1=totalSum-S2 where totalSUm is the sum of elts of an given array so S1+S2=totalSum so S1=totalSum=S2
// as S1-S2=D then it become totalSum-S2-S2=D which is become totalSum-D=2*S2 which is also become S2=(totalSum-D)/2 so can I say I'm looking for subsets which are having summation as (totalSum-D)/2 so the question now become countSubSets whose sum is (totalSum-D)/2 which we done in the problem CountsSubsetsWithSumK here k=(totalSum-D)/2 and here nums[i]>=0 so we used 0 include problem which we done in CountsSubsetsWithSumKII

// but do we have edge cases yes we definitely know that the constraints told us that the numbers will be like 0<=nums[i] so we know one thing for sure that (totalSum-D) cannot go negative it has to  be greater than equal to zero that's one of the cases that (totalSum-D)>=0 why because if i'm looking for a sum and that's what is the sum? this sum is sum of a subset so if it's a subset and the nums[i]>=0 then how can a sum of a subset be negative thereby this (totalSUm-D)>=0 and you're dividing by 2 so again there is no fractions because all the numbers as nums[i]>=0 all are integers so so if all are integers you can't have a decimal right thereby the other edge case would be (totalSum-D)%2==0 i.e  has to be even

// so there are two edge cases
// i) (totalSum-D)>=0
// ii) (totalSum-D)%2==0 so just check for these couple of cases and then the question becomes the countsSubsetsWithSumKII where k=(totalSum-D)/2 because here also 0 is include in an array

// now solve

#include <bits/stdc++.h>
using namespace std;

// Since the answer may be too large, return it modulo '10^9 +7'.
int mod = (int)(1e9 + 7);

// recursion
// copy the code of problem countsSubsetsWithSumKII because here also 0 is include in an array

// you can write target or sum also
int f1(int index, int target, vector<int> &arr)
{
  // base case when 0 also include in an array
  if (index == 0)
  {
    // i)
    if (target == 0 && arr[0] == 0)
      return 2;
    // ii) and iii) combine
    if (target == 0 || arr[0] == target)
      return 1;
    // in other case
    return 0;
  }
  // if we don't take that elt
  int notPick = f1(index - 1, target, arr);
  // if we take that elt but before that we have to check that elt is enough or not
  int pick = 0;
  if (arr[index] <= target)
    pick = f1(index - 1, target - arr[index], arr);

  // // Since the answer may be too large, return it modulo '10^9 +7'.
  return (pick + notPick) % mod; // return total count subsets with sum=target
}

// memoization
// recursion
// copy the code of problem countsSubsetsWithSumKII because here also 0 is include in an array
int f2(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  // base case
  if (index == 0)
  {
    // i)
    if (target == 0 && arr[0] == 0)
      return 2;
    // ii) and iii) combine
    if (target == 0 || arr[0] == target)
      return 1;
    // in other case
    return 0;
  }

  if (dp[index][target] != -1)
    return dp[index][target];

  int notPick = f2(index - 1, target, arr, dp);
  int pick = 0;
  if (arr[index] <= target)
    pick = f2(index - 1, target - arr[index], arr, dp);

  // // Since the answer may be too large, return it modulo '10^9 +7'.
  return dp[index][target] = (pick + notPick) % mod;
}

// tabulation
int f3(vector<int> &arr, int n, int sum) // sum is k which is given
{
  vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
  // base case
  if (arr[0] == 0)
    dp[0][0] = 2; // when index =0 and target=arrr[0]=0 so return 2
  else
    dp[0][0] = 1; // arr[0] anything !=0 and target(sum)=0 so not pick
  if (arr[0] != 0 && arr[0] <= sum)
    dp[0][arr[0]] = 1;

  // index is from 1 to n-1 becasue we already done with index=0
  for (int index = 1; index < n; index++)
  {
    // in this here target go from 0 to sum
    // and target(i.e sum) is from 0 to k(i.e sum) and we already done with target=0
    for (int target = 0; target <= sum; target++)
    {
      int notPick = dp[index - 1][target];
      int pick = 0;
      if (arr[index] <= target)
      {
        pick = dp[index - 1][target - arr[index]];
      }
      // // Since the answer may be too large, return it modulo '10^9 +7'.
      dp[index][target] = (pick + notPick) % mod;
    }
  }

  return dp[n - 1][sum];
}

// space optimization
int f4(vector<int> &arr, int n, int sum)
{
  vector<int> prev(sum + 1, 0);
  if (arr[0] == 0)
    prev[0] = 2; // because arr[0]=sum=0 so return 2 because we have two options discuss above
  else
    prev[0] = 1;
  if (arr[0] != 0 && arr[0] <= sum)
    prev[arr[0]] = 1;

  // same as tabulation we do
  for (int index = 1; index < n; index++)
  {
    vector<int> curr(sum + 1, 0);
    curr[0] = 1; // when sum=0/ target=0
    // in this problem here target go from 0 to sum
    for (int target = 0; target <= sum; target++)
    {
      int notPick = prev[target];
      int pick = 0;
      if (arr[index] <= target)
      {
        pick = prev[target - arr[index]];
      }
      // // Since the answer may be too large, return it modulo '10^9 +7'.
      curr[target] = (pick + notPick) % mod;
    }
    prev = curr;
  }
  return prev[sum];
}
int findWays(vector<int> &arr, int target)
{
  int n = arr.size();
  // recursion
  // return f1(n - 1, target, arr);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
  // return f2(n - 1, target, arr, dp);

  // tabulation
  // return f3(arr, n, target);

  // space optimization
  return f4(arr, n, target);
}
// where d is given difference
// time complexity and space complexity remains same as of earlier version of this  problem
int countPartitions(int n, int d, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += arr[i];

  if ((totalSum - d) < 0 || ((totalSum - d) % 2) != 0)
    return false;

  return findWays(arr, (totalSum - d) / 2);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int d;
  cin >> d;
  cout << countPartitions(n, d, arr);
  return 0;
}