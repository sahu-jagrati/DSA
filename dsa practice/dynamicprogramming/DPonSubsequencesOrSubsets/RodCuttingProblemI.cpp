// Problem Statement: Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

// Examples

// Input : price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8
// Output :25
// Explanation :Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

// Input :price = [1, 5, 8, 9], N = 4
// Output :10
// Explanation :Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.

// as we solved many problems so here we also observe that we can take that piece or notTake that piece are the two possibilites and also we can take any piece of length infinite times

// for example-N=5 and price=[2,5,7,8,10] so  N=5 is the total rod length
// we can cut the rode into the pieces like we cut the rod into 5 pieces of length =1 this is one of the possible way and we get the selling value=price[1]*5=2*5=10 because we cut the rod into length=1 so 5 timesso A.T.Q price[i] denotes the value of a piece of rod of length i inches (1-based indexing), other possible way: we cut the rod into 1 piece of length=1 and 2 piece of length =2 so total value=price[1]*1+price[2]*2=2*1+5*2=2+10=12 which is greater than first way value  so in this way you can actually cut this into several other ways like 1 piece of length=1 and 1 piece of length=4 so value=price[1]*1+price[4]*1=2*1+8*1=10 and other way alse: 1 piece of length=2 and 1 piece of length=3 so value=price[2]*1+price[3]*1=5+7=12 then it can be a lot of ways so you need to tell what is the maximum cost that you can get so this cost you have to maximize it and you can try every possible way and you will see that this is the maximal cost for this example maximum cost=12 whice we get by cut rod into length of 2,3 or length of 1,2,2 and this is what the problem states you have to cut the rod into pieces and you have to sell that in the market and you have to make sure that the cost that you get from the market is the maximum cost.

// The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an item that will in the long term give less value.

// As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which gives us the maximum value in the given constraints.

// we can say that this problem is kind of similar to the unbounded knapsack problem where we are given an array with values and weights and we collect weights and we can use the item infinite times but A.T capacity of bag in that question

// here we are try to form the rod of length N
// so can I think the problem in the opposite fashion instead of saying break N into pieces of rod can I say collect rod lengths and make it N and amke sure it is maximized

// so can i solve the problem in a similar way to knapsack i think i can so what we'll do is I will try to pick lengths and sum them up to make the given N, i'll try to pick them in various ways i'll try to pick length in all possible ways so for all possible ways the approach is recurrence
// and we know how to write recurrence
// i) express in terms  of index obviously you can express in terms of index because  you're given an array of rod lengths and prices where rod lengt array is like 1 to N so function is f(index,N) and for initial call is f(N-1,N) because here the total length is also the array size

// ii) explore all possibilities
// we know there is two possibilities-i) take the piece of rod ii) notTake the piece of rod

// iii) return max of all possible ways so maximize the price
// so the question is pretty much similar to what we did in unbounded knapsack why becau se over here what are you looking you're looking to format this particular N and you're trying to maximize all the possibilities so can i say this I will start with

// as we start recursion from index n-1 to 0 top-down approach and for length N to 0 also so we get base case at index=0
// f(index,N){
// i) base case
// if(index==0) we have single elt and  we know the rod length for zero index is 1 because we know indexing is 1 based and index also represent the length so when we are at index==0 rodlength =1 and assume it has a price[0]=6 and let's assume N=12 this is the remaining rod length that i'm looking to make initially whatever it is this is the remaining lot rod length i'm looking to make now the question is how can we make this N=12 because over here rodlength=1 so if we can take rod length = 1 -> 12 times .can I say that will make this remaining length N=12 yes it will so whatever N is left at the end of the day at index=0 can I say the pricing will be because the rodlength=1 and I can make that remaining length N so I will require N pieces of rodlength=1 and what will be the price? return N*price[0] because the last guy is of length =1 at index=0
// if(index==0)return N*price[0];
//

// ii) explore possibilities
// i) notake that length of piece if we do not take that rod length then the price added will be zero and we'll move th e previous index with the same N
// int notTake=0+f(index-1,N)
// and when we take that piece of length first we have to check that the piece length is enough and we know piec length is index+1
// int rodlength=index+1
// if(rodlength<=N)take=price[index]+f(index,N-rodlength) // stilee we stand at the same index because we can actually pick up any piece of length as many times so there is a infinite supply and we already whenevere there is infinite supply as we do in unbounded knapsack we stand at the same index

