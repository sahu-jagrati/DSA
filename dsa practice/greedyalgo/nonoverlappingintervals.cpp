// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// we can also remove [1,2] and [2,3] then rest are non-overlapping intervals but in that case we remove 2 intervals and we want minimum number of intervals so answer=1 by removing interval[1,3]
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Constraints:

// 1 <= intervals.length <= 10^5
// intervals[i].length == 2
// -5 * 10^4 <= starti < endi <= 5 * 10^4

// question is same to n meetings in a single room in which we want maximum number of meetings we can perform in a single room without ovelap with other meetings

// and here we want minimum intervals we can remove to make rest intervals non-overlaaping=size of array-maximum intervals that are not overlapp(i.e maximum number of meetings we can perform in a single room without ovelap with other meetings)

// there is only one change is that intervals [5,7] and [7,9] are said non-overlap intervals but in meeting question they are not overlap so this is change here

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
  return a.second < b.second; // sort in ascending order of end[i]
}

// t.c-O(nlogn)(sorting) + O(n)(traversing loop)
// s.c-O(1)
int minIntervalRemove(vector<pair<int, int>> &intervals)
{
  int n = intervals.size();
  // nlogn
  sort(intervals.begin(), intervals.end(), compare); // sort in ascending order of end[i]

  // we use cnt for counting maxintervals that are not overlap
  // because first meeting/interval is performed obviously means not overlap
  int cnt = 1, lastEndTime = intervals[0].second;

  // traverse intervals array
  // i=0 already done initially
  // run n times
  for (int i = 1; i < n; i++)
  {
    // this is the change here we use = to also
    if (intervals[i].first >= lastEndTime)
    {
      cnt = cnt + 1;
      lastEndTime = intervals[i].second;
    }
  }
  return n - cnt; // return minimum interval remove to make rest intervals non-overlapping where cnt is max intervals that are not overlap
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<pair<int, int>> intervals(n);
  for (int i = 0; i < n; i++)
  {
    cout << "Enter start,end for " << i + 1 << ": ";
    cin >> intervals[i].first >> intervals[i].second;
  }
  int answer = minIntervalRemove(intervals);
  cout << "Minimum intervals remove to make rest of all intervals non-overlapping: " << answer << endl;

  return 0;
}