// Partition a set into two subsets such that the difference of subset sums is minimum.

// You are given an array containing 'n' non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.

// You just need to find the minimum absolute difference considering any valid division of the array elts.

// Input: nums = [1, 2, 3, 4]
// Output: 0
// Explanation: Two subsets can be [1,4] and [2,3].
// minimum absolute difference =abs((1+4)-(2+3))=0

// Input: nums = [8, 6, 5]
// Output: 3
// Explanation: Two subsets can be [8] and [6, 5].
//  minimum absolute difference =abs((8)-(6+5))=3

// previously we done the problem - SubsetSumEqualToTarget in that we check in a given array is there exists a subset with sum equal to target(k).

// here in this problem we have an array and we have to divide that arrau into two subsets such that the absolute difference between subset sums is minimum and subsets can be of anysize but < n(size of an entire array).

// in previous problem SubsetSumEqualToTarget we do
// f(index,target) in recursion top-down so it's f(n-1,target(k))
// and this is a recursive solution of that problem
// f(index,target){
//   if(target==0)return true;
//   if(arr[0]<=target)return arr[0]==target;

//   bool notTake=f(index-1,target);
//   bool take=false;
//   if(arr[index]<=target)take=f(index-1,target-arr[index]);

//   return take||notTake;
// }  // and we call the recursion with f(n-1,k) where k is given target in that problem

// and it's tabulation solution is this
// f(n,arr,k){
// vector<vector<bool>>dp(n,vector<bool>(k+1,false));
// // target==0
// for(int index=0;index<n;index++)dp[index][0]=true;
// // index==0
// if(arr[0]<=k)dp[0][arr[0]]=true;
// for(int index=1;index<n;index++){
//   for(int target=1;target<=k;target++){
//     bool notTake=dp[index-1][target];
//     bool take=false;
//     if(arr[index]<=target)take=dp[index-1][target-arr[index]];
//     dp[index][target]=take||notTake;
//   }
// }
// return dp[n-1][k];
// }

// this above is the tabulation solution of the problem SubsetSumEqualToTarget

// now what does a dp[i][j] signify
// let's assume n=5 and target=7
// so dp[5][7+1]=dp[5][8]=dp[n][k+1]
// so rows=5 and columns=8
// now can you tell me where did you find your answer at the end of the day
// you said you call the recurrence f(n-1,target) and you said can an array of n-1 ending at n-1 achieve target can this entire array achieve this target so you also said that the answer will be lying at dp[n-1][target] so what does this mean you are saying for this if n=5 and target=7 you are saying if dp[4][7] == true then we can have a subset sum of target=7 so can i say how's the dp array being filled in tabulation form, firstly all the base cases are filled.

// so if dp array is like
// index- 0   1   2   3   4   5   6   7    - k+1
//   0    T   T
//   1    T
//   2    T
//   3    T
//   4    T

//   n       // T means true

// what are the base cases? if target==0 and any index it is true and second is - if(arr[0]<=target)dp[0][arr[0]]=true so if arr=[1,3,2,5,6] and target=7
// and rest of the cells are filled by using tabulation code and whatever is filled at dp[4][7] is our answer it can be true or false but in finding the target=7 if you are write the tabulation you end up filling this dp[4][0] because at the index 4 like in the entire array the target 0 can be achieved because if I don't pick up any elt in the subset the target 0 can be achieved similarly whatever value will be at dp[4][1] I can say I can cahieve the target 1 or I cannot achieve the target 1 because it can be true or false, similarly whatever value is at dp[4][2] I can say I can achieve the target 2 or I cannot achieve the target 2, similarly at dp[4][3] I can say I can achieve the target 3 or I cannot achieve the target 3, so can I say I can tell yes or no for every target value from (1 to 7) can I achieve every target value from 1 to 7 I can definitely say yes or no if I write the tabulation because the tabulation makes sure that I fill the entire matrix and eventually I will get to know if I can achieve 1 if I can achieve 2 if I can achieve 3 if I can achieve 4 if I can achieve 5 if I can achieve 6 if I can achieve 7 and just because the question asked target=7 so we pick up the dp[4][7] and we said this is our answer it can be T/F if the target was like if someone comes up and gives you are a different target now you still can say without calling the tabulation again, the last array of dp matrix  will strictly help you to tell if you can achieve target 5 or not or if you can achieve target 6 or not this is what tabulation signifies. for here if dp[3][4] so  index =3 means till only the index - 3 a target of four can be achieved or not. this is signifying by the third row(index=3) similarly every row is signifying something.

