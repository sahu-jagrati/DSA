// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation:
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444

// Constraints:

// 1 <= arr.length <= 3 * 10^4
// 1 <= arr[i] <= 3 * 10^4

#include <bits/stdc++.h>
using namespace std;

// example: arr=[3,1,2,4]
// we want a sum of subarray minimums

// if we write all subarray here are:
// and take minimum of them then:

// for index 0:     Minimum
// [3]               3
// [3,1]             1
// [3,1,2]           1
// [3,1,2,4]         1

// for index 1:
// [1]               1
// [1,2]             1
// [1,2,4]           1

// for index 2:
// [2]               2
// [2,4]             2

// for index 3:
// [4]               4

// now we take sum of subarray minimum
// sum=3+1+1+1+1+1+1+2+2+4=17
// answer = 17

// brute force solution:

// generate each subarray and track minimum of them and add it in totalSum

// Initialize a variable to hold the total sum, starting from 0
// Start a loop to fix the starting index of the subarray
// Initialize a variable to keep track of the minimum element in the current subarray
// Use an inner loop to extend the subarray to the right
// Update the minimum element as the subarray grows
// Add the current minimum to the total sum
// Repeat this process for all possible subarrays
// Return the total sum after all subarrays are processed

// function to find the sum of the minimum value in each subarray

// t.c-O(n^2)
// s.c-O(1)
int sumSubarrayMins(vector<int> &arr)
{
  int n = arr.size();
  int mod = 1e9 + 7; // mod value because sum can be large so we take modulus

  // to store total sum
  int totalSum = 0;
  // traverse on the array
  for (int i = 0; i < n; i++)
  {
    // to store the minimum of subarray
    int mini = arr[i];
    // nested loop to get all subarrays starting from index i
    for (int j = i; j < n; j++)
    {
      // update the minimum vale
      mini = min(mini, arr[j]);
      // update the sum
      totalSum = (totalSum + mini) % mod;
    }
  }
  // return the computed totalSum
  return totalSum;
}

// optimal approach:
// example: arr=[3,1,2,4]
// we want a sum of subarray minimums

// if we write all subarray here are:
// and take minimum of them then:

// for index 0:     Minimum
// [3]               3
// [3,1]             1
// [3,1,2]           1
// [3,1,2,4]         1

// for index 1:
// [1]               1
// [1,2]             1
// [1,2,4]           1

// for index 2:
// [2]               2
// [2,4]             2

// for index 3:
// [4]               4

// now we take sum of subarray minimum
// we can say sum = summation of (minimum*no.of subarray in which minimum is it )
// like here in this example
// if we see
// minimum=3 is only for 1 subarray so we add 3*1 in our totalSum
// minimum=1 is for 6 subarray so we add 1*6 in our totalSum
// minimum=2 is for 2 subarray so we add 2*2 in our totalSum
// minimum=4 is for 1 subarray so we add 4*1 in our totalSum
// so totalSum= (3*1) + (1*6) + (2*2) + (4*1)=3+6+4+4=17 our answer

// so we have to count no. of subarrays for the number for which it is minimum in that subarray
// here for an example arr=[1,4,6,7,3,7,8,1]
// if we count number of subarrays for which minimum =3
// if we stand at 3 then in right upto 8, 3 is minimum so we have total number of elemets in right=3 i.e [3,7,8] for which minimum=3
// if we stand at 3 and check in left for which minimum=3 then in left upto 4, 3 is minimum so we have total numer of elements in left = 4 i.e [4,6,7,3] for which minimum=3

// we see that for this part [4,6,7,3,7,8] if we make subarrays that include 3 in it  then minimum = 3
// so we have to count number of subarrays for which minimum = 3
// if I ask you what is the contribution of this particular 3 and how many subarrays will it be the minimum?
// We will be like-
// in right of 3
// [3] , [3,7] , [3,7,8] for these subarrays 3 will be minimum
// if I take [3,7,8,1] here 1 is minimum not 3
// if we check on left we also have
// [7,3] , [6,7,3], [4,6,7,3] these also subarrays for which 3 is minimum we cannot go beyond 4 because for that 1 is minimum

// there may be some subarray by combining left and right side for which 3 is minimum  like [7,3,7] for this 3 is minimum, we can also have [6,7,3,7,8] for this also 3 is minimum

// so we can combine them as well okay so I know one thing for a fact on the left I can take all of these 4 elts as a subarray and on the right I can take 3 eltments of a subarray for which 3 is minimum we cannot take 1 of both side in our subarray so if I can take 4 elts on the left and 3 elts on the right What will be the total number of subarray that we can generate? This is 4*3=12 , so total number of subarrays for which 3 is minimum are 4*3=12

