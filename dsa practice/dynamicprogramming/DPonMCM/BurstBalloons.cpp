// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10

// Constraints:

// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

// example: nums[]=[3,1,5,8] and n=4
// given n balloons indexing from 0 to n-1. Each balloon is painted with a number on it represented by an array nums.
// like balloon1 is painted with 3
// balloon2 is painted with 1
// balloon3 is painted with 5
// balloon4 is painted with 8
// we are asked to burst all the balloons.
// now if I'm bursting the balloon painted with 5 here then the number of coins that we will get will be the nums[i-1]*nums[i]*nums[i+1] where i is the index of the balloon that we burst so here we coins=1*5*8=40

// so the question states we have to burst the balloons in any order you wu=ish like you can burst 5 then you can burst 8 then you can burst 1 then you can burst 3 or you can go like 3 then 5 then 8 then 1 you can follow any order and in following the order we will be getting some coins because every time we burst a balloon we get some coins so the summation of those coins should be maximum

// for an example if I decide that the first balloon that I'll burst is 3 then coins will be adding is 1*3*1 because in question also mention when we go out of bound then for that nums[i-1] or nums[i+1]=1 so here coins add =1*3*1=3
// now after that we left with nums[]=[1,5,8] now we burst the balloon painted with 1 so coins added is 1*1*5=5
// now we left with nums[]=[5,8] now I decide burst the balloon with 5 paint so coins added is 1*5*8=40
// now we left with nums[]=[8] so we burst it and coins added is 1*8*1=8
// so total coins we get is 3+5+40+8=56 by burst in order 3,1,5,8

// now if we try another order of bursting the balloon
// nums[]=[3,1,5,8]
// we start with bursting the balloon painted with 1 so coins added is 3*1*5=15
// now we left with [3,5,8] now we will try to burst the balloon painted with 5 so coins added is 3*5*8=120
// now we left with [3,8] now we will try to burst the balloon painted with 3 so coins added is 1*3*8=24
// now we left with [8] so we will burst it and coins added is 1*8*1=8

// so total number of coins we get is = 15+120+24+8=167

// and the question stated we have to maximize the number of coins so for this example the maximum coins we get is 167 if we follow the order 1,5,3,8. We can follow various other ways but the maximum we can obtain is 167

// now how do we approach this question?
// if we take an example again: we have nums[]=[3,1,5,8] so if we see a pattern to this question it is somewhere related to the partition of MCM(Matric Chain Multiplication) question so we have to follow an order right like we can follow the order 3,1,5,8 or we can follow the order 1,3,5,8 or we can follow the order 8,1,3,5 so they can always be various set of orders but we need to understand which will be the first we pick so apparently for now we have nums[]=[3,1,5,8] this is the entire range of elts, among them any one can be the first we can pick like we can burst 3 first or we can burst 1 first or we can burst 5 first or we can burst 8 first so we can burst out any one first so can I say the range is [3,1,5,8] is given nums array like if i is at the starting point of nums and j is at the ending point of given nums array so from i to j any one can be the first elt so I can think it in the direction of MCM problem because in the MCM, there were matrices like ABCD then we decided that we will first take B and C multiply then the result goes and gets multiply with A and the with D that is what we did so Can I similarly say if I consider this given nums[] =[3,1,5,8] array as an entire stuff we decide which one is the first elt it can be 3 or it can 1 or it can be 5 or it can be 8 so it's like we have entire range
// nums[]=   [3,1,5,8]
//            i     j
// then we start thinking of the second elt then we start thinking of third elt so we can follow that order but can we or can we not

// by taking a simple example of [b1,b2,b3,b4,b5,b6] randomly balloons
// imagine let's burst first b4 so waht is the value that I add up to the answer Can I say it is - b3*b4*b5 is the coins that I'll get and in the left we will be left with this [b1,b2,b3] and in right we left with [b5,b6] these are subproblems so can I say this is a answer = b3*b4*b5 + [b1,b2,b3] subproblem + [b5,b6] subproblem. Can I saythis is the answer? No, I cannot say like just burst b4 and then solve these subproblems individaully add up this answer Will that work the answer ? No why will that not work? let's understand

// let's understand why we cannot solve the subproblems independently, solving them independently will not work is the main concept of this problem? so why this [b1,b2,b3] suproblem and [b5,b6] subproblem cannot be solved independently when we burst the balloon b4

