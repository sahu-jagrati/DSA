// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

#include <bits/stdc++.h>
using namespace std;

// here we solve this problem by recursion in next we solve this by binary search

// we know what is subsequence?
// A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].

// now we have to find the longest increasing subsequence
// let's take an example
// nums[]=[10,9,2,5,3,7,101,18]
// if we try out different types of subsequences then we can say one of them is :
// i) [10,101] with length=2
// ii) [9,101] again with length=2
// iii) [5,7,101] with length=3
// iv) [2,3,7,101] with length=4
// v) [2,3,7,18] with length=4
// in question we want longest increasing subsequence so here the length of the longest increasing subsequence is 4

// we remember that in all the subsequence problems we followed a simple pattern that was a pick or notpick means that we either take that guy or we did not take that guy

// if we take one more example-
// nums[]=[7,7,7,7]
// here the length of longest increasing subsequence is 1 because in question it mention we want strictly increasing subsequence we cannot take equal elts it has to be incresing so the length of longest increasing subsequence here is 1 and the subsequence is [7].

// now how do we solve this particular problem?
// we know there can be various subsequences which can be answers so the first thing that comes let's try out various subsequences and to print all subsequences we use two methods - i) power set ii) recursion
// either we can use power set or we can use recursion to generate all the subsequences
// once we have generated subsequences then we can easily see if it is increasing or not then we check for increase that is the brute force generate all the subsequences check for increase and store the longest among them . we know in order to generate all the subsequences we end up taking 2^n time for a length of array n which is exponential in nature and this will give us a time linit exceed so the brute force will definitely not work.

// then what we are trying?
// we are trying all ways and we know we can do this by recursion

// rule to write recursion is:
// i) express everything  in terms of index
// ii) explore all possiblities, there are two possibilities:  i) this can be a part of my subsequence(take) ii) this can not be a part of my subsequence(nottake)
// iii) then take the longest means take the max length(take,nottake)

// let's take an example:
// nums[]=[10,9,2,5,3,7,101,18]
// i) express everything  in terms of index
// here we are given an array so index will also be there which  we can start from 0th index

// ii) now this 0th index portion can be a part of my subsequence or can not be a part of my subsequence because it is the first elt and we can say this can be a part of my subsequence or cannot be. we will say i'll form a subsequence which has a 10 (nums[0]) or either we will say i'll not take nums[0] as subsequence now imagine this 10 to be the part of the longest increasing subsequence no we move to the next index which is nums[1]=9 now Can 9 be the part of the same subsequence? the answer is no because we previously took 10 and we are looking for increasing so we cannot have 9 as the part of this particular subsequence so what we judge here we previously took 10 so we cannot take 9 at the current index yes we have to keep a store of the previous index that decide whether we have to take the current index or not so for 9 previous index is 0th index which is nums[0]=10

// what I can say is I can express the recurrence in terms of index and previous index i.e (index,prev_index) because previous allows us to make a choice whether we can include current index in my subsequence or not so we need to know who is ths previous so we also carry the previous index

// f(index,prev_index)
// initially we starting recurrence with f(0,-1) means basically saying 0th index is the first guy and since it is the first guy so there is no previous index so we take prev_index initially = -1 now f(0,-1) signify that give me the length of longest increasing subsequence from 0th index with no previous elt if we write f(3,0) means give me length of LIS starting from 3rd index whose previous index is 0.

// f(index,prev_index){

// i) base case
// as we start recursion from 0th index so
// when we do we end ? we know in subsequences we end when we run out of elts so can I say after n-1 the next one will be n I still run out of elts at the nth index so
// if(index==n) I am running out of index I don't have any more elts so if I don't have any more elts what will be the length? I will give you a length=0 because I don't have anything so
// if(index==n)return 0

// ii) explore possibilities:i) either this guy is a part of subsequence  ii) or this guy is not a part of subsequence
// i) when it(i.e the current index ) is not a part of subsequence then we move to the next index and if this particular index is not the part of the subsequence then Can I say that the previous_index still stays the same and we have to return the length so Will the length increas? answer is no so
// length= 0+f(index+1,prev_index) // when we nottake the current index  // length increase=0 because it is not a part of subsequence so length not increase

