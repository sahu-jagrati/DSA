// Problem Statement: A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack

// Input: n = 3, W = 8, wt = [2, 4, 6], val = [5, 11, 13]
// Output: 22
// Explanation:We can take item with weight 2 (value 5) four times to fill capacity 8,total value = 5 × 4 = 20.
// But a better choice: take item with weight 2 (value 5) twice and item with weight 4 (value 11) once → total weight = 2 + 2 + 4 = 8, total value = 5 + 5 + 11 = 21.
// Even better: take two items with weight 4 (value 11 each), total value = 22, which is maximum.

// Input: n = 2, W = 3, wt = [2, 1], val = [4, 2]
// Output: 6
// Explanation:We can take item with weight 1 (value 2) three times , total value = 6.
// Taking weight 2 (value 4) plus weight 1 (value 2) also gives 6. No combination yields more than 6.

// How is this problem different from 0/1 knapsack?
// in 0/1 knapsack problem clearly stated that we can take an any item only one time i.e there will only be one occurences of all items but here in unbounded knapsack it states that the thief  can take a single item any number of times(i.e infinite supply) he wants and put it in his knapsack. Similar to questions MinimumCoinChange and CoinChangeII.

// so as we'll follow the pattern of knapsack
// for recurrence it is
// i) f(index,W)
// ii) explore all possibilities
// iii) return max of all possibilities

// so in recursion we go top-down approach from index n-1 to 0 and for weight we go from W to 0
// f(index,W){
// base case
// if(index==0){
// if there is an single item  like we have a single item with wt[0]=3 and value[0]=10 and W(weight capacity of bag)=8 so if I ask you how many times can the thief steal this item because he will obivously steal there is only one item left and he still has a baggage weight =8 so it's very obvious that he is going to steal this item like Why will he not steal logically he will always steal it because if he doesn't steal this because this is the last item if it does not steals it it will be his loss so if the W=8 what will he do? he'll try to steal it that's for sure so how many items will he steal because I know this item is having an infinite supply and he has a W=8 left so he'll steal two items because the wt[0]=3 so still twice if W=13 we take three four items of wt[0] or if W=2 then he'll not be able to steal it so can I say whatever bag weight he will steal (W/wt[0]) is the number of items it can steal I say this is the number of times like the integer(W/wt[0]) will be the number of times it can steal it if it is W=8 then 8/3=2 or if it is W=13 then 13/3=4 or if it is W=2 then 2/3=0. what is the value that it will add? value add is = (W/wt[0])*value[0] so this is the base case that we reach the end so
// if(index==0){
// return (W/wt[0])*value[0];
//}

// ii) explore possibilites- there are only two possibilites -i) take that item ii) not take that item
// int notTake=0+f(index-1,W)
// int take=INT_MIN;  because we want max value so start with INT_MIN
// first check wt[index] is enought to capacity of bag
// if(wt[index]<=W){
// take=value[index]+f(index,W-wt[index]); we still stand at the same index because we can take any item infinite times
//}
// return max(take,notTake)
//}

// t.c for recursion- here is greater than O(2^n) in this problem it is greater than O(2^n) because for a particular index we're taking it and we're still standing on the same index so in order to analyze this you have to say that for every index the options that you have is not exactly 2^n it can go beyond that thereby we can like in general interview you don't have to explain this much you can call it as exponential because you cannot theoretically prove the t.c so you can call it as exponential

// s.c for recursion-O(n) can we say this? no because it's way more that that why because if you are standing at the same index the auxiliary space is not O(n) it can go beyond of that like assuming the wt[index]=1 and at max it can go upto O(W) assuming it reduces by one one one one it can go to target so again
// so S.c=O(W)

// now convert this in memoization by using dp[n][W+1]
// now when you memoize it then
// t.c for memoization-O(n*W)
// s.c-O(n*W)(for dp)+O(W)(around for auxiliary satck space )
// where W is maximum bag capacity that thief can hold it is given

// tabulation
// so in recursion we go top-down approach from n-1 to 0 for index and for weight we go from original weight capapcity W to 0
// so in tabulation we go from bottom-up from 0 to n-1 for index  and for weight go from 0 to original weight capacity W
// so i) write base case
// ii) look at the parameter that are changing here the parameters are index,target and write it in the oppposite fashion of recursion so in recursion we go n-1 to 0 so intbulation we go 0 to n-1
// iii) copy the recurrence

