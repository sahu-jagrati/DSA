#include <bits/stdc++.h>
using namespace std;

struct Job
{
  int index;
  int start;
  int finish;
};

// Sort jobs by finish time
bool compare(Job a, Job b)
{
  return a.finish < b.finish;
}

void intervalScheduling(vector<int> &start, vector<int> &finish)
{
  int n = start.size();
  vector<Job> jobs(n);

  for (int i = 0; i < n; i++)
  {
    jobs[i] = {i + 1, start[i], finish[i]};
  }

  // Step 1: Sort by finish times
  sort(jobs.begin(), jobs.end(), compare);

  cout << "Jobs sorted by finish time:\n";
  cout << "Job\tStart\tFinish\n";
  for (auto j : jobs)
    cout << j.index << "\t" << j.start << "\t" << j.finish << "\n";

  // Step 2: Greedy selection
  vector<int> selected;
  int lastFinish = -1;

  for (int i = 0; i < n; i++)
  {
    if (jobs[i].start >= lastFinish)
    {
      selected.push_back(jobs[i].index);
      lastFinish = jobs[i].finish;
    }
  }

  // Step 3: Output
  cout << "\nMaximum set of compatible jobs:\n";
  for (int id : selected)
    cout << "Job " << id << " ";
  cout << "\nTotal jobs selected: " << selected.size() << endl;
}

int main()
{
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> finish = {2, 4, 6, 7, 9, 9};

  intervalScheduling(start, finish);
  return 0;
}
