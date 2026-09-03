// Problem Statement: Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type

// we are always assuming that coins[i]>0
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.
// Input : coins = [2, 5], amount = 3
// Output: -1
// Explanation :  It's not possible to make amount 3 with coins 2 and 5. Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

// like example-
// coins=[1,2,3], target=7 (amount)

// one be can have lik 7=3+3+1 and the number of coins required = 3
// one can be like 7=2+2+2+1 and the number of coins required=4
// but we want that minimum number of coins so here answer=3

// Can we apply greedy here?
// Why a Greedy Solution doesn’t work?

// if we have an example-coins=[1,2,3] and target=7
// so maximum coin here is 3 if we take 3 then 7/3=2 so we take 2 coins of 3 now amount left=7-2*3=1 , another maximum coin is 2 but this is greater than left amount 1 so can't take next maximum coin is 1 so 1/1=0 and amount left=1-1*1=0 so we required coins here{3,3,1} ans=3 here greedy gives correct answer but if we have example this coins={1,5,6,9} and target=11 so A.T greedy we choose max coin which is 9 so 11/9 =1 so we take 1 coin of 9 and amount left=11-1*9=2 and 5 and 6 coin are greater than left amount=1 so if we take coin 1 then 2/1=2 them amount left=2-2*1=0 so we required total 3 coins-{9,1,1} but here can be better answer then this if we take one coin of 5 and one coin of 6 i.e{5,6} so total coins required is 2 which is minimum then greedy solution. so we greedy approach doesn't work.
// there is no uniformity like here in this example the difference between (9-6)=3 , (6-5)=1, (5-1)=4 so there is no uniformity in the differences of coin thereby you don't know what is the next denomination hence something like greedy cannot be applied in such cases.

// The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an item that will in the long term give less value. Let us understand this with help of an example. If we consider denominations as [1,5,6,9] and our target is 11, then greedily we will select one coin of denomination 9 and two coins of denomination 1. But the actual solution is to choose one coin each of denomination 5 and 6.

// As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which gives us the minimum number of coins.

// as usual the method of pick and notPick we also use here that we also done in 0/1 kanpsack problem only difference here is we have to calculate minimum number of coins required to get target

// as usual we write the rules of recurrecne
// i) express in terms of index and also here we are looking for something i.e target so we take f(index,target)
// ii) explore all possibilites
// iii) return minimum of all possibilities

// question stating that we have to find out the minimum number of coins required so can I say I have to write a function that returns the minimal coin so

// in recursion here we go top-down approach - f(n-1,target) that means if there is an array then f(n-1,target) signify that till index (n-1) till the entire array upto (n-1) what are the minimum coins that will be required to form this target

// so recurrence is now-
// f(index,target){
// base case
// as we go from n-1 to 0 so we write base case at 0 and then you start thinking in terms of a single array containing a single elt and a possible target so like assume coins array have a single elt and coins[0]=6 and target=7 now tell me one thing if coins[0]=6 and target=7 so can this target be achieved what are the minimum number of coins that you will take to achieve this target=7 ? answer =0 because I cannot achieve target=7 using a coins[0]=6  but what if coins[0]=7 now your answer will be striver we can achieve the target=7 because it will take us one denomination of 7 to achiever this target=7 or if i change target=12 and coins[0]=4 then you'll be like striver we will be requiring three denominations of coins[0]=4 is the minimal that I will require in order to achieve this target via the denomination of 4 so can I say if the target is divisible by coins[0] then I written the minimum as target/denomination right and if it's not then i'll return that it's not possible so thereby the minimum number of coins is infinite no matter how many coins you bring you cannot don't return zero otherwise the minimum steps will be counted as zero so don't return zero because min(0,other value)=0 so don't return zero
// so base case is
// if(index==0){
// and we are always assuming that the coins[i] will always have a denomination >0 because coin never be negative or zero that's common sense
// if(target%coins[index])return target/coins[index]; where index==0
// else return INT_MAX(or 1e9, 1e9 is safe to return ); we cannot return 0 because when we take min then it always count zero because 0 is minimum then other positive value so we take INT_MAX or if there is overflow then you can return something as 1e9 why because you can see in possiblities there is 1+f() so when we add 1+INT_MAX it will overflow thereby in order to have safety return 1e9;
//}

