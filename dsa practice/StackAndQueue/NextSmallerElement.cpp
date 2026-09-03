// Problem Statement: Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
// The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
// If there is no smaller element to the right, then the NSE is -1.

// Examples
// Example 1:
// Input:
//  arr = [4, 8, 5, 2, 25]
// Output:
//  [2, 5, 2, -1, -1]
// Explanation:

// - For 4, the next smaller element is 2.
// - For 8, the next smaller element is 5.
// - For 5, the next smaller element is 2.
// - For 2, there is no smaller element to its right → -1.
// - For 25, no smaller element exists → -1.

// Example 2:
// Input:
//  arr = [10, 9, 8, 7]
// Output:
//  [9, 8, 7, -1]
// Explanation:

// Each element’s next right neighbor is smaller.
// Each element’s next right neighbor is smaller.

#include <bits/stdc++.h>
using namespace std;

// brute force solution: // so for each index i we check in right is there any next smaller elt so we go from i+1 to n-1
// Initialize an answer array filled with -1
// Loop from i = 0 to n - 1
// Loop from j = i + 1 to n - 1
// If a smaller element is found at j, update answer[i] and break
// Continue to the next i
// Return the answer array

// t.c-O(n^2)
// s.c-O(n) for ans array which is required
vector<int> nextSmallerElemnets(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1); // we initialize with -1 so if there is no next Smaller elt it is -1
  for (int i = 0; i < n; i++)
  {
    // so for each index i we check in right is there any next smaller elt so we go from i+1 to n-1
    // if we get next smaller elt then we update ans[i]  and break because we want first next smaller elt
    for (int j = i + 1; j < n; j++)
    {
      // we want next smaller elt so we strictly check it means nums[j]<nums[i] not even equal
      if (nums[j] < nums[i])
      {
        ans[i] = nums[j];
        break;
      }
    }
  }
  return ans;
}

// optimal approach: Using monotonic stack and here we use stack in increasing order
// so here we traverse given nums array from right to left i.e from i=n-1 to 0
// Initialize an answer array filled with -1
// Initialize an empty stack
// Loop from i = n - 1 to 0
// While stack is not empty and top is greater than or equal to current element, pop the stack because we maintain stack in increasing order so top is the next smaller elt
// If stack is not empty, set answer[i] to top of stack
// Push current element to stack
// Return the answer array

// t.c-O(n)(for outer for loop)+O(n)(for inner while loop throughtout the whole journey not for each i) so total t.c-O(2n), not O(n^2)
// s.c-O(n)(for stack in worst case hold upto n elts)+O(n)(for ans array which is required)
vector<int> nextSmallerElts(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1); // Initialize an answer array filled with -1
  // stack to store potential next smaller elts
  stack<int> st; // maintain in increasing order
  // we traverse from right to left so we easily get next smaller elt
  for (int i = n - 1; i >= 0; i--)
  {
    int currElt = nums[i];
    // While stack is not empty and top is greater than or equal to current element, pop the stack because we maintain stack in increasing order so we check strictly means  not even equal should be in top
    while (!st.empty() && st.top() >= currElt)
    {
      st.pop();
    }
    // If stack is not empty, set answer[i] to top of stack because we maintain stack in increasing order so top is the next smaller elt
    if (!st.empty())
    {
      ans[i] = st.top();
    }
    // Push current element to stack
    st.push(currElt);
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
  // vector<int> ans = nextSmallerElemnets(nums);
  vector<int> ans = nextSmallerElts(nums);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}