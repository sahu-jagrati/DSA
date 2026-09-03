// You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

// A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

// Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

// An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

// Example 1:

// Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
// Output: 2
// Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
// The maximum distance is 2 with pair (2,4).
// Example 2:

// Input: nums1 = [2,2,2], nums2 = [10,10,1]
// Output: 1
// Explanation: The valid pairs are (0,0), (0,1), and (1,1).
// The maximum distance is 1 with pair (0,1).
// Example 3:

// Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
// Output: 2
// Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
// The maximum distance is 2 with pair (2,4).

// Constraints:

// 1 <= nums1.length, nums2.length <= 10^5
// 1 <= nums1[i], nums2[j] <= 10^5
// Both nums1 and nums2 are non-increasing.

#include <bits/stdc++.h>
using namespace std;

// we use two pointer approach
// t.c-O(n+m)
// s.c-O(1)
int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();
  int m = nums2.size();
  int ans = 0; // if we have no valid pair then ans is 0
  int i = 0, j = 0;
  while (i < n && j < m)
  {
    // condition check
    if (nums1[i] <= nums2[j])
    {
      // instead of checking i<=j separate we use max built in function so if j-i is -ve then max take ans which is positive from starting so always positive
      ans = max(ans, j - i);
      j++;
    }
    // when nums1[i]>nums2[j] and we don't want to reset j =ifor each i because we want maximum distance so if j travel and i still is less then we get maximum distance so don't need to reset j=i for each i
    else
    {
      i++;
    }
  }
  return ans;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums1[i];
  }
  vector<int> nums2(m);
  for (int j = 0; j < m; j++)
  {
    cin >> nums2[j];
  }
  cout << maxDistance(nums1, nums2);
  return 0;
}

// initially i think this solution-
// this give time limit exceed and also have some logic issue
// int maxDistance(vector<int> &nums1, vector<int> &nums2)
// {
//   int n = nums1.size();
//   int m = nums2.size();
//   int ans = INT_MIN;
//   int i = 0, j = 0;
//   while (i < n)
//   {
//     while (i <= j && j < m)
//     {
//       if (nums1[i] <= nums2[j])
//       {
//         if ((j - i) > ans)
//           ans = j - i;
//         j++;
//       }
//       else
//       {
//         break;
//       }
//     }
//     if (i > j)
//     {
//       j++;
//     }
//     else
//     {
//       i++;
//       j = i;
//     }
//   }
//   if (ans == INT_MIN)
//     return 0;
//   return ans;
// }

// Issues in your code:
// j = i reset every time → this loses valid progress.
// Nested while(i <= j && j < m) condition is not needed.
// Using INT_MIN is unnecessary (distance is always ≥ 0).

// Clean & Correct Approach:
// Keep i and j
// Only move forward (never reset j)
// Maintain i ≤ j

// that we do above in main answer
// Key Idea:
// If condition satisfies → move j (increase distance because we want maximum distance)
// Else → move i (fix violation)
// Never move backwards → keeps it O(n + m)

// Why your version struggles:

// When you reset j = i, you recheck elements unnecessarily, making it less efficient and potentially wrong in edge cases.