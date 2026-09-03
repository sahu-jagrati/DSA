#include <bits/stdc++.h>
using namespace std;

struct Job
{
  int start, finish, weight;
};

// time complexity-O(nlogn)(because of binary search)
// space complexity-O(n)

// Binary search to find last job that doesn’t conflict with job[i]

int findLastNonConflicting(vector<Job> &jobs, int i)
{
  int low = 0, high = i - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (jobs[mid].finish <= jobs[i].start)
    {
      if (jobs[mid + 1].finish <= jobs[i].start)
        low = mid + 1;
      else
        return mid;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

pair<int, vector<int>> weightedIntervalScheduling(vector<Job> &jobs)
{
  int n = jobs.size();
  sort(jobs.begin(), jobs.end(), [](Job a, Job b)
       { return a.finish < b.finish; });

  vector<int> dp(n, 0);
  vector<int> p(n, -1);

  // Precompute p(i)
  for (int i = 0; i < n; i++)
    p[i] = findLastNonConflicting(jobs, i);

  dp[0] = jobs[0].weight;

  // DP computation
  for (int i = 1; i < n; i++)
  {
    int include = jobs[i].weight;
    if (p[i] != -1)
      include += dp[p[i]];
    dp[i] = max(include, dp[i - 1]);
  }

  // Reconstruction
  vector<int> selected;
  int i = n - 1;
  while (i >= 0)
  {
    int include = jobs[i].weight + (p[i] != -1 ? dp[p[i]] : 0);
    if (include > (i > 0 ? dp[i - 1] : 0))
    {
      selected.push_back(i);
      i = p[i];
    }
    else
    {
      i--;
    }
  }
  reverse(selected.begin(), selected.end());

  return {dp[n - 1], selected};
}

int main()
{
  vector<Job> jobs = {
      {1, 3, 5}, // start, finish, profit
      {2, 5, 6},
      {4, 6, 5},
      {6, 7, 4},
      {5, 8, 11},
      {7, 9, 2}};

  auto result = weightedIntervalScheduling(jobs);
  int maxProfit = result.first;
  vector<int> selected = result.second;

  cout << "Maximum total profit: " << maxProfit << endl;
  cout << "Jobs selected (0-indexed after sorting by finish time): ";
  for (int idx : selected)
    cout << "(" << jobs[idx].start << "," << jobs[idx].finish << "," << jobs[idx].weight << ") ";
  cout << endl;

  return 0;
}