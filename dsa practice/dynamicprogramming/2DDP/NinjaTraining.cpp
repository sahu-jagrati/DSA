// Ninja is planning this 'N' days long training schedule. Each day, he can perform any one of these three activites(Running,Fighting Practice,Learning New moves). Each activitu has some merit points on each day. As Ninja has to improve all his akills, he can't do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size n*3 points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// Example 1:
// Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
// Output: 210
// Explanation:
// Day 1: fighting practice = 70
// Day 2: stealth training = 50
// Day 3: fighting practice = 90
// Total = 70 + 50 + 90 = 210
// This gives the optimal points.

// Example 2:
// Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]
// Output: 290
// Explanation:
// Day 1: running = 70
// Day 2: stealth training = 20
// Day 3: running = 200
// Total = 70 + 20 + 200 = 290
// This gives the optimal points

// example-[[10,50,1],[5,100,11]]

// if we think of greedy appraoch then

// day 0- max we can earn is 50
// day 1- max we can earn is 11 because we cann't do the same activity in two consecutive days so not 100, so
// total earn is 50+11=61

// but instead of using greedy we can earn more
// if day 0 we earn 10
// day we earn 100
// total - 10+100=110 which is more from greedy so can't use greedy here

// greedy fails so next comes in mind is try all possible ways- so recursion- we know for recursion we do in three steps
// 1. express problem in index
// 2. do all stuffs on that index A.T question
// 3. take max(all stuffs)

// 1. for index
// we have days so we can treat day as an index because I have to decide on a given day what I'm trying to do

// in recursion we go top-down approach i.e (n-1)->0th

// let's assume that like there are multiple days
// let n=6
// and I am at day 3 and we calculate day 4,5 A.T index 0
// so at day 3 I am also having three activites(1,2,3) like either I can perform the activity 1 or 2 or 3 but I need to know what was the last task performed like we go from (n-1) to 0th so someone has to tell what was the last activity is performed because we can't perform same activity two consecutive days

// so according to condition  we can't perform same activity two consecutive days so along with the index you can add a parameter in the recurrence because over here in order to decide what stuff I'll do on an index I need to know what I did on the previous index  so along with the day as an index we have a parameter last

// step 1. of recuurence -  f(day,last)

// we do 0-based indexing
// 0->task0 perform
// 1->task1 perform
// 2->task2 perform
// 3->no task was done,  when this case arise when you start from the last day which is (n-1) day because when you start on the last day what options do you have? you have option of performing the any task means you can perform any activity and thereby you go across all the possible paths so initially I can say that the call will be made for f(n-1,3) which states what does this reference means give me the maximum merit points that you can earn on the array starts from 0 and ends at (n-1) and  before (n-1) you perform 3 means no task performed

// f(2,1) means give me the max merit points that you can earn on the array starts from 0 and ends at index 2 and given that you performed task1 right at the third index

// now start recurrence
// f(day,last)
// we start from (n-1) and go to n-2,n-3,...,0
// so 0 is the base case

// f(day,last){
// if(day==0) means you have take the max task from the three task but you have to recognized that the it is not the same as the last one
// so we can say that
// base case
// if(day==0){
// maxi=0
// this for loop over the three  activity we have
// for(i=0->2){
// if(i!=last)maxi=max(maxi,task[0][i]) // because we find for index =0 so task[0][i]
// return maxi
//}
//}

// now for remaining days you have to just take care that previous days use that activity we can't use so
// again we take maxi=0 because we want maximum points
// maxi=0
// again loop over three activities
// for(i=0->2){
// if(i!=last){
// we add points of that day of that activity which is not last with the previous points that we calculate by recurrence
// int points=task[day][i]+f(day-1,i)  // we call recurrence for previous day and for that last = i because we give i activity to day so we can't give i activity to day-1 now
// maxi=max(maxi,points)
//}
//}
// return maxi
//}

// so whenver you start recurrence-f(n-1,3) means n-1 can take any one of three activity so here last=3 say that no activity till has done because n-1 is the last index from that we start so initially it can choose any of three activity

// take example and see overlapping subproblems

//         t0,t1,t2  task that we define above that t0 means activity 1 , t1 means activity 2, t2 means activity3
// matrix=[[2,1,3],  ->day0
//         [3,4,6],  ->day1
//         [10,1,6],  ->day2
//         [8,3,7]]   ->day3

// so we start recurrence from last day which is 3 here and for that we choose initially any activity so we pass 3 as a last means none of the activity has done till
// f(3,3) we can perform any task/activity so
// f(2,0) or f(2,1) or f(2,2)
// f(2,0) say that day3 uses activity1 (i.e task 0) so for day2 last =0 means we can't use task0 for day2
// similarly we can say for f(2,1) and f(2,2)

