// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2;
// The number 2 can't find next greater number.
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// Constraints:

// 1 <= nums.length <= 10^4
// -10^9 <= nums[i] <= 10^9

#include <bits/stdc++.h>
using namespace std;

// here we also want a first next greater elt but in same array and we can traverse array circularly so like
// example: arr=[2,10,12,1,11]
// for nums[0]=2 we check in right for next greater elt we get 10
// for nums[1]=10 we get 12
// for nums[2]=12 in right there is no next greater elt but it is finish no because A.T.Q we can check in circular so we can also check before 12 but there also we don't get so now we can say for 12 , ans[2]=-1
// for nums[3]=1 we get 11
// for nums[4]=11 there is no next greater elt in right but when we go circular means before 11 start from index 0 to i-1   then first next greater we get 12

// so naive solution is that for each i : i=0 to n-1
// first we check in right of current elt :  j=i+1 to n-1 if we get then okay otherwise
// then we check in circular means before current elt : 0 to i-1
// this is very naive solution but can I do better yes we use the concept of circular array
// It is very simple so what we do? we double the array , not by doubling it in a real coding , we just think it virtually so we double the array in my mind so for above example we can think like : arr=[2,10,12,1,11] 2,10,12,1,11 this is in our mind virtually
// imagine if I stand at 10 means arr[1] and if I ask you what will be the entire circular array?  Can I say if I take n elts from where I stand means I stand at 10 and if I take n elts from 10 then we go upto 2 after double the array where n is the length of original given array . Why? Given elts here n =5 so if I'm standing at 10 and from there if I can take the five elts then we get [10,12,1,11,2] so this is my circular array for sure do I double the array that is the question ? I don't need
// What I'll do is I'll try to think hypothetically
// Let's see for an example here n=5
// arr=[2,10,12,1,11] 2 10 12 1 11   this we double the array in our mind
// index:0  1  2 3  4  5  6  7 8  9   think hypothetically for indexing 5 to 9
// so whenever the value of i comes to index 5 when we are traversing I don't have a 5th index so what we will do is ? we'll say 5%n which is 5%5=0 and 0 is nothing but index 0 and if we look at 6%5=1 which is index 1 similarly 7%5=2 index 2 , 8%5=3 index 3 and 9%5=4 which is index 4 so we can just play with the indexes we don't need to double the array in a data structure we just do it hypothetically
// so what we do is we go for each and every elt so for i from 0 to n-1

// for(i=0 to n-1){
// we need to traverse each and every elt in a circular way
// for(j=i+1 to i+n-1){
// index=j%n;
// if(arr[j]>arr[i])ans[i]=arr[j]; break;
//}
//} this take t.c-O(n^2) and s.c-O(n) for ans array  so we need to optimize this, so optimal solution is monotonic stack

// brute force:
// approach:
// Create an array to store the answer of the same size as the input array, filled with -1.
// Iterate through each element at index i from 0 to n-1.
// For each element, start a second loop from 1 to n-1 to check the next elements in circular order using (i + j) % n.
// If a greater element than the current one is found during the inner loop, assign it to answer[i] and exit the inner loop.
// After completing both loops, return the answer array containing the next greater elements.

// Function to find the next greater element for each element in the circular array
// t.c-O(n^2)
// s.c-O(n)   required to store the answer
vector<int> nextGreater(vector<int> &nums)
{
  int n = nums.size(); // size of array

  // To store the next greater elements
  vector<int> ans(n, -1);

  for (int i = 0; i < n; i++)
  {
    // get the current elt
    int currElt = nums[i];
    // nested loop to get the next greater elt
    for (int j = 1; j < n; j++)
    {
      // getting the hypothetical index after traverse circularly
      int ind = (j + i) % n;
      // If the next greater element is found
      if (nums[ind] > currElt)
      {
        // Store the next greater element
        ans[i] = nums[ind];

        // Break from the loop
        break;
      }
    }
  }
  return ans;
}

// optimal approach: using monotonic stack in decreasing order
// example: nums=[2,10,12,1,11]
// by using the monotonic stack in the next greater element we starting from the last element and for 11 I was looking in the right but this is a circular array so for 11 we need elt before 11 in the stack but they not so what I'll do is hypothetically double the array
// so if I hypothetically double the array it will be :
// nums=[2,10,12,1,11] 2 10 12 1 11
// index: 0 1  2  3  4  5  6  7 8  9
// so last index is 2*n-1 where n is length of original given array
// here n=5 so last index is 9
// so now can I say whenever I'm at nums[4]=11 I'll have these elements in right of 11 traverse only when I started the last element 2*n-1 so what I'll do is I'll take the stack and I'll be storing everything in the decreasing order
// so we start from 2*n-1 index and initially stack is empty

