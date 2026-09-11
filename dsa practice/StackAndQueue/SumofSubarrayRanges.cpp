// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
// Example 2:

// Input: nums = [1,3,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [3], range = 3 - 3 = 0
// [3], range = 3 - 3 = 0
// [1,3], range = 3 - 1 = 2
// [3,3], range = 3 - 3 = 0
// [1,3,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
// Example 3:

// Input: nums = [4,-2,-3,4,1]
// Output: 59
// Explanation: The sum of all subarray ranges of nums is 59.

// Constraints:

// 1 <= nums.length <= 1000
// -10^9 <= nums[i] <= 10^9

// Follow-up: Could you find a solution with O(n) time complexity?

#include <bits/stdc++.h>
using namespace std;

// brute force solution: we generate each subarray and calculate the largest and smallest elt in the subarray

// example: nums=[1,4,3,2]
// range=largest-smallest
// for index 0 subarrays are:
// subarray           largest        smallest     range
// 1                      1            1          0
// 1 4                    4            1          3
// 1 4 3                  4            1          3
// 1 4 3 2                4            1          3

// for index 1 subarrays are:
//  4                    4             4          0
//  4 3                  4             3          1
//  4 3 2                4             2          2

// for index 2 subarrays are:
//   3                   3             3          0
//   3 2                 3             2          1

// now we want sum of all subarray ranges of nums so sum=(0+3+3+3) + (0+1+2) + (0+1) = 13 our answer

// so that's is a brute force solution
// one thing we noticed that subarray of size 1 has no contribution in sum because for that largest=smallest so range =0 so sum+=0=sum
// so in nested loop we start from j=i+1 instead of j=1

// t.c-O(n^2)
// s.c-O(1)
long long subArrayRanges(vector<int> &nums)
{
  int n = nums.size();
  // i use long long because constraints are so large
  long long sum = 0;
  // generate all subarray
  for (int i = 0; i < n; i++)
  {
    // take largest and smallest for each subarray for now nums[i]
    long long largest = nums[i];
    long long smallest = nums[i];
    // we run j loop from i+1 to n-1 , not from i to n-1 because single size subarray has no contribution
    for (int j = i + 1; j < n; j++)
    {
      // update largest and smallest for the subarray
      largest = max(largest, (long long)nums[j]);
      smallest = min(smallest, (long long)nums[j]);
      // add range of all subarrays in sum
      sum = sum + (largest - smallest);
    }
  }
  return sum;
}

// now optimal solution: this is done by using the problem "Sum of subarray Minimum" and similary we get "Sum of subarray Maximum"

// we done previously problem "Sum of subarray Minimum" in that we take a minimum elt of all subarrays and take a sum of that minimums
// and similarly we can calculate "Sum of subarray Maximum" in that we take a maximum elt of all subarrays and take a sum of that maximums
// suppose we have nums=[1,4,3,2]
// // for index 0 subarrays are:
// subarray           minimum         maximum
// 1                      1            1
// 1 4                    1            4
// 1 4 3                  1            4
// 1 4 3 2                1            4

// for index 1 subarrays are:
//  4                    4             4
//  4 3                  3             4
//  4 3 2                2             4

// for index 2 subarrays are:
//   3                   3             3
//   3 2                 2             3

// as range=largest-smallest and sum+=range
// we get largest and smallest from above for each subarray so we get range and add in sum
// sum= (1-1)+(4-1)+(4-1)+(4-1)+(4-4)+..... +(3-2)=13
// if we notice
// sum = summation of all maximum of the subarrays - summation of all minimums of the subarrays
// i.e
// sum = "Sum of all subarray maximum" - "Sum of all subarray Minimum"
// and we know how to get "Sum of all subarray Minimum" we done it in previous problem and similarly we get "Sum of all subarray Maximum"

// Algorithm:

// Find the index of the next smaller elt to the right for each elt using NSE(next smaller elt) logic.
// Find the index of the previous smaller or equal elt to the left using PSEE logic.
// Find the next greater elt to the right for each elt using NGE logic.
// Find the index of the previous greater or equal elt to the left using PGEE logic.
// Use NSE and PSEE to calculate the total contribution of each elt as the minimum in subarrays.
// Use NGE and PGEE to calculate the total contribution of each elt as the maximum in subarrays.
// Subtract the total of subarray minimum from the total of subarray maximums.
// Return the result as the sum of ranges of all subarrays.

