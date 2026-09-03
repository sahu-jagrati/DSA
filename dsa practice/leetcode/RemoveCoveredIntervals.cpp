// Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

// The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

// Return the number of remaining intervals.

// Example 1:

// Input: intervals = [[1,4],[3,6],[2,8]]
// Output: 2
// Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
// Example 2:

// Input: intervals = [[1,4],[2,3]]
// Output: 1

// Constraints:

// 1 <= intervals.length <= 1000
// intervals[i].length == 2
// 0 <= li < ri <= 10^5
// All the given intervals are unique

#include <bits/stdc++.h>
using namespace std;

// brute force solution
// t.c-O(n^2)
// s.c-O(1)

// in brute force we check for each interval which covered which so we use two for loops in which both start from 0 to n but there is a case if an interval is covered by more than one interval, we cannot remove it two times, we remove it once by any recoverd interval
// example- intervals=[[1,10],[2,8],[3,7]] here [3,7] is covered by both [1,10] and [2,8] so we cannot count twice to remove it, it should be removed only once

int removecoveredintervals(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  int cnt = 0; // number of covered intervals

  for (int i = 0; i < n; i++)
  {
    int a = intervals[i][0];
    int b = intervals[i][1];
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue; // skip that
      int c = intervals[j][0];
      int d = intervals[j][1];

      // check condition
      if (c <= a && b <= d)
      {
        cnt++;
        break; // means we covered this interval so cnt this interval only once
      }
    }
  }
  // so number of remaining intervals = n-number of covered intervals = n- cnt
  return n - cnt;
}

// optimal solution- greedy approach
// first we sort the intervals A.T starting time in ascending order if starting time is equal then sort it A.T end time in descending order.

// here what we do we sort intervals first A.T starting time in ascending order so no nedd to check them after that because for an example if s1=1,s2=2 then 2 is come inside 1 in interval so for start time there is no nedd to check separately after sorting now  we have to check for only endtime for endtime if starttime equal for two interval then we sort it in descending order of endtime so that for nextinterval if endtime less than first it means it covered in first interval

bool static compare(vector<int> &a, vector<int> &b)
{
  // if starting time is equal then sort it A.T end time in descending order.
  if (a[0] == b[0])
  {
    return a[1] > b[1];
  }
  // else sort the intervals A.T starting time in ascending order
  return a[0] < b[0];
}

// t.c-O(nlogn)(for sorting)+O(n)(loop)
// s.c-O(1)

int removeCoveredIntervals(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  sort(intervals.begin(), intervals.end(), compare);
  int cnt = 0; // number of remaining intervals
  int maxEnd = 0;
  for (int i = 0; i < n; i++)
  {
    if (intervals[i][1] > maxEnd)
    {
      cnt++;
      maxEnd = intervals[i][1];
    }
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> intervals[i][0] >> intervals[i][1];
  }
  cout << removecoveredintervals(intervals) << endl;
  cout << removeCoveredIntervals(intervals);
  return 0;
}