// So imagine if we are bursting  b4 it is over(finish ) and what is the state after this it will be [b1,b2,b3,b5,b6]  so imagine if we would have taken this [b1,b2,b3] as an individual subproblem and we would have burst out b3 apparently right after b3 after b4 burst if it had decided to burst out b3 who would have been the right guy of b3? it is b5 so can I say even if I take this [b1,b2,b3] subproblem independently this b3 will be taking a dependency of b5 might or if I say after b4 if I decide to burst out b5 then also like if I burst out br then on the parallel it has a dependeny on b3 in left and it has a b6 dependency so imagine if we are bursting out b5 after this we will have [b1,b2,b3,b6] so after this if we decide to burst out b6 now b6 still has a dependency on b3 so we cannot just randomly decide that this [b5,b6] is an individaul subproblem because for dp to work this has to be an individual subproblem we should not ne depending on the values of this [b1,b2,b3] understood now we might argue but striver if b6 is getting bursted we just take the b3 as the left guy no that will  not work imagine after bursting b5 we had [b1,b2,b3,b6] and we decided to burst b3 so this b3 was dependent on b6 so depending on who is getting burst so b3 might be dependent on b5 or b3 might be dependent on b6 so we cannot individaully solve these subproblems

// so a key point is that if I start from front like if I have [3,1,5,8] and we burst 1 first then we had [3,5,8] if we burst 5 then we have [3,8] then if we burst 3 then we had [8] so

//     [3,1,5,8]  burst 1 first
//      [3,5,8]   then burst 5
//       [3,8]    then burst 3
//        [8]     then burst 8

// so we cannot go in this direction top to bottom instead of this we go in opposite direction we'll start thinking in the opposite directiom like I will say if there are 4 elts who was the last guy and the answer that I'll get is 8  then I'll say who's the second last guy 3 and if this is a subproblem [3,8] I get 3 is the second last guy after that I'll say who is the other guy it will say 5 and subproblem is [3,5,8] and after that I'll ask who is the other guy it'll say 1 and subproblem is [3,1,5,8]

// let's take this example nums[]=[3,1,5,8]
// okay we say like 8 is the last guy to be bursted okay so as of now we had this [3,1,5,8] entire range that has to be solved now to avoid complications we know on the right of 8 there is no one and we know on the left of 3 is no one so what I'll just do to avoid complications I'll add a 1 on the left of 3 and add 1 on the right of 8 like this we have 1, 3,1,5,8, 1 because in question also mention for boudary guys take nums[i-1] or nums[i+1]=1 so now we have  1, 3,1,5,8, 1  but [3,1,5,8] this is the numbers that we have to solve adding 1 both side is just to avoid complications

// now imagine 8 is the last guy to be solved and initially [3,1,5,8] this is the range that we are looking for and I'm saying instead of now on this [3,1,5,8] range deciding which is the first guy I decide who is the last guy so if I decide who is the last guy so if I decide who is the last guy then can I say cost will be 1*8*1 if 8 is the last guy imagine if 8 is the last guy then can I say the cost will be 1*8*1 because for last guy there is no one in left and no onde in right so in that case we take nums[i-1] & nums[i+1]=1 i.e we have like 1,  8,  1

//   8      coin add = 1*8*1
// as we are going in the reverse way okay before this if we remember there was [3,8] and I decided to burst out 3 so if [3,8] and 8 is remaining in the last that means we have bursted out eight now we just have this much range [3,1,5] as we are going from the back so we just have this much range [3,1,5], 8 has been bursted so now I'm saying we have a 3 that has to be bursted so can I say for this 3 I definitely know since I have bursted out before 8, 8 will be the right guy because I am going in the reverse direction just because 8 was here in the next step I was able to burst eight so I'm very much sure that 3 has a right guy 8 because all the others would have been bursted and these steps like one

// this given below is the whole approach to dsolve this problem above also I write the same approach according to video understand but below is the clear-cut approach from starting to end

// We must burst balloons in a specific order to collect the most coins. The order of bursting affects the total, and multiple valid sequences may exist.

// Initially, we may think to choose the first balloon to burst, assuming we can solve the rest separately. But this leads to interdependency problems.

// For example, bursting the middle balloon splits the array into two parts. But bursting one side may still depend on balloons from the other, making them not truly independent.

