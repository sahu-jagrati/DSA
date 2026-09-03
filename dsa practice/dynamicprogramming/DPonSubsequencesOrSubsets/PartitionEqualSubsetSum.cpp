// you are given an array 'arr' of 'n' positive integers. your task is to find if we can partition the given array into two subsets such that the sum of elts in both subsets is equal.

// example-let's say the given array is [2,3,3,3,4,5], then the array be partitioned as [2,3,5] and [3,3,4] with equal sum 10.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

// in question SubsetSumEqualToK- we solve it in that we have to find a subset with a given target if it is exist then return true or else false

// now here in this question we want exactly two subsets such that sum of subset1(s1) ==  sum of subset2(s2)

// we say the entire given array sum is S and we are dividing them into two blocks then one of the block(subset) will have sum as S1 and other one subset have sum S2 and I know S1=S2=(S/2) where S is the total sum
// so we have figured out that we need to make sure that the subset has to have a sum of S/2.

// the first thing is very sure if S is having an odd sum then the division is not possible because you cannot have an odd sum divided into two subsets with equal sum that is definitely not possible so if it is odd it's not possible

// now if S is an even sum then what is the problem can I say I'm looking for a subset with a sum S/2 then you will can be say like if I'm looking for a subset then how will I get the second subset? if one subset we got as S/2 then the remaining elts are bound to give you the remaining sum which is (S-S/2)=S/2 so you'll get a remaining sum as S/2 also.

// so I just need to check if I can get one subset because if I can get one subset then automatically means I can get the second subset as well

// so we have an array we find the entire sum of an array and then check if I can get subset with sum S/2 and we do this problem of checking SubsetsumequalToK as previous. So you just check if S is odd then return false or if S is even then take target=S/2 and do the problem SubsetSumequalToK

#include <bits/stdc++.h>
using namespace std;

// I am writing here only space optimization code of SubsetSumequalToK for recursion,memoization or tabulation see code of this in it's file
bool subsetSumToK(int n, vector<int> &arr, int k)
{
  // prev row
  vector<bool> prev(k + 1, false);
  // Base case: target 0 can always be formed by empty subset
  prev[0] = true; // when target =0 so it is true

  // Base case: if first element <= k, mark true
  if (arr[0] <= k)
  {
    prev[arr[0]] = true;
  }
  // Iterate over all elements from second to last
  for (int index = 1; index < n; index++)
  {
    vector<bool> curr(k + 1, false);
    curr[0] = true; // when target=0 then always true
    for (int target = 1; target <= k; target++)
    {
      bool notTake = prev[target]; // means from index-1 which is prev
      bool take = false;
      if (arr[index] <= target)
      {
        take = prev[target - arr[index]]; // means from index-1 which is prev
      }
      curr[target] = take || notTake; // update current row which is index
    }
    prev = curr;
  }
  return prev[k]; // which is index-1 of k
}

// t.c-O(n)(for totalSum)+O(n*target)(for check subsetSumToK)
// s.c-O(target)(for prev and curr array in subsetSumToK chcek fuction)
bool canPartition(vector<int> &nums)
{
  int n = nums.size();
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += nums[i];
  if (totalSum % 2 != 0)
    return false; // when S is odd so we can't divide into two subsets with equal sum
  int target = totalSum / 2;
  return subsetSumToK(n, nums, target);
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
  cout << canPartition(nums);
  return 0;
}