// ii) when the current index  is a part of my subsequence
// let's take an above example if we are at f(0,-1) we say we'll take 10 and we move to next index so now prev_index is update and prev_index=0 and current index=1 and the length will also indcrease by 1 because we take 10 in our subsequence now we are at 9 and we have again two choices that we can take 9 or we cannot take 9 so when we take 10 in our subsequence Can we take 9? No, why because we are looking for an increasing subsequence and 9 is less than 10 so it is not increasing  so we get a pattern that if prev_index==-1 then we can take it or if nums[prev_index]<nums[index] that means sequence is increasing so we can take the current index and increase the length by 1 and update the prev_index
// if(prev_index==-1 || nums[prev_index]<nums[index]){
// length=max(length, 1+f(index+1,index) ) // when we take the current index
//}

// return length;
//}

// t.c for recursion: 2^n because for every index we are having two options take or nottake
// s.c for recursion: O(n) auxiliary stack space

// now there are overlapping subproblems so we optimize it by memoization

// we have two changing parameters : (index , prev_index)
// index go from 0 to n-1 so maximum index can be n and what's the next thing? prev_index but there is a problem with prev_index this starts from -1 and goes to n-1 so if we are using a 2D array how do we store -1 because we cannot take an index=-1 as in arrays index starts from 0 so what we do is that? we increase the index by 1 i.e for -1 it become 0, for 0 it become 1, for it become 2, .... for n-1 it become n so we will shift the index by 1 so now prev_index go from 0 to n which means if we take n+1 that  will suffice so we do coordinate shift by 1

// so we will declare dp[n][n+1]

// t.c-O(n*n)
// s.c-O(n*n)(for dp)+O(n)(for auxiliary stack space)

// recursion here start from 0th index initially
// t.c-O(2^n)
// s.c-O(n) for auxiliary stack space
int f1(int index, int prev_index, vector<int> &nums, int n)
{
  // base case when we ran out of elts
  if (index == n)
    return 0;

  // when we don't take current index elt then length does not change and prev_index also not change and we move to next index
  int length = 0 + f1(index + 1, prev_index, nums, n);
  // when we take current index elt then length change if it is maximum then prev length and prev_index also update
  // we want strictly increasing subsequence
  if (prev_index == -1 || nums[prev_index] < nums[index])
  {
    length = max(length, 1 + f1(index + 1, index, nums, n));
  }

  return length;
}

// memoization
// t.c-O(n*n)
// s.c-O(n*n)(for dp)+O(n)(for auxiliary stack space)
// it give time limit exceed if n goes to 10^5 because n*n become 10^5 * 10^5 = 10^10 for dp
int f2(int index, int prev_index, vector<int> &nums, int n, vector<vector<int>> &dp)
{
  // base case when we ran out of elts
  if (index == n)
    return 0;

  // we do prev_index+1 because for prev_index we shift by 1 because in array we cannot store -1 so we shift by 1
  if (dp[index][prev_index + 1] != -1)
    return dp[index][prev_index + 1];
  // when we don't take current index elt then length does not change and prev_index also not change and we move to next index
  int length = 0 + f1(index + 1, prev_index, nums, n);
  // when we take current index elt then length change if it is maximum then prev length and prev_index also update
  // we want strictly increasing subsequence
  if (prev_index == -1 || nums[prev_index] < nums[index])
  {
    length = max(length, 1 + f1(index + 1, index, nums, n));
  }

  return dp[index][prev_index + 1] = length;
}

// tabulation
// rules
// 1. write base case
// 2. write changing parameter in opposite fashion of recursion
// 3. copy the recurrence

// 1.  in recursion we have base case if(index==n) return 0
// so first we declare the dp[n+1][n+1] as for index==n we return 0 in recursion so for tabualtion we have to go for index 0 to n for storing index=n so we declare dp[n+1][n+1] since everything is already assigned to 0 we don't need to specifically write for the base case

