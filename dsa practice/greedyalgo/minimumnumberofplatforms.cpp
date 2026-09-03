// given an array of arrival and departure time of n train

// we want minimum number of platforms required to accomodate all trains with their arraival and departure time.

// arr[]=[900.945,955,1100,1500,1800]
// dep[]=[920,1200,1130,1150,1900,2000]
// means

// train       arrival time    departure time
// 1            9:00            9:20
// 2            9:45            12:00
// 3            9:55            11:30
// 4            11:00           11:50
// 5            15:00           19:00
// 6            18:00           20:00

// answer =3 minimum platform  required to accomodate all trains with their arraival and departure time.

#include <bits/stdc++.h>
using namespace std;

// naive solution- find maximum intersection of train with other trains like

// t1 intersect with 0 train so require 1 paltforms for itself
// t2 intersect with 2 other train so require 3 paltforms with itself
// t3 intersect with 2 other train so require 3 paltforms with itself
// t4 intersect with 2 other train so require 3 paltforms with itself
// t5 intersect with 1 other train so require 2 paltforms with itself
// t6 intersect with 1 other train so require 2 paltforms with itself

// two trains overlap if:
// start2<=end1 AND end2>=start1

// t.c-O(n^2)
//  s.c-O(1)
int minPlatformRequired(vector<int> &arr, vector<int> &dep)
{
  int n = arr.size();
  int maxCnt = 0;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0; // cnt how many overlap with train i
    int start1 = arr[i];
    int end1 = dep[i]; // arrival and departure time of ith train
    for (int j = 0; j < n; j++)
    {
      int start2 = arr[j];
      int end2 = dep[j];

      // correct overlap condition
      if (start2 <= end1 && end2 >= start1)
      {
        cnt++;
      }
    }
    maxCnt = max(maxCnt, cnt);
  }
  return maxCnt;
}

// optimal version(sorting+two pointer approach)
// we have arrival and departure array
// so we move according to time(watch) like
// step-1 time=900 t1 arrive
// step-2 time 920 t1 dep
// step-3 time 945 t2 arr
// step-4 time 955 t3 arr
// step-5 time 1100 t4 arr
// step-6 time 1130 t3 dep
// step-7 time 1150 t4 dep
// step-8 time 1200 t2 dep
// step-9 time 1500 t5 arr
// step-10 time 1800 t6 arr
// step-11 time 1900 t5 dep
// step-12 time 2000 t6 dep

// so we make sorted time array- combination of arrival and departure array
// (900,A)(920,D)(945,A)(955,A)(1100,A)(1130,D),(1150,D)(1200,D)(1500,A)(1800,A)(1900,D)(2000,D) so run loop on this array and cnt platform each time
// if arrival - cnt++
// if departure - cnt--
// maxPlatform=max(maxPlatfor,cnt)

// but this third array takes extra space- so we sort arr[] and dep[] array separately and use two pinter approach this distinguish the train arrival and departure time but if train arrive then also departure

// if all tarins are arrive then there is no more trains going to arrive so no more platforms will be used

// Why This Works
// Sort arrival and departure times separately.
// If next train arrives before previous leaves → need extra platform.
// If a train departs → free one platform.

// t.c-O(2*(nlogn+n))
// sc.-O(1) by dissorting(change) given array by sorting them so 
// if in interview they say not dissort(change) input array so take third array put all in this and sort it and run loop on it
int minPlatformRequiredToAllTrain(vector<int> &arr, vector<int> &dep)
{
  int n = arr.size();
  // sort arrays
  sort(arr.begin(), arr.end()); // nlogn
  sort(dep.begin(), dep.end()); // nlogn

  // take two pointers and move in both array
  int i = 0, j = 0;
  int platforms = 0, maxPlatforms = 0;
  while (i < n && j < n) // O(2*n) because we sometime travel first array and sometime travel second array
  {
    if (arr[i] < dep[j])
    {
      platforms++;
      maxPlatforms = max(maxPlatforms, platforms);
      i++;
    }
    else if (arr[i] > dep[j])
    {
      platforms--;
      j++;
    }
  }
  return maxPlatforms;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  cout << "Enter arrival time: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> dep(n);
  cout << "Enter departure time: ";
  for (int i = 0; i < n; i++)
  {
    cin >> dep[i];
  }

  // int answer = minPlatformRequired(arr, dep);
  int answer = minPlatformRequiredToAllTrain(arr, dep);
  cout << answer << endl;
  return 0;
}