// as of now from subsetSum what we have derived - from subsetSum the tabulation derived we can like if we check for a target=k we can derive if every possible target between (1 & k) is possible or not possible. if I'm just checking for target=k the tabulation automatically will tell me for every value between 1 to k I don't need to do any extra steps so with the help of this we solve our given problem partition a set into two subsets with minimum absolute difference.

// the given problem state that divide the array into couple of subsets like the absolute difference between subset sums is minimum.
// one subset with sum is S1 and the other subset with sum is S2, we want min(abs(S1-S2))

// so how can be solve this because we have just now learned that we can easily check if any subset of any given sum is possible in an array or not with the use of the matrix. So can I say if I can just figure out S1,  I don't have to figure out S2 why?

// let's examine this given an array - [3,2,7] and if I say one of the partition contains-[3] so the summation is 3 . Do I need to find the other partition like [2,7] and do the summation as 9 do I need that? the answer to that is no why? because if I know the total sum over here the total sum is 12 so can I say the summation is 3 for the first partition, the summation for the next partition will be (total sum of an array - the sum of the elts of first partition) so S2=12-3=9 where 12 is the total sum of an given array elts and 3 is the summation of first partition.Can I say if I take 2 as a first partition then S1=2 then S2=12-2=10, so what am I looking for abs(S1-S2) to be as minimum as possible, so  do we actually require all the possible if I can give you all the possible S1 then our job is done because I can say I'll try out all partitions of S1 but how it's gonna work if I ask you what can be the all the partitions of S1 can I say the minimal summation of S1 will be 0 when I say I don't pick up any elt and the maximum summation will be when I say all the elts are in my summation S1 so maximum S1 can be total array sum which is 12 in our used example. so can I say the minimum value of the partition one summation will be zero and the maximum value of the partition one summation that I can get is the total sum of all the elts so all the elts are in my partition one.

// so in our above example total sum is 12(i.e 3+2+7)
// so min summation S1 =0 and max summation S1 =12
// 0 1 2 3 4 5 6 7 8 9 10 11 12  now I know the S1 will be in this range but I need to determine which are the valid S1 because everyone cannot be S1 all the partition are not possible so we'll be like okay we know in problem SubsetSumEqualToTarget we taught that the lastrow will tell you if target=0/1/2/3/4....k is possible or not possible in tabulation concept so can I say I know one thing that totalSum=12 here is possible because I will take all the elts so if I call the tabulation method for this size=3 here and target=12 so dp[3][12+1] so last row will tell me if 0 is possible or 1 is possible and so on till target=k so now what I can say is let's check 0 is possible it will tell me yes 0 is possible let's check 1 is possible  it will tell me no let's check 2 is possible it will tell me yes we are check according to our above example where arr=[3,2,7] so 2 is possible because there can be subset with sum 2, let's check 3 is possible it will tell yes because there can be subset with sum=3, 4 is possible - no, 5 is possible yes because (3+2), 6 is possible no, 7 is possible yes, 8 is possible - no, 9 is possible yes because(7+2), 10 is possible yse because (7+3), 11 is possible no, 12 is possible yes (7+3+2) so I figured out what values are possible and this can easily be done with the help of the last row that has been generated in this dp matrix if I call the tabulation method of subsetSum. So can I say that in our example valid S1 are {0,2,3,5,7,9,10,12} which are possible these are the partition that are possible for S1 so can I find the corresponding S2 and the answer to that will be yes

// valid S1-{0,2,3,5,7,9,10,12} so corresponding S2 will be (totalSum-S1)
// so S2-{12-0,12-2,12-3,12-5,12-7,12-9,12-10,12-12}-{12,10,9,7,5,3,2,0}

// so I see for every S1 I got the corresponding S2 so can I say the absolute difference over here is
// abs(S1-S2)-{12-0,10-2,9-3,7-5,7-5,9-3,10-2,12-0}-{12,8,6,2,2,6,8,12} and what do we need the minimal and what's the minimal that I see it's 2 so answer =2 using subsetSum problem we did this problem

// we declare dp[n][totalSum+1] because here target=totalSum that can be maximum possible value od S1

// then we call subsetSum problem so we get the lastrow of the dp

// now I know from 0 till the totalSum it is possible
// mini=1e9
// for(i=0;i<=totalSum){
// if(dp[n-1][i]==true) // means if lastrow with target=i if possible then{
// S1=i
// S2=totalSum-i
// mini=min(mini,abs(S2-S1))
//}
//}

