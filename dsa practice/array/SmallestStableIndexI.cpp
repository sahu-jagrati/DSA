// You are given an integer array nums of length n and an integer k.

// For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

// In other words:

// max(nums[0..i]) is the largest value among the elements from index 0 to index i.
// min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
// An index i is called stable if its instability score is less than or equal to k.

// Return the smallest stable index. If no such index exists, return -1.

// Example 1:

// Input: nums = [5,0,1,4], k = 3

// Output: 3

// Explanation:

// At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
// At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
// At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
// At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
// This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.
// Example 2:

// Input: nums = [3,2,1], k = 1

// Output: -1

// Explanation:

// At index 0, the instability score is 3 - 1 = 2.
// At index 1, the instability score is 3 - 1 = 2.
// At index 2, the instability score is 3 - 1 = 2.
// None of these values is less than or equal to k = 1, so the answer is -1.
// Example 3:

// Input: nums = [0], k = 0

// Output: 0

// Explanation:

// At index 0, the instability score is 0 - 0 = 0, which is less than or equal to k = 0. Therefore, the answer is 0.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 10^9
// 0 <= k <= 10^9

#include <bits/stdc++.h>
using namespace std;

// I solve this problem

// we cannot sort the given array because it change the indexing

// for maximum at index i we want max(nums[0...i])
// for minimum at index i we want min(nums[i...n-1])

// we want maximum value for the index i from index 0 to i i.e max(nums[0...i]) we get this easily , when we calculate instability score for each index at that time we also simultaneous update maximum

// but for minimum value for index i is min(nums[i...n-1]) means we want minimum value of that index to all the  remaining index so for that we make an minArray so minarray[i]  store the minimum value for that index from i to n-1 for that we start traversing from n-1 to 0 because we want min(nums[i...n-1]) so for minArray[n-1]=nums[n-1]=min(nums[(n-1)...(n-1)])
// minArray[i]=min(minArray[i+1],nums[i]) by this we get the min(nums[i...n-1])

// then we calculate instability score for each index and always check smallest stable index

// t.c-O(n)(for making minArray)+O(n)( for calculating instability score for each index)=O(n)
// s.c-O(n)(for minArray)
int firstStableIndex(vector<int> &nums, int k)
{
  int n = nums.size();
  vector<int> minArray(n); // where minArray[i] represents min(nums[i...n-1])
  // as we travel from back means n-1 to 0 so minArray[n-1]=nums[n-1]-min(nums[(n-1)...(n-1)])
  minArray[n - 1] = nums[n - 1];
  // now we go from n-2 to 0
  for (int i = n - 2; i >= 0; i--)
  {
    // now  minArray[i]=min(minArray[i+1],nums[i]) by this we get the min(nums[i...n-1])

    minArray[i] = min(minArray[i + 1], nums[i]);
  }
  // for getting maximum upto that index we want max(nums[0...i]) so for index 0 it is max(nums[0...0])=nums[0]
  int maxElt = nums[0]; // and for other index we update it if we get max
  int smallestStableIndex = INT_MAX;
  // we calculate instabilty score for each index and check condition and get smallest stbale index
  for (int i = 0; i < n; i++)
  {
    // update maximum if current nums[i] is greater
    maxElt = max(maxElt, nums[i]);
    // calculate instabilty score
    int instabilityScore = maxElt - minArray[i];
    // check condition
    if (instabilityScore <= k)
      smallestStableIndex = min(smallestStableIndex, i);
  }
  if (smallestStableIndex != INT_MAX)
    return smallestStableIndex;
  return -1;
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
  cout << firstStableIndex(nums, k);
  return 0;
}