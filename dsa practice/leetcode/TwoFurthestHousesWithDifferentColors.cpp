// There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

// Return the maximum distance between two houses with different colors.

// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

// Example 1:

// Input: colors = [1,1,1,6,1,1,1]
// Output: 3
// Explanation: In the above image, color 1 is blue, and color 6 is red.
// The furthest two houses with different colors are house 0 and house 3.
// House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
// Note that houses 3 and 6 can also produce the optimal answer.
// Example 2:

// Input: colors = [1,8,3,8,3]
// Output: 4
// Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
// The furthest two houses with different colors are house 0 and house 4.
// House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
// Example 3:

// Input: colors = [0,1]
// Output: 1
// Explanation: The furthest two houses with different colors are house 0 and house 1.
// House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.

// Constraints:

// n == colors.length
// 2 <= n <= 100
// 0 <= colors[i] <= 100
// Test data are generated such that at least two houses have different colors.

#include <bits/stdc++.h>
using namespace std;

// brute force- constraints are small so we try every pair of different color
// t.c-O(n^2)
// s.c-O(1)
int maxDistance(vector<int> &colors)
{
  int n = colors.size();
  int ans = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (colors[i] != colors[j])
      {
        if (abs(i - j) > ans)
          ans = abs(i - j);
      }
    }
  }
  return ans;
}
// greedy approach - we use two pinters
// one pointer is in left and another is at right
// in first case we move right pointer only if colors[l]==colors[r]
// in second case we move left pointer only if colors[l]==colors[r]
// t.c-O(n)+O(n)=O(2n) in worst case if only one pointer move in both case
// s.c-O(1)
int maxdistance(vector<int> &colors)
{
  int n = colors.size();
  int ans = INT_MIN;
  int l = 0, r = n - 1;
  // first case
  while (l <= r)
  {
    if (colors[l] != colors[r])
    {
      ans = max(ans, abs(l - r));
      l++;
      r--;
    }
    // move only right pointer
    else
    {
      r--;
    }
  }
  // // second case - because moving left pointer only when  equal also be a case
  l = 0, r = n - 1;
  while (l <= r)
  {
    if (colors[l] != colors[r])
    {
      ans = max(ans, abs(l - r));
      l++;
      r--;
    }
    // move only left pointer when equal
    else
    {
      l++;
    }
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<int> colors(n);
  for (int i = 0; i < n; i++)
  {
    cin >> colors[i];
  }
  // cout << maxDistance(colors);
  cout << maxdistance(colors);
  return 0;
}
