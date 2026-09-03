// we have single room
// in that we can perform one meeting at a single time
// we have n meetings with their start and end time
// initially the room is empty.
// so you can start with any meeting

// example-
// start[]= [0,3,1,5,5,8]
// end[]=   [5,4,2,9,7,9]

// if we start with meeting(0,5) having start time=0 and end time 5 after this i cannot perform(3,4),(1,2),(5,9),(5,7) because upto 5 room is fill with meeting (0,5) we can perform only (8,9) after that so total meeting we done=2

// if we start with(1,2) meeting then after this we can do meeting(3,4) also but after that (0,5) we cannot do because it's done in(0,5) but at that time room is full so cannot do after this we can do (5,7) and then (8,9) we can do (5,9) cannot do
// so total meetings done=4

// question say ypu can follow any order of your choice
// and the task is to maximize the number of meeting that we can perform using one single meeting room

// so we will try to take the meetings that are ebding faster.

// faster meetings -> ending time
// so I will be greedy that we take meetings that end fast.

// so in above example- m3 ends fast after that m2 ends fast m1 cannot do then m5 ends fast, m4 cannot do, then m6 ends fast

// 1) first we sort the meetings according to their finish time in ascending order

// and we store meetings like (start time,end time,position)
// we use position if we have to return order of meeting in which they are finish then position is used

// // initially the room is empty. so we are sure that first meeting is performed obviously so
// we use two variables cnt and free time that store end time of meeting that has performed
// and we take data structure to store position of meetings that has performed

// for next meeting to be performned start time>free time, not equal to or less than, then meeting can perform and then free time=end time of that meeting

#include <bits/stdc++.h>
using namespace std;

struct meeting
{
  int startTime;
  int endTime;
  int position;
};

bool compare(meeting m1, meeting m2)
{
  return m1.endTime < m2.endTime; // sort in ascending order
}

// t.c-O(nlogn)(sorting) + O(n)(traversing loop)
// s.c-O(position array size)

int numberOfmeetingDone(vector<meeting> &meetings)
{
  int n = meetings.size();
  // nlogn
  sort(meetings.begin(), meetings.end(), compare); // on the basis of end time in ascending order
  int cnt = 1, freetime = meetings[0].endTime;     // because first meeting is performed obviously
  vector<int> positionArray;                       // for order of meetings that are done
  positionArray.push_back(meetings[0].position);

  // traverse meetings array
  // i=0 already done initially
  // run n times
  for (int i = 1; i < n; i++)
  {
    if (meetings[i].startTime > freetime)
    {
      cnt = cnt + 1;
      freetime = meetings[i].endTime;
      positionArray.push_back(meetings[i].position);
    }
  }
  return cnt; // if want order of meetings that has done then return position array
}

int main()
{
  int n;
  cout << "enter the size of array: ";
  cin >> n;

  vector<meeting> meetings(n);
  for (int i = 0; i < n; i++)
  {
    cout << "Enter starttime, endtime, position for job " << i + 1 << ": ";
    cin >> meetings[i].startTime >> meetings[i].endTime >> meetings[i].position; // for position enter i+1
  }

  int answer = numberOfmeetingDone(meetings);
  cout << "Number of meetings we can perform are: " << answer << endl;
  return 0;
}