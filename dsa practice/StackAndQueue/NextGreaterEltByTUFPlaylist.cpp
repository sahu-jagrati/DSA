// Problem Statement: Given an integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

// Examples
// Input: arr = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: In the array, the next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4 is -1, since it does not exist.
// Input : arr = [6, 8, 0, 1, 3]
// Output: [8, -1, 1, 3, -1]
// Explanation : In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on the right and hence -1.

#include <bits/stdc++.h>
using namespace std;

// this problem is similar to "NextGreaterElementsII" but in that problem we can traverse circulary for getting first next greater elt means we can find first next greater elt before or after that elt but here we have to traverse the array in a single way only no circular way

// brute force is for every index from 0 to n-1 we go for index+1 to n-1 and whenever we get the nest greater elt then we take it and break because we want first next greater  elt

// t.c-O(n^2)
// s.c-O(n)(for ans which is required) , where n is size of given array
vector<int> nextGreaterElt(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1); // initialize with -1 so if for any elt if we don't get next greater elt then for that it is -1
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      // we want strictly greater elt
      if (nums[j] > nums[i])
      {
        ans[i] = nums[j];
        break;
      }
    }
  }
  return ans;
}

// optimal approach: Using  montonic stack and here in stack we store elts in decreasing order
// and we start traversing the array from right to left means from n-1 to 0 because if we travel from right to left then we can easily store the next greater elt for every elt

// approach:
// To find the next greater element for each element in an array, we can use a stack to efficiently track potential candidates. As we traverse the array from right to left, we maintain a stack that always stores elements in decreasing order from top to bottom. This way, when we process an element, we can simply pop off all smaller or equal elements (which can't be the next greater element), and the top of the stack, if it exists, will be the next greater element. If the stack is empty, there is no greater element to the right, so we assign -1.
// Initialize an empty stack and a result array of the same length as input.
// Traverse the array from the last element to the first (right to left).
// For each element, pop elements from the stack while the stack top is less than or equal to the current element.
// If the stack becomes empty, no greater element exists, assign -1 in the result.
// Otherwise, the top of the stack is the next greater element for the current element.
// Push the current element onto the stack for use in future comparisons

// example: nums=[5,7,1,2,6,0]
// // Initialize an empty stack and a result array of the same length as input.
// // Traverse the array from the last element to the first (right to left).

// iteration start from i=n-1=5 here
//   i                      stack              ans
// i=5 stack is empty so ans[5]=-1 and we push nums[5]=0 in stack

//   5                        0               ans[5]=-1
// i=4 we have nums[4]=6 which is greater than st.top() so pop it and then stack is empty so and[4]=-1 and push 6 in stack
//   4                         6               ans[4]=-1
// i=3 we have nums[3]=2 which is smaller than st.top() so for nums[3], ans[3]=st.top()=6 and push 2 in stack
//   3                         6,2             ans[3]=6
// i=2 we have nums[2]=1 which is smaller than st.top() so for nums[2], ans[2]=st.top()=2 and push 1 in stack
//   2                         6,2,1           ans[2]=2
// i=1 we have nums[1]=7 which is greater than st.top() so pop it, again it is greater than st.top() so again pop it, again it is greater than st.top() so again pop it now stack is empty so ans[1]=-1 and push 7 in stack
//   1                         7                 ans[1]=-1
// i=0 we have nums[0]=5  which is smaller than st.top() so for nums[0], ans[0]=st.top()=7 and push 5 in stack
//   0                         7,5                ans[0]=7

// finish iteration we get our answer array: ans=[7,-1,2,6,-1,-1]

// t.c-O(n) (for outer for loop )+O(n)(for inner while loop throughout the whole journey not for every i) so total t.c =O(2n), not O(n^2)
// s.c-O(n) for stack in worst case +O(n)(for ans which is required)=O(n)
vector<int> nextGreater(vector<int> &nums)
{
  // stack to store elts in decreasing order
  stack<int> st;
  // result array of same size
  int n = nums.size();
  vector<int> ans(n);
  // traverse from right to left
  for (int i = n - 1; i >= 0; i--)
  {
    // pop all smaller or equal elts from the current elt if stack is not empty
    // we pop out for equal to also because we want next greater elt
    while (!st.empty() && st.top() <= nums[i])
    {
      st.pop();
    }
    // if stack is empty, no greater elt for the current elt
    if (st.empty())
      ans[i] = -1;
    // else top of stack is the next greater elt for the current elt
    else
      ans[i] = st.top();
    // push current elt
    st.push(nums[i]);
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
  // vector<int> ans = nextGreaterElt(nums);
  vector<int> ans = nextGreater(nums);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}