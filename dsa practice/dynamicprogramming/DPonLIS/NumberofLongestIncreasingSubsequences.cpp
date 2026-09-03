// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
// Example 2:

// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

// Constraints:

// 1 <= nums.length <= 2000
// -10^6 <= nums[i] <= 10^6
// The answer is guaranteed to fit inside a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

// to solve this problem we use the problem longest increasing subsequence as a prerequisites

// as we already know that what is longest increasing subsequence now here we want number of longest increasing subsequence

// for an example-:
// nums[]=[1,3,5,4,7]
// here the length of longest increasing subsequence is 4
// and the longest increasing subsequences here are :
// i) {1,3,5,7}
// ii) {1,3,4,7} both are of length = 4
// so number of longest increasing subsequences here are - 2
// so in this problem we don't want length of longest increasing subsequence, we want number of longest increasing subsequence

// now how do we solve this particular problem?
// if we remember the problem longest increasing subsequence where we find the length of longest increasing subsequence we tried to fill the dp aray usinga couple of loops the code of that problem is :
// code of LIS is:
// for(index=0;index<n;index++){
// for(int prev=0;prev<index;prev++){
// if(arr[prev]<arr[index]&&1+dp[prev]>dp[index]){
// dp[index]=1+dp[prev]
//}
//}
//}
// where dp array store the length of longest increasing subsequence till index i

// but here we have to count number of longest increasing subsequences

// let's take an example:
// nums[]=[1,3,5,4,7]
// now here with dp array we maintain one more array which is count array both are initialized with value =1 because the value at index i is also subsequence itself so

// here we take two 1D array - i) dp array initialized with value 1 for itself, dp[i] signifies the length of longest increasing subsequence till index i
// ii) count array is also initialized with value 1 because itself is also a subsequence so count is initialized with 1, count[i] signifies the number of longest increasing subsequences till index i

// for an above example:nums[]=[1,3,5,4,7]
// initially we have :
// dp[]=[1,1,1,1,1]
// count[]=[1,1,1,1,1]
// now we start from index=0
// so at index=0 there is only one subsequence which is {1} so dp[0]=1 already we have and count[0]=1 because we have only 1 longest increasing subsequence of length 1 till index 0
// index=1 and nums[1]=3 now till index =1 we have longest increasing subsequence is {1,3} so dp[1]=2 i.e length of longest increasing subsequence till index =1  and count[1]=1 still because for length =2 we have 1 longest increasing subsequence till index=1
// index=2 and nums[2]=5 now till index=2 we have longest increasing subsequence is {1,3,5} so dp[2]=3 i.e length of longest increasing subsequence till index =2 and count[2]=1 still because for length =3 we have 1 longest increasing subsequence till index=2
// index=3 and nums[3]=4 now till index =3 we have longest increasing subsequence is {1,3,4} so dp[3]=3 i.e length of longest increasing subsequence till index =3 and count[3]=1 because for length=3 we have 1 longest increasing subsequence till index=3
// index=4 and nums[4]=7 now till index=4 we have two  longest increasing subsequences - i) {1,3,4,7} and ii) {1,3,5,7} so dp[4]=4 i.e length of longest increasing subsequence till index=4 and count[4]=2 because for length=4 we have 2 longest increasing subsequences till index=4

// so now dp and count array are:
// dp[]=[1,2,3,3,4]
// count[]=[1,1,1,1,2]
// so now here the length of longest increasing subsequence is 4 which is at index=4 so number of longest increasing subsequences here are count[4]=2

// assume if we have like dp[]=[1,2,3,4,4]
// count[]=[1,1,1,2,2]
// now here we have length of longest increasing subsequence is 4 but we have at two index: at index=3 and at index=4 so the number of longest increasing subsequences here are count[3]+count[4]=2+2=4

// so now in code of LIS we have :
// for (index=0;index<n;index++){
// for(prev=0;prev<index;prev++){
// if(arr[prev]<arr[index]&& 1+dp[prev]>dp[index]){
// dp[index]=1+dp[prev]
// count[index]=count[prev]
//}
// here we have one more condition when 1+dp[prev]==dp[index] because here we count number of longest increasing subsequences so if we get same length from another subsequence also then we add count[prev] with count[index] so
// else if(arr[prev]<arr[index] && 1+dp[prev]==dp[index]){
// but in this case length still same because 1+dp[prev]==dp[index] only count increase so
// count[index]+=count[prev]
// }
// }
//}

// after that in dp array in any index we have length of longest increasing subsequence we add the count value of that indexes because we want number of longest increasing subsequences

