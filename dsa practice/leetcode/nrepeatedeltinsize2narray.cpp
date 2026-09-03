// You are given an integer array nums with the following properties:

// nums.length == 2 * n.
// nums contains n + 1 unique values, n of which occur exactly once in the array.
// Exactly one element of nums is repeated n times.
// Return the element that is repeated n times.

// Example 1:

// Input: nums = [1,2,3,3]
// Output: 3
// Example 2:

// Input: nums = [2,1,2,5,3,2]
// Output: 2
// Example 3:

// Input: nums = [5,1,5,2,5,3,5,4]
// Output: 5

// Constraints:

// 2 <= n <= 5000
// nums.length == 2 * n
// 0 <= nums[i] <= 104
// nums contains n + 1 unique elements and one of them is repeated exactly n times.

#include <bits/stdc++.h>
using namespace std;

// done by me
int repeatedNTimes(vector<int> &nums)
{
  int size = nums.size();

  unordered_map<int, int> mpp;
  for (int i = 0; i < size; i++)
  {
    mpp[nums[i]]++;
  }
  for (auto it : mpp)
  {
    if (it.second == size / 2)
    {
      return it.first;
    }
  }
  return -1;
}

// seeing in solution section
//

int repeatedNtimes(vector<int> &nums)
{
  int size = nums.size();
  for (int i = 0; i < size; i++)
  {
    if (nums[i] == nums[i + 1])
      return nums[i]; // because each elt appears exactly once except n times occur elt so
    if (i + 2 < size)
    {
      if (nums[i] == nums[i + 1])
        return nums[i];
    }
  }
  return nums[0];
}
// Intuition

// Let's break down the problem step by step:

// What we have: Array of size 2n with one element appearing exactly n times, others appear once
// Key observation 1: The repeated element takes up EXACTLY 50% of the array
// Key observation 2: With 50% density, the element can't be spread too far apart
// Critical insight: In any window of 3 consecutive elements, the repeated element MUST appear at least twice
// Why 3? Because mathematically, you cannot distribute n items across 2n positions while avoiding duplicates in every 3-element window
// The trick: Just check if current element matches next element OR element at distance 2
// Why not window size 2?

// Pattern like [x, a, x, b, x, c] has no adjacent duplicates but still valid
// Window of 2 is insufficient to guarantee finding duplicates
// Why window size 3 works?

// With 50% density, it's mathematically impossible to avoid duplicates in every 3-position window
// This is guaranteed by the distribution constraint
// Approach
// Breaking down the solution into clear steps:

// Step 1: Understand the Constraint

// Array size = 2n
// One element appears n times (exactly half)
// All other elements appear once
// Step 2: Key Mathematical Property

// If element occupies 50% of positions
// It cannot spread itself more than 2 positions apart anywhere
// Any 3 consecutive positions MUST contain it at least twice
// Step 3: Simple Check

// For each position i, check two things:
// Is nums[i] == nums[i+1]? (adjacent match)
// Is nums[i] == nums[i+2]? (distance 2 match)
// If either matches, we found our answer!
// Step 4: Edge Case

// If loop completes without finding match
// Return nums[0] (handles patterns like [x, a, b, x])
// Why this works:

// We're checking every possible 3-element window
// The repeated element MUST appear in at least one of these checks
// No need for extra space or complex logic
// Algorithms Used
// Primary Technique: Sliding Window + Mathematical Property (Pigeonhole Principle)

// Breakdown:

// Sliding Window: Check fixed window of 3 consecutive elements
// Pattern Matching: Compare current with i+1 and i+2 positions
// Mathematical Guarantee: 50% density ensures match within window of 3
// Complexity
// Time complexity: O(n)

// Space complexity: O(1)

// Mathematical Proof: Pigeonhole Principle
// Understanding the Core Concept:

// The Pigeonhole Principle is a fundamental counting principle in mathematics. Simply put: if you have more pigeons than pigeonholes, at least one pigeonhole must contain more than one pigeon.

// Applied to Our Problem:

// Setup:

// Array has 2n total positions (the "pigeonholes")
// One element appears n times (n "pigeons" of the same type)
// Other elements appear once each
// Key Insight:
// The repeated element occupies exactly 50% of all positions in the array.

// Why Window of Size 3?

// Let's analyze different window sizes:

// Window Size 1:

// Cannot detect duplicates (only one element to check)
// Useless for our purpose
// Window Size 2:

// Can fail! Counter-example: [x, a, x, b, x, c]
// The element x appears at positions 0, 2, 4 (50% of 6 elements)
// No adjacent duplicates exist
// Pattern is valid but we miss it with window size 2
// Window Size 3:

// This is where mathematics guarantees success!
// With 50% density, you CANNOT spread elements to avoid all 3-windows
// Mathematical Proof:

// Consider any 3 consecutive positions in the array. Let's think about distribution:

// If repeated element appears 0 times in window:

// It must appear in remaining positions
// But it needs to maintain 50% density across entire array
// This creates a "gap" that's too large
// If repeated element appears 1 time in window:

// Only 1 out of 3 positions = 33.3% density in this window
// To compensate and maintain 50% overall, other windows need >50%
// But if other windows have >50%, they'll have 2+ occurrences
// We'll catch it there!
// Mathematical impossibility:

// Across the entire array of 2n elements
// Element appears n times (50%)
// If EVERY 3-window had ≤1 occurrence
// Maximum possible frequency = ⌈2n/3⌉ < n when n ≥ 3
// Contradiction! Element cannot achieve its required frequency
// Conclusion:
// At least one window of 3 consecutive positions MUST contain the repeated element at least twice. Our algorithm checks positions i, i+1, and i+2 for every i, covering all such windows.

// Why Our Algorithm Works:

// By checking:

// nums[i] == nums[i+1] (positions i and i+1 match)
// nums[i] == nums[i+2] (positions i and i+2 match)
// We effectively examine every possible 3-element window and detect when the repeated element appears twice within it.

// Time Guarantee:
// Since the mathematical property guarantees a match within some 3-window, we'll find it in our single O(n) pass through the array.

// Alternative Approaches & Optimizations
// Other techniques to solve this problem:

// Hash Map/Set - Track seen elements, O(n) time but O(n) space
// Sorting - Sort and find adjacent duplicates, O(n log n) time
// Random Selection - Keep picking random pairs until match (probabilistic)
// Boyer-Moore Voting Algorithm - Find majority element variant
// XOR Operations - Mathematical bit manipulation (complex for this problem)

int main()
{
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
  {
    cin >> nums[i];
  }
  cout << repeatedNTimes(nums) << endl;
  cout << repeatedNtimes(nums) << endl;
  return 0;
}