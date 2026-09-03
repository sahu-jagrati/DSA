// You are given an array(0-based indexing) of positive integers and you have to tell how many different ways of selecting the elts from the array are there such that the sum of chosen elts is equal to the target number 'k'.

// Two subsets are considered different if sets of indexes of elts chosen by these subsets are different.

// Input is given such that the answer will fit in a 32-bit integer.

// Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K.

// Input: arr = [1, 2, 2, 3], K = 3
// Output: 3
// we can have the following subsets with target sum of 3
// [1,2]-[arr[0],arr[1]], [1,2]-[arr[0],arr[2]], [3]-arr[3]
// total count of subsets-3

// Input: arr = [1, 2, 3, 4, 5], K = 5
// Output: 3
// Explanation: The subsets are [5], [2, 3], and [1, 4].

// constraints:
// 1<=n<=100
// 1<=nums[i]<=1000
// 1<=tar<=1000

// for solving this problem we already know about the problem subsetSumEqualToTarget where we check is there exist a subset with sum=target and here in this problem we have to count number of subsets with sum=target.

// whenever there is a problem related to count you write the function and in the base case whatever is the condition if the condition is satisfying you return one and if the condition is not satisfying you return zero this will always be done in all the count problems and what did i tell you if there are multiple function calls then all the function calls addition will be the number of ways that will be returned, count the number of ways always in the base case there will be return one or return zero because you're basically trying out every possible choices and at the end of the day they will tell you if it's possible or if it's not possible and these are the ways you basically add up all the ways and you return that.

// write the recurrence and what are the rules to write the recurrence

// rules to write the recurrence-

// 1.  express the recurrence in terms of indexes
// because it's the array it will be array index and what are we looking for we are looking for a specific target so we are looking for something right so that something will also be part so that's a thumb rule like always express everything in terms of indexes it can be grids it can be 1d array it can be 2d it can be 3d the thumb rule is the first parameter will always like you'll see in almost all the cases it will be indexes and the other one over here since the question is revolving around target it will be target so your recurrence will be expressed in terms of index and target

// f(index,target) and it signify that  till  index how many subsequences are there which will give you a sum =target

// 2. explore all possibilities
// there are two possibilites that - i) pick the elt ii) notpick the elt
// 3. sum all of the possibilities and return because the question stated count the total number of ways

// this question is same of subsetSumEqualToTarget instead of checking we have to count total subset in subsetSumEqualToTarget we do take||notTake so here we do take+notTake and all are same

// so base case is-
// i) if target==0 return true in that problem so here we return 1
// ii) if index==0 return arr[0]==target same here also

// and all the things are same- take and notTake
// return take+notTake

#include <bits/stdc++.h>
using namespace std;

// recursion- same as the problem subsetSumEqualToTarget so see that problem, only difference is we have to return all subsets with sum=target so we do addition here instead of return bool we return int
// // t.c for recursion - O(2^n) because for every array element you have couple of options either you take that element into consideration or you say i'm not going to take this element so you just have couple of considerations

// s.c for recursion-O(n) auxiliary stack space

// recursion here we do top-down approach from index (n-1 to 0)
// almost all problems in all the index problems either if you're starting from the back it's going to be index equal to equal to 0 or if you're starting from the front it's going to be the last index that's what the base case will be

// you can write target or sum also

int f1(int index, int target, vector<int> &arr)
{
  // base case-
  // i) if target==0
  if (target == 0)
    return 1; // any index can be
  // ii) if index==0
  if (index == 0)
  {
    return (arr[0] == target); // so it return 1 if it is or return 0 if it is not
  }
  // if we don't take that elt
  int notPick = f1(index - 1, target, arr);
  // if we take that elt but before that we have to check that elt is enough or not
  int pick = 0;
  if (arr[index] <= target)
    pick = f1(index - 1, target - arr[index], arr);

  return pick + notPick; // return total count subsets with sum=target
}

// we know there will be overlapping subproblems so we do memozation
// memoization also same to that problem subsetSumEqualToTarget so see that problem, only difference is we have to return all subsets with sum=target so we do addition here instead of return bool we return int