// here we have now three recursive call so which one we first do f(2,0) completely then we return back and come to f(2,1) and complete it and come back to f(2,2)

// so now if we are at f(2,0) so for day2 we can't do 10 points activity it can either perform t1 or t2 so
// f(1,1) or (1,2)
// we proceed with f(1,1) now
// f(1,1) say that day2 perform activity2(i.e task1) so you can't perform it so day1 now can perform either t0 or t2 so
// f(0,0) or f(0,2)
// we proceed with f(0,0) now

// f(0,0) now day==0 base case and for that we can't perform t0 , we can either perform t1 or t2 so
// f(0,0)=max(t1,t2)=max(1,3)=3
// now f(0,0) return 3

// for f(1,1) by f(0,0)
// points=matrix[1][0]+f(0,0)=3+f(0,0)=3+3=6
// maxi=max(maxi,points)=max(0,6)=6
// now we come back to f(0,2) now day==0 base case and for that we can't perform t2 , we can either perform t0 or t1 so
// f(0,2)=max(t0,t1)=max(2,1)=2
// for f(1,1) by f(0,2)
// points=matrix[1][2]+f(0,2)=6+2=8
// maxi=max(maxi,points)=max(6,8)=8

// now f(1,1) return with 8

// now we come back to f(1,2) for this we can't perform t2 , we can either perform t0 or t1 so
// f(0,0) or f(0,1)

// f(0,0) return 6
// f(0,1) day==0 base case for this we can't perform t1 , we can either perform t0 or t2 so
// f(0,1)=max(2,3)=3

// for f(1,2) by f(0,0)
// points=matrix[1][0]+f(0,0)=3+3=6
// maxi=max(maxi,points)=max(0,6)=6

// for f(1,2) by f(0,1)
// points=matrix[1][1]+f(0,1)=4+3=7
// maxi=max(maxi,points)=max(0,7)=7

// now f(1,2) return with 7

// now we come back to f(2,0)

// for f(2,0) by f(1,1)
// points=matrix[2][1]+f(1,1)=1+8=9
// maxi=max(maxi,points)=max(0,9)=9

// for f(2,0)by f(1,2)
// points=matrix[2][2]+f(1,2)= 6+7=13
// maxi=max(maxi,points)=max(9,13)=13

// now f(2,0) return with 13

// so we see there are overlapping subproblems
// similarly we can go with f(2,1) and f(2,2) in which we are also get overlapping subproblems

// so when we get overlapping subproblem we do one thing memoization

// day can have values (0,1,...,n-1) - n
// last can be (0,1,2,3) nothing more that that - 4

// so dp matrix is initialized with dp[n][4] with -1 value

// recursion solution

#include <bits/stdc++.h>
using namespace std;

