// Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

// Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

// Example 1:

// Input: n = 4, k = 2
// Output: 5
// Explanation: The two line segments are shown in red and blue.
// The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
// Example 2:

// Input: n = 3, k = 1
// Output: 3
// Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
// Example 3:

// Input: n = 30, k = 7
// Output: 796297179
// Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.

// Constraints:

// 2 <= n <= 1000
// 1 <= k <= n-1

#include <bits/stdc++.h>
using namespace std;

// What are we counting?
// We have points: 0,1,2,3,...,n-1
// A segment (a,b) is valid when: a<b

// first we understand the what "non-overlapping" means here:
// Suppose we have a segment (a,b) covers the points from a to b.
// Every segment must have a<b, even a!=b
// Two segments can share an endpoint, e.g (0,2) and (2,3) are valid, they share an endpoint 2
// Their interior cannot overlap, so (0,3) and (1,2) are not valid

// Each segment covers atleast two points.
// And the endpoints of each segment must have integral coordinates means integer coordinates.
// And it is not necessary that the k line segments cover all n points, it can cover all n points or cannot cover all n points.

// We are givingg n points from 0 to n-1

// We solve this problem Using "DP + prefix sum"

// here we use 2D dp
// define the Dp:
// Let dp[i][j] represents the number of ways to draw exactly j non-overlapping segments using the first i points: 0,1,2,...,i-1

// here dp[n][k] represents the number of ways to draw the exactly k non-overlapping segments using the n points which is our answer.
// for example: dp[4][1] means number of ways to draw 1 non-overlapping segments using 4 points that is 0,1,2,3 because(0 to n-1)

// here we want total number of ways to draw the exactly k non-overlapping segments using the n points

// so we try all ways from 0 to k means we try to draw all line segments to calculate exactly k non-overlapping segments by using the first i points i.e we go for 0 points , 1 points , 2 points, and so on upto n-1 points

// How do we calculate dp[i][j]?
// now there is a case how we handled the last point
// Consider the last point i-1
// There are two possibilities:

// Case 1: Point i-1 is not the endpoint of a segment i.e we don't use point i-1
// Then we simply don't use this point: dp[i-1][j] means the number of ways to draw exactly j non-overlapping segments using the first i-1 points: 0,1,2,...,i-2 here i-1 is not includes
// example: if we have points: 0,1,2,3 and don't use point 3, we only use: 0,1,2 which gives: dp[3][j] means with 3 points

// Case 2: A segment enda at point i-1
// Suppose this last segment is: (s,i-1)
// For example: if i=4, the last point is 3.
// The possible last segments are:
// (0,3)
// (1,3)
// (2,3)

// We cannot have (3,3) because a segment must cover atleast two points A.T.Q

// Since a segment must contain atleast two points: s<=i-2 because if s==i-2 then we have points : i-2 and i-1 means two points in segment or if s<i-2 then there are more than two points in segment (s,i-1)

// if j=i-1 then segment is (s,j)
// Before this segment, we need j-1 segments using points upto s.
// If the new segment starts at s, those previous j-1 segments can use points upto s.
// Because segments are allowed to share endpoints.
// example: (0,2), (2,3) is valid.
// So if the new segment is: (2,3) the previous segment is allowed to end at 2.

// That gives: dp[s+1][j-1] means the number of ways to draw exactly j-1 non-overlapping segments using the first s+1 points: 0,1,2,...,s for each possible s.

// Why s+1?
// Because the points available before the new segment are: 0...s and sharing endpoint s is allowed so new segment starts with s see in above example.

// Therefore:

// we want total number of ways so we want summation of all ways
// dp[i][j]= ( total ways when endpoint is not use) + (total ways when endpoint is use)
// so total ways when endpoint is not use : dp[i-1][j]

// and total ways when endpoint is  use: dp[1][j-1]+dp[2][j-1]+dp[3][j-1]+...+dp[i-1][j-1]

// dp[i][j]=dp[i-1][j]+dp[1][j-1]+dp[2][j-1]+...+dp[i-1][j-1] = when i-1 is not included + when i-1 is endpoint

// Now we nned to optimize the summation(dp[1][j-1]+dp[2][j-1]+...+dp[i-1][j-1])
// If we calculate this sum every time, the complexity becomes O(n^2  *k)

// instead of that, we use Prefix Sum
// maintain prefix:
// where prefix stores: dp[1][j-1]+dp[2][j-1]+...+dp[i-1][j-1]
// then : dp[i][j]=dp[i-1][j]+prefix
// this reduces the complexity from O(n^2 *k) to O(n*k)

// now there is one important thing:
// when we calculate prefix we use previous prefix value to calculate current preifx
// When we wrote:
// prefix = prefix + dp[i-1][j-1];

// When i=1, this adds:
// dp[0][0] but dp[0][0]=1 because there is one way to draw 0 segments.
// That is correct for the 0-segment state, but it should not be counted as a possible previous configuration for creating a new segment.
// There must be atleast one point availbale before the new segment's endpoint.

// Therefore, we only update the prefix when:

// i>=2 because when i=1 then in prefix we add dp[0][0] means 0-segment state which is not counted in configuration for creating a new segment

// Base case:
// If we want exactly 0 segments, there is exactly one way: draw nothing:
// so: dp[i][0]=1 for every i
// dp[0][0]=1
// dp[1][0]=1
// dp[2][0]=1 and so on

// But for j>0, if there are not enough points, the answer is 0.
// dp[0][1]=0
// dp[0][2]=0
// because we cannot draw a segment without points.