// 2.  as in recursion for index we go from 0 to n and for prev_index go from -1 to n-1 so in tabulation we go from n to 0 and for prev_index we go from n-1 to -1 as we cannot store -1 as an index in array so we shift index by 1 so we go from n to 0 but prev_index is depend upon current index so it goes from index-1 to 0 because it cannot be beyond current index

// t.c-O(n*n)
// s.c-O(n*n) for dp
// it give time limit exceed if n goes to 10^5 because n*n become 10^5 * 10^5 = 10^10 for dp
int f3(vector<int> &nums, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // we declare [n+1][n+1] because for index==n it return 0 as a base case so for storing index=n we want dp[n+1][]

  // as we already assign 0 during declare so we don't write base case specifically

  // as for index==n already done in base case so we go for index from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {
    // as prev_index depend upon current index so it go from index-1 to 0
    for (int prev_index = index - 1; prev_index >= -1; prev_index--)
    {
      // when we don't take current index elt then length does not change and prev_index also not change and we move to next index

      // we do prev_index+1 because we cannot store -1 as an index in an array so we do coordinate shift by 1
      int length = 0 + dp[index + 1][prev_index + 1];
      // when we take current index elt then length change if it is maximum then prev length and prev_index also update
      // we want strictly increasing subsequence
      if (prev_index == -1 || nums[prev_index] < nums[index])
      {
        // as when we take current elt in our subsequence so we move to next index and current index become prev_index so prev_index=index but prev_index can be -1 also that cannot be store in an array so we shift by 1 so now prev_index update to index+1
        length = max(length, 1 + dp[index + 1][index + 1]);
      }

      // prev_index+1 because of coordinate shift for -1
      dp[index][prev_index + 1] = length;
    }
  }
  return dp[0][-1 + 1]; // we write -1+1 because of coordinate shift for -1
}

// space optimization
// as for calculating dp[index][] we want dp[index+1][] so we want only ahead row not entire matrix so we do space optimization

// t.c-O(n*n) // it give time limit exceed if n goes to 10^5 because n*n become 10^5 * 10^5 = 10^10
// s.c-O(n*2) for ahead and curr  1D array

int f4(vector<int> &nums, int n)
{
  vector<int> ahead(n + 1, 0), curr(n + 1, 0);

  // as we already assign 0 during declare so we don't write base case specifically

  // as for index==n already done in base case so we go for index from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {
    // as prev_index depend upon current index so it go from index-1 to 0
    for (int prev_index = index - 1; prev_index >= -1; prev_index--)
    {
      // when we don't take current index elt then length does not change and prev_index also not change and we move to next index

      // we do prev_index+1 because we cannot store -1 as an index in an array so we do coordinate shift by 1
      int length = 0 + ahead[prev_index + 1];
      // when we take current index elt then length change if it is maximum then prev length and prev_index also update
      // we want strictly increasing subsequence
      if (prev_index == -1 || nums[prev_index] < nums[index])
      {
        // as when we take current elt in our subsequence so we move to next index and current index become prev_index so prev_index=index but prev_index can be -1 also that cannot be store in an array so we shift by 1 so now prev_index update to index+1
        length = max(length, 1 + ahead[index + 1]);
      }

      // prev_index+1 because of coordinate shift for -1
      curr[prev_index + 1] = length;
    }
    ahead = curr;
  }
  return ahead[-1 + 1]; // we write -1+1 because of coordinate shift for -1
}

// so Can we say space optimization is the best solution?
// no the best solution uses a like weird method tabulation method, tabulation method in different way for that see "Printing Longest Increasing Subsequence file "
int longestIncreasingSubsequence(vector<int> &nums, int n)
{
  // recursion
  // start from index=0 and for that prev_index=-1
  // return f1(0, -1, nums, n);

  // memoization
  // we shift index by 1 for prev_index because of  prev-index == -1
  // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  // return f2(0, -1, nums, n, dp);

  // tabulation
  // return f3(nums,n);

  // space optimization
  return f4(nums, n);
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
  cout << longestIncreasingSubsequence(nums, n);
  return 0;
}