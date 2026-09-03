// the problem is 0/1 knapsack and this problem is a very very very very very very very important problem for any interview

// prblem statement-
// There is a thief who goes to some house to steal items and in that house there are 'n' items each of the item has a particular weight 'w' and and a particular value 'v' and the thief has a bag and this bag cannot carry everything in the home it can only carry items till it does not exceeds the given weight 'W'. so Your task is to find the maximum  sum of value of items that the thief can steal.

// example- n=3
// wt array: wt-[3,4,5]
// value array: v-[30,50,60]
// and the thief's bag can carry maximum weight W=8
// so find maximum sum of value that theif can steal

// possible ways to steal item

// i) if theif stole item with wt=5 then value=60 and now it's bag weight become W=8-5=3 so still he can steal item with wt=3 and we have an item with wt=3 so he stole that item also so now the value become 60+30=90 and now it's bag weigth become W=3-3=0 means now he cann't steal anything so we get value=90

// ii) if theif stole wt=4 then value=50 and W=8-4 =4 so now theif can stole only wt<=4 so it stole wt=3 and value=50+30=80 and W=4-3=1 still bag has capacity of wt=1 but we don't have any item with wt=1 so we get value=80

// iii) if we stole wt=5 then value=60 and W=8-5=3 but here we can't stole item with wt=4 because now our bage capacity is of W=3

// so maximum value we can is 90 , the maximum that you can generate is 90

// Greedy approach like let's steal the valuable(i.e maximum value)items first and then we will be stealing according to the weight left in our bag again uh he's a thief right so he doesn't knows a lot of maths so that's that's the first approach that you'll think i'll go to the house and i'll see an iphone this is the costliest thing so i'll just put this into my bag similarly i can assume that okay i'll take this mouse and put this into the back because it is another costly thing thief will be going in the direction of picking up the most costly i think but if you go will you do that let's analyze will the greedy approach work? answer is no
// let's take an example- n=3
// wt-[3,2,5]
// v-[30,40,60]
// W=6 bag's weight
// so if we'll steal the costliest thing and the costliest thing comes out to be 60 here so value=60 and W=6-5=1 remaining because of stolen five can you steal wt=3 or wt=4 no so I get from thie max value=60 but we are educated so  so if i'm educated what i'll do is i'll steal wt=2 with v=40 so value=40 and W=6-2=4 and then we steal wt=3 with v=30 so now value=40+30=70 and W=4-3=1 now i can't steal anything because W=1 and there is no item with wt=1 so we get max value from this approach =70 which is maximum then greedy approach so we cann't apply greedy.

// why did greedy fail?
// becaue of uniformity was not there because there is nothing uniform over here for less weight the value is more over here for more weight the value is less so there is no uniformity you are not sure so uniformity is not there you don't know in the future you might get someone who adds up to get better so so as long as uniformity is not there you definitely cannot apply greedy

// so now we will trying out all combinations and among those combinations you will take the best value best total value giving combination make sense and how do you try out all combinations there's only one way and that's recursion

// we know rules of recursion

// i) express everything in terms of index
// we have an array so we have index you can think in terms of indexes and what we do what is the next thing that you will do the next parameter that's what is the next parameter the thief has gone to steel with a bag so he needs to be careful if the bag is full or not so i can say bag weight is the next criteria where we see that if the weight is still there or not so i can say the bag weight you can say
// f(index,W) where W is the bag's weight

// ii) explore all possibilites
// here we have two possibility - i) pick that item ii) not pick that item

// iii) returm maximum of all possiblitites

// so f(index,W) the initial call here we go from top-down approach so f(n-1,W)

// // let's take an example- n=3
// wt-[3,2,5]
// v-[30,40,60]
// W=6 bag's weight so our initial call is f(n-1,W) which is here f(2,6) which signify that till the index 2 what is the maximum that you can generate i.e till index 2 what maximal value you will get with weight of bag as six

// now the question arises what are the base cases
// as we have started from (n-1) so we will write the base case at 0 because if we're starting it from n-1 try to write base case it as 0 and if we're starting from 0 then try to write base case it of n-1
// so here we go from top-down approach means start fr0m n-1 so we write base case at 0

