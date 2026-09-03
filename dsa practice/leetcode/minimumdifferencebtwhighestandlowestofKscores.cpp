// You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

// Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

// Return the minimum possible difference.

// Example 1:

// Input: nums = [90], k = 1
// Output: 0
// Explanation: There is one way to pick score(s) of one student:
// - [90]. The difference between the highest and lowest score is 90 - 90 = 0.
// The minimum possible difference is 0.
// Example 2:

// Input: nums = [9,4,1,7], k = 2
// Output: 2
// Explanation: There are six ways to pick score(s) of two students:
// - [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
// - [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
// - [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
// - [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
// - [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
// - [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
// The minimum possible difference is 2.

// Constraints:

// 1 <= k <= nums.length <= 1000
// 0 <= nums[i] <= 10^5

// we have to select k students scores and in that k length array take high scores and low scores then find difference of high-low
// do for all k length array and get minimum of all difference

// you can pick any of k students not necessary to be continuous

// example- nums=[9,4,1,7], k=3
// we have to take 3 students subarray
// i) [9,4,1] then high=9 and low=1, so diff.=(9-1)=8
// ii)[4,1,7] then high=7,low=1, so diff=6
// iii) [9,4,7] then high=9,low=4 so diff=5
// iV)[9,1,7]then high=9 low=1 so diff=8

// then minimum difference is 5

// if we sort array

// Intuition
// To minimize the difference between the highest and lowest scores among the selected k students, we must select them continuously from the sorted array. This is because if we skip a certain index i during the selection, replacing the current highest score in the selection with nums[i] will not increase the highest score. Consequently, the difference between the highest and lowest scores will also not increase. Therefore, there must exist an optimal selection scheme in which k consecutive elements are chosen from the sorted array.

// Based on this observation, we first sort the array nums in ascending order. Then, we traverse nums using a sliding window of fixed size k. Let the left boundary of the sliding window be i. The right boundary is then i+k−1, and the difference between the highest and lowest scores among these k students is nums[i+k−1]−nums[i].

#include <bits/stdc++.h>
using namespace std;

// t.c-O(nlogn)+O(n)=O(nlogn), where n is size of array
// s.c-O(1) no extra space used
int minDifference(vector<int> &nums, int k)
{
  int n = nums.size();
  int minDiff = INT_MAX;
  // it takes O(nlogn)
  sort(nums.begin(), nums.end());

  // it run (i+k-1)-(i)+1=k, when k=2 we have to travel almost whole array so in that case we travel n length
  for (int i = 0; i + k - 1 < n; i++)
  {
    minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
  }
  return minDiff;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elts in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k;
  cout << "Enter the number of students to pick: ";
  cin >> k;
  int answer = minDifference(arr, k);
  cout << "MINIMUM Difference btw highest and lowest of K scores: " << answer << endl;
  return 0;
}