// let's analyze the base case
// first we declare dp[n][W+1] with 0 initial value
// now base case
// in recursion we have
// if(index==0){
// return (W/wt[0])*value[0];
//}

// i) now in tabulation base case is
// what can be the values of W? always think like don't think that given W as the initial W it is not the initial W when the index==0 like there might be a call for f(0,6) or f(0,4) it can be anything so can I say the W can be anything from 0 to given W value so for anything from 0 to given W what does it have at index==0 return (W/wt[0])*value[0] where W can be anything from 0 to give value of W in question

// so when index==0 then for any W from 0 to original given W
// for(int w=0;w<=W;w++){
// dp[0][w]=(w/wt[0])*value[0]
//}

// ii) in recursion we go n-1 to 0 for index and for W we go from original W to 0
//  so here in tabulation we go from  1 to n-1 for index  because we already done with index==0
//  for(int index=1;index<n;index++){
//  and for W go from 0 to original W
// for(int w=0;w<=W;w++){
//  copy the recurrence
// }
// }

// t.c for tabulation-O(n*W)
// s.c-O(n*W) for dp

// let's code

#include <bits/stdc++.h>
using namespace std;

// recursion
int f1(int index, int W, vector<int> &wt, vector<int> &val)
{
  // base case
  if (index == 0)
    return (int)(W / wt[0]) * val[0];
  // explore possibilities
  int notTake = 0 + f1(index - 1, W, wt, val);
  int take = 0; // because we want max so start with 0 and first we check also
  if (wt[index] <= W)
    take = val[index] + f1(index, W - wt[index], wt, val); // we still stand at same index because we can take any item infinite times
  return max(take, notTake);
}

// memoization
// t.c for memoization-O(n*W)
// s.c-O(n*W)(for dp)+O(W)(around for auxiliary satck space )
// where W is maximum bag capacity that thief can hold it is given
int f2(int index, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
  // base case
  if (index == 0)
  {
    dp[0][W] = (int)(W / wt[0]) * val[0];
  }
  if (dp[index][W] != -1)
    return dp[index][W];

  int notTake = 0 + f2(index - 1, W, wt, val, dp);
  int take = 0;
  if (wt[index] <= W)
    take = val[index] + f2(index, W - wt[index], wt, val, dp); // we still stand at same index because we can take any item infinite times

  return dp[index][W] = max(take, notTake);
}

// tabulation
// t.c for tabulation-O(n*W)
// s.c-O(n*W) for dp
int f3(int n, int W, vector<int> &wt, vector<int> &val)
{
  vector<vector<int>> dp(n, vector<int>(W + 1, 0));
  // base case
  for (int w = 0; w <= W; w++)
  {
    dp[0][w] = (int)(w / wt[0]) * val[0]; // when index==0
  }
  for (int index = 1; index < n; index++)
  {
    for (int w = 0; w <= W; w++)
    {
      int notTake = 0 + dp[index - 1][w];
      int take = 0;
      if (wt[index] <= w)
        take = val[index] + dp[index][w - wt[index]]; // we still stand at same index because we can take any item infinite times

      dp[index][w] = max(take, notTake);
    }
  }
  return dp[n - 1][W];
}

