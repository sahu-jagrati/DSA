// Problem Statement: Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.

// Examples
// Example 1:
// Input:
//  arr = [5, 1, 4, 2, 3, 6, 8, 7]
// Output:
//  6
// Explanation:

// The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with a length of 6.
// The sequence increases from 1 to 8 and then decreases at 7.

// Example 2:
// Input:
//  arr = [10, 20, 30, 40, 50, 40, 30, 20]
// Output:
//  8
// Explanation:
//  The entire array is bitonic, increasing up to 50 and then decreasing. The length of the bitonic sequence is 8.

#include <bits/stdc++.h>
using namespace std;

// we solve this problem  by using the concept of Longest increasing subsequence (LIS)

// now our question states that we want longest bitonic subsequence
// bitonic means first the subsequence is increasing then it decreasing
// and we want subsequence
// A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements.

// for an example:
// arr[]=[1,11,2,10,4,5,2,1]
// if I pick [1,2,10,4,2,1] so here {1,2,10} increasing and after that {4,2,1} is decreasing so it is a bitonic subsequence
// similarly I can pick something like [1,2,10,5,2,1]
// similarly I can pick something like [1,11,10,4,2,1]
// similarly I can pick somethink like [1,11,10,5,2,1]
// all of the above are bitonic subsequences and among all the bitonic subsequences we have to tell  the longest length of bitonic subsequence so here length of longest bitonic subsequence is 6 so we return 6 as answer

// Does bitonic only means increase and then decrease?
// No, It can just be increase  or It can just be decrease
// for an example:
// arr[]=[1,10,2,3,4,5,6]
// now this is an array and I'm asking you the longest increasing subsequence so we can be like okay and answer to this will be [1,2,3,4,5,6] and length  =6 we don't pick up 10 so this is longest increasing subsequence but we'll be like but this is not bitonic because this is just increasing where is the decreasing portion as I said it cannot have a decreasing portion that' okay so this is a perfect bitonic subsequence, a longest increasing subsequence is also a bitonic subsequence

// So I can say a longest increasing subsequence is also a bitonic subsequence and similarly the longest decreasing subsequence is also a bitonic subsequence

// So we can say that bitonic subsequence can have  increase and then decrease portion or can have just increase portion or can have just decrease portion

// for an example:
// arr[]=[5,4,3,100,2,1]
// over here I can say [5,4,3,2,1] of length 5 this is an longest decreasing subsequence and it is still bitonic subsequence because it has the decreasing portion as I said bitonic can either have both increasing and then decreasing or it can  either have increasing or it can either have decreasing as long as it is having either of them or both of them

// Now how do we approach this problem?
// we know a subsequence increasing or something like this can be related to longest increasing subsequence
// Can I relate this to longest increasing subsequence?
// in longest increasing subsequence what does dp[i] signifies?
// if we remember the code of LIS it is like
// initially dp[i] declare with value=1
// for(i=0;i<n;i++){
// for(j=0;j<i=j++){
// if(arr[j]<arr[i]&&1+dp[j]>dp[i]){
// dp[i]=1+dp[j]
//}
//}
//}
// what does this dp[i] signify? if we remember dp[i] signifies  the longest increasing subsequence till index i .
// for an example-
// arr[]=[1,11,2,10,4,5,2,1] if for this array I have to write the dp then Can I say dp will be definitely like this
// dp for above array as longest increasing subsequence
// dp[0]=1 because we have only {1} till index 0
// dp[1]=2 because we have {1,11} as LIS
// dp[2]=2 because we have {1,2} as LIS
// dp[3]=3 because we have {1,2,10} as LIS
// dp[4]=3 because we have {1,2,4} as LIS
// dp[5]=4 because we have {1,2,4,5} as LIS
// dp[6]=2 because we have {1,2} as LIS
// dp[7]=1 because we have {1} as LIS
// so dp[]=[1,2,2,3,3,4,2,1] so this is the dp of longest increasing subsequence

// as for this example what is longest bitonic subsequence ?
// for this example longest bitonic subsequence is {1,2,10,4,2,1} of length=6 if we see this from left then {1,2,10} is increasing and if we see the subsequence from right then {4,2,1} is increasing see from right i.e {1,2,4} is increasing

