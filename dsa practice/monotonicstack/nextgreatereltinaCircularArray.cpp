// Given a circular array arr[], find the next greater element for each element in the array.
// Note: The next greater element of an element is the first next element greater than it when traversing the array in order (circularly). If no such element exists, return -1 for that position.

// Examples:

// Input: arr[] = [5, 7, 1, 2, 6]
// Output: [7, -1, 2, 6, 7]
// Explanation:
// Next greater element for 5 is 7.
// For 7, no greater element exists, so it is -1.
// For 1, the next greater element is 2.
// For 2, the next greater element is 6.
// For 6, the next greater element is 7 (circularly).

// Input: arr[] = [6, 8, 0, 1, 3]
// Output: [8, -1, 1, 3, 6]
// Explanation: In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is 6.

#include <bits/stdc++.h>
using namespace std;

// Naive Approach] - Using Nested Loops - O(n^2) Time and O(1) Space
// In a circular array, after reaching the n-th index, traversal continues again from index 0. To handle this, we can use the modulo operator. By iterating from index i to i + n and accessing elements as index % n, we can simulate circular traversal within the array itself. This allows us to process the circular nature of the array without using any extra space

vector<int> nextGreater(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++)
  {
    // we start from j=1 because j=0 give itself
    for (int j = 1; j < n; j++)
    {
      // checking for next greater elt
      if (nums[i] < nums[(i + j) % n])
      {
        ans[i] = nums[(i + j) % n];
        break;
      }
    }
  }
  return ans;
}

// [Expected Approach] Using Stack - O(n) Time and O(n) Space
// monotonic decreasing stack (stack that maintains elements in decreasing order).
// We use the same ideas as next greater element in a normal array. Stack to find out the next greater element in linear time. We traverse the array from right to left. For each element, we remove elements from the stack that are smaller than or equal to it, as they cannot be the next greater element. If the stack is not empty after this, the top element of the stack is the next greater element for the current element. We then push the current element onto the stack.

// Initialize res with -1 and an empty stack st.
// Loop from 2n - 1 to 0 to handle circular traversal.
// Use i%n to access the correct index in the array.
// While stack is not empty and top element is ≤ current element, pop from stack.
// If i < n and stack is not empty, set res[i] to st.top().
// Push current element arr[i % n] to the stack.
// Return the result array res.

vector<int> nextGreaterElt(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1);
  stack<int> st;
  // traverse the array from right to left
  for (int i = 2 * n - 1; i >= 0; i--)
  {
    // pop elts from the stack that are less than or equal to the current elt
    while (!st.empty() && st.top() <= nums[i % n])
    {
      st.pop();
    }
    // if the stack is not empty, the top elt is the next greater elt
    if (i < n && !st.empty())
    {
      ans[i] = st.top();
    }
    // push the current elt
    st.push(nums[i % n]);
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

  // vector<int> res = nextGreater(nums);
  vector<int> res = nextGreaterElt(nums);
  for (int x : res)
  {
    cout << x << " ";
  }

  return 0;
}