// space optimization- 2D dp  to two 1D array(prev,curr)
// t.c-O(n*W)
// s.c-O(W) for prev,curr
int f4(int n, int W, vector<int> &wt, vector<int> &val)
{
  vector<int> prev(W + 1, 0);
  // base case
  for (int w = 0; w <= W; w++)
  {
    prev[w] = (int)(w / wt[0]) * val[0];
  }
  for (int index = 1; index < n; index++)
  {
    vector<int> curr(W + 1, 0);
    for (int w = 0; w <= W; w++)
    {
      int notTake = 0 + prev[w];
      int take = 0;
      if (wt[index] <= w)
        take = val[index] + curr[w - wt[index]];

      curr[w] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[W];
}

// here in this problem  we can also do more space optimization by converting two 1D array(prev,curr) into one single array(prev)
// how if we see two-array solution of space optimization what am I using? I am using previous and I am using current in order to compute the current so can I say if we have prev row and curr row and what am I doing in order to compute curr[w] we do
// notTake=0+prev[w]
// take=val[index]+curr[w-wt[index]]
// so can I say whenever you are trying to compute curr[w] what are you using? You are using this prev[w] and from the current but from the back curr[w-wt[index]] means w-wt[index] lie left side of w. now a simple question is whenever you're trying to compute curr[w] apart from prev[w] from prev row are you requiring any other from prev row and the answer is no because we are just requiring prev[w] which is the same column guy of curr[w] that we compute so can I say whatever values like this curr[w] whatever value I'll get I'll just rewrite over here at prev[w] then I'll move here to next so can I say I can use a single array? yes we can because we do not need the previous values we just need the same column guy so use the same column guy use the previous compute this curr[w] and just put it previous and you can use a single array.

// If we closely look the relation,
// dp[ind][cap] =  max(dp[ind-1][cap] ,dp[ind][cap-wt[ind]]

// We see that to calculate a value of a cell of the dp array, we need only the previous row values (say prev). So, we don’t need to store an entire array. Hence we can space optimize it.

// We will be space optimizing this solution using only one row.
// If we clearly see the values required:  dp[ind-1][cap] and dp[ind-1][cap - wt[ind]], we can say that if we are at a column cap, we will only require the values of the same column from the previous row and other values will be from the cur row itself. So why do we need to store an entire array for prev row?

// If we need only one value from the prev row, there is no need to store an entire row. We can work a bit smarter.
// We can use the cur row itself to store the required value in the following way:
// We somehow make sure that the previous value( say preValue) is available to us in some manner ( we will discuss later how we got the value).
// Now, let us say that we want to find the value of cell cur[3], by going through the relation we find that we need a preValue and one value from the cur row.
// We see that to calculate the cur[3] element, we need only a single variable (preValue). The catch is that we can initially place this preValue at the position cur[3] (before finding its updated value) and later while calculating for the current row’s cell cur[3], the value present there automatically serves as the preValue and we can use it to find the required cur[3] value. ( If there is any confusion please see the code).
// After calculating the cur[3] value we store it at the cur[3] position so this cur[3] will automatically serve as preValue for the next row. In this way, we space-optimize the tabulation approach by just using one row.

// t.c-O(n*W)
// s.c-O(W) for curr only
int f5(int n, int W, vector<int> &wt, vector<int> &val)
{
  // Create a 1D DP array where cur[cap] stores max value for given capacity
  vector<int> curr(W + 1, 0);
  // base case: fill values for first item
  for (int w = 0; w <= W; w++)
  {
    curr[w] = (int)(w / wt[0]) * val[0];
  }
  // Iterate through remaining items
  for (int index = 1; index < n; index++)
  {
    for (int w = 0; w <= W; w++)
    {
      // Option 1: Not take current item
      int notTake = 0 + curr[w]; // we use curr[w] before we update it so we don't need another array
      // Option 2: Take current item (if it fits)
      int take = 0;
      if (wt[index] <= w)
      {
        take = val[index] + curr[w - wt[index]]; // w-wt[index] lie left of w and we use curr[w] before we update it so we don't need another array
      }
      // store the better option
      curr[w] = max(take, notTake); // here we update the curr[w] but we already use the previous value of curr[w]
    }
  }
  // Return max value for capacity W
  return curr[W];
}
int unboundedKnapsack(int n, int W, vector<int> &wt, vector<int> &val)
{
  // recursion
  // return f1(n - 1, W, wt, val);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  // return f2(n - 1, W, wt, val, dp);

  // tabulation
  //  return f3(n,W,wt,val);

  // space optimization - 2D dp  to two 1D array(prev,curr)
  // return f4(n, W, wt, val);

  // space optimization by convertion two 1D array(prev,curr) into one single array(curr)
  return f5(n, W, wt, val);
}

int main()
{
  int n;
  cin >> n;
  vector<int> wt(n);
  for (int i = 0; i < n; i++)
    cin >> wt[i];
  vector<int> value(n);
  for (int i = 0; i < n; i++)
    cin >> value[i];
  int W;
  cin >> W; // where W is maxweight that bag can have
  cout << unboundedKnapsack(n, W, wt, value);
  return 0;
}