// so if I could generate 12 subarrays that means 3 is minimum for 12 subarrays which means the contributions of 3 in sum is = 12*3=36

// This is the key idea behind counting subarrays where a particular element is the minimum.

// For your array:

// [1, 4, 6, 7, 3, 4, 8, 1]

// Let's focus on 3 at index 4.

// 1. What does it mean for 3 to be the minimum?

// A subarray containing 3 has 3 as its minimum if every other element in that subarray is ≥ 3.

// So starting from 3:

// [1, 4, 6, 7, 3, 4, 8, 1]
//                  ↑
//                  3

// We cannot include the 1 on the left, because then minimum would be 1.

// We also cannot include the 1 on the right.

// 2. Count possible left choices

// From 3, move left:

// 1  4  6  7  3
// ↑           ↑
// bad         3

// We can choose:

// Don't include anything → 3
// Include 7 → [7,3]
// Include 6,7 → [6,7,3]
// Include 4,6,7 → [4,6,7,3]

// But we stop before 1.

// So there are 4 left choices.

// Think of it as:

// [1] [4] [6] [7] [3]
//  ↑
//  stop

// Possible starting positions = 1,2,3,4
// 3. Count possible right choices

// From 3, move right:

// 3  4  8  1
// ↑        ↑
// 3       bad

// Possible choices:

// Don't include anything → 3
// Include 4 → [3,4]
// Include 4,8 → [3,4,8]

// Then we hit 1, so stop.

// Therefore there are 3 right choices.

// 4. Multiply

// Now every valid left choice can be combined with every valid right choice.

// So:

// number of subarrays where 3 is minimum
// = left choices × right choices
// = 4 × 3
// = 12

// For example:

//         3
//         ↓
// [3]                    ← left choice 1, right choice 1
// [3,4]
// [3,4,8]

// [7,3]
// [7,3,4]
// [7,3,4,8]

// [6,7,3]
// [6,7,3,4]
// [6,7,3,4,8]

// [4,6,7,3]
// [4,6,7,3,4]
// [4,6,7,3,4,8]

// Exactly 12.

// Why multiplication works

// Suppose:

// L = number of valid ways to choose the left boundary
// R = number of valid ways to choose the right boundary

// For every valid left boundary, you can independently choose any valid right boundary.

// Therefore:

// Total = L × R

// This is basically the multiplication principle of counting.

// And this idea becomes extremely useful in problems like Sum of Subarray Minimums, where instead of just counting, we calculate:

// contribution of element
// = element × (# valid left choices) × (# valid right choices)

// For your 3:

// contribution = 3 × 4 × 3 = 36

// The important part is: we count boundaries, not individual subarrays directly.

// but now the question arises how do we figure out that we'll have 3 elts in the right and 4 elts in the left ?

// it was simple:
// arr = [1,4,6,7,3,4,8,1]
// index= 0 1 2 3 4 5 6 7

// ask you a very simple question for this 3 at index =4 which is the next smallest eltement so if we look in array it is 1 so when we add 1 to our subarray then 3 never remains the minimum anymore so we cannot add 1 so what do we know is for this 3 at index =4 next smaller element lie at index=7 so 7-4=3 will give 3 elements on the right okay
// if we look at the previous smaller element for this 3 at index=4 it is 1 so for 3 previous smaller element is 1 at index=0 sow e are currently at the index=4 so current index-previous smaller index gives 4-0=4 elements
// and then we multiply 4*3=12

// so all we need to know is where is the previous smaller element index and next smaller element index for current index
// we do this for each and every element of an array
// let's say if we have arr=[1,4,6,7,3,7,8,10]
// then for 3 at index=4 there is no next smaller element in that case next smaller element index to be n so in right we have 8-4=4 elements
//  and for the case when we have no previous smaller element than for that previous smaller elt index = -1

// so when for a current index
// i) when we have no next smaller element in that case next smaller element index = n
// ii)  when we have no previous smaller element than for that previous smaller elt index = -1

// now we have some edge cases

// imagine given you an array like arr=[1,1]
// arr = [1,1]
// index= 0 1
// now we write next smaller element for the first 1 - it does not have next smaller elt so for that we write n=2
// second 1 also does not have so it also n=2
// next smaller elt index -  2  2  for both

// and the previous smaller elt would be -1 for both because they don't have
// now let's do the contribution part

//  index   =     0    1
//  arr     =    [1    1 ]
//  nse     =     2    2
//  pse     =     -1   -1

//  for index 0 in left we have: 0-(-1)=1 elt he himeslef
// for index 0 in right we have: 2-0 =2 elt which is correct so index 0 elt contribution = left*right=1*2=2 which are for subarrays : [1](first one), [1,1]

