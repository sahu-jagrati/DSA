// Problem Statement: Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1..

// Example 1:
// Input: heights = [2, 1, 3, 5, 4]
// Output: 2
// Explanation: One possible route can be,
// 0th step -> 2nd Step = abs(2 - 3) = 1
// 2nd step -> 4th step = abs(3 - 4) = 1
// Total = 1 + 1 = 2.

// Example 2:
// Input: heights = [7, 5, 1, 2, 6]
// Output: 9
// Explanation: One possible route can be,
// 0th step -> 1st Step = abs(7 - 5) = 2
// 1st step -> 3rd step = abs(5 - 2) = 3
// 3rd step -> 4th step = abs(2 - 6) = 4
// Total = 2 + 3 + 4 = 9.

// Example 3:
// Input: heights=[10,20,30,10]
// way to reach from 0th to 3rd stair
// i) 10->20 then 20->30 then 30->10, energy=40
// ii) 10->20 then 20->10, energy=20
// iii) 10->30 then 30->10, energy=40
// we want minimum energy so it is 20 here because we can jump either one step or two step at a time

// so we have to try all possible stuff

// why a greedy solution does not works here?
// greedy here means we take min of (going 1 step from that stair,going 2 step from that stair)

// example- heights=[30,10,60,10,60,50]
// from 30 we can go 10 or 60 but min(30-10,60-30)=20
// now we reach at 10 from 10 we can go 60 or 10, so min is = 0
// now we reach 10 from 10 we can go 60 or 50, so min is =40
// energy=20+0+40=60

// now instead of greedy we try another way
// from 30 we go 2 step to 60 so
// from 60 we also go 2 step to 60
// from 60 we go to 50
// energy=30+0+10=40 which is minimum from greedy approach

// so we realise that the greedy way did not give you the correct path because you started greedily but you lost out probably somewhere
// so it's better to try all possible ways

// sometimes it will happen that initially you took the better way but you lost out on something significant like this 60 to 60 would have been zero you lost out in future so in such cases greedy doesn't works and you have to try recursion

// A.T our short trick
// i) express our problem in index so we do it - [0,1,2,....,n-1]
// ii) do all stuffs on that index
// iii) take the min(all stuffs)

// f(n-1)-min energu required to reach (n-1) from 0

// we talk in terms of index here means from going 0th index to 0th index like
// what will be the costing in order to reach from zero to zero that's going to be zero
// f(0)=(0th step->0th step)=0

// f(index){
// if(index==0) return 0
// }
// do all stuff on that index
// from any index frog can jump either one step or 2 step

// left=f(index-1) + abs(arr[index]-arr[index-1])

// if i'm jumping yes the question arises if i'm jumping from an index to an index minus 1 what is the energy that is being consumed i know in order to jump from index to index minus 1 the energy consumed is array of index minus array of index minus 1 that is what the energy is consumed

// right=f(index-2)+abs(arr[index]-arr[index-2])

// but i need to be slightly careful can i do an index minus two always
// the answer to that is yes you can do it if it is not the first index because if you are standing at the
// first index you cannot jump two because that will take you to minus 1 you cannot jump to
// so you need to write a case like this if index is greater than 1
// then only i can take the right jump otherwise i cannot like make sense because if you add the first index you'll not be able to take
// the right job

// if(index>1){
// right=f(index-2)+abs(arr[index]-arr[index-2])
// }

// take the min(all stuffs)

// return min(left,right);

// that's how you can write the recurrence as i told you follow three techniques you'll be able to write any recurrence relationships yes now you have written the recurrence relationship that is absolutely perfect so we have understood the recurrence relationship now it's time to see if there are overlapping sub problems and how is this recursion actually working right

// take example- heights=[30,10,60,10,60,50], n=6 so we have to go from 0th to 5th index
// f(5) from there we can go
// f(4) or f(3)
// and calculate both by above recursion code

// understood right so do you observe overlapping sub problems
// that is i'm able to do it by the way f of 1 will go to f of 0 as well i'm able to do it
// so if i mark the overlapping sub problems there is one f(3)
// first one another one f(3) so i have figured out
// if if f of 3 answer if f of 3 is answer i'm figuring out then f of 3 is answer
// why will i again figure out so there are overlapping sub problems so if there are overlapping sub problems can i say
// the answer to those sub problems will be similar thereby i can apply memoization to this particular recursion
// got it so i am understanding that okay i can definitely apply memoration so
// you can easily apply memorization but i just in a case to complete the recursion real quickly draw it so in order to
// reach zero i'll take zero amount correct