// ii) explore all possibilities
// generally in subsequences there are two possibilities - i) either you take the coin or ii) you do not take the coin but over here there will be slight difference why so if we see our example: coins=[1,2,3] and target=7 so whenever we took the coin 3 used two additions of that so in our question it states that There are infinite numbers of coins of each type i.e means there is an infinite supply of each coins while in previous questions that we solve, a single elt was just used once  like in knapsack you just stole the elt once but over here any coins can be used infinite times then you might be thinking striver then best thing is divide it like we're using it do a 7/3 =2 and we're using it twice. Will that make sense? no because it might happen you don't need always like assume there is something like 25/3=8 we don't need to use it eight times probably there might be a case where you have to take seven times or seven denominations of 3 amke it 21 and probably take 2 denominations and make it 25 there might be cases like this it's always not necessary that if we're using a denomination we end up using the entire portion it can be seven denominations or it cna be six denominations or it can be five denominations, it can be any number of denominations that you can make so I will be like okay there are two cases:
// i) I decide I will not take it and if I not take, am I adding to the number of coins because what function duty is the to return the number of coins so make sure when you're not taking you count the number of coins counted will be 0 and if you'are not taking it what happens to this f() then we go to next index we move back index-1 with the same target because if we don't take this coin then target remain same
// int notTake=0+f(index-1,target)

// ii) what about take so if you're taking now you're looking for minimum whenever you're looking for minimum you assign take=INT_MAX or if you're looking for maximum then assign take=INT_MIN
// int take=INT_MAX;
// now when can you take it so this like assume coins[index]=6 and target=3. Can you take this denomination? no because coins[index]>target so we can't take it  so before taking any denomination check
// if(coins[index]<=target){
// then i can take it now if you're taking a coin into your denomination let's understand if you're taking a coin what is this function f() doing? this function is counting coins so how many coins are you taking 1 and rest for the remaining target you have to figure out the remaining target is target-coins[index] because of you took up a coin so the target will reduce to also  and now you look for what are the minimum in which I can form this target now (target-coins[index]) that's why you again call this function choice you will again call this function by taking it but there's a question what will happen to this index because if like assume coins[index]=3 and target=8 so now remaining target is 8-3=5 if this 3 is picked only once you add one but if you go back i.e index-1 then you will not be allowed to pick it once more so the best thing that you do is you say I'm gonna stand over here itself i.e at index and I'm gonna pick it again so I will call the index againg and this time with the reduced target i.e target-coins[index]
// take=1+f(index,target-coins[index]) so I am stayed at the same index  remember this as a thumb rule whenever there is an infinite supply of anything / multiple use such statements always when you consider take case it will stand at the same index, it won't move to the previous index it will stand at the same index. Now you might have a question but striver if it stands at the same index it will keep standing at that index always? answer  no  first in example target was 8 when you picked up 3 next it will become 5 when you pick up 3 again this 5 will become 2 and then you cannot pick up this 3 hence ultimately you will move at a moment because by picking up by picking up you're reducing the target as much as possible so eventually you will move so that's the funda of take case
//
//}

// iii) return min(take,notTake)
//}

// example- coins=[1,2,3]
// target=8
// recursion initial call-f(2,8)
// if nottake then f(1,8)

// if take then 1+f(2,8-3)=1+f(2,5)

// now first call is for f(1,8)
// if nottake- f(0,8)
// if take-1+f(1,8-2)=1+f(1,6)

// go with f(0,8) here index==0 and coins[0]=1 so target%coins[0]=8%1==0 so we return target/coins[0]=8/1=8
// so f(0,8) return 8

// now f(1,6)
// if nottake f(0,6) and it return 6
// if take 1+f(1,6-2)=1+f(1,4)

// now f(1,4)
// nottake- f(0,4)return 4
// take 1+f(1,4-2)=1+f(1,2)

// f(1,2)
// nottake f(0,2)return 2
// take 1+f(1,2-2)=1+f(1,0)

// f(1,0) go across,  target=0

// t.c for recursion- here is greater than O(2^n) in this problem it is greater than O(2^n) because for a particular index we're taking it and we're still standing on the same index so in order to analyze this you have to say that for every index the options that you have is not exactly 2^n it can go beyond that thereby we can like in general interview you don't have to explain this much you can call it as exponential because you cannot theoretically prove the t.c so you can call it as exponential

// s.c for recursion-O(n) can we say this? no because it's way more that that why because if you are standing at the same index the auxiliary space is not O(n) it can go beyond of that like assuming the minimum coin denomination is coin=1 and at max it can go upto O(target) assuming it reduces by one one one one it can go to target so again
// so s.c-O(target)

// so this is slightly different problem than other problem till we solve because here still we stand at the same index after taking it

// next step is memoization- because there can be overlapping subproblem so we declare dp[n][target+1] with -1 initialization
// now when you memoize it then
// t.c for memoization-O(n*target)
// s.c-O(n*target)(for dp)+O(target)(around for auxiliary satck space )

// tabulation
// so in recursion we go top-down approach from n-1 to 0 for index and for target we go from original target to 0
// so in tabulation we go from bottom-up from 0 to n-1 for index  and for target go from 0 to original target
// so i) write base case
// ii) look at the parameter that are changing here the parameters are index,target and write it in the oppposite fashion of recursion so in recursion we go n-1 to 0 so intbulation we go 0 to n-1
// iii) copy the recurrence

// let's analyze the base case
// first we declare dp[n][target+1] with 0 initial value
// now base case
// in recursion we have
// if(index==0){
// if(target%coins[index]==0)return target/coins[index]; where index==0
//}

