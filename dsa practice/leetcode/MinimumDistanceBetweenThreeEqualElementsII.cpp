// You are given an integer array nums.

// A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

// The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

// Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

// Example 1:

// Input: nums = [1,2,1,1,3]

// Output: 6

// Explanation:

// The minimum distance is achieved by the good tuple (0, 2, 3).

// (0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.

// Example 2:

// Input: nums = [1,1,2,3,2,1,2]

// Output: 8

// Explanation:

// The minimum distance is achieved by the good tuple (2, 4, 6).

// (2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8.

// Example 3:

// Input: nums = [1]

// Output: -1

// Explanation:

// There are no good tuples. Therefore, the answer is -1.

// Constraints:

// 1 <= n == nums.length <= 10^5
// 1 <= nums[i] <= n

// Hint 1
// The distance formula abs(i - j) + abs(j - k) + abs(k - i) simplifies to 2 * (max(i, j, k) - min(i, j, k)).
// Hint 2
// Group the indices for each unique number. For a number to form a good tuple, it must appear at least 3 times.
// Hint 3
// For each number that appears at least 3 times, we want to find three of its indices p < q < r that minimize r - p. This is achieved by considering every three consecutive indices in the sorted list of indices.

#include <bits/stdc++.h>
using namespace std;

// using hint i solve this
// for dist = 2*(max(i,j,k)-min(i,j,k))  we use this
// we try to make a 2D vector array in which row size is (n+1) and column is variable of size
//  because nums[i] has elt from 1 to n so we try to do that in 2D array row index represent the nums[i] and in row[i] we have indices of that number(i.e nums[i])present in nums as in column
// if any row size is >=3 than it has 3 indices for that number and we check in that row array dist

int minimumDistance(vector<int> &nums)
{
  int n = nums.size();
  if (n <= 2)
    return -1;
  int ans = INT_MAX;
  // 2D vector array in which no.of rows are (n+1) because nums has elt from 1 to n so and no. of colums are variable in size
  vector<vector<int>> result(n + 1);
  // traverese nums and push index  according to its value in that index
  // / Group the indices for each unique number.
  for (int i = 0; i < n; i++)
  {
    result[nums[i]].push_back(i); // we psuh_back indices in row array for that elt occur in nums
  }
  // traverse result matrix
  for (int i = 0; i <= n; i++)
  {
    int m = result[i].size();
    // row size is >=3 then we can get atleast three indices
    if (m >= 3)
    {
      // we sort the row array becuase we want p<q<r that minimize r-p for this we want to check every  three consecutive indices in the sorted list of indices.
      sort(result[i].begin(), result[i].end());
      // we check 3 indices elt each time so we can go upto m-3 so that we check (m-3,m-2,m-1)
      for (int j = 0; j <= result[i].size() - 3; j++)
      {
        // using dist formula
        // we already sort the array so we take last and first in that three consecutive indices
        int dist = 2 * (result[i][j + 2] - result[i][j]);
        if (dist < ans)
          ans = dist;
      }
    }
  }
  if (ans == INT_MAX)
    ans = -1;
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
  cout << minimumDistance(nums) << endl;
  return 0;
}

// we want to prove:
// |i-j|+|j-k|+|k-i|=2*(max(i,j,k)-min(i,j,k))
// The expression depends only on the relative order of i,j,k, not their exact values.

// So assume without loss of generality (WLOG):
// i<=j<=k
// in our case : i,j,k are distinct indices so they cannot be equal
// so we assume: i<j<k
// Now remove absolute values:
// since i<j<k:
// |i-j|=j-i
// |j-k|=k-j
// |k-i|=k-i
// add them:
//|i-j|+|j-k|+|k-i|=(j-i)+(k-j)+(k-i)
// = 2K-2i
// 2(k-i)
// Since:
// k=max(i,j,k)
// i=min(i,j,k)
// we get:
// = 2(max(i,j,k)-min(i,j,k))
// hence proved.

// Intuition (Very Important)

// Think of points on a number line:

// The total pairwise distances between three points always equals twice the distance between the farthest two points.