// function to find the indices of next smaller elts
vector<int> findNSE(vector<int> &nums)
{
  int n = nums.size();
  // to store answer as indices
  vector<int> ans(n);
  // stack
  // we store indices in stack
  stack<int> st;
  // start traversing from back because we wnat next smaller elt
  for (int i = n - 1; i >= 0; i--)
  {
    // get the current elt
    int currElt = nums[i];
    // pop the elts in the stack until the stack is not empty and the top elt is not the smaller elt
    // as we store indices in stack so
    while (!st.empty() && nums[st.top()] >= currElt)
    {
      st.pop();
    }
    // update the answer
    ans[i] = !st.empty() ? st.top() : n; // store index
    // push the index of current elt in the stack
    st.push(i);
  }
  // return the answer
  return ans;
}
// function to find the indices of next greater elt
vector<int> findNGE(vector<int> &nums)
{
  int n = nums.size();
  // to store answer as indices
  vector<int> ans(n);
  // stack
  // we store indices in stack
  stack<int> st;
  // start traversing from back because we want next greater elt
  for (int i = n - 1; i >= 0; i--)
  {
    // get the current elt
    int currElt = nums[i];
    // pop the elts in the stack until the stack is not empty and the top elt is not the greater elt
    // as we store indices in stack so
    while (!st.empty() && nums[st.top()] <= currElt)
    {
      st.pop();
    }
    // update the answer
    ans[i] = !st.empty() ? st.top() : n; // store index
    // push the index of current elt in the stack
    st.push(i);
  }
  // return the answer
  return ans;
}
// function to find the indices of previous smaller or equal elts
vector<int> findPSEE(vector<int> &nums)
{
  int n = nums.size();
  // to store answer as indices
  vector<int> ans(n);
  // stack
  // we store indices in stack
  stack<int> st;
  // start traversing from front because we want  previous smaller or equal elts
  for (int i = 0; i < n; i++)
  {
    // get the current elt
    int currElt = nums[i];
    // pop the elts in the stack until the stack is not empty and the top elts are greater than the current elt
    // as we store indices in stack so
    while (!st.empty() && nums[st.top()] > currElt)
    {
      st.pop();
    }
    // update the answer
    ans[i] = !st.empty() ? st.top() : -1; // store index
    // push th index of current elt in the stack
    st.push(i);
  }
  // return the answer
  return ans;
}
// function to find the indices of previous greater or equal elts
vector<int> findPGEE(vector<int> &nums)
{
  int n = nums.size();
  // to store answer as indices
  vector<int> ans(n);
  // stack
  // we store indices in stack
  stack<int> st;
  // start traversing from front because we want  previous greater or equal elts
  for (int i = 0; i < n; i++)
  {
    // get the current elt
    int currElt = nums[i];
    // pop the elts in the stack until the stack is not empty and the top elts are smaller than the current elt
    // as we store indices in stack so
    while (!st.empty() && nums[st.top()] < currElt)
    {
      st.pop();
    }
    // update the answer
    ans[i] = !st.empty() ? st.top() : -1; // store index
    // push th index of current elt in the stack
    st.push(i);
  }
  // return the answer
  return ans;
}

// function to find the sum of the minimum value in each subarray
// means here we get summation of  all minimums of the subarrays
long long sumSubarrayMins(vector<int> &nums)
{
  vector<int> nse = findNSE(nums);
  vector<int> psee = findPSEE(nums);
  int n = nums.size();
  // to store sum of all minimums
  long long sum = 0;
  // traverse on the array
  for (int i = 0; i < n; i++)
  {
    // count the number of left side  subarrays for the current elt is minimum
    int left = i - psee[i];
    // count the number of right side subarrays for the current elt is minimum
    int right = nse[i] - i;
    // count of total subarrays where current elt is minimum
    long long freq = left * right * 1LL;

    // contribution due to current elt in totalSum is
    long long val = (freq * nums[i] * 1LL);
    // updating the totalsum
    sum = (sum + val);
  }
  // return the computed sum
  return sum;
}

// function to find the sum of the maximum value in each subarray
// means here we get summation of  all maximums of the subarrays
long long sumSubarrayMaxs(vector<int> &nums)
{
  vector<int> nge = findNGE(nums);
  vector<int> pgee = findPGEE(nums);
  int n = nums.size();
  // to store sum of all minimums
  long long sum = 0;
  // traverse on the array
  for (int i = 0; i < n; i++)
  {
    // count the number of left side  subarrays for the current elt is maximum
    int left = i - pgee[i];
    // count the number of right side subarrays for the current elt is maximum
    int right = nge[i] - i;
    // count of total subarrays where current elt is maximum
    long long freq = left * right * 1LL;

    // contribution due to current elt in totalSum is
    long long val = (freq * nums[i] * 1LL);
    // updating the totalsum
    sum = (sum + val);
  }
  // return the computed sum
  return sum;
}

// function to find the sum of subarray ranges in each subarray
// Time Complexity: O(N), since calculating the sum of subarray maximums takes O(N) time and calculating the sum of subarray minimums takes O(N) time.

// Space Complexity: O(N), since calculating the sum of subarray maximums requires O(N) space and calculating the sum of subarray minimums requires O(N) space.
// for detailed explanation of t.c and s.c see problem "Sum of subarray minimum"
long long subarrayRanges(vector<int> &nums)
{
  // return the result
  return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
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
  cout << subArrayRanges(nums) << endl;
  cout << subarrayRanges(nums);

  return 0;
}