// if we carefully observe in our example we see S1 and S2 are (12-0) and in last we have (0-12) and similar we have (2-10) and from last we have (10-2) and so on. So basically what happens is the subsets we had arr=[3,2,7] so first time it might have take 3 in the subset in the partition one , next time the partition one might have 2 , next time the partition one might have 7 going across there will be a moment the partition two will be having 3, the partition two will be having 2, the partition two will be having 7 like it can also have single elts so do we need to check because we are just checking for absolute difference so thereby I can say if I check for half of the sum then also we should be good enough
// so for(i=0;i<=totalSum/2){ all are same from above code }

// let's code now

#include <bits/stdc++.h>
using namespace std;

// by using tabulation method of subsetSumEqualToTarget problem
// t.c-O(n)(for calculating totalSum)+O(n*k)(for nested loops where k=totalSum)+O(totalSum/2)(for getting mini loop) where n is length of an array
// s.c-O(n*k) for dp
int minSubsetSumDifference(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += arr[i];

  // call tabulation method of subsetSumEqualToTarget problem
  int k = totalSum;
  vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
  // if target==0 index can be anything
  for (int i = 0; i < n; i++)
    dp[i][0] = true;
  // index=0
  if (arr[0] <= k)
    dp[0][arr[0]] = true;
  for (int index = 1; index < n; index++)
  {
    for (int target = 1; target <= k; target++)
    {
      bool notTake = dp[index - 1][target];
      bool take = false;
      if (arr[index] <= target)
        take = dp[index - 1][target - arr[index]];
      dp[index][target] = take || notTake;
    }
  }

  // so now entire dp matrix is generated and you get the lastrow which is dp[n-1][col->0....totalSum]
  int mini = 1e9; // because we want minimum
  // we go half it's mention above in discussion
  for (int s1 = 0; s1 <= totalSum / 2; s1++)
  {
    if (dp[n - 1][s1] == true)
    {
      mini = min(mini, abs((totalSum - s1) - s1));
    }
  }
  return mini;
}

// by space optimization method of subsetSumEqualToTarget problem
// t.c-O(n)(for calculating totalSum)+O(n*k)(for nested loops where k=totalSum)+O(totalSum/2)(for getting mini loop) where n is length of an array
// s.c-O(K)
int minsubsetSumDifference(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += arr[i];

  // by space optimization method of subsetSumEqualToTarget problem
  int k = totalSum;
  vector<bool> prev(k + 1, false);
  // base case when target=0
  prev[0] = true;
  // when index=0;
  if (arr[0] <= k)
    prev[arr[0]] = true;

  for (int index = 1; index < n; index++)
  {
    vector<bool> curr(k + 1, false);
    curr[0] = true; // when target=0
    for (int target = 1; target <= k; target++)
    {
      bool notTake = prev[target];
      bool take = false;
      if (arr[index] <= target)
        take = prev[target - arr[index]];

      curr[target] = take || notTake;
    }
    prev = curr;
  }
  int mini = 1e9;
  for (int s1 = 0; s1 <= totalSum / 2; s1++)
  {
    if (prev[s1] == true)
    {
      mini = min(mini, abs((totalSum - s1) - s1));
    }
  }
  return mini;
}

// also by memoization method of subsetSumEqualToTarget problem
// Time Complexity: O(N*K), there are total N*K states, where N is the length of array and K is the total sum of the array.
// Space Complexity: O(N*K) + O(N), we use a memo table to avoid recomputation. Extra auxiliary stack space is used for recursion.
bool subsetSumUsed(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  // base case
  if (target == 0)
    return dp[index][target] = true;
  if (index == 0)
    return dp[index][target] = (arr[0] == target);

  if (dp[index][target] != -1)
    return dp[index][target];

  bool notTake = subsetSumUsed(index - 1, target, arr, dp);
  bool take = false;
  if (arr[index] <= target)
    take = subsetSumUsed(index - 1, target - arr[index], arr, dp);

  return dp[index][target] = take || notTake; // boolean can be 0 or 1 it automatically return in integer
}

int minsubsetsumDifference(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; i++)
    totalSum += arr[i];

  // Initialize a DP table to store the results of the subset sum problem by memoizatiom
  int k = totalSum;
  vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

  // Calculate the subset sum for each possible sum from 0 to the total sum
  for (int i = 0; i <= totalSum; i++)
  {
    bool dummy = subsetSumUsed(n - 1, i, arr, dp); // dummy is just used to store the result the function give otherwise it has no use
  }
  int mini = 1e9;
  for (int s1 = 0; s1 <= totalSum / 2; s1++)
  {
    if (dp[n - 1][s1] == true)
    {
      mini = min(mini, abs((totalSum - s1) - s1));
    }
  }
  return mini;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << minSubsetSumDifference(arr, n) << endl;
  cout << minsubsetSumDifference(arr, n) << endl;
  cout << minsubsetsumDifference(arr, n) << endl;
  return 0;
}