// So, this approach fails as subproblems overlap and depend on each other. Instead, think in reverse: choose the last balloon to burst.

// Now, if we burst a balloon last, the balloons on its left and right are fixed, allowing us to treat the left and right parts as separate subproblems.

// For example, if a middle balloon is burst last, its neighbors are known, and we can solve the left and right sections independently. This eliminates overlapping dependency.

// Now subproblems are truly independent. We use this structure to apply a Partition DP technique.

// Start with the whole array marked by i and j.
// Try all possible last balloons to burst within i to j.
// Calculate total coins as:
// Coins from bursting the chosen balloon (with neighbors)
// Plus coins from solving the left subarray
// Plus coins from solving the right subarray
// Track the maximum among all such combinations.
// Mark the array with two pointers i and j, covering the full range of balloons.

// recursion
// we start from bursting last balloon in the order i.e in last there is only one balloon left for that we have 1 and 1 both side and bursting last balloon can be any one from given balloons

// t.c for recursion- exponential in nature
// s.c- O(n) for auxiliary stack space
int f1(int i, int j, vector<int> &nums)
{
  // base case when i crosses j
  if (i > j)
    return 0;
  int maxi = INT_MIN;
  // last burst balloon can be anyone from given balloons
  for (int index = i; index <= j; index++)
  {
    int cost = nums[i - 1] * nums[index] * nums[j + 1] + f1(i, index - 1, nums) + f1(index + 1, j, nums);
    maxi = max(maxi, cost);
  }
  return maxi;
}

// there can be overlapping subproblems so apply memoization
// we have two changing parameters i and j
// i can somewhere start from 1 to n so maximum i can probably take it size [n+1] and j is somewhere from n to 1 so [n+1] so we declare dp[n+1][n+1]

// t.c-
// i and j runs so n*n and for every i and j we run a for loop i to j so approx. n also so total t.c-O(n*n*n)
// s.c-O(n*n)(for dp)+O(n)(for auxiliary stack space)
int f2(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
  // base case
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int maxi = INT_MIN;
  for (int index = i; index <= j; index++)
  {
    int cost = nums[i - 1] * nums[index] * nums[j + 1] + f2(i, index - 1, nums, dp) + f2(index + 1, j, nums, dp);
    maxi = max(maxi, cost);
  }
  return dp[i][j] = maxi;
}

// tabulation
// Step 1: write the base case
// so in recursion we have base case as: if(i>j)return 0
// as in tabulation we initalize dp with 0 so there is no need to write base case separatley
// Step 2: write changing parameter in opposite fashion
// as in recursion i go from somewhere 1 to n and j go from somewhere n to 1 in recursion we start with calling f(1,n) so in tabulation i go from n to 1 and j go from 1 to n
// Step 3: copy the recurrence

// t.c-O(n*n*n)
// i and j runs so n*n and for every i and j we run a for loop i to j so approx. n also so total t.c-O(n*n*n)
// s.c-O(n*n) for dp
int f3(vector<int> &nums, int n)
{
  // we declare dp[n+2][n+2] because when j=n then j+1=n+1 so we declare dp with n+2 size
  vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

  // as dp already initialize with 0 so no need to write base case separately
  for (int i = n; i >= 1; i--)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i > j) // that we do in base case of recursion when i crosses j then nothing has to done
        continue;
      int maxi = INT_MIN;
      for (int index = i; index <= j; index++)
      {
        int cost = nums[i - 1] * nums[index] * nums[j + 1] + dp[i][index - 1] + dp[index + 1][j];
        maxi = max(maxi, cost);
      }
      dp[i][j] = maxi;
    }
  }
  return dp[1][n];
}
int maxCoins(vector<int> &nums)
{
  int n = nums.size(); // original given array size before inserting 1
  // we insert 1 both side of the nums because for bursting last balloon the values of nums[i-1]&nums[j+1] is 1
  nums.push_back(1);
  nums.insert(nums.begin(), 1);
  // recursion
  // initially we take i=1 and j=n, j=n because after inserting 1 at starting balloon n-1 comes at n
  // return f1(1, n, nums);

  // memoization
  // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  // return f2(1, n, nums, dp);

  // tabulation
  return f3(nums, n);
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
  cout << maxCoins(nums);
  return 0;
}