// so what we will do is?
// if we have an array[]=[1,11,2,10,4,5,2,1]
// then if we start from an index=0 to see increasing subsequence then  we take dp for longest increasing subsequence is dp1[]=[1,2,2,3,3,4,2,1]
// now for same array if we start from index=n-1 to see increasing subsequence and write dp for longest increasing subsequence then we have dp2[]=[1,5,2,4,3,3,2,1] here for an example dp2[1]=5 this is for {11,10,4,2,1} is longest increasing subsequence from backward for index =1 we see from backward as increasing subsequence
// now Can I say if I have two dp tables one is the for forward increasing and other one is the for backward increasing
// now in an given array if I am standing here at 10 then till 10 including 10 from forward we have longest increasing subsqeuence of length 3 and from backward till 10 including 10 we have longest increasing subsequence of length 4 so Can I say the overall length will be 3+4=7 i.e {1,2,10} will 3 length and from backward {10,4,2,1} will 4 length but there is a guy 10 who is common from both side so we do 7-1=6 so at 10 we got the bitonic to be of length 6.
// So can I say in this way I can figure out the entire bitonic? I can so let's figure out the entire bitonic so
// we have
// dp1[]=[1,2,2,3,3,4,2,1] for forward longest increasing subsequence
// dp2[]=[1,5,2,4,3,3,2,1] for backward longest increasing subsequence then longest bitonic subsequence is bitonic[i]=dp1[i]+dp2[i]-1, we do -1 because the number itself at index common from both so we remove it once
// bitonic[0]=dp1[0]+dp2[0]-1=1+1-1=1
// bitonic[1]=dp1[1]+dp2[1]-1=2+5-1=6
// bitonic[2]=dp1[2]+dp2[2]-1=2+2-1=3
// bitonic[3]=dp1[3]+dp2[3]-1=3+4-1=6
// bitonic[4]=dp1[4]+dp2[4]-1=3+3-1=5
// bitonic[5]=dp1[5]+dp2[5]-1=4+3-1=6
// bitonic[6]=dp1[6]+dp2[6]-1=2+2-1=3
// bitonic[7]=dp1[7]+dp2[7]-1=1+1-1=1
// so we get botonic[]=[1,6,3,6,5,6,3,1] so length of longest bitonic subsequence is 6

// so if we can figure out the LIS from front and figure out the LIS from back and combine them we get our longest bitonic subsequence hence this is how we can easily use the LIS to solve this particluar problem

// so we use LIS code here
// t.c-O(n^2)*2 for dp1 and dp2 calculation + O(n) for bitonic // we can remove this for loop by comparing maxi above during dp2 calculation
// s.c O(n*2) for dp1 and dp2 1D array
int longestBitonicSubsequence(vector<int> &arr, int n)
{
  // this is from forward we calculate length of LIS
  // declare dp of size n 1D array
  vector<int> dp1(n, 1); // initially assigned to 1 because for itself length is 1

  // here we just want dp array not length of LIS we want length of longest bitonic subsequence which is calculated by forward and backward LIS
  for (int index = 0; index < n; index++)
  {
    // check for previous so go from 0 to index-1
    for (int prev = 0; prev < index; prev++)
    {
      // check prev elt is smaller or not
      if (arr[prev] < arr[index] && 1 + dp1[prev] > dp1[index])
      {
        // then check current dp value with new one if it is greater then we will store it
        dp1[index] = 1 + dp1[prev];
      }
    }
  }

  // this is from backward we calculate length of LIS
  vector<int> dp2(n, 1);
  for (int index = n - 1; index >= 0; index--)
  {
    for (int prev = n - 1; prev > index; prev--)
    {
      if (arr[prev] < arr[index] && 1 + dp2[prev] > dp2[index])
      {
        dp2[index] = 1 + dp2[prev];
      }
    }
  }

  // now calculate bitonic for bitonic[i]=dp1[i]+dp2[i]-1, -1 for removing common elt once
  int maxi = 0; // length of longest bitonic subsequence
  // we can remove this for loop by comparing maxi above during dp2 calculation
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, dp1[i] + dp2[i] - 1);
  }
  return maxi;
}

// Does bitonic only means increase and then decrease?
// No, It can just be increase  or It can just be decrease
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << longestBitonicSubsequence(arr, n);
  return 0;
}