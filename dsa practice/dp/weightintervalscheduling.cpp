#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// structure for job/interval
struct Job
{
  int start, finish, weight;
};

// custom comparator to sort jobs by finish time
bool jobCompare(Job a, Job b)
{
  return a.finish < b.finish;
}

// binary search: find last job that doesn't conflict with job[i]
int latestNonConflict(vector<Job> &jobs, int i)
{
  int low = 0, high = i - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (jobs[mid].finish <= jobs[i].start)
    {
      if (jobs[mid + 1].finish <= jobs[i].start)
      {
        low = mid + 1;
      }
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

// dp solution for weighted interval scheduling
int weightedIntervalScheduling(vector<Job> &jobs)
{
  // sort jobs by finish time
  sort(jobs.begin(), jobs.end(), jobCompare);

  int n = jobs.size();
  vector<int> dp(n);

  dp[0] = jobs[0].weight;

  for (int i = 1; i < n; i++)
  {
    // include current job
    int incl = jobs[i].weight;
    int l = latestNonConflict(jobs, i);
    if (l != -1)
    {
      incl += dp[l];
    }
    // exclude current job
    dp[i] = max(incl, dp[i - 1]);
  }

  return dp[n - 1];
}

int main()
{
  int n;
  cin >> n;
  vector<Job> jobs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> jobs[i].start >> jobs[i].finish >> jobs[i].weight;
  }
  cout << " Optimal profit " << weightedIntervalScheduling(jobs) << endl;

  return 0;
}