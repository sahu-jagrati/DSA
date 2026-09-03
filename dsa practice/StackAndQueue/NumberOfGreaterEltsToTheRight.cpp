// Problem Statement: Given an array arr of size n containing elements, find the number of next greater element for each element in the array in the order of their appearance.

// The next greater element of an element in the array is the  element on the right that is greater than the current element.

// If there does not exist a next greater element for the current element, then the number of  greater element for that element is 0.

// Examples
// Example 1:
// Input:
//  arr = [1, 3, 2, 4]
// Output:
//  [3, 1, 1, 0]
// Explanation:

// The number of next greater element for 1 is 3, for 3 is 1, for 2 is 1, and for 4 is 0 (no greater element on the right).

// Example 2:
// Input:
//  arr = [6, 8, 0, 1, 3]
// Output:
//  [1, 0, 2, 1, 0]
// Explanation:

// The number of next greater element for 6 is 1, for 8 is 0, for 0 is 2, for 1 is 1, and for 3 is 0.

#include <bits/stdc++.h>
using namespace std;

// solution: // so for each index i we check in right is there any next smaller elt so we go from i+1 to n-1 and count the number of next greater elts.

// Initialize an array answer with all elements set to 0 to store the number of next greater elements.
// Traverse the array using a for loop to select the current element.
// and we take count variable to store the number of next greater elts
// Use a nested for loop to traverse the right side of the array (from the current element) to find the next greater element.
// If a next greater element is found, we increase the count by 1.
// once the inner loop finish the we update the ans[i]=count
// Once the outer for loop ends, return the answer array containing the results.

// t.c-O(n^2)
// s.c-O(n) for ans array which is required
vector<int> numberOfGreaterElts(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, 0); // initialize an ans array with 0 means if there is no next greater elt then number of next greater elt for current elt is 0
  for (int i = 0; i < n; i++)
  {
    // so for each index i we check in right is there any next smaller elt so we go from i+1 to n-1 and count the number of next greater elts.
    int cnt = 0;
    for (int j = i + 1; j < n; j++)
    {
      // we check strictly means nums[j]>nums[i] not even equal
      if (nums[j] > nums[i])
      {
        cnt++;
      }
    }
    ans[i] = cnt;
  }
  return ans;
}

// here we cannot use stack solution  because we cannot say st.size() = number of next greater elts for current elt because we pop out from the stack means suppose we have an example: nums=[1,3,2,4] so here when are at index=1 we have nums[1]=3 so for 3 we pop out 2 from the stack but for nums[0]=1 , 2 has to be cnt in number of next greater elt but 2 is not in stack because when for nums[1]=3 we pop out 2 from the stack so we cannot say size of stack is number of next greater elt for current elt

//  using monotonic stack and here we use stack in decreasing order
// so here we traverse given nums array from right to left i.e from i=n-1 to 0

// Initialize an answer array to store the number of next greater elements for the given array.
// Declare a stack data structure to help with the traversal.
// Start traversing the array from the back from n-1 to 0
// For the current element, pop elements from the stack until the top is less than or equal to the current element.
// If a greater element is found, we store the size of stack in the answer array means here size of stack denote the number of next greater elt then current elt otherwise, store 0.
// Push the current element into the stack while maintaining a decreasing order of elements.
// Once the traversal is complete, the answer array will contain the results.

// vector<int> numberOfGreaterElements(vector<int> &nums)
// {
//   int n = nums.size();
//   vector<int> ans(n, 0); // Initialize an answer array filled with 0 means if there is no next greater elt then number of next greater elt for current elt is 0
//   // stack to store potential next greater elts
//   stack<int> st; // maintain in decreasing order
//   // we traverse from right to left so we easily get next greater elt
//   for (int i = n - 1; i >= 0; i--)
//   {
//     int currElt = nums[i];
//     // While stack is not empty and top is less than or equal to current element, pop the stack because we maintain stack in decreasing order so we check strictly means  not even equal should be in top
//     while (!st.empty() && st.top() <= currElt)
//     {
//       st.pop();
//     }
//     // If stack is not empty, set answer[i] to size  of stack because we maintain stack in decreasing order so here size of stack denote the number of next greater elt then current elt otherwise, store 0.
//     if (!st.empty())
//     {
//       ans[i] = st.size(); // number of next greater elts and if stack is empty then ans[i]=0 which we already initialize an ans array so no need to write specific
//     }
//     // push current elt in stack
//     st.push(currElt);
//   }
//   return ans;
// }

// so here brute force is only solution, we cannot use stack solution for count number of next greater elts explanation mention above
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vector<int> ans = numberOfGreaterElts(nums);

  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}