//  i                 stack
// i=9 we have 11 and stack is empty so just push it in stack   and the next greater elt for this index 9 do I need ? No we need next greater elt for only index 0 to n-1 not for hypothetically indices so for them we just maintain the stack
//  9                  11
// i=8 we have 1 and at st.top we have 11 greater than 1 so no problem push 1 in stack
//  8                  11,1
// i=7  we have 12 and st.top is lesser than 12 so pop it until we get greater than
//  7                  12
//  i=6   we have 10 and st.top =12 which is greater than 10 so just push 10 in stack
//  6                  12,10
//  i=5 we have 2 and st.top =10 which is greater than 2 so just push 2 in stack
//  5                   12,10,2
// now we come in our actual array
// i=4 we have 11 and st.top=2 lesser than 12 so pop it until we get greater than we pop 2 and 10 from the stack and now there is only 12 in stack and now we want next greater elt for current elt because we are now in actual array how do we know that? because index=4 is lesser than n=5 so for 11 next greater elt is 12 and push 11 in stack
//  4                    12,11
// i=3 we have 1 for this next greater elt is 11 and push 1 in stack
//  3                    12,11,1
//  i=2 we have 12 and st.top is lesser than 12 so pop it until we get greater than , so after pop stack is empty so for 12 next greater elt is not exist so it is -1 and push 12 in stack
//   2                   12
//  i=1 we have 10  for this next greater elt is 12 and push 10 in stack
//   1                   12,10
// i=0      we have 2 for this next greater elt is 10 and push 2 in stack
//  0                     12,10,2

// iteration finish and we get the next greater elt for every elt by traversing the array circularly

// what we do is?

// Initialize an answer array with default values of -1
// Initialize an empty stack to keep track of elements
// Traverse from 2n - 1 down to 0 using modulus to simulate circular indexing
// While stack is not empty and top of stack is less than or equal to current element, pop from stack
// If index is in the original array range means when i<n, assign top of stack to answer if stack is not empty, else keep -1
// Push the current element onto the stack
// After traversal ends, return the answer array

// example: nums=[1,2,3,4,3]
// we intitialize with an empty stack
// and iterate from 2*n-1 to 0
// so here n=5
// so we go from i=9 to 0
// and we have ans array of size n=5 initialize with -1
// ans=[-1,-1,-1,-1,-1]

//   i                      stack                  ans

//   9                       3                    [-1,-1,-1,-1,-1]
//   8                       4                    [-1,-1,-1,-1,-1]
//   7                       4,3                  [-1,-1,-1,-1,-1]
//   6                       4,3,2                [-1,-1,-1,-1,-1]
//   5                       4,3,2,1              [-1,-1,-1,-1,-1]
//   4                       4                  [-1,-1,-1,-1,4]
//   3                       4            [-1,-1,-1,-1,4]
//   2                       4,3                [-1,-1,4,-1,4]
//  1                        4,3,2            [-1,3,4,-1,4]
//  0                        4,3,2,1          [2,3,4,-1,4]

// so iteration finish and our answer is [2,3,4,-1,4]

// t.c-O(2*n)(for outer for loop )+O(2*n)(in worst case for inner while loop when we have to pop out 2n elts from stack because we go circularly and this is in throughout the whole process not for every i) so total t.c = O(4*n) = O(n)
// s.c-O(2n)in worst case for stack storing 2n elts because we go circularly  + O(n)(for ans array which is required)
vector<int> nextGreaterElts(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1); // we initialize with -1 so if for any elt we don't get next greater elt then for that it is -1
  // we use monotonic stack(in decreasing order) to store next greater elt at top
  stack<int> st;
  // we traverse for each index two times because we can find next first greater elt for each elt before or after it means by circularly
  // how?
  // we iterate from i=2*n-1 to i>=0 using modulus to simulate circular indexing
  for (int i = 2 * n - 1; i >= 0; i--)
  {
    // get the actual index
    int ind = i % n;
    // get the current elt
    int currElt = nums[ind];
    // pop the elements in the stack until the stack is not empty and the top element is not the greater element
    while (!st.empty() && st.top() <= currElt)
    {
      st.pop();
    }
    // store the answer for the second half
    if (!st.empty() && i < n)
    {
      ans[i] = st.top(); // why we say i<n because we traverse from i=2*n-1 so for every index we go two times so when we come in i<n we get correct value for that index because at that time for that index we traverse circularly one time to get first next greater elt, // If index is in the original array range, assign top of stack to answer if stack is not empty, else keep -1
    }
    // Push the current element in the stack  maintaining the decreasing order
    st.push(currElt); // simply push elt in stack
  }
  return ans;
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
  vector<int> ans = nextGreaterElts(nums);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}