// two pointers/sliding window- it is not a specific algo. , it is constructive algo. which keeps on changing A.T problem statement
// only that stays constant is the window, we keep on moving the window

// how we move the window is depend on the answer?

// we have so many pattern and template here we discuss about it and use in problem and also A.T problem we modify it

#include <bits/stdc++.h>
using namespace std;

// pattern1- CONSTANT WINDOW - mostly not ask in interview

// example - we have an array and an integer k, we have to find the maxsum of k consecutive elt of an array
// here k is constant window  length means we can take k elt of an array at a time

// arr=[-1,2,3,3,4,5,-1], k=4
// so we use two pointers/sliding window with constant

// t.c-O(n) in worst case when k=n so l=0 and r=n-1
// s.c-O(1)
int maxSumOfkElt(vector<int> &nums, int k)
{
  int n = nums.size();
  if (k > n)
    return 0;
  int l = 0, r = k - 1; // we take constant window

  int sum = 0;
  // first we take sum of l to r window
  for (int i = l; i <= r; i++)
  {
    sum += nums[i];
  }

  int maxSum = INT_MIN;
  // now we slide the constant window one by one to get maxsum
  // for next k consecutive elt
  while (r < n - 1)
  {

    // subtract nums[l] in sum
    sum = sum - nums[l];
    l++;
    r++;
    // add nums[r] in sum
    sum = sum + nums[r];
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}

// pattern-2 find longest subarray/substring with given condition most common problem in most of the interview ask
// we have 3 formats for these type of problems- brute,better,optimal

// example- given an array and an integer k find the longest subarray with sum <=k
// arr=[2,5,1,7,10] and k=14
// subarray - consecutive elt of an array- can be single elt or entire array or consecutive portion of an array

// brute solution- generate all subarray with sum<=k

// t.c-O(n^2)
// s.c-O(1) where n is size of array nums
int maxLenSubarraySum(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxlen = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum = sum + nums[j];
      if (sum <= k)
      {
        maxlen = max(maxlen, j - i + 1);
      }
      else if (sum > k)
        break;
    }
  }
  return maxlen;
}

// better solution- two pointers/sliding window- size of window changes every time
// we will start with a window size of one i.e l=r=0 initially
// we sue sliding window here
// window will always has two pointers- left(l) and right(r)
// left- signifies the leftmost portion of the window
// right- signifies the rightmost portion of the window

// initially sum=0 for our example
// we have 2 concept-
// expand- we use right(r) for the right edge of window
// shrink- we use left(l) for the left edge of window

// maxlen=max(maxlen,r-l+1)

// upto the condition is valid we expand the window
// whenver the condition is invalid we shrink the window by moving left pointer
// and we shrink one by one till the condition is invalid once the condition valid we again start expane the window

// template- l=0,r=0,sum=0,maxlen=0 here only sum is variable else all are constant in the template because sum is change whenever we shrink or expand

// this is the pattern of the template which is followed everywhere - all are constant only one is variable i.e sum here
// t.c-O(n(for outer loop)+n(for inner while loop))=O(2n), never be O(n^2) where n is size of array nums
// s.c-O(1)
int maxLenSubarraysum(vector<int> &nums, int k)
{
  int n = nums.size();
  int l = 0, r = 0, sum = 0, maxlen = 0; // template

  // run n times
  while (r < n)
  {
    sum = sum + nums[r];

    // when condition is invalid shrink until conditiion is valid
    //  inner while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey, shrink is done only in some steps, not in all steps and in that some steps by adding them all it can be travel whole array so
    while (sum > k)
    {
      sum = sum - nums[l];
      l = l + 1; // shrink the window
    }
    if (sum <= k)
    {
      // if you want to print maxlen subarray then store l and r also here
      maxlen = max(maxlen, r - l + 1);
    }
    r = r + 1; // expand the window
  }
  return maxlen;
}

// optimal solution- this is only when we want maxlen, this cannot we use to print maxlen subarray
// in this we try to remove inner while loop
// how?
// we reduce inner while loop to if condition when the condition is invalid shrink the window only ny one place because we know maxlen and when condition is invalid currentlength is different so we try to shrink the window only by one place to match current length with maxlen because going beyond maxlen has no matlab because we want maxlen so if we go beyond this have no matlab so we shrink only by one

// t.c-O(n) for outer while loop
// s.c-O(1) where n is size of array nums
int maxlenSubarraysum(vector<int> &nums, int k)
{
  int n = nums.size();
  int l = 0, r = 0, sum = 0, maxlen = 0; // template

  // run n times
  while (r < n)
  {
    sum = sum + nums[r];

    // when condition is invalid shrink only by one place which takes O(1) time now

    if (sum > k)
    {
      sum = sum - nums[l];
      l = l + 1; // shrink the window
    }
    if (sum <= k)
    {
      // if you want to print maxlen subarray then store l and r also here
      maxlen = max(maxlen, r - l + 1);
    }
    r = r + 1; // expand the window
  }
  return maxlen;
}

// pattern3- find number of subarrays with some given condition
// if we directly use two pointers here it is difficult to count subarray with given condition
// it give wrong answer, we cannot figure out where to move l and r

// example- find  number of subarray with sum = goal, it is not length so whenever the constant condition is there it is very tough to reliaze whether to expand or whether to shrink in such scenarion we break problem into two problem-
// i) find number of subarray with sum <=goal
// ii) find number of subarray with sum <=goal-1

// so number of subarray with sum =goal is equal to (x-y) where

// x=  number of subarray with sum <=goal
// y= number of subarray with sum <=goal-1
// and we find x and y by using pattern 2

// pattern4- shortest/minimum window with given condition
// also a rare case scenarion, not ask lot of time
// similar to better solution of pattern-2
// we this pattern-4 in minimum window substring question

// most use pattern is 2 with all format - brute,better,optimal and remember its template also

int main()
{

  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt of an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int k;
  cout << "Enter the value of k: ";
  cin >> k;
  // int answer = maxSumOfkElt(nums, k);
  // cout << "Max sum of k consecutive elts: " << answer << endl;
  // int result = maxLenSubarraySum(nums, k);
  // int result = maxLenSubarraysum(nums, k);
  int result = maxlenSubarraysum(nums, k);
  cout << "maxlength of subarray having sum less than equal to k: " << result << endl;
  return 0;
}