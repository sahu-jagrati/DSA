// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 1 <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

// brute force -
// generate each sliding window of size k and scan it to get maximum of that window

// if given array size is n then upto which index we can get window of size k? index (0 -> n-k)

// Every time the sliding window moves, we manually check all the elts within that window and pick the maximum.

// Loop throught the array from 0 to (n-k)
// for each iteration, extract the subarray of window size means if we are at index i then we scan upto i+k-1 for the current window to get maximum of that window of size k
// Scan through that subarray to find the maximum elt
// Store the maximum of the current window in the result array
// After the loop ends, return the result array

// t.c-O(n-k)*(k)
// s.c-O(n-k) for answer array
// to return max of each sliding window of size k
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  // answer vector to store maximum of each window
  vector<int> answer;
  int n = nums.size();
  // loop through the array till the window can slide
  for (int i = 0; i <= (n - k); i++)
  {
    // initialize the max elt as the first elt of the current window
    int maxi = nums[i];
    // traverse through the current window of size k
    for (int j = i; j <= (i + k - 1); j++)
    {
      // update maxi if a larger value is found
      maxi = max(maxi, nums[j]);
    }
    // append the max of this window to the answer array
    answer.push_back(maxi);
  }
  return answer;
}

// optimize solution-
// instead of nested loops can we do this in one traverse
// example: nums=[4,0,-1,3,5,3,6,8], k=3
// here first window of size k=3 is [4,0,-1]
// and for next window what we do?
// we remove one elt from front and push one elt from back
// like here for second window we remove 4 from front and push 3 from back and get [0,-1,3] and so on for other windows of size k=3

// we keep track of
// k elts, keep the window elt
// and we can use monotonic stack to store elt in decreasing order, we use monotonic stack when we need greater or smallest in constant complexity

// keep the window elts- I need to add and I need to delete elts

// I need a stack data structure for motonic and I need a data structure in which we add and delete elt -> two way data structure - open from both ends so we can remove elt from front and add elt from back

// Do we use a stack and a data structure for k elts? No, We use a single data structure

// Double-ended queue(dequeue) is a generalized version of queue data structure that allows insert and delete at both ends.

// Means you can add and delete from front as well as you can add and delete from back so you can apply both operations from both ends.

// Sliding Window problems often lead to repeated work when recalculating the maximum in each window. To identify inefficiencies, consider this: if we move from the window [1,2,3] to [2,3,2], we recalculate the max even though the outgoing elt(1) was not the maximum.

// The real concern is only when the outgoing elt was the maximum. To optimize, we use a deque to maintain elts in a way that always keeps track of the current maximum efficiently. When a new elt enters, we push it to the back of the deque, but before that, we remove all smaller elts from the back since they are not useful anymore. Also, if the elt at the front is outside the window's range, we remove it. This ensures that the elt at the front of the deque always represents the maximum of the current window.

// Initialize an empty deque and a result list
// Loop through the array from start to end
// Remove front of deque if it's outside the current window
// Remove all elts smaller than the current one from the back of the deque
// Insert the current index at the back of the deque
// If the window has at least k elts, append the front elt's value to the result i.e // once the first window is completed, add front elt to answer array
// Why front because we store elts in decreasing order in deque
// Return the result list

// t.c-O(2n)(n for traversal and n for pop back inner while loop) each elt is pushed and popped from the dequeue at most once, so overall traversal is linear.
// s.c-O(k) deque stores at most k elts at any time, one for each index in the window +O(ans size=n-k)  , where n is size of given array
vector<int> maxSlidingWindowSizeK(vector<int> &nums, int k)
{
  // deque to store indices of useful elts in the current window
  deque<int> dq;
  // answer array to store the maximums
  vector<int> answer;
  // loop through each elt in the array
  for (int i = 0; i < nums.size(); i++)
  {
    // remove elts from the front if they are out of this window's range
    // dq.front() give index so if that index is out of window's range
    if (!dq.empty() && dq.front() <= i - k)
    {
      // remove from front of dq
      dq.pop_front();
    }
    // remove all elts from the back that are smaller than current elt
    while (!dq.empty() && nums[dq.back()] < nums[i])
    {
      // remove from back of dq
      dq.pop_back();
    }
    // add the current elt index to the deque from back
    dq.push_back(i);

    // once the first window is completed, add front elt to answer array
    // Why front because we store elts in decreasing order in deque
    if (i >= k - 1)
    {
      answer.push_back(nums[dq.front()]);
    }
  }
  return answer;
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
  // vector<int> ans = maxSlidingWindow(nums, k);
  vector<int> ans = maxSlidingWindowSizeK(nums, k);
  for (int it : ans)
  {
    cout << it << " ";
  }
  return 0;
}