// return max(take,notTake)
//}

#include <bits/stdc++.h>
using namespace std;

// recursion
// t.c for recursion- here is greater than O(2^n) in this problem it is greater than O(2^n) because for a particular index we're taking it and we're still standing on the same index so in order to analyze this you have to say that for every index the options that you have is not exactly 2^n it can go beyond that thereby we can like in general interview you don't have to explain this much you can call it as exponential because you cannot theoretically prove the t.c so you can call it as exponential

// s.c for recursion-O(N) can we say this? yes in this case because if you are standing at the same index the auxiliary space is the recursion depth and it can go till we go off target whatever target is because we're taking the target again and again like assuming that there is only one elt so so its length of piece always 1  and at max it can go upto O(N) assuming it reduces by one one one one it can go to N(total length of rod) so again
// so S.c=O(N)
int f1(int index, int length, vector<int> &price)
{
  // base case
  if (index == 0)
  {
    return (length)*price[0];
  }
  // expore tow possibilities
  int notTake = 0 + f1(index - 1, length, price);
  // if we take that piece of rod first we have to check the length of rod is enough or not
  int take = INT_MIN; // we start with INT_MIN because we want maximum
  // length of piece of rod is index of price array(1-based indexing) so rodLength=index+1 because of 1-based indexing
  int rodLength = index + 1;
  if (rodLength <= length)
    take = price[index] + f1(index, length - rodLength, price); // if we take that piece of rod  we add the price of it and still we stand at the same index because we can take any piece of rod infinite times with length - (length of that piece which is index+1)

  return max(take, notTake);
}

// memoization so we make dp of index and total rod length which is N and also maxindex can be N-1 so dp[N][N+1]

// t.c for memoization-O(N*N)
// s.c-O(N*N)(for dp)+O(N)(for auxiliary stack space)

int f2(int index, int length, vector<int> &price, vector<vector<int>> &dp)
{
  // base case
  if (index == 0)
    return (length)*price[0];
  if (dp[index][length] != -1)
    return dp[index][length];
  int notTake = 0 + f2(index - 1, length, price, dp);
  int take = INT_MIN;
  int rodLength = index + 1;
  if (rodLength <= length)
    take = price[index] + f2(index, length - rodLength, price, dp); // still at the same indexbecause we can take any piece of rod infinite times

  return dp[index][length] = max(take, notTake);
}

// tabulation
// so in recursion we go top-down approach from N-1 to 0 for index and for totalLength we go from original length N to 0
// so in tabulation we go from bottom-up from 0 to N-1 for index  and for length go from 0 to original length N
// so i) write base case
// ii) look at the parameter that are changing here the parameters are index,length and write it in the oppposite fashion of recursion so in recursion we go N-1 to 0 so in tabulation we go 0 to N-1
// iii) copy the recurrence

// let's analyze the base case
// first we declare dp[n][W+1] with 0 initial value
// now base case
// in recursion we have
// if(index==0){
// return N*price[0]; where N is the length at that time of rod
//}

// now in tabulation base case is
// let's look at the base case it states index==0 and does it have a boundary on N and the answer to that is - it does not have a boundary on it so N can be abything from 1 to N so thereby I can say that
// for(len=0 to N){
// when index==0
// dp[0][len]=len*price[0];
//}

// and for other index
// for(index=1 to N-1){
// for(len=0 to N){
// copy the recurrence
//}
//}

// t.c-O(N*N)
// s.c-O(N*N) for dp
int f3(int N, vector<int> &price)
{
  vector<vector<int>> dp(N, vector<int>(N + 1, 0));
  // base case when index=0 length can be any from 0 to N
  for (int length = 0; length <= N; length++)
  {
    dp[0][length] = length * price[0];
  }

  // for remaining
  for (int index = 1; index < N; index++)
  {
    for (int length = 0; length <= N; length++)
    {
      int notTake = 0 + dp[index - 1][length];
      int take = INT_MIN;
      int rodLength = index + 1;
      if (rodLength <= length)
        take = price[index] + dp[index][length - rodLength]; // still at the same indexbecause we can take any piece of rod infinite times
      dp[index][length] = max(take, notTake);
    }
  }
  return dp[N - 1][N];
}

// space optimization- 2D dp  to two 1D array(prev,curr)
// t.c-O(N*N)
// s.c-O(N) for prev,curr