// base case
// if(index==0){
// what does this mean of f(0,w)- this mean a thief has come like the thief just has a single element and with a bag weight of w, what is the max value that he can get if the thief is just at here index==0 and he has a w weight assume the wt[0]=6 and value[0]=10000. and the theif is coming with f(0,8) and this is the last element what will the thief do will he steal it why will he not steal it he still has a bag weight of 8 left and it will just take wt[0]=6 as long as he can fit this in he will steal and go so do that he'll be like okay if if the last element can fit in my bag i will take this if i take this what is function giving the max value max value so it's a single element there's only one value that you will get which is value[0]
// if(wt[0]<=W)return val[0];

// but if the thief comes up with something like a bag W=4 can he steal now?  no he cannot why he cannot he has come to the last item but the weight that he carries is 4 and wt[0]=6 which is greater than the bag capacity so he cannot take it so if he cannot get the return 0
// else return 0;
//}

// now explore possibilities - there are two possibilities if we are standing at a particular guy then what options does the thief have-they'll either steal it or he'll not steal it so he will have two options either he will decide to not take it or he'll decide to take it
// i) if I am not taking that elt then we'll move to the next item and the value we add is 0 because we don't take that elt and the weight of the bag will also remain same

// int nottake=0+f(index-1,W)

// if we take that elt for taking that elt fist we have to check is thief bag has enough capacity or not so
// int take=0
// if(wt[index]<=W){
// take=value[index]+f(index-1,W-wt[index])
//}

// return max(take,notTake);

#include <bits/stdc++.h>
using namespace std;

// recursion
// t.c-O(2^n) because we are trying out couple of ways for every elt
// s.c-O(n) auxiliary satck space

int f1(int index, int W, vector<int> &wt, vector<int> &value)
{
  // base case
  if (index == 0)
  {
    if (wt[0] <= W)
      return value[0];
    else
      return 0;
  }
  // explore possiblity
  int notTake = 0 + f1(index - 1, W, wt, value);
  int take = INT_MIN;
  if (wt[index] <= W)
  {
    take = value[index] + f1(index - 1, W - wt[index], wt, value);
  }
  return max(take, notTake);
}

// memoization
// t.c-O(n*W) where W is the max bag capacity
// s.c-O(n*W)(for dp)+O(n)(for auxiliary satck space )

int f2(int index, int W, vector<int> &wt, vector<int> &value, vector<vector<int>> &dp)
{
  // base case
  if (index == 0)
  {
    if (wt[0] <= W)
      return value[0];
    else
      return 0;
  }
  if (dp[index][W] != -1)
    return dp[index][W];
  int notTake = 0 + f2(index - 1, W, wt, value, dp);
  int take = INT_MIN;
  if (wt[index] <= W)
    take = value[index] + f2(index - 1, W - wt[index], wt, value, dp);

  return dp[index][W] = max(take, notTake);
}

// tabulation
// in recursion we go top-down from n-1 to 0
// so now in tabulation we go bottom-up from 0 to n-1
// dp[n][W+1] where n is size of wt array
// now base case
// the theif have bag capacity of W
// in recursion we say if index==0 and and if wt[0]<=W then return value[0] so can I say for index=0 we can return value[0] for each wt from wt[0] to W

// t.c-O(n*W)
// s.c-O(n*W) for dp where W is the max bag capacity
int f3(vector<int> &wt, vector<int> &value, int n, int W)
{
  vector<vector<int>> dp(n, vector<int>(W + 1, 0));
  // base case
  for (int i = wt[0]; i <= W; i++)
  { // wt[0]<=W and index==0 so return value[0]
    dp[0][i] = value[0];
  }
  // in recursion for index we go from n-1 to 0
  // we already done with index=0 so go from 1 to n-1
  for (int i = 1; i < n; i++)
  {
    // in recursion for weight we go from W to 0
    // here we go from 0 to W
    for (int j = 0; j <= W; j++)
    {
      int notTake = 0 + dp[i - 1][j];
      int take = INT_MIN;
      if (wt[i] <= j)
      {
        take = value[i] + dp[i - 1][j - wt[i]];
      }
      dp[i][j] = max(take, notTake);
    }
  }
  return dp[n - 1][W];
}

