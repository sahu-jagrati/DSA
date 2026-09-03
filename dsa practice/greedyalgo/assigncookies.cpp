// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

// Example 1:
// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.

// Example 2:
// Input: g = [1,2], s = [1,2,3]
// Output: 2
// Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
// You have 3 cookies and their sizes are big enough to gratify all of the children,
// You need to output 2.

// Constraints:

// 1 <= g.length <= 3 * 10^4
// 0 <= s.length <= 3 * 10^4
// 1 <= g[i], s[j] <= 2^31 - 1

// here we have greed array which denotes that the greed of children example- greed=[1,5,3,3,4] like child1 has greed of 1 minimum size of a cookie that the child will be content with, child2 has greed of 5 minimum size of a cookie that the child will be content with and so on
// size array represent the size of cookie

// parent give cookie to each child but child can take cookie if and only if greed[i]<=size[j]
// and each child can have atmost one cookie

// we want to maximize the number of children that are assign with cookie

// example- greed=[1,5,3,3,4] and size=[4,2,1,2,1,3], we want greed[i]<=size[j]
// i)way - 1 can be assign size 4 cookie because 1<=4, for 5 there is no cookie with ssize >5, for 3 we have size 3 cookie, for 3 we have no cookie because size 4 and 3 already assign so cannot assign again so here no.of children assign with cookie=2

// ii)way- 1 can be assign with size 1 cookie, for 5 no cookie, 3 assign with size 3 cookie, 3 assign with size 4 cookie, for 4 no cookie so no.of children assign with cookie=3

// max children  assign with cookie=3

// answer=3

#include <bits/stdc++.h>
using namespace std;

// solution is - first sort both array then use two pointers approach

int maxChildrenAssignWithCookie(vector<int> &greed, vector<int> &size)
{
  int n = greed.size();
  int m = size.size();
  sort(greed.begin(), greed.end());
  sort(size.begin(), size.end());

  int l = 0, r = 0; // l for greed array and r for size array
  while (l < n && r < m)
  {
    if (greed[l] <= size[r])
    {
      l++;
    }
    r++;
  }
  return l; // return number of children assign with cookie
}

// you can  do this problem with dp also
// memoization
// We use recursion to try all ways of assigning cookies to children. At each step, if the current cookie can satisfy the current child, we try both: assigning it or skipping it, and take the better result. If it can't satisfy, we skip. To avoid recalculating the same subproblems, we store results in a 2D dp[child][cookie] array. This saves time by reusing already computed answers.
// Sort both student and cookie array in ascending order.
// Begin from the first student and the first cookie and at each step, check if the current cookie can satisfy the current student.
// If the cookie can't satisfy the student, skip it and try the next one.
// If yes, either give the cookie to the student and move to the next student and next cookie or skip the cookie and try giving the next one to the same student.
// For every student-cookie pair, remember the result so you don’t recalculate it later. Repeat the process until you’ve considered all students or all cookies.

// how we write memoization see dp notes
// Start recursion from index 0 for both arrays in this problem we go from bottom-up for memoization

// Time Complexity: O(n*m), every pair of student and cookie is checked exactly once.
// Space Complexity: O(n*m) + O(n+m), A 2D memoization table is used to store result of subproblems and an additional O(n+m) stack space is used.

int memoization(int greedIndex, int sizeIndex, vector<int> &greed, vector<int> &size, vector<vector<int>> &dp)
{
  // Base case: if we reach end of either list
  if (greedIndex >= greed.size() || sizeIndex >= size.size())
  {
    return 0;
  }
  // Return memoized result if already computed
  if (dp[greedIndex][sizeIndex] != -1)
    return dp[greedIndex][sizeIndex]; // here memo is dp matrix I just change name

  int result = 0;
  // If the cookie satisfies the child's greed
  if (size[sizeIndex] >= greed[greedIndex])
  {
    // Option 1: assign this cookie and move to next student and cookie
    result = max(result, 1 + memoization(greedIndex + 1, sizeIndex + 1, greed, size, dp));
  }
  // Option 2: skip this cookie and try the next one for the same student
  result = max(result, memoization(greedIndex, sizeIndex + 1, greed, size, dp));

  // store result in dp table
  return dp[greedIndex][sizeIndex] = result;
}

// tabulation approach-
// We build a 2D table from the end, where each cell dp[i][j] represents the maximum number of children that can be satisfied from child i and cookie j onward. At each point, we decide whether to assign the current cookie or skip it. This approach avoids recursion and computes the solution iteratively using previously filled results.
// Sort both student and cookie array in ascending order.
// Create a table that stores the best result for every combination of remaining students and cookies and start filling the table from the end, where all students or all cookies are already used.
// At each cell, check if the current cookie can satisfy the current student. If it can, decide between giving the cookie to the student or skipping it and store whichever gives a better result.
// If it can’t, move to the next cookie without satisfying this student.
// Keep filling the table backward until you reach the beginning.

// in memoization we go bottom-up so now in tabulation we go top-down

// Time Complexity: O(n*m), every pair of student and cookie is checked exactly once.
// Space Complexity: O(n*m), A 2D memoization table is used to store result of subproblems.
int tabulation(vector<int> &greed, vector<int> &size)
{
  int n = greed.size();
  int m = size.size();

  // Sort both arrays to prepare for DP
  sort(greed.begin(), greed.end());
  sort(size.begin(), size.end());

  // Create a 2D DP table
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // fill dp table whcih is of size dp[n+1][m+1]
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      // Skip current cookie if greed not satisfy
      int skip = dp[i][j + 1];
      // Take current cookie if it satisfies student's greed
      int take = 0;
      if (size[j] >= greed[i])
      {
        take = 1 + dp[i + 1][j + 1];
      }
      // Take the best of both choices
      dp[i][j] = max(skip, take);
    }
  }
  return dp[0][0];
}

int findContentChildren(vector<int> &greed, vector<int> &size)
{
  // Sort both arrays to prepare for DP
  sort(greed.begin(), greed.end());
  sort(size.begin(), size.end());

  // memoization
  // Initialize DP table with -1
  // vector<vector<int>> dp(greed.size(), vector<int>(size.size(), -1));

  // return memoization(0, 0, greed, size, dp);

  // tabulation
  return tabulation(greed, size);
}

int main()
{
  int n, m;
  cout << "Enter the size of an arrays: ";
  cin >> n >> m;
  vector<int> greed(n);
  cout << "Enter the elt of an array greed: ";
  for (int i = 0; i < n; i++)
  {
    cin >> greed[i];
  }
  vector<int> size(m);
  cout << "Enter the elt of an array size: ";
  for (int i = 0; i < m; i++)
  {
    cin >> size[i];
  }

  // optimal approach is grredy one
  int answer = maxChildrenAssignWithCookie(greed, size);
  cout << "Max Children Assign With Cookie are:  " << answer << endl;

  // we just for knowing about dp we use dp also here
  cout << findContentChildren(greed, size);
  return 0;
}
