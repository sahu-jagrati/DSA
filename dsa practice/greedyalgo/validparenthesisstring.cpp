#include <bits/stdc++.h>
using namespace std;

// if we have asterick in string then we have to try all possible combinations after replacing asterick with ')' or '(' or ' '(i.e empty space)
// we do this by recursion approach

// t.c-
// Case analysis

// If character is '(' or ')' → 1 recursive call
// If character is '*' → 3 recursive calls
// In the worst case, the string contains only '*'.
// So each level of recursion creates 3 branches.
// Recursion depth = n
// Total calls:
// t.c=O(3^n)
// This is exponential time complexity.

// Space Complexity
// Space comes from the recursion stack.
// Maximum recursion depth = n
// Each call stores:
// parameters (index, cnt)
// function stack frame
// So stack depth:-O(n)
bool recursiveApproach(string &s, int index, int cnt)
{
  if (index == s.size())
    return cnt == 0; // means if cnt==0 valid else return false
  if (cnt < 0)
    return false;
  if (s[index] == '(')
    return recursiveApproach(s, index + 1, cnt + 1);
  if (s[index] == ')')
    return recursiveApproach(s, index + 1, cnt - 1);

  // when s[i]=='*' i.e asterick it replace in three ways- ')' or '(' or ' '(i.e empty space)
  return (recursiveApproach(s, index + 1, cnt + 1) || recursiveApproach(s, index + 1, cnt - 1) || recursiveApproach(s, index + 1, cnt));
}
bool validParenthesis(string s)
{
  int cnt = 0;
  return recursiveApproach(s, 0, cnt);
}

// optimize solution-
// if we simply have string with no asterick then we have simple cnt approach that is if we have '(' bracket then cnt+1 or if we have ')' bracket cnt-1
// but we have asterick which has three possible ways so instead of carrying cnt variable we take range
// if in range min=0 then it is a valid string and if min !=0 then it is not a valid string
// for range we have two variable min and max initially bith are 0
// if there is '(' bracket then min=min+1 and max=max+1
// if there is  ')' bracket in that case if min =0 then we don't go to -1, we only decrease max=max-1 or if min!=0 then both are decrease by -1
// in case of asterick in both min and max we take three possible ways
// like min=0 so we can have {-1,0,+1} but -1 not consider so min range is [0,1] and max=0 then it can have{-1,0,+1} but -1 not consider so max range is[0,1] in that case min =0 and max=1
// if min and max are other than 0 then simply take three ways of asterick and take range min = min of range and max = max of range

// for more details see notes

// t.c-O(n)
// s.c-O(1)
// we derived this solution from basic approach recursion we check all possible range here and then we go to this approach range so in interview first describe recursive approach then this
bool checkValidParenthesis(string s)
{
  int min = 0, max = 0;
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
    {
      min = min + 1;
      max = max + 1;
    }
    else if (s[i] == ')')
    {
      min = min - 1;
      max = max - 1;
    }

    // this is the case when asterick is in that case we take range of min and max value so we directly do min=min-1 and max=max+1 instead of checking all three posiible ways for both min and max, for checking all ways see in notes=

    else
    {
      min = min - 1;
      max = max + 1;
    }
    if (min < 0)
      min = 0;
    if (max < 0)
      return false; // this is the case when s=))) in this we already start with min=-1 and max=-1 so range=[-..,-..] in range max should never be negative if max is negative then s is invalid parenthesis
  }
  return (min == 0); // range is from 0 to something that the left side is at zero so it is possible we can have combination which will end up to zero thereby it is valid string. if range is from 1 to 4 means we can achieve everything but we cannot achieve zero because the left is not at zero so this is a invalid string
}
int main()
{
  string s;
  cin >> s; // having only (,), or *

  // cout << validParenthesis(s) << endl;
  cout << checkValidParenthesis(s) << endl;
  return 0;
}