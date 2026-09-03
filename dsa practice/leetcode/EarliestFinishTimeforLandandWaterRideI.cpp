// You are given two categories of theme park attractions: land rides and water rides.

// Land rides
// landStartTime[i] – the earliest time the ith land ride can be boarded.
// landDuration[i] – how long the ith land ride lasts.
// Water rides
// waterStartTime[j] – the earliest time the jth water ride can be boarded.
// waterDuration[j] – how long the jth water ride lasts.
// A tourist must experience exactly one ride from each category, in either order.

// A ride may be started at its opening time or any later moment.
// If a ride is started at time t, it finishes at time t + duration.
// Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
// Return the earliest possible time at which the tourist can finish both rides.

// Example 1:

// Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]

// Output: 9

// Explanation:​​​​​​​

// Plan A (land ride 0 → water ride 0):
// Start land ride 0 at time landStartTime[0] = 2. Finish at 2 + landDuration[0] = 6.
// Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, finish at 6 + waterDuration[0] = 9.
// Plan B (water ride 0 → land ride 1):
// Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
// Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 9 + landDuration[1] = 10.
// Plan C (land ride 1 → water ride 0):
// Start land ride 1 at time landStartTime[1] = 8. Finish at 8 + landDuration[1] = 9.
// Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish at 9 + waterDuration[0] = 12.
// Plan D (water ride 0 → land ride 0):
// Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
// Land ride 0 opened at landStartTime[0] = 2. Start at time 9, finish at 9 + landDuration[0] = 13.
// Plan A gives the earliest finish time of 9.

// Example 2:

// Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]

// Output: 14

// Explanation:​​​​​​​

// Plan A (water ride 0 → land ride 0):
// Start water ride 0 at time waterStartTime[0] = 1. Finish at 1 + waterDuration[0] = 11.
// Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and finish at 11 + landDuration[0] = 14.
// Plan B (land ride 0 → water ride 0):
// Start land ride 0 at time landStartTime[0] = 5. Finish at 5 + landDuration[0] = 8.
// Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and finish at 8 + waterDuration[0] = 18.
// Plan A provides the earliest finish time of 14.​​​​​​​

// Constraints:

// 1 <= n, m <= 100
// landStartTime.length == landDuration.length == n
// waterStartTime.length == waterDuration.length == m
// 1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 1000

#include <bits/stdc++.h>
using namespace std;

// here we have to do exactly one land ride and one water ride but in earliest possible time
// so we check for each pair of one land ride and one water ride

// t.c-O(n*m)
// s.c-O(1)

int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
{
  int n = landStartTime.size();
  int m = waterStartTime.size();
  int mini = INT_MAX; // because we want earliest possible time meanse minimum time to take exactly one land ride and one water ride

  // first we take land ride and then take water ride because we have to check from both side which one give earliest possible time
  for (int i = 0; i < n; i++)
  {
    int start1 = landStartTime[i];
    int end1 = start1 + landDuration[i];
    for (int j = 0; j < m; j++)
    {
      // If waterStartTime[j] <= end1, you can start it at end1. and add waterduartion
      // If waterStartTime[j] > end1, you must wait until waterStartTime[j]. and add water duration
      //  So the finish time should be: we take max because end1 is sum of landstart+landduartion if it is max then add water duration or if water start max then add water duration directly we take max because we don't want to do like waterstart-end1+end1+waterduration which is also equal to waterstart+waterduration so we directly take max of both
      int finish = max(end1, waterStartTime[j]) + waterDuration[j]; // because duration add in both cases
      mini = min(mini, finish);
    }
  }

  // now we first take water ride and then take land ride
  for (int i = 0; i < m; i++)
  {
    int start2 = waterStartTime[i];
    int end2 = start2 + waterDuration[i];
    for (int j = 0; j < n; j++)
    {
      int finish = max(end2, landStartTime[j]) + landDuration[j]; // similar process here
      mini = min(mini, finish);
    }
  }
  return mini;
}

// above code same but slightly small by removing unwanted variables

int earliestfinishtime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
{
  int n = landStartTime.size();
  int m = waterStartTime.size();

  int mini = INT_MAX;
  // land to water
  for (int i = 0; i < n; i++)
  {
    int end1 = landStartTime[i] + landDuration[i];
    for (int j = 0; j < m; j++)
    {
      int finish = max(end1, waterStartTime[j]) + waterDuration[j]; // because duration add in both cases
      mini = min(mini, finish);
    }
  }
  // water to land
  for (int i = 0; i < m; i++)
  {
    int end2 = waterStartTime[i] + waterDuration[i];
    for (int j = 0; j < n; j++)
    {
      int finish = max(end2, landStartTime[j]) + landDuration[j]; // similar process here
      mini = min(mini, finish);
    }
  }
  return mini;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> landStartTime(n);
  for (int i = 0; i < n; i++)
  {
    cin >> landStartTime[i];
  }
  vector<int> landDuration(n);
  for (int i = 0; i < n; i++)
  {
    cin >> landDuration[i];
  }
  vector<int> waterStartTime(m);
  for (int i = 0; i < m; i++)
  {
    cin >> waterStartTime[i];
  }
  vector<int> waterDuration(m);
  for (int i = 0; i < m; i++)
  {
    cin >> waterDuration[i];
  }
  // cout << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
  cout << earliestfinishtime(landStartTime, landDuration, waterStartTime, waterDuration);
  return 0;
}