// we have job with their id,deadline, and profit
// deadline means if deadline=4 then you can perform that job on day1 or day2 or day3 or day4 means you can perform that job in any one day from 1 to 4 but not beyond 4

// and in a one day we can perform only one single job, not more than it,not less that it

// every job has a profit associated with it.
// Our task is to maximize the profit by performing the jobs. we can perform any number of jobs the only thing is we have to keep mind is it should be performed under a deadline

// example-
// id deadline profit
// 1    4       40
// 2    1       10
// 3    1       40
// 4    1       30

// if day1 we perform job of id1 then profit=40
// at day2 we cannot perform any other job because all job has deadline=1 which is out because we done job of id1 at that day
// so profit we have =40
// but we want maximum profit

// if day1 we do job of id3 having high profit for id2 and id4 so profit=40
// at day2 we do job of id1 profit=40+40
// so total profit is 80 which is maximum profit

// 1) -  if we have deadline much more then delay the job to the end day because initiald days will be empty and we can perform other jobs on those days whose deadline is much closer

// 2) - we want maximum profit so it's better to perform maximum profit job first

// first- we sort job in descending order Accorsing to their profit so we perform job with maximum profit first on the end of the day of their deadline

// we make hashaaray of size maxdeadline+1 having initial value=-1 which denotes no job done on that day
// when we do job on that day we mark it with the job id
// if job deadline is=4 and if day4 is already done by other job then we check for day3 if it is also done then we check for day2 if this also done then check for day1 if this also done means we cannot do this job

// because we can perform job in any one day from 1 to deadline day

// we cnt maxprofit and no.of job we can done by travelling jobs array

#include <bits/stdc++.h>
using namespace std;

struct Job
{
  int id;
  int deadline;
  int profit;
};

bool compare(Job a, Job b)
{
  return a.profit > b.profit; // sort in descending order
}

// t.c-O(nlogn)(for sorting) + O(n)(for loop to  getting maxdeadline ) + O(n*maxDeadline)(in worst case)
// s.c-O(maxdeadline) for hasharray

pair<int, int> maxProfit(vector<Job> &jobs)
{
  int n = jobs.size();
  // nlogn for this
  // on the basis of profit in descending order
  sort(jobs.begin(), jobs.end(), compare);
  int totalProfit = 0, cntJob = 0;
  int maxDeadline = -1; // for size of hasharray we have to know about maxdeadline
  // run n times
  for (int i = 0; i < n; i++)
  {
    maxDeadline = max(maxDeadline, jobs[i].deadline);
  }
  vector<int> hasharray(maxDeadline + 1, -1); // size and initial with -1

  // travel jobs array
  // run n times
  for (int i = 0; i < n; i++)
  {
    // we start with  end day of the deadline so in initial days we can perform other jobs whose deadline is much closer

    // this is difficult to know how much it run
    // in worst case if  all day are full so maxDealine time run

    // we can optimize this for loop using disjointset union of graph theory but this is for competitive programming not ask in interview
    for (int j = jobs[i].deadline; j >= 1; j--)
    {
      if (hasharray[j] == -1)
      {
        cntJob = cntJob + 1;
        totalProfit = totalProfit + jobs[i].profit;
        hasharray[j] = jobs[i].id;
        break;
      }
    }
  }
  return {totalProfit, cntJob};
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<Job> jobs(n);
  for (int i = 0; i < n; i++)
  {
    cout << "Enter id, deadline, profit for job " << i + 1 << ": ";
    cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
  }

  pair<int, int> answer = maxProfit(jobs);
  cout << "Maximum profit is: " << answer.first << " and total job done is: " << answer.second << endl;
  return 0;
}