// for index 1 in left we have : 1-(-1)=2
// for index 1 in right we have: 2-1=1 and the contribution comes out be left*right=2*1=2 and this time the subarrays that are considered  is [1,1] , [1](second one)
// but wait [1,1] already considered why are we again considering [1,1] so we'll have to be very sure if we're considering it from first one then don't consider from the back(i.e seocnd one) so we could do either way , either we consider from the back and then we don't consider from the front so we can only consider it once so what we could do is  ?
// We could probably consider it in the front which is typically saying the next smaller elt is correct and we don't consider it on the back and now what this means is when we looking for previous smaller element over here when we are at index 1 when we looked for previous smaller element we didn't find and we wrote -1 instead of it we end up writing index 0 what we'are saying for 1 at index 1 is first 1 at index 0 is my previous smaller elt so it boils down to not previous smaller element this time we find "previous smaller or equal elements" so when we do this
// then for index 1, previous smaller or equal element index is 0 so left=1-0=1
// right=1 so contribution of second one = 1*1=1

// so we find previous smaller or equal element index in left
// and in right we find next smaller element index

// ALgorithm:
// Use a stack to find the index of the next smaller element to the right for each position
// Use another stack to find the index of the previous smaller or equal element to the left for each position
// For each element, determine how many subarrays it appears in as the minimum using its NSE and PSEE indices
// Calculate the contribution of each element by multiplying its value with its frequency
// Add each contribution to a total sum
// Return the total sum modulo 10^9 + 7

// function to find the indices of next smaller elements
// it return array
vector<int> findNSE(vector<int> &arr)
{
  int n = arr.size();
  // to store the answer
  // we store indices in ans array
  vector<int> ans(n);
  // stack to store indices of next smaller elt
  stack<int> st;
  // we want next smaller elt so we
  // start traversing from the back
  for (int i = n - 1; i >= 0; i--)
  {
    // get the current elt
    int currElt = arr[i];
    // pop the elements in the stack until the stack is not empty and the top element is not the smaller elt
    // as we store indices in tsakc so we compare arr value
    // and here we also remove equal elt from the stack
    while (!st.empty() && arr[st.top()] >= currElt)
    {
      st.pop();
    }
    // update the answer
    // if stack is empty then ans[i]=n otherwise ans[i]=st.top
    ans[i] = !st.empty() ? st.top() : n;
    // push the  index of current elt in the stack
    st.push(i);
  }
  // return the answer
  return ans;
}

// function to find the indices of previous smaller or equal elts
vector<int> findPSEE(vector<int> &arr)
{
  int n = arr.size();
  // to store the answer
  // we store indices in ans array
  vector<int> ans(n);
  // stack to store indices of PSEE
  stack<int> st;
  // traverse on the array from the i=0 because we want PSEE
  for (int i = 0; i < n; i++)
  {
    // get the current elt
    int currElt = arr[i];
    // pop the elts in the stack until the stack is not empty and the top elts are greater than the current elt means only pop when arr[st.top]>currelt
    // if arr[st.top]==currelt then don't pop
    while (!st.empty() && arr[st.top()] > currElt)
    {
      st.pop();
    }
    // update the answer  if stack is not empty then st.top otherwise -1
    ans[i] = !st.empty() ? st.top() : -1;
    // push the index of current elt in the stack
    st.push(i);
  }
  // return the answer
  return ans;
}

// function to find the sum of the minimum value in each subarray
// t.c-O(2n)(for findNSE)+O(2n)(for findPSEE)+O(n)(for totalsum )=O(5n)=approx. O(n)
// s.c-O(2n)(for ans+stack in findNSE)+O(2n)(for ans+stack in findPSEE)+O(2n)(for nse and psee array)=O(6n)=approx.O(n)
int sumSubArrayMins(vector<int> &arr)
{
  // get the NSE array
  vector<int> nse = findNSE(arr);
  // get the PSEE
  vector<int> psee = findPSEE(arr);
  int n = arr.size();
  int mod = 1e9 + 7;
  // to store totalsum
  int totalSum = 0;
  // traverse an array
  for (int i = 0; i < n; i++)
  {
    // count the number of left side  subarrays for the current elt
    int left = i - psee[i];
    // count the number of right side subarrays for the current elt is
    int right = nse[i] - i;
    // count of total subarrays where current elt is minimum
    long long freq = left * right * 1LL;

    // contribution due to current elt in totalSum is
    int val = (freq * arr[i] * 1LL) % mod;
    // updating the totalsum
    totalSum = (totalSum + val) % mod;
  }
  // return the computed sum
  return totalSum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << sumSubarrayMins(arr) << endl;
  cout << sumSubArrayMins(arr) << endl;
  return 0;
}