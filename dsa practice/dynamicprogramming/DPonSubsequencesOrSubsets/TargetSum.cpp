// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

// as we already done with dp of subsequences that let apply recursion and call f(index,target) and there will be a couple of possibilities either assign positive or either assign negative and keep on doing recursion  but can we do something better because yeah you can definitely write a recursion which is like you take couple of ways basically saying like this f(index,target) and there'll be a couple of ways where you assign the plus sign, the negative sign and since the question says count the number of ways you return sum(plus and negative) that is the common recurrence that we can do but can we solve this using any of the problem that we have solved previously because we solve the problems previously like subsetSum and countPartitionsWIthGivenDifference(S1-S2=d)

// like assume we have arr=[1,2,3,1] and target=3
// if we assign positive and negative sign like this: -1+2+3-1=3+2-1-1=3 so can I say I am assigning some portion to a subset s1 whish is [3,2] an then if I take a negative common I am assigning [1,1] to a subset S2 right thereby the summation  S1 is 5 and the summation S2 is 2 and the difference is S1-S2=5-2=3 which is the question that we have to solve in this problem so we done with solving this now so we have already done a problem where we say that given an array divide them into subsets such that first subset has subset sum S1 and second subset has subset sum S2 and if you take difference S1-S2 =D you have to count these many guys and we have already done this problem in countPartitionWithGivenDifference so the given question is exactly similar to this. only they have just changed the language. question is similar that divide the array into two partition and take S1-S2=target so we done this given problem with the previous solved problem and I know one of the subsets will have all the positive elts and the other subset will always have all the negative elts so if I'm  able to do that I think we will be able to solve this particular problem

// so let's code

#include <bits/stdc++.h>
using namespace std;

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
      curr[target] = (pick + notPick);
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

int countPartitions(int n, int d, vector<int> &arr) // where d is target
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += arr[i];

  if ((totalSum - d) < 0 || ((totalSum - d) % 2) != 0)
    return false;

  return findWays(arr, (totalSum - d) / 2);
}
// I just copy here the space optimization code of countPartitionsWithGivenDifference and for tabulation,memoization, recursion see in that file
int targetSum(int n, int target, vector<int> &arr)
{
  // so we call
  return countPartitions(n, target, arr);
}

// so this is the exactly the same question to countPartitionsWithGivenDifference only they change the language to confuse.
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  cout << targetSum(n, target, arr);
  return 0;
}