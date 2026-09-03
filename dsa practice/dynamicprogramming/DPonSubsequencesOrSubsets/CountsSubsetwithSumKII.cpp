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
// 0<=nums[i]<=1000
// 1<=tar<=1000

// same problem to countSubsetwithSumK only here nums[i] can be 0 also

// The test case {0,0,1} has been explained in problem countSubsetWithSumKII
// if  we check the testcase {0,0,1} with sum=1 in problem countSubsetWithSumK then it give answer=1 but ideally answer is 4 subsets how? - subsets can be - {0,1}(first zero ,1),{0,1}(second zero ,1),{1},{0,0,1} here it give answer=1 because the solution we write is not considered 0 as array elt because in constraint nums[i]>=1 and nums[i]<=1000 so 0 is not include so it give that answer and our solution also not considered 0 that's why but now how would you solve this problem if i change the constraints like 0<=nums[i]<=1000 means if 0 can also be an array elt then how we get total no. of subsets with sum=k this problem is solved in countSubsetWithSumKII

// now 0 can also be an array elt
// does 0 change the sum? no because addition of 0 or removal of 0 will never alter the sum the sum will still stay the same so that is the idea that we will take into consideration and we will compute the number of zeros

// in an example-arr={0,0,1} and target/sum=1
// number of zeroes=2 and in how many ways two zeros can be represented - i){0}(i.e if we take first zero ) ii){0}(i.e if we take second zero ) iii){0,0}(i.e if we take both zeroes) iv){}(i.e if we take neither of them) so there is 4 ways that we can represent two zeroes and we wnat sum/target=1 so if we add/append 1 in these subsets i get sum/target=1 because addition of 0 or removal of 0 will never alter the sum so total number of subsets with sum=1 is 4 i.e {0,1},{0,1},{0,0,1},{1}
// so if i can figure out how many ways i can represent the total number of zeroes (here total number of zeroes=2) then the answer will be there so how many ways can you represent the 'n' zeros it's 2^n comes from the algorithm power set so if total number of zeroes=2 then number of ways to rempresent them is 2^2=4 subsets so that's one of the ways you will solve it when you say that you're going to compute the power like the number of zeros and then uh you just do pow(2,n) where 'n' is total number of zeroes here

// this is the one way power set

// but how we correct our problem countSubsetWithSumK code if 0 is also include in our array
// why did it fail? if we see our recursion code of that problem
// if(target==0)means when sum==0 so eventually what happens is if i give you an array like {0,0,1} length of array==3 and sum/target=1
// and i am starting from here call f(2,1) which is the second index with the sum one
// for f(2,1): notTake=f(1,1), take=f(1,0)
// in take we get f(1,0) so remember code's first line say if(target==0)return 1 so these (i.e in array {0,0}) couple of zeros are actually not considered because we return 1 when we get sum/target=0 thereby there is a problem so what i can say is i need to go deep yes i need to go deep instead of returning from here i need to go deep which is for f(1,0): notTake-f(0,0) and take-f(0,0) then i have to think of something so basically i have to go deep so the changes in that problem code are we done here with same problem

#include <bits/stdc++.h>
using namespace std;

// in that problem base case was this
// base case-
// // i) if target==0
// if (target == 0)
//   return 1; // any index can be
// // ii) if index==0
// if (index == 0)
// {
//   return (arr[0] == target); // so it return 1 if it is or return 0 if it is not
// }

// but when we include 0 in an array we remove this base case if(target==0) because that is something which is creating problem and i have to go deep till index ==0  and that's when i think of the base case
// if we are standing at the index==0 that means you just have a single element right
// if(index==0){
// imagine if the sum is 0 and the arr[0] is also =0 what options do you have maybe like striver either you can take this guy into your subsequence because then also the sum will not be altered because arr[0]=0 or it we will not take  it then also there will be no problem so there are two options with the single guy there are two options you say i'll take the zero into consideration or you'll say i'm not going to take this into consideration so
// i) base case
// if(sum==0&&arr[0]==0)return 2; // because we have two options
// ii) base case
// if arr[0]=5 and sum==0 so if you decide to take this guy then the sum will be altered so you just have one way which is not taking because if you don't take this then the subsequence will still have a sum zero so
// if(sum==0)return 1;
// iii) base case
// if arr[0]=5 or anything and it's equal to sum i.e sum also =5 or anything then then if i don't take it then the sum will not go to 0 which is problem because it will not go if i don't take it but if i take it 5-5=0 and the sum will go to 0 so again a single way so
// if (arr[0]==sum)return 1
// we can combine ii) and iii)
// if(sum==0||arr[0]==sum)return 1
// and in all other cases when index=0 we return 0;
//}

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

  return pick + notPick; // return total count subsets with sum=target
}

// similarly we change in memoization and in other methods also
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

  return dp[index][target] = pick + notPick;
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
      dp[index][target] = pick + notPick;
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
      curr[target] = pick + notPick;
    }
    prev = curr;
  }
  return prev[sum];
}
// time complexity and space complexity remains same as of earlier version of this  problem
int countSubsetWithSumKII(vector<int> &arr, int n, int sum)
{
  // recursion
  // return f1(n - 1, sum, arr);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  // return f2(n - 1, sum, arr, dp);

  // tabulation
  // return f3(arr, n, sum);

  // space optimization
  return f4(arr, n, sum);
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
  int sum;
  cin >> sum;
  cout << countSubsetWithSumKII(arr, n, sum);
  return 0;
}