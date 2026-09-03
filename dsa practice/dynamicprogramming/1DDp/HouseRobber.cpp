// Problem Statement: Given an array of N positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

// Note: A subsequence of an array is a list with elements of the array where some elements are deleted (or not deleted at all) and the elements should be in the same order in the subsequence as in the array.

// Examples
// Input: nums = [1, 2, 4]
// Output: 5
// Explanation:
// Subsequence {1,4} gives maximum sum.

// Input:  [2, 1, 4, 9]
// Output: 11
// Explanation:
// Subsequence {2,9} gives maximum sum

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

// what comes to your brain first to solve this problem

// let's try out all subsequences with the givin condition

// and then pick the one with the maximum sum
// for this initially we think about recursion

// question how do you print all subsequences so there's a technique which is known as pick and non-pick

// 1. write recurrence what did it teach you express every recursion in terms of indexes
// 2. do stuffs on that index
// 3. eturn the best that you can get

// print subsequence- pick/non-pick

// here what is the problem- pick subsequence with no adjacent elts
// where do you pick subsequence - from an array and whenever there is an array there has to be an index so the first property has been satisfied that i will have the recurrence based on the index

// now there is a question there's a constraint rather with no adjacent how do i deal with it because i know how to print all the subsequences but now there's a constraint which states with no adjacent elements right so we want the maximum sum

// so can i say our recursion to define something like this

// f(index) states the maximum sum that you can get if you pick a subsequence from the index 0 till the index i.e (0,....,index) maximum sum that you can get by picking up a subsequence with no adjacent elements from 0 to index
// f(index){
// if(index==0) what will be the best thing that i can do like there can be a lot of things but as of now let's keep this aside let's think of the other cases because we know we're gonna start from n minus one now in recursion

// we know in order to print subsequence you have a pick which states if you take this element into a subsequence the sum has to increase and the sum will increase by arr[index] so if you are picking up an index what is the question stating you cannot pick up an adjacent element so can i say you will not pick (index-1) so can i directly go to (index-2)  this make sense because if i am picking index i cannot pick index minus 1 because the condition states no adjacent so the transition instead of going to index minus 1 and deciding what will we do for is we say go to index minus 2

// pick = arr[index]+f(index-2)

// what are the stuffs that i can do i can say this particular index element will be a part of my subsequence or will not be
// if  decide that i will not pick then it will be a zero plus if i'm not picking an index can i pick an index minus 1 makes sense

//  nonpick=0+f(index-1)

// the last step is written best because you want the maximum sum
// return max(pick,nonpick)
// }

// but now still there's a question what if we reach somewhere around index == 0  so if we are reaching at index == 0 at any moment that means you have not picked up index == 1 (not pick when i reached index==0)
// so can i say the best that i can do is pick the element arr[index] when i reach index ==0 because if i haven't picked up index 1 i need to pick it because then only i can maximize my sum because remember the array does not have any negative elements thereby i can say i will return

// if(index==0) return arr[index]
// what if index was 1 and you did (1-2) and you went on to a negative index so you are running out of bound so there will be another edge case that you have to think in recursion so i can say if i am going index lesser than 0 i will be like return 0 because there will be nothing else so over here

// if(index<0)return 0

// in recursion
// the time complexity is definitely exponential which is (2^n) because you'll try out all like it's not exactly 2 to the power n it's going to be lesser than that so you have to memoize it now

// now question arises how do you optimize recursion you have to figure out if the recursion has overlapping sub problems then we can definitely memoize it

// let's take example-[2,1,4,9] in index it is [0,1,2,3]
// f(3)- if we pick index 3 then it go to f(1) and if we not pick then it go to f(2)
// we solve one side first then at f(1) if pick then f(-1) if not pick then f(0)
// so f(-1) return 0 and f(0) return arr[0]=2
// pick=arr[1]+f(-1)=1+0=1
// nonpick=0+f(0)=2
// so f(1)=max(0,2)=2, what does f(1) signify ?
// f(1) signifies the maximum sum that you can gather if you pick up a subsequence with no adjacent elements from zero to index one

// solve another side of f(3) which is f(2)
// for f(2) if pick then f(0) or if not pick then f(1) now do you see an overlapping sub problem you do see right this f(1)  is an overlapping problem there is no need to again go to f(-1) and f(0) so you can directly take f(1) right from calculated previous one because that's the value which has already been stored
// so for f(2)
// pick=arr[2]+f(0)=4+2=6
// nonpick=0+f(1)=2
// f(2)=max(6,2)=6, what does f(2) signify ?
// f(2) signifies the maximum sum that you can gather if you pick up a subsequence with no adjacent elements from zero to index two

// for f(3)
// pick=arr[3]+f(1)=9+2=11
// nonpick=0+f(2)=6
// f(3)=max(11,6)=11

// there are overlapping sub problems and how did the recursion work so now we can easily apply memoization to it and we can reduce the time complexity because what will be the memory action technique obivously how many statesare there f(3),f(2),f(1) and so on o can i say there are n states like states like 0 1 2 3 so you can create an array of size dp(n,-1) and follow the steps of converting recursion to memoization

// what will happen is it will change it to a time complexity of O(n) instead of the exponential one and the space complexity will change to be O(n) stack space and a O(n) array space

// in memoization
// t.c-O(n)
// s.c-O(n)(stack space)+O(n)(array space) but there is still a recursion stack space which we have to omit later
#include <bits/stdc++.h>
using namespace std;

// recurcion solution
// in recursion
// the time complexity is definitely exponential which is (2^n)
int f1(int index, vector<int> &nums)
{
  if (index == 0)
    return nums[index];
  if (index < 0)
    return 0;

  int pick = nums[index] + f1(index - 2, nums);
  int notpick = 0 + f1(index - 1, nums);

  return max(pick, notpick);
}

// memoization solution
// in memoization
// t.c-O(n)
// s.c-O(n)(stack space)+O(n)(array space) but there is still a recursion stack space which we have to omit later
int f2(int index, vector<int> &nums, vector<int> &dp)
{
  if (index == 0)
    return nums[index];
  if (index < 0)
    return 0;

  if (dp[index] != -1)
    return dp[index];
  int pick = nums[index] + f2(index - 2, nums, dp);
  int notpick = 0 + f2(index - 1, nums, dp);

  return dp[index] = max(pick, notpick);
}

// tabulation solution
// t.c-O(n)
// s.c-O(n)
int f3(int n, vector<int> &nums)
{
  vector<int> dp(n, -1);
  dp[0] = nums[0];
  int neg = 0; // neg-negative
  for (int i = 1; i < n; i++)
  {
    int pick = nums[i];
    if (i > 1)
      pick += dp[i - 2];

    int notpick = 0 + dp[i - 1];
    dp[i] = max(pick, notpick);
  }
  return dp[n - 1];
}

// space optimization
// t.c-O(n)
// sc-O(1)
int f4(int n, vector<int> &nums)
{
  int prev = nums[0];
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int pick = nums[i];
    if (i > 1)
      pick += prev2;
    int notpick = 0 + prev;

    int curr = max(pick, notpick);

    prev2 = prev;
    prev = curr;
  }
  return prev;
}
int rob(vector<int> &nums)
{
  int n = nums.size();

  // recursion solution
  // return f1(n - 1, nums);

  // memoization solution
  // vector<int> dp(n, -1);
  // return f2(n - 1, nums, dp);

  // tabulation solution
  // return f3(n, nums);

  // space optimization solution
  return f4(n, nums);
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
  cout << rob(nums);
  return 0;
}