// we use the code of LIS with slight changes
// t.c-O(n^2)(for calculating dp and count array)+O(n)(for numberofsequence)
// s.c-O(2*n)for dp and count 1D array
int numberOfLIS(vector<int> &nums, int n)
{
  vector<int> dp(n, 1), count(n, 1); // both are initialized with value=1 because itself is also a subsequence
  int maxi = 1;                      // length of longest increasing subsequence
  for (int index = 0; index < n; index++)
  {
    for (int prev = 0; prev < index; prev++)
    {
      // first case when we get new longest increasing subsequence at that index so
      if (nums[prev] < nums[index] && (1 + dp[prev]) > dp[index])
      {
        dp[index] = 1 + dp[prev];
        count[index] = count[prev];
      }
      // another case when we got same length that dp[index] already have but from another subsequence so length still same but count increase by prev of that count because we get same length of the longest increasing subsequence till that index from another subsequence also so
      else if (nums[prev] < nums[index] && (1 + dp[prev]) == dp[index])
      {
        // length same only count increase
        count[index] += count[prev];
      }
    }
    // length of longest increasing subsequence
    maxi = max(maxi, dp[index]);
  }
  // by using maxi we track count for same length of longest increasing subsequence
  int numberOfSubsequence = 0;
  for (int i = 0; i < n; i++)
  {
    if (maxi == dp[i])
    {
      numberOfSubsequence += count[i];
    }
  }
  return numberOfSubsequence;
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
  cout << numberOfLIS(nums, n);
  return 0;
}

// one more example we take to understand:
// nums[]=[1,5,4,3,2,6,7,10,8,9]

// initialized dp and count array with value=1
// dp[]=[1,1,1,1,1,1,1,1,1,1]
// count[]=[1,1,1,1,1,1,1,1,1,1]

// now start from index=0
// at index=0 we have nums[0]=1, there is only one subsequence which is {1} so dp[0]=1 already we have and count[0]=1 because we have only 1 longest increasing subsequence of length 1 till index 0

// index=1 and nums[1]=5 now till index =1 we have longest increasing subsequence is {1,5} so dp[1]=2 i.e length of longest increasing subsequence till index =1  and count[1]=1 still because for length =2 we have 1 longest increasing subsequence till index=1

// index=2 and nums[2]=4 now till index =2 we have longest increasing subsequence is {1,4} so dp[2]=2 i.e length of longest increasing subsequence till index =2  and count[2]=1 still because for length =2 we have 1 longest increasing subsequence till index=2

// index=3 and nums[3]=3 now till index =3 we have longest increasing subsequence is {1,3} so dp[3]=2 i.e length of longest increasing subsequence till index =3  and count[3]=1 still because for length =2 we have 1 longest increasing subsequence till index=3

// index=4 and nums[4]=2 now till index =4 we have longest increasing subsequence is {1,2} so dp[4]=2 i.e length of longest increasing subsequence till index =4  and count[4]=1 still because for length =2 we have 1 longest increasing subsequence till index=4

// index=5 and nums[5]=6 now till index =5 we have longest increasing subsequence of length =3  are - i){1,5,6} ii){1,4,6} iii){1,3,6} iv){1,2,6} so dp[1]=3 i.e length of longest increasing subsequence till index =5  and count[5]=4  because for length =3 we have 4 longest increasing subsequence till index=5

// index=6 and nums[6]=7 now till index =6 we have longest increasing subsequence of length=4 are - i){1,5,6,7} ii){1,4,6,7} iii){1,3,6,7} iv){1,2,6,7}  so dp[6]=4 i.e length of longest increasing subsequence till index =6  and count[6]=4 because for length =4 we have 4 longest increasing subsequence till index=6

// index=7 and nums[7]=10 now till index =7 we have longest increasing subsequence of length=5 are - i){1,5,6,7,10} ii){1,4,6,7,10} iii){1,3,6,7,10} iv){1,2,6,7,10}  so dp[7]=5 i.e length of longest increasing subsequence till index =7  and count[7]=4 because for length =5 we have 4  longest increasing subsequence till index=7

// index=8 and nums[8]=8 now till index =8 we have longest increasing subsequence of length=5 are - i){1,5,6,7,8} ii){1,4,6,7,8} iii){1,3,6,7,8} iv){1,2,6,7,8}  so dp[8]=5 i.e length of longest increasing subsequence till index =8  and count[8]=4 because for length =5 we have 4 longest increasing subsequence till index=8

// index=9 and nums[9]=9 now till index =9 we have longest increasing subsequence of length=6 are - i){1,5,6,7,8,9} ii){1,4,6,7,8,9} iii){1,3,6,7,8,9} iv){1,2,6,7,8,9}  so dp[9]=6 i.e length of longest increasing subsequence till index =9  and count[9]=4 because for length =6 we have 4 longest increasing subsequence till index=9

// so now dp and count array are
// dp[]=[1,2,2,2,2,3,4,5,5,6]
// count[]=[1,1,1,1,1,4,4,4,4,4]

// now we get length of longest increasing subsequence is 6 which is at index=9 only so number of longest increasing subsequences are count[9]=4