// // the first thing is figure out the changing states so there is an index and there is a sum that might change
// we initialized with dp matrix of size n*(k+1) where k is given sum
// dp[n][k+1] with value -1 and it is a int matrix
// index go from (0 to n-1)
// target go from (0 to k)

// you can write target or sum also

// t.c-O(n*sum(i.e k))
// s.c-O(n*sum)(for dp)+O(n)(for auxiliary stack space)

int f2(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  // base case
  // i) target==0
  if (target == 0)
    return dp[index][target] = 1; // any index can be
  // ii) if index==0
  if (index == 0)
    return dp[index][target] = (arr[0] == target);

  if (dp[index][target] != -1)
    return dp[index][target];

  int notPick = f2(index - 1, target, arr, dp);
  int pick = 0;
  if (arr[index] <= target)
    pick = f2(index - 1, target - arr[index], arr, dp);

  return dp[index][target] = pick + notPick;
}

// tabulation- in recursion we go top-down so in tabulation we do bottom-up same as problem subsetSumEqualToTarget so see that problem, only difference is we have to return all subsets with sum=target so we do addition here instead of return bool we return int

// t.c-O(n*sum)
// s.c-O(n*sum) for dp

int f3(vector<int> &arr, int n, int sum) // sum is k which is given
{
  vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
  // base case
  // i) target(i.e sum)==0 so any index it can be
  for (int i = 0; i < n; i++)
    dp[i][0] = 1; // means true
  // ii) if index=0
  if (arr[0] <= sum)
  {
    dp[0][arr[0]] = 1; // index=0
  }

  // index is from 1 to n-1 becasue we already done with index=0
  for (int index = 1; index < n; index++)
  {
    // and target(i.e sum) is from 1 to k(i.e sum) and we already done with target=0
    for (int target = 1; target <= sum; target++)
    {
      int notPick = dp[index - 1][target];
      int pick = 0;
      if (arr[index] <= target)
      {
        pick = dp[index - 1][target - arr[index]];
      }
      dp[index][target] = pick + notPick;
    }
  }
  return dp[n - 1][sum];
}

// space optimization also same as problem subsetSumEqualToTarget so see that problem, only difference is we have to return all subsets with sum=target so we do addition here instead of return bool we return int

// t.c-O(n*sum)
// s.c-O(sum) for prev and curr array

int f4(vector<int> &arr, int n, int sum)
{
  vector<int> prev(sum + 1, 0);
  // target(i.e sum)=0 return 1 means true
  prev[0] = 1;
  // if first element <= k, mark true(i.e 1) because we go bottom-up
  if (arr[0] <= sum)
    prev[arr[0]] = 1;

  // same as tabulation we do
  for (int index = 1; index < n; index++)
  {
    vector<int> curr(sum + 1, 0);
    curr[0] = 1; // when sum=0/ target=0
    for (int target = 1; target <= sum; target++)
    {
      int notPick = prev[target];
      int pick = 0;
      if (arr[index] <= target)
      {
        pick = prev[target - arr[index]];
      }
      curr[target] = pick + notPick;
    }
    prev = curr;
  }
  return prev[sum];
}

int countSubsetWithSumK(vector<int> &arr, int n, int sum)
{
  // reucrsion
  return f1(n - 1, sum, arr);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  // return f2(n - 1, sum, arr, dp);

  // tabulation
  // return f3(arr, n, sum);

  // space optimization
  // return f4(arr, n, sum);
}

// The test case {0,0,1} has been explained in problem countSubsetWithSumKII
// if here we check the testcase {0,0,1} with sum=1 then it give answer=1 but ideally answer is 4 subsets how? - subsets can be - {0,1}(first zero ,1),{0,1}(second zero ,1),{1},{0,0,1} here it give answer=1 because the solution we write is not considered 0 as array elt because in constraint nums[i]>=1 and nums[i]<=1000 so 0 is not include so it give that answer and our solution also not considered 0 that's why but now how would you solve this problem if i change the constraints like 0<=nums[i]<=1000 means if 0 can also be an array elt then how we get total no. of subsets with sum=k this problem is solved in countSubsetWithSumKII
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int sum;
  cin >> sum;
  cout << countSubsetWithSumK(arr, n, sum);
  return 0;
}

// if our array has negative integers also then we use hashmap<key,value> instead of dp to store negative sum