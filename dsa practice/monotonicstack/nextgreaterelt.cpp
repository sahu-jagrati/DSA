// Given an array arr[] of integers, determine the Next Greater Element (NGE) for every element in the array, maintaining the order of appearance.

// The Next Greater Element for an element x is defined as the first element to the right of x in the array that is strictly greater than x.
// If no such element exists for an element, its Next Greater Element is -1.
// Examples:

// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

// Input: arr[] = [6, 8, 0, 1, 3]
// Output: [8, -1, 1, 3, -1]
// Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

// [Naive Approach] Using Nested Loops - O(n2) Time and O(1) Space

#include <bits/stdc++.h>
using namespace std;

// [Naive Approach] Using Nested Loops - O(n2) Time and O(1) Space

vector<int> nextGreaterElement(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1);

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[j] > nums[i])
      {
        ans[i] = nums[j];
        break;
      }
    }
  }
  return ans;
}

// [Expected Approach] Using Stack - O(n) Time and O(n) Space

// The idea is to use a monotonic decreasing stack (stack that maintains elements in decreasing order). We traverse the array from right to left. For each element, we pop elements from the stack that are smaller than or equal to it, since they cannot be the next greater element. If the stack is not empty, the top of the stack is the next greater element. Finally, we push the current element onto the stack.

vector<int> nextgreaterElement(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--)
  {
    // pop elements from the stack that are less than or equal to the current elt
    while (!st.empty() && st.top() <= nums[i])
    {
      st.pop();
    }
    // if the stack is not empty, the top elt is the next greater elt
    if (!st.empty())
    {
      ans[i] = st.top();
    }
    // push the current elt onto the stack
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

  // vector<int> res = nextGreaterElement(nums);
  vector<int> res = nextgreaterElement(nums);
  for (int x : res)
  {
    cout << x << " ";
  }

  return 0;
}