// so for f(1)
// left=f(0)+20=20 here
// but there is no right for that- right=let INT_MAX
// so f(1)=min(left,right)=(20,INT_MAX)=20
// particular recursion nice now we are at f of 2 so f of 2
// 15:22
// would have called the left recursion as f of one plus a jump from two to one
// 15:28
// plus a jump from two to one which will cost him fifty so that costed him fifty and there'll be a
// 15:34
// right jump which will be directly to f of zero now there will be a jump from two to 0
// 15:39
// which will cost him 30. so there will be a 30. now you remember f of 1 this had a value of 20 so it will return
// 15:47
// with a 20. so this guy gave him 20. so 20 plus 50 will give him
// 15:52
// 70 f of 0 will be how much 0 so 0 plus 30 gives him 30 which one will
// 15:59
// f of 2 give the minimum so it will return 30
// 16:04
// so f 2 got 30 perfect so again make sense because if i logically explain you let
// 16:12
// me raise this if i logically give you an explanation well this makes sense yes this will make
// 16:18
// sense because if i'm standing at f of 2 yes if i'm standing at f of 2
// 16:24
// there there are a couple of ways one is this one is this which will cost him 20 plus 50 which is 70 or the other
// 16:30
// one is this which is 30. so 30 is what you have got right now
// 16:35
// again similarly f of three when you're at f of three understand
// 16:41
// there is a left call of f of two plus the absolute difference which is from
// 16:46
// three to two so if you're going from three to two it's 50. so you can just take a plus 50.
// 16:52
// so what is f of 2 it has returned you as 30 correct
// 16:58
// what's the right jump the right jump is about f 1 plus what
// 17:04
// now will you f of one so from one to three will be
// 17:10
// zero one two three will be zero so plus zero now will you go and do the recursion
// 17:15
// call of f of one will you go and do again f of zero f of one is already computed you see
// 17:21
// it's just overlapping sub problem you can directly take the value from the dp array as
// 17:26
// 20 this gives you 20 this gives you 80. which one will you take 20 obviously
// 17:31
// so f of 3 becomes 20 perfect
// 17:38
// so remember i'm storing the values of f of 3 f of 2 f of 1 in probably some dp array
// 17:43
// as you have seen in my lecture one next you're at f of 4 so if i'm at f of 4 what is that doing it's again calling
// 17:51
// f of 3 plus absolute of 3 to 4 will be 50. so uh 50
// 17:58
// and it's calling f of 2 plus 4 to 2 will be 0 so i can do 0
// 18:05
// what's f of 3 if i write what's f of 3 20 what's f 2 30 so 20 plus
// 18:12
// 50 70 this is 30 which only 30 again
// 18:17
// an overlapping sub problem ignored you did not f 2 will not go deep into recursion because the moment you call f
// 18:24
// of 2 it will directly get the value 30 and return 30. so you got the minimum as 30 so f of 4 becomes 30. perfect
// 18:33
// next step is this particular step f of 3 so when i'm at f of 5 what's happening
// 18:40
// i'm saying okay i can definitely go to ff4 plus absolute of uh jumping from
// 18:46
// four to five which is ten so let's take ten similarly if i am jumping from five to
// 18:51
// three if i'm jumping from five to three can i say it's uh
// 18:57
// 40 yes so plus 40 of f of 3 now carefully observe f of 4 is already
// 19:04
// 30 f of 3 is already 20 30 plus 10 gives you 40 20 plus 40 gives you 60 which one
// 19:11
// will you take 40 or 16 definitely 40. so this value is 40.
// 19:17
// thereby this recursion is also solved so did you observe something there were multiple sub problems that i
// 19:24
// ended up solving repeatedly overlapping sub problems as i said so this is how generally uh
// 19:31
// recursion tends to work it goes on goes on because if a problem has been solved if you have already like if you already
// 19:37
// know what's the what's the summation from 0 to 3 why do you want to recompute it again just
// 19:42
// reuse it that's what i've done and i've got the answer as 40 which was indeed the answer
// 19:47
// this is how the recursion tree works and how you get the minimal possible way uh
// 19:53
// generally uh if you draw this recursion tree by yourself you'll understand much more but in in general uh

// the next question how do you convert a recurrence into a
// dp so that's when you see memoization okay so trick to apply memoration look at the parameters changing

// recurrence->Dp
// there is only one parameter changing which is the index parameter  let's come back it's index what is the maximum value of index A.T. our question n-1

// so we create dp[n] array initialized to -1 - step1

// step -2 Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already calculated using the dp array. If yes, simply return the value from the dp array.
// if(dp[index]!=-1)return dp[index]

// step-3 Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already calculated using the dp array. If yes, simply return the value from the dp array.

#include <bits/stdc++.h>
using namespace std;

// recurive solution
int f(int ind, vector<int> &heights)
{
  if (ind == 0)
    return 0;

  int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if (ind > 1)
    right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

  return min(left, right);
}

// memoization- top-down approach means we fo from main problem to base case
int f1(int ind, vector<int> &heights, vector<int> &dp)
{
  if (ind == 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int left = f1(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if (ind > 1)
    right = f1(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

  return dp[ind] = min(left, right);
}

// tabulation-bottom-up approach means we go from base case to main problem

int f3(int n, vector<int> &heights)
{
  vector<int> dp(n, 0);
  dp[0] = 0; // because from 0th step we cann't go down any step now it's last step
  for (int i = 1; i < n; i++)
  {
    int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;
    if (i > 1)
      right = dp[i - 2] + abs(heights[i] - heights[i - 2]);

    dp[i] = min(left, right);
  }
  return dp[n - 1];
}

// space optimization solution
// i did tell you one thing anytime there is something like (index-1) and (index-2) there can always be an space optimization take this as a thumb rule there will always be a space optimization if there is something like index minus 1 and index minus 2 always

int f4(int n, vector<int> &heights)
{
  int prev = 0;
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int left = prev + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;
    if (i > 1)
      right = prev2 + abs(heights[i] - heights[i - 2]);

    int curr = min(left, right);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

int frogJump(int n, vector<int> &heights)
{
  // recursive solution
  // return f(n - 1, heights);

  //  memoization solution
  // vector<int> dp(n, -1);
  // return f1(n - 1, heights, dp);

  // tabulation solution
  // return f3(n, heights);

  // space optimization solution
  return f4(n, heights);
}

int main()
{
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> heights[i];
  }
  cout << frogJump(n, heights);
  return 0;
}