int f4(int N, vector<int> &price)
{
  vector<int> prev(N + 1, 0);
  // base case when index=0;
  for (int length = 0; length <= N; length++)
  {
    prev[length] = length * price[0];
  }

  for (int index = 1; index < N; index++)
  {
    vector<int> curr(N + 1, 0);
    for (int length = 0; length <= N; length++)
    {
      int notTake = 0 + prev[length];
      int take = INT_MIN;
      int rodLength = index + 1;
      if (rodLength <= length)
        take = price[index] + curr[length - rodLength];
      curr[length] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[N];
}

// here in this problem  we can also do more space optimization by converting two 1D array(prev,curr) into one single array(curr)
// in previous problem unbounded knapsack we do there also so for more details see that so over there you saw we were using a state prev[length] right above the curr[length] in the same column and (length-rodLength) lie left of length if we are trying to compute curr[length] then we required only left protion of curr row and from the previous row we want only the same column guy not entire previous row  so there's no need to store entire previous row  so whenever we're computing the current just rewrite over left side
// If we closely look the relation,

// dp[ind][cap] =  max(dp[ind-1][cap] ,dp[ind][cap-wt[ind]]

// We see that to calculate a value of a cell of the dp array, we need only the previous row values (say prev). So, we don’t need to store an entire array. Hence we can space optimize it.

// We will be space optimizing this solution using only one row. If we clearly see the values required:  dp[ind-1][cap] and dp[ind-1][cap - wt[ind]],  we can say that if we are at a column cap, we will only require the values of the same column from the previous row and other values will be from the cur row itself. So why do we need to store an entire array for prev row?

// If we need only one value from the prev row, there is no need to store an entire row. We can work a bit smarter. We can use the cur row itself to store the required value in the following way:
// We somehow make sure that the previous value( say preValue) is available to us in some manner ( we will discuss later how we got the value).
// Now, let us say that we want to find the value of cell cur[3], by going through the relation we find that we need a preValue and one value from the cur row.
// We see that to calculate the cur[3] element, we need only a single variable (preValue). The catch is that we can initially place this preValue at the position cur[3] (before finding its updated value) and later while calculating for the current row’s cell cur[3], the value present there automatically serves as the preValue and we can use it to find the required cur[3] value. ( If there is any confusion please see the code).
// After calculating the cur[3] value we store it at the cur[3] position so this cur[3] will automatically serve as preValue for the next row. In this way, we space-optimize the tabulation approach by just using one row.

// t.c=O(N*N)
// s.c-O(N) for curr array single array
int f5(int N, vector<int> &price)
{
  // Create a 1D DP array where cur[cap] stores max value for given capacity
  vector<int> curr(N + 1, 0);
  // base case: fill values for first item
  for (int length = 0; length <= N; length++)
  {
    curr[length] = length * price[0]; // when index=0
  }
  // Iterate through remaining items
  for (int index = 1; index < N; index++)
  {
    for (int length = 0; length <= N; length++)
    {
      // Option 1: Not take current item
      int notTake = 0 + curr[length]; // we use curr[w] before we update it so we don't need another array
      // Option 2: Take current item (if it fits)
      int take = INT_MIN;
      int rodLength = index + 1;
      if (rodLength <= length)
        take = price[index] + curr[length - rodLength]; // length-rodlength lie left of length and we use curr[length] before we update it so we don't need another array

      // store the better option
      curr[length] = max(take, notTake); // here we update the curr[w] but we already use the previous value of curr[w]
    }
  }
  return curr[N];
}

// size of price array is also equal to N i.e total length of rod
// price[i] denotes the value of a piece of rod of length i inches (1-based indexing).
int maximumValueCuttingRod(int N, vector<int> &price)
{

  // recursion
  // return f1(N - 1, N, price);

  // memoization
  // vector<vector<int>> dp(N, vector<int>(N + 1, -1));
  // return f2(N - 1, N, price, dp);

  // tabulation
  // return f3(N, price);

  // space optimization - 2D dp  to two 1D array(prev,curr)
  // return f4(N, price);

  // space optimization by convertion two 1D array(prev,curr) into one single array(curr)
  return f5(N, price);
}

int main()
{
  int N;
  cin >> N;
  vector<int> price(N);
  for (int i = 0; i < N; i++)
  {
    cin >> price[i];
  }
  cout << maximumValueCuttingRod(N, price);
  return 0;
}