// example: for n=4, k=2
// Points 0 to n-1 i.e 0,1,2,3

// i) for one segment i.e when j=1, there are :
// (0,1)
// (0,2)
// (0,3)
// (1,2)
// (1,3)
// (2,3)
// so: dp[4][1]=6 means there 6 ways to draw exactly 1 non-overlapping segment with 4 points

// ii) for two segments, the valid possibilities are:
// (0,1), (1,2)
// (0,1), (2,3)
// (0,1),(1,3)
// (0,2),(2,3)
// (1,2),(2,3)
// therefore: dp[4][2]=5 means there are 5 ways to draw exactly 2 non-overlapping segment with 4 points
int mod = 1e9 + 7;
// t.c-O(n)(for first for loop when we want 0 line segments)+O(k*n)=O(k*n)
// s.c-O(k*n) for dp matrix
int numberOfSets(int n, int k)
{
  // dp[i][j]=number of ways to draw exactly j segments using the first i points
  // we want number of ways to draw exactly k non-overlapping segments using the n points so it is store in dp[n][k] so that's why we use dp of size (n+1,k+1)
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
  // we already initialized dp with 0 so base case when j>0 if there are not enough points, the answer is 0.
  // dp[0][1]=0
  // dp[0][2]=0
  // because we cannot draw a segment without points.

  // base case: when k=0 means 0-segment state, there is only 1 way to draw 0 segment which is draw nothing
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 1;
  }

  // we go for all possible segmenst upto k
  // we already done with 0-segment
  // here we go with segment 1 to k
  for (int j = 1; j <= k; j++)
  {
    long long prefix = 0;
    // using each points means when we have 1 point , when we have 2 points and so on upto n points ofr each j
    for (int i = 1; i <= n; i++)
    {
      // Add dp[i-1][j-1] only when there are atleast 2 points available
      if (i >= 2)
      {
        prefix = (prefix + dp[i - 1][j - 1]) % mod;
      }
      // two possibilities:
      // i) don't use endpoint i-1 so in that case dp[i-1][j]
      // ii) a segment ends at point i-1 so in that case prefix
      // we want all ways so summation of all possibilities
      dp[i][j] = (dp[i - 1][j] + prefix) % mod;
    }
  }
  // number of ways to draw exactly k non-overlapping segments using the n points store in dp[n][k]
  return dp[n][k];
}

// dry run:
// n=4, k=2

// j runs from 1 to 2

// for j=1:

// when i=1: dp[1][1]=dp[0][1]=0
// now prefix=0
// when i=2: dp[2][1]=dp[1][1]+prefix=1+0=1, now prefix=1
// when i=3:dp[3][1]=dp[2][1]+prefix=dp[2][1]+(prefix+dp[2][0])=1+(1+1)=3. now prefix=3
// when i=4: dp[4][1]=dp[3][1]+prefix=dp[3][1]+(prefix+dp[3][0])=3+(2+1)=6

// for j=2

// when i=1: we have only the first 1 point which is 0(0 to 1-1) and we want 2 segments so impossible.
// initially prefix=0 since i=1 not>=2 soprefix=0
// dp[1][2]=dp[0][2]+prefix=0+0=0

// when i=2 now we have two points : 0,1
// Can we make 2 segments? No. We only have two points, so we can make atmost one segment:(0,1) because we want atleast two points in one segment
// i=2>=2 so prefix=prefix+dp[i-1][j-1]
// now prefix=0+dp[1][1]=0+0=0
// dp[2][2]=dp[1][2]+prefix=dp[1][2]+(prefix+dp[1][1])=0

// when i=3 now we have three points: 0,1,2
// We want exactly 2 segments.
// there is exactly one way:(0,1), (1,2) , the two segments share point 1, which is allowed.
// now prefix=prefix+dp[2][1]=0+1=1
// dp[3][2]=dp[2][2]+prefix=dp[2][2]+(prefix+dp[2][1])=0+(0+1)=1
// What does that 1 represent?
// It represents: (0,1),(1,2)
// Why?
// We are creating the second segment ending at point 2.
// The possible second segment can start at: 0 or 1
// But to have a valid previous configuration, the relevant contribution here is: dp[2][1]=1 the previous segments is: (0,1) then we create: (1,2) so: (0,1),(1,2)

// when i=4 now we have all 4 points: 0,1,2,3
// now prefix=prefix+dp[3][1]=1+3=4
// dp[4][2]=dp[3][2]+prefix=1+4=5

// now understand prefix=4
// When calculating:

// dp[4][2]

// we have two cases.

// Case 1: Don't use point 3

// Then we simply have:

// dp[3][2] = 1

// That gives:

// (0,1), (1,2)

// That's our 1.

// Case 2: The second segment ends at point 3

// The possible second segments are:

// (0,3)
// (1,3)
// (2,3)

// For each possibility, we need a valid way to make the first segment.

// Second segment = (0,3)

// There is no room for a previous segment before it.

// So:

// 0 ways
// Second segment = (1,3)

// Before it, we can have:

// (0,1)

// So:

// 1 way
// Second segment = (2,3)

// Before it, we can have any one segment using points 0,1,2:

// (0,1)
// (0,2)
// (1,2)

// So:

// 3 ways

// Therefore:

// 0 + 1 + 3 = 4

// That's exactly our:

// prefix = 4

// And then:

// dp[4][2]
// =
// dp[3][2] + 4

// = 1 + 4

// = 5

// finish and our answer is dp[4][2]=5
int main()
{
  int n, k;
  cin >> n >> k;
  cout << numberOfSets(n, k);
  return 0;
}