int f1(int day, int lastUsed, vector<vector<int>> &points)
{
  // base case
  if (day == 0)
  {
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
      if (task != lastUsed)
      {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }
  int maxi = 0;
  // for any other day except 0
  // we againg go with three activities
  for (int task = 0; task < 3; task++)
  {
    if (task != lastUsed)
    {
      int point = points[day][task] + f1(day - 1, task, points);
      maxi = max(maxi, point);
    }
  }
  return maxi;
}

// memoization solution
// in this we go top-down approach

// t.c-O(n*4)*3 in worst case where n*4 is the size and for each elt we run for loop 3 times
// s.c=O(n)(for stack space because at max we go for n days)+O(n*4)(size space)(dp matrix)

int f2(int day, int lastUsed, vector<vector<int>> &points, vector<vector<int>> &dp)
{
  if (day == 0)
  {
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
      if (task != lastUsed)
      {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }
  if (dp[day][lastUsed] != -1)
    return dp[day][lastUsed];
  // for other days
  int maxi = 0;
  for (int task = 0; task < 3; task++)
  {
    if (task != lastUsed)
    {
      int point = points[day][task] + f2(day - 1, task, points, dp);
      maxi = max(maxi, point);
    }
  }
  return dp[day][lastUsed] = maxi;
}

// tabulation solution
// dp[n][4]
// in this we go bottom-up approach
// so first we solve for base case
// here base case is day==0
// so for day ==0 we can have last=0/1/2/3 because in tabulation we start with base case not n-1 so in day 0 we initially we have all three activity
// so we can have (0,0)/(0,1)/(0,2)/(0,3)
// so if lastUsed=0 then it is end up with taking max(task1,task2)
// if it last=1 then it is end up with taking max(task0,task2)
// if it last2= then it is end up with taking max(task0,task1)
// if it last=3 it is end up taking with max(task0,task1,task2)
// so we can say that the base case is
// dp[0][0]=max(points[0][1],points[0][2])
// dp[0][1]=max(points[0][0],points[0][2])
// dp[0][2]=max(points[0][0],points[0][1])
// dp[0][3]=max(points[0][0],points[0][1],points[0][2])

// now this is the base case done
// we convert memoization into tabulation so see code of memoization and A.T that try to convert first we done with the base case now for each day
// next we have to go for day =1,2,...., n-1
// and for each day last can be 0/1/2/3
// if last=0 then task can be 1/2
// if last=1 then task can be 0/2
// if last=2 then task can be 0/1
// if last=3 then task can be 0/1/2

// so now see in code
// t.c-O(n*4*3) because of three for loop
// s.c-O(n*4) for dp matrix
int f3(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n, vector<int>(4, -1));
  // base case- day==0 and last can be 0/1/2/3
  // here last can be 3 because we start from 0 to n-1 so initially i can take any one of three activity
  dp[0][0] = max(points[0][1], points[0][2]);                    // when last=0
  dp[0][1] = max(points[0][0], points[0][2]);                    // when last=1
  dp[0][2] = max(points[0][0], points[0][1]);                    // when last=2
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); // when last=3 means no activity has done till now

  // now for remaining days
  for (int day = 1; day < n; day++)
  {
    // last can be 0/1/2/3
    for (int last = 0; last < 4; last++)
    {
      // if last is something then task!=last
      // and task can be 0/1/2 i.e activity can be 1/2/3 A.T last so do as same as we do in memoization
      // int maxi=0; // instead of this you can directtly write
      dp[day][last] = 0;
      for (int task = 0; task < 3; task++)
      {
        if (task != last)
        {
          int point = points[day][task] + dp[day - 1][task];
          // maxi=max(maxi,point);
          dp[day][last] = max(dp[day][last], point);
        }
      }
      // dp[day][last]=maxi;
    }
  }
  // answer is the recurrence call that we made in recursion initially
  return dp[n - 1][3];
}

// space optimization
// how can be think of space optimization if we see point= points[day][task] + dp[day - 1][task]; which is the sum of previous day
// and dp[day][last] is nothing but max(dp[day][last],points[day][task]+dp[day-1][last]) and dp[day-1][last] is nothing but the previous state so here we can optimize the space

// if we think of dp matrix
// index -   0 1 2 3
// index-  0             this row is the base case for which we calculate separately
//         1             this row is what - dp[day][last]=.......+dp[day-1][last] means depend on previous row only
//         2             this row depend on its previous row i.e row 1, not depend not row 0 anymore
//         3              similarly this row is depend on row2 not on row0 or row 1
//         4             similarly here this depend on row3 not on row0/1/2

// so do we need to store an entire matrix ?
// can't we do something like thie let's start with a very small array and what we do is we store the day0 row over here in this array and then create a dummy size 4 array and try to compute them and then again store it and then use this to compute the next and then again store it then againg use this to compute the next then again store it and at the end compute the last and thereby this will be the answer

// I just store a size 4 array and don't require an matrix of n*4 because there's no need to store previous information because what I require is just the previous sky thereby I'll do a space optimization

// t.c-O(n*4*3) because of three for loop
// s.c=O(4)=constant, single prev array
int f4(int n, vector<vector<int>> &points)
{
  // we make an array of size 4
  // which is prev
  vector<int> prev(4, 0);
  // we first store the day0 in prev array as initially
  prev[0] = max(points[0][1], points[0][2]);                    // when for day0, last=0
  prev[1] = max(points[0][0], points[0][2]);                    // when last=1
  prev[2] = max(points[0][0], points[0][1]);                    // when last=2
  prev[3] = max(points[0][0], max(points[0][1], points[0][2])); // when last=3 means no activity has done till now

  for (int day = 1; day < n; day++)
  {
    // we make temp array for store it
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++)
    {
      temp[last] = 0; // instead of dp[day][last]
      for (int task = 0; task < 3; task++)
      {
        if (task != last)
        {
          temp[last] = max(temp[last], points[day][task] + prev[task]); // dp[day-1][last]=prev=last now in single array
        }
      }
    }
    prev = temp;
  }
  return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  // recursion solution
  // return f1(n - 1, 3, points);

  // memoization solution
  // vector<vector<int>> dp(n, vector<int>(4, -1));
  // return f2(n - 1, 3, points, dp);

  // tabulation solution
  // return f3(n, points);

  // space optimization solution
  return f4(n, points);
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> points(n, vector<int>(3));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> points[i][j];
    }
  }
  cout << ninjaTraining(n, points);
  return 0;
}