// i) now in tabulation base case is
// what can be the values of target? always think like don't think that given  target as the initial target it is not the initial target when the index==0 like there might be a call for f(0,6) or f(0,4) it can be anything so can I say the target can be anything from 0 to given target value so for anything from 0 to given target what does it have at index==0 if(target%coins[index]==0)dp[0][target]=target/coins[0] where target can be anything from 0 to give value of target in question

// so when index==0 then for any target from 0 to original given target
// for(int t=0;t<=target;t++){
// if(t%coins[0]==0)dp[0][t]=t/coins[0];
// else dp[0][t]=1e9;
//}

// ii) in recursion we go n-1 to 0 for index and for target we go from original target to 0
//  so here in tabulation we go from  1 to n-1 for index  because we already done with index==0
//  for(int index=1;index<n;index++){
//  and for target go from 0 to original target
//  for(int t=0;t<=target;t++){
//  copy the recurrence
// }
// }

// t.c for tabulation-O(n*target)
// s.c-O(n*target) for dp

#include <bits/stdc++.h>
using namespace std;

// recursion
int f1(int index, int target, vector<int> &coins)
{
  // base case
  if (index == 0)
  {
    if (target % coins[0] == 0)
      return target / coins[0];
    else
      return 1e9;
  }
  int notTake = 0 + f1(index - 1, target, coins);
  int take = 1e9;
  if (coins[index] <= target)
    take = 1 + f1(index, target - coins[index], coins); // we are still stand at same index because we can take each type of coin infinite times

  return min(take, notTake);
}

// memoization
int f2(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
{
  // base case
  if (index == 0)
  {
    if (target % coins[0] == 0)
      return target / coins[0];
    else
      return 1e9;
  }
  if (dp[index][target] != -1)
    return dp[index][target];
  int notTake = 0 + f2(index - 1, target, coins, dp);
  int take = 1e9;
  if (coins[index] <= target)
    take = 1 + f2(index, target - coins[index], coins, dp); // we are still stand at same index because we can take each type of coin infinite times

  return dp[index][target] = min(take, notTake);
}

// tabulation
int f3(vector<int> &coins, int target, int n)
{
  vector<vector<int>> dp(n, vector<int>(target + 1, 0));
  // base case
  for (int t = 0; t <= target; t++)
  {
    if (t % coins[0] == 0)
      dp[0][t] = t / coins[0]; // when index==0
    else
      dp[0][t] = 1e9;
  }
  // so in recursion we go top-down approach from n-1 to 0 for index and for target we go from original target to 0
  // so in tabulation we go from bottom-up from 0 to n-1 for index  and for target go from 0 to original target
  for (int index = 1; index < n; index++)
  {
    for (int t = 0; t <= target; t++)
    {
      int notTake = 0 + dp[index - 1][t];
      int take = 1e9;
      if (coins[index] <= t)
      {
        take = 1 + dp[index][t - coins[index]];
      }
      dp[index][t] = min(take, notTake);
    }
  }
  return dp[n - 1][target];
}

// space optimization
// t.c-O(n*target)
// s.c-O(target) for prev and curr
int f4(vector<int> &coins, int target, int n)
{
  vector<int> prev(target + 1, 0);
  for (int t = 0; t <= target; t++)
  {
    if (t % coins[0] == 0)
      prev[t] = t / coins[0]; // t/coins[0] gives how many coins you can take of coins[0] value when it satisfy condition
    else
      prev[t] = 1e9;
  }

  for (int index = 1; index < n; index++)
  {
    vector<int> curr(target + 1, 0);
    for (int t = 0; t <= target; t++)
    {
      int notTake = 0 + prev[t];
      int take = 1e9;
      if (coins[index] <= t)
      {
        take = 1 + curr[t - coins[index]];
      }
      curr[t] = min(take, notTake);
    }
    prev = curr;
  }
  return prev[target];
}
int minimumCoins(vector<int> &coins, int amount)
{
  int n = coins.size();

  // recursion
  // int ans = f1(n - 1, amount, coins);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  // int ans = f2(n - 1, amount, coins, dp);

  // tabulation
  // int ans = f3(coins, amount, n);

  // space optimization
  int ans = f4(coins, amount, n);
  if (ans >= 1e9)
    return -1; // that we have no coins to make amount
  else
    return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  int amount;
  cin >> amount;
  cout << minimumCoins(coins, amount);
  return 0;
}

// in this problem when we run tabulation code for large data it give time limit exceed but memoization and space optimization running successfullu so it's mostly because the reason is a lot of times happens is that you design test cases in such a way that in memoization you actually don't visit all the  n*target states so you might be visiting very less amount of states and there is an auxiliary space but you might be visiting a lot lesser number of states but if you look over tabulation it exactly visits n*target states since all the n*target states visited that's the reason mostly sometimes it might happen and show time lime exceed in tabulation case but most of the time it does not happen