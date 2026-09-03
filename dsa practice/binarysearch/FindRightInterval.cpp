// You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

// The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

// Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

// Example 1:

// Input: intervals = [[1,2]]
// Output: [-1]
// Explanation: There is only one interval in the collection, so it outputs -1.
// Example 2:

// Input: intervals = [[3,4],[2,3],[1,2]]
// Output: [-1,0,1]
// Explanation: There is no right interval for [3,4].
// The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
// The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
// Example 3:

// Input: intervals = [[1,4],[2,3],[3,4]]
// Output: [-1,2,-1]
// Explanation: There is no right interval for [1,4] and [3,4].
// The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.

// Constraints:

// 1 <= intervals.length <= 2 * 10^4
// intervals[i].length == 2
// -10^6 <= starti <= endi <= 10^6
// The start point of each interval is unique

#include <bits/stdc++.h>
using namespace std;

// brute force

// what I think is that
// A.T.Q we want, the right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

// and we want indexing that we return in answer array according to given intervals array so we make temp for intervals array and sort the temp array we sort the temp array because we want minimized startj for each interval and startj>=endi so we sort temp array

// next we store the each interval with their index according to given intervals arrray because for answer array we want that so we use map data structure

// next we again take map data structure and start traversing sort temp array to get the right interval and in map for each interval of temp we store the index of interval j , here one thing also we want startj minimized so for getting right interval we search it from i to n for each interval i
// now we make ans array
// in ans array we have to return the index according to given interval array so we search the index of interval of intervals array in map of temp

bool compare(vector<int> &a, vector<int> &b)
{
  return a[0] < b[0]; // start point is unique so we don't need to check for equal start value
}
// for an example we have intervals=[[1,2]] here [1,2] is not a right interval for itself because startj=1 and endi=2 so startj is not >= endi
// if we take another example- [[1,1],[3,4]] here for interval [1,1] right interval is itself because startj=1 and endi =1 so satisfy startj>=endi here [3,4] also satisfy but we want minimized startj so that's why we go j from i to n means from itself to n

// t.c-
// sorting-O(nlogn)
// we use ordered map so it take O(logn) for each operation so for mpp1 insert it is O(nlogn)
// nested searching-O(n^2)
// for ans array-O(nlogn)
// so approx total t.c-O(n^2)
// s.c-O(n)(for mpp1)+O(n)(for mpp2)+O(n)(for ans array)=O(n)
vector<int> findRightInterval(vector<vector<int>> intervals)
{
  int n = intervals.size();
  vector<vector<int>> temp = intervals;    // copy the intervals array because we want to sort
  sort(temp.begin(), temp.end(), compare); // sort A.T start
  // for storing index of intervals array
  map<pair<int, int>, int> mpp1;
  for (int i = 0; i < n; i++)
  {
    mpp1[{intervals[i][0], intervals[i][1]}] = i; // original index
  }
  // now for each interval i we get index of right interval j so for that we use temp array because we sort it A.T start so we get minimized startj easily
  map<pair<int, int>, int> mpp2;
  for (int i = 0; i < n; i++)
  {
    int index = -1; // if we don't get any  right interval j then we store index =-1 for interval i
    // we want startj is minimized so we start from j=i to n
    for (int j = i; j < n; j++)
    {
      if (temp[j][0] >= temp[i][1])
      {
        // we have to store the actual index of temp[j] interval which we store in mpp1
        index = mpp1[{temp[j][0], temp[j][1]}];
        break; // because we want minimized so when we get first index that fulfil condition we break
      }
    }
    // we store right interval index for interval i in mpp2
    mpp2[{temp[i][0], temp[i][1]}] = index;
  }
  // now answer array
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    // for interval i we want right interval j index but A.T given interval array so we get that from mpp2 for each intervals array interval
    ans[i] = mpp2[{intervals[i][0], intervals[i][1]}];
  }
  return ans;
}

// optimized approach
// since given that start point is unique, so we don't need: map<pair<int,int>,int>
// we only need to store: start->original index because start point is unique so we sort intervals according to it no need of end point to compare if start is equal for two intervals
// then:
// sort intervals by their starting point.
// for every interval[start,end], binary search for the smallest start>=end.
// return the original index corresponding to that start.
// we wnat only index of right interval not whole interval

// t.c-
// push in v-O(n)
// sorting:O(nlogn)
// n binary searches-O(nogn) because for each binary search O(logn) so for n it is O(nlogn)
// total t.c-O(nlogn)
// s.c-O(n)(for v)+O(n)(for ans)=O(n)

vector<int> FindRightInterval(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  // we store start point of each interval with original index
  // {start,original_index}
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
  {
    v.push_back({intervals[i][0], i});
  }
  // sort by start
  sort(v.begin(), v.end());
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++)
  {
    int end = intervals[i][1];
    // find first start>=end
    // we use binary searcj on v array of start
    int l = 0, r = n - 1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (v[mid].first >= end)
      {
        ans[i] = v[mid].second;
        r = mid - 1; // because we wnat minimized start
      }
      else
      {
        l = mid + 1;
      }
    }
  }
  return ans;
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
  // vector<int> ans = findRightInterval(intervals);
  vector<int> ans = FindRightInterval(intervals);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}