// space optimization - 2D dp  to two 1D array(prev,curr)
// t.c-O(n*W)where W is the max bag capacity
// s.c-O(2*W) fro prev and curr

int f4(vector<int> &wt, vector<int> &value, int n, int W)
{
  // prev row
  vector<int> prev(W + 1, 0);
  // base case
  for (int i = wt[0]; i <= W; i++)
    prev[i] = value[0];

  for (int i = 1; i < n; i++)
  {
    vector<int> curr(W + 1, 0);
    for (int j = 0; j <= W; j++)
    {
      int notTake = 0 + prev[j];
      int take = INT_MIN;
      if (wt[i] <= j)
      {
        take = value[i] + prev[j - wt[i]];
      }
      curr[j] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[W];
}

// here in this problem  we can also do more space optimization by converting two 1D array(prev,curr) into one single array(prev)
// how if we see two-array solution of space optimization
// we have curr[j]=max(prev[j],value[i]+prev[j-wt[i]]) i.e max(take,notTake)
// NOtice that both values come from prev row, not from curr.

// Where is j-wt[i]?
// suppose:
// capacity_ 0 1 2 3 4 5 6 7 8
//                     j=8
// if wt[i]=3 then j-wt[i]=8-3=5 which is always on the left side of j
// capacity: 0 1 2 3 4 5 6 7 8
//                     j-wt   j  here we are so j-wt[i] always left side of j

// normally we do for(int j=0;j<=W;j++)
// but we can also do : for(int j=W;j>=0;j--) because the formula only uses values from the previous row.

// Why can we remove curr?
// suppose:
// previous row: 0 1 2 3 4 5 6 7 8
// we start filling from the right side
// when computing: dp[8] we need dp[8-wt[i]] which is somewhere on the left. since we haven't touched the left side yet, it's value is still the old(previous -row) value. so we can safely overwrite: dp[8] then compute dp[7] Again, the required value is further left and still unchanged. continue 8->7->6->5...
// Each time, the needed value is on the left and still contains the previous-row value.

// Therefore the same array can act as:

// previous row (for positions not yet processed)
// current row (for positions already processed)

// at the same time.

// why not left to right?
// supoose: for(int j=0;j<=W;j++)
// consider wt[i]=2 when computing: dp[5] you need dp[3]
// But dp[3] may already have been updated in the current row.

// So you are using a current-row value instead of a previous-row value.

// This effectively allows taking the same item multiple times.

// That becomes Unbounded Knapsack, not 0/1 Knapsack.

// so that's why we go from right to left and we optimize to one single array

// t.c-O(n*W)
// sc.-O(W) only for single array prev
int f5(vector<int> &wt, vector<int> &value, int n, int W)
{
  vector<int> prev(W + 1, 0);
  for (int i = wt[0]; i <= W; i++)
    prev[i] = value[0];

  for (int i = 1; i < n; i++)
  {
    // we go from right to left  and we optimize to one single array
    for (int j = W; j >= 0; j--)
    {
      int notTake = 0 + prev[j];
      int take = INT_MIN;
      if (wt[i] <= j)
        take = value[i] + prev[j - wt[i]];

      prev[j] = max(take, notTake); // we update from right hand side so that we use previous left side before changing to new
    }
  }
  return prev[W];
}

// // where W is maxweight that bag can have
int zeroOneKnapSack(vector<int> &wt, vector<int> &value, int W)
{
  int n = wt.size();

  // recursion
  // return f1(n - 1, W, wt, value);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  // return f2(n - 1, W, wt, value, dp);

  // tabulation
  // return f3(wt, value, n, W);

  // space optimization- 2D dp  to two 1D array(prev,curr)
  // return f4(wt, value, n, W);

  // space optimization by convertion two 1D array(prev,curr) into one single array(prev)
  return f5(wt, value, n, W);
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
  cout << zeroOneKnapSack(wt, value, W);
  return 0;
}