// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
// Example 3:

// Input: arr = [1], k = 1
// Output: 1

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 10^9
// 1 <= k <= arr.length

#include <bits/stdc++.h>
using namespace std;

// the problem state that we are given an array like
// arr=[1,15,7,9,2,5,10] and we'll be given a certain k=3
// we need to partition the array such that none of the partitions have more than length k=3
// like if we partition given array like this [1,15,7,9] so this partition length is 4 which is greater that k=3 so this partition is not allowed, we can partition at max length 3
// for an example if I decide that partitions are:
// i) [1,15] here length is 2 <k=3
// ii) [7,9,2] here length is 3<=k=3
// iii) [5,10] here length is 2 <=k=3
// so these partitions are allowed because each partition length is atmost k
// so all of these are allowed now once we have done the partition, the partition array changes to its maximum means like
// in i) partition maximum =15 so this partition array changes to [15,15] means all of its elts become 15
// for ii) partition maximum = 9 so they changes to 9 like [9,9,9]
// in iii) partition maximum = 10 so that array changes to [10,10]

// so once it has changed we get summation of them so
// i) 15+15=30
// ii) 9+9+9=27
// iii) 10+10=20
// so total=30+27+20=77
// so if I decide to do a partition like this we get 77 as a summation

// but we want maximum summation

// so if I do partition like this
// i) [1,15,7]
// ii) [9]
// iii) [2,5,10]
// each partitions are allowed having length atmost k=3
// now changes them with maximum
// i) [15,15,15], sum=45
// ii) [9], sum=9
// iii) [10,10,10], sum=30
// so total we get is 45+9+30=84

// so we get 84 by this valid partition which is greater than 77
// so maximum summation we get for this array is 84

// so we have to do a partition in such a way that we get the maximum summation so make sure the summation is maximized

// this question is similar to the question "Palindrome Partitioning II" in that we was using the 'front partition logic'

// we see that over here there can be various recurrences because if this is an array we can have multiple partitions
// arr=[1,15,7,9,2,5,10],k=3 this is an array and there can be various partitions like we have i) partition [1,15,7] ii) partition [9] iii) [2,5,10] or we can do partition like this also i) [1,15] ii) [7,9,2] iii) [5,10] or there are various way of partition it

// whenever we know that there are various ways to solve the problem what do we do? we tend to try out all ways and try out all ways there is only one possibilities that is the recursion and out of all ways we take the best possible way to solve the problem

// rules to write the recurrence:
// 1. Express everything in terms of an index
// here we have an array so definitely we have an index so we can express the array in terms of index
// 2. try all possible partitions from that index
// 3. take the best partition here we want the maximum summation so from all possibilities take the maximum
// 4. write the base case

// we will be starting with
// f(index) - this problem is similar to "Palindrome Partitioning II" so we will be using front partition logic

// for an example we have:
// arr=[1,15,7,9,2,5,10] and k=3
// so this was the array
// so f(0)  this means the index value is at the 0th index
// f(0) means give me the maximum sum if we have an array from 0th index means we have an entire array
// [1,15,7,9,2,5,10]
//  index=0
// that means they have an array from index-0 then what is the maximum sum that you can generate  by partitioning it in atmost k length  give me that, when we are at index=0 means we have an entire array

// f(3) means [1,15,7,9,2,5,10]
//                    index=3
// f(3) means give me the maximum sum that we can generate from this portion [9,2,5,10]  by partitioning  it in atmost k length
// f(1) means index=1 so give me the maximum sum that we can generate from this portion [15,7,9,2,5,10] by partitioning  it in atmost k length

// so this is the meaning of f(index) given the maximum sum that can be generated from that index till the end   by partitioning  it in atmost k length

// we done with express everything in terms of an index

// now we try every partitions
// we know that we have to partition the array in such way that the length of partition is atmost k
// here in above example k=3 which states that we cannot have any longer partition than 3

// in our array : arr=[1,15,7,9,2,5,10]
// since we are trying out all partitions from that index
// like we have index=0 so we are at now
//    [1,15,7,9,2,5,10]
//     index=0
// where can the partitions be we can? we can do a partition here [1] | [15,7,9,2,5,10] and solved the portion [15,7,9,2,5,10] in itself again, we can do a partition here also [1,15] | [7,9,2,5,10] then we solved thos portion [7,9,2,5,10] in itself , again we will be like we can do a partition here [1,15,7] | [9,2,5,10] then we solved thos portion [9,2,5,10] in itself , Can we do a partition [1,15,7,9] | [2,5,10] ? No, we cannot because this partition [1,15,7,9] have length=4 but we can do a partition atmost length k so thereby this is not possible so when I have to stop doing the partition - when the partition length crosses the k, so can I say this if I'm having an index I can definitely start the partitions like if I try to write it
// for(int j=index;j< min(n,index+k);j++){
// so we can do a partition from the index to index+k
// so what will be - it will definitely be index,index+1,...,index+k becausee we have to do till kth partition we cannot exceed that so from index to index+k we try out all partition and take the best and as index+k might exceeds the last elt so we have to make sure that it is less than n so that's why we take min(n,index+k)
// like we are standing at index=0 so we can do partiton at index=0 then partition at j=1 then partition at j=2 , next can we do partition at j=3 - no because it exceed the k so we go till index+k

// so Can I say if in above example if we do partition and start from index=0 assume if a partition is here [1,15,7] and assume j is at 7 i.e at index=2 can I say till here the summation of this portion what does this array changes [15,15,15] it changes to the maximum value so if I ask what is the sum of that portion? it is length of that portion * maximum elt i.e (len*maxi) so I take the two variable - len and maxi where len count the length of that portion and maxi will track the maximum of that portion  so sum=(len*maxi) + the remaining portion that has to be solved by itself which is f(j+1)
//}

// f(index){

// base case as we traverse in terms of an index and we try out all partition so if our index reaches the last index then there will be no partitions so we return 0 as the summation
// if(i==n)return 0

// maxSum;
// len=0,maxi=INT_MIN;  // track of that partition portion
// try out all partitions from index to till kth partition so
// for(int j=index;j<min(index+k);j++){
// len++;
// maxi=max(maxi,arr[j]); // track of maximum elt of that portion
// sum=(len*maxi)+f(j+1)
// maxSum=max(maxSum,sum);
//}
// return maxSUm; // maxSUm is the best possible summation that we can get by partitioning the given array by trying out all partitions with given condition k
//}

// so we used the front partition logic that we start with partition from index=0 and try out all possible partitions with length atmost k  and front partition also maintain the contiguous sub-arrays that is take the elts in same order in which they are given

// try with pen and paper for more understanding

// recursion
// t.c- exponential in nature
// s.c-O(n) auxiliary stack space

int f1(int index, int n, int k, vector<int> &nums)
{
  // base case when we reach end there is no partition
  if (index == n)
    return 0;

  int maxSum = INT_MIN;
  // track the length and maximum elt of the partition subarray
  int len = 0, maxi = INT_MIN;
  // try out all possible partition
  for (int j = index; j < min(n, index + k); j++)
  {
    len++;
    maxi = max(maxi, nums[j]);
    // summmation of that partition is (len*maxi) + the part that solved by itself
    int sum = (len * maxi) + f1(j + 1, n, k, nums);
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}

// memoization
// there can be overlapping subproblems so we apply memoization
// we have one changing parameter index which go from 0 to n-1 so we declare dp[n] 1D array

// t.c-O(n*k), there are total n states, index runs from 0 to n-1, where n is the length of array and for every state we check all subarrays of length k.

// s.c-O(n)(for dp array)+O(n)(for auxiliary stack space)

int f2(int index, int n, int k, vector<int> &nums, vector<int> &dp)
{
  // base case when we reach end there is no partition
  if (index == n)
    return 0;

  if (dp[index] != -1)
    return dp[index];

  int maxSum = INT_MIN;
  // track the length and maximum elt of the partition subarray
  int len = 0, maxi = INT_MIN;
  // try out all possible partition
  for (int j = index; j < min(n, index + k); j++)
  {
    len++;
    maxi = max(maxi, nums[j]);
    // summmation of that partition is (len*maxi) + the part that solved by itself
    int sum = (len * maxi) + f1(j + 1, n, k, nums);
    maxSum = max(maxSum, sum);
  }
  return dp[index] = maxSum;
}

// tabulation
// 1. write base case
// 2. write changing parameter in opposite fashion of recursion
// 3. copy the recurrence

// t.c-O(n*k), there are total n states and for every state we check all subarrays of length k.
// s.c-O(n) for dp array

int f3(int n, int k, vector<int> &nums)
{
  // we declare dp of size n+1 because for base we have to store index==n
  vector<int> dp(n + 1, 0);
  // base case when we reach end in recursion we have if(index==n)return 0; so here
  dp[n] = 0;
  // as in recursion index parameter go from 0 to n-1 so in tabulation it go in opposite fashion so it go from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {

    int maxSum = INT_MIN;
    // track the length and maximum elt of the partition subarray
    int len = 0, maxi = INT_MIN;
    // try out all possible partition
    for (int j = index; j < min(n, index + k); j++)
    {
      len++;
      maxi = max(maxi, nums[j]);
      // summmation of that partition is (len*maxi) + the part that solved by itself
      int sum = (len * maxi) + dp[j + 1];
      maxSum = max(maxSum, sum);
    }
    dp[index] = maxSum;
  }
  return dp[0];
}

int maxSumAfterPartitioning(vector<int> &nums, int k)
{
  int n = nums.size();

  // recursion  initially we start from index=0 to partition the given string which is a front partition technique
  // in starting we have an entire array
  // return f1(0, n, k, nums);

  // memoization
  // vector<int> dp(n, -1);
  // return f2(0, n, k, nums, dp);

  // tabulation
  return f3(n, k, nums);
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
  int k;
  cin >> k;
  cout << maxSumAfterPartitioning(nums, k);
  return 0;
}
