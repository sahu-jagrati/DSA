// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// Constraints:

// 0 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti <= endi <= 10^5
// intervals is sorted by starti in ascending order.
// newInterval.length == 2
// 0 <= start <= end <= 10^5

// example- intervals = [[1,2],[3,4],[5,7],[8,10],[12,16]], newInterval = [6,8]
// see [1,2],[3,4] are not overlap with new interval so copy left section as it is
// intervals- [5,7],[8,10] are overlap with new interval so take min of start of all overlap interval for start which is min(5,6,8)=5 and max of end of all overlap intervals for end which is max(7,8,10)=10 so insert interval becomes=[5,10]
// right section copy as it is which is interval - [12,16]
// se result=[[1,2],[3,4],[5,10],[12,16]]

// example-intervals = [[1,2],[3,4],[7,7],[8,10],[12,16]], newInterval = [5,6]
// here no interval overlap with newinterval so copy left section as it is,insert new interval, and copy right section as it is of intervals
// result=[[1,2],[3,4],[5,6],[7,7],[8,10],[12,16]]

#include <bits/stdc++.h>
using namespace std;

// we do
// if there are overlapping intervals after insert new interval then we take min of start of all overlap interval for start and max of end of all overlap intervals for end

// or if there is not overlapping intervals then copy left section,insert new interval, and copy right section as it is of intervals

// because given array intervals is sorted in ascending order by starti and having non-overlapping intervals

// t.c-O(n) because we traverse each interval inside intervals array once
// s.c-O(n) for result intervals array

vector<vector<int>> insertNewInterval(vector<vector<int>> &intervals, vector<int> &newInterval) // newinterval array has 2 elts only
{
  int n = intervals.size();
  vector<vector<int>> result;
  int i = 0;
  // left section as it is copy until it is valid the condition
  while (i < n && intervals[i][1] < newInterval[0])
  {
    result.push_back(intervals[i]);
    i = i + 1;
  }
  // when there is overlapping intervals then take min and max of start and end of all overlapping intervals
  while (i < n && intervals[i][0] <= newInterval[1])
  {
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    i = i + 1;
  }
  // add new interval
  result.push_back(newInterval);
  // right section copy as it is
  while (i < n)
  {
    result.push_back(intervals[i]);
    i = i + 1;
  }
  return result;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cout << "Enter start,end for " << i + 1 << ": ";
    cin >> intervals[i][0] >> intervals[i][1];
  }
  vector<int> newInterval(2);
  cout << "enter elt of new interval that is sorted in ascending order by start and non-overlapping intervals: ";
  cin >> newInterval[0] >> newInterval[1];

  vector<vector<int>> answer = insertNewInterval(intervals, newInterval);
  cout << "Intervals array after insert new interval is: ";
  for (auto it : answer)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
  return 0;
}
