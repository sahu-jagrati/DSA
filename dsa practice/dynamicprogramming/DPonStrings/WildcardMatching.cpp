// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

// Problem Statement: We are given two strings 'S1' and 'S2'. String S1 can have the following two special characters.

// '?' can be matched to a single character of S2.
// '*' can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
// We need to check whether strings S1 and S2 match or not.

// Examples

// Input: S1 = "ab*cd", S2 = "abdefcd"
// Output: true
// Explanation: "ab" matches "ab", '*' matches "def", "cd" matches "cd". The strings match.

// Input: S1 = "*a*b", S2 = "aaab"
// Output: true
// Explanation: First '*' matches "aa", 'a' matches 'a', second '*' matches empty string, 'b' matches 'b'. The strings match.

#include <bits/stdc++.h>
using namespace std;

// '?' means matches with single character
// '*' means matches with sequence of length zero or more

// and these '?' and '*' are only in  string s1 with other lowercase characters, it will not be in the string s2, string s2 having only lowercase characters.

// assume we have s1="?ay" and s2="ray"
// so if we start from back of both string then 'y' matches with 'y', 'a' matches with 'a' and the '?' matches with 'r' because '?' matches with single character so we can say '?' matches with 'r' so s1 is matching with s2 so we return true.

// let be take another example
// s1="ab*cd"   s2="abdefcd"
// let's figure out s1 and s2 match or not
// so as start from back 'd' match with 'd', 'c'c match with 'c', and from front 'a' matches with 'a', 'b' matches with 'b' so here we have a '*' also which matches with the entire sequence 'def' because '*' means it matches with the sequence of length 0 or more so '*' matches with 'def' so s1 match with s2 so we return true.

// another example
// s1="**abcd"  s2="abcd"
// so 'd' matches with 'd', 'c' matches 'c', 'b' matches with 'b', 'a' matches with 'a' now these '*' we can say a single '*' is a length 0 so this is matching with a length 0 and also a second '*' is also matching with length 0 so hypothetically s1 == s2 so we return true

// so if we have '*' it can be match with length=0/1/2/3/....

// let's take other example
// s1="ab?d"  s2="abcc"
// here if we see 'a' matches with 'a', 'b' matches with 'b', '?' matches with 'c', but 'd' is not matching with 'c' so s1!=s2 so we return false

// so in question given a string s1 which will definitely which can or cannot have like it will have lowercase letters for sure it can have a question mark and it can have a star as well given a string s2 which will just have lowercase letters you need to tell me if the string s1 matches with the string s2 or not you just need to return me either are true or you just need to return me either uh false

// so how we proceed with this problem? the first thing that comes in our mind is string matching

// but where is the main problem?
// the main problem arises if it is a '*' because for '?' it is very straightforward they will match with single character but when we have a '*' the problem arises because let's tale an example assume s1="ab*cd" and s2="abdefcd" so when you are matching we'll be like 'd' matches with 'd', 'c' matches 'c' but for the '*' you exactly don't know how many will match because you know b' matches with 'b', 'a' matches with 'a' but for the '*' we have to be very critical whether we take this 'f' or whether we will take 'ef' or whether we will take 'def' or whether we will take 'bdef' or whether we will take 'abdef' or  so for '*' we can be like we will not take any one and we will start matching 'b' with 'f' or we can be like for a '*' we will take 'f' and then we will start matching with 'b; and 'e' or we can be like for the '*' we will take 'ef'and we will match 'b' with 'd' or we can be like for the '*' we will take 'def' and then we will match 'b' with 'b' and then 'a' with 'a' and comes out to be true so we without trying we cannot say that we will be taking length 3 for '*' we have to try by taking length 0 by taking 1 by taking 2 by taking 3 by taking 4  and so on so we have to try all ways like for '*' we cannot say directly for '*' so we have to try all possible ways and for that we go with recursion

// so string matching by recursion
// we know for writing recursion we have rules:
// i) we have  two strings so express in terms if (i,j)
// ii) explore all comparisons
// iii)it is asking you can or you can not so out of all comparisons if anyone can  then we return true

// i)
// f(i,j)
// we start recursion here top-down approach so f(n-1,m-1) what does this signify? assume if we have string s1="ab*cd" so n=5 and s2="abdefcd" so m=7 so f(n-1,m-1)=f(4,6) signifies that in the string s1 from 0 to 4 index and in sthe string s2 from 0 to 6 index are they matching  so it's going to return yes or no

// f(i,j){

// base case we know one thing that base case has to return true or false
// i) when string s1 is exhausted what will happen so this is basically means (i<0) means s1 has no more characters and also there can be a possibility that s2 also have no more characters so can we say when both of them get exhausted so in order to the comparison it is successful so return true
// if(i<0&&j<0)return true
// but what if s1 is only exhausted and string s2 still have some characters which means i<0 and j>=0 so there are some comparisons still left so return false
// if(i<0&&j>=0)return false

// ii) when string s2 is exhausted only and string s1 still have something what will be the case we will be like extremely straight and false no because when string s1 still has something means it might have something when can it match with empty strings2 when can a string s1 which has something match with an empty string s2 if string s1 has all '*' because '*' can only be represents by empty and if string s1 has anything other than '*' it cannot be

// so if(j<0&&i>=0){
// if s1 is left with all '*' then true or else return false
// for(k=0;k<=i;k++){if(s1[k]!='*'){return false}}
// else
// return true
//}

// ii) explore all comparisons
// what can be the cases?
// i) we are like if they are matching it is very straightforward both the string gets reduced or if there was a '?' in s1 then it is also match with the single character of s2 so in this case we also reduced both string so either both the characters match or if it is a '?' in s1 then they will also match so we can say whenever we did string matching problems what conditions we had 1.match condition 2. not match condition so for the 1. match conditions we have two conditions over here
// if(s1[i]==s2[j] || s1[i]=='?')return f(i-1,j-1) because they are matching so we shrink the  both string

// what can be the other conditions?
// we can think of if i points to '*' and j points to some char in s2 and we know '*' can be of length 0 or of length 1 or of length 2 and so on so we can match any number of characters for the '*' so one thing is for sure that we will always take the case where we will say the '*' means nothing (i.e empty ) so we will be like okay if s1[i]=='*' and let's assume it means nothing which means i will go one redused so i-1and j still be there because we said the '*' is equal to nothing because 0 length was allowed thereby we have f(i-1,j) now what can be the other thing? we need to check for a length of 1 and for length of 2 and for length of 3 and so on how will we manage that either we write a for loop where we say we will take 'f' then we will take 'ef' then we will take 'def' then we will take 'bdef' fro the '*' otherwise can we do this by recursion

// so let's assume we have "ab*" and i points '*' and we have "abdef" and j points 'f' and go to start comparing  so which automatically we meant nothing for '*' and then we compare 'b' with 'f'
//            ab*
//          abdef
//       /                           \
//    when '*' means nothing            when '*' means 'f' length=1 so
//   ab | abdef and i points 'b' and j 'f'       in that case we have:  ab* | abde and i points '*' and j points 'e'  so now again we do the same thing so we take two branch and say '*' means nothing and in other we say '*' means 'e' so
 //                            /                     \
                        when '*' nothing                when '*'means 'e' so
//           ab | abd  i points 'b' and j points 'd'                  ab* | abd  and i points '*' and j points 'd' again we do same thing for this
//                /             \ 
//      when '*' nothing         when '*' means 'd'
//    ab | abd and i points 'b' and j points 'd'                 ab* | ab and i points '*' and j points 'b' againg we do same thing so
//               /
//  we get:  ab | ab when '*' means nothing  and eventually they will match so we will be like okay it will go 'b' matches with 'b' and i go to 'a' and j go to 'a' so
//     |
//    a | a and eventually they will also meatch so we will be like empty so we tried out all patterns see for '*' we take length 0, length 1 , length 2 , length 3
// how did we do it let's analyze every step when we start we said we have two cases i) for '*' means nothing so we move i and j still at same so f(i-1,j) ii) and in other we say let's take 'f' for '*' in that case i still at the '*' and j reduce by 1 so we get f(i,j-1) so these are the two functions that we are doing
//   if(s1[i]=='*') return f(i-1,j) || f(i,j-1)

// now what if this string s1 did not match or it is not a star like assume we have s1="abc" and i points 'b' and s2="aec" and j points 'e' so 'b' did not match with 'e' and this is also neither a '*' nor a '?' so this is not matching so at the end s1 !=s2 so we return false

// when they did not match and it is not a '*' so
// return false
//}

// t.c for recursion: exponential because for '*' we go with length 0,1,2 and so on
// s.c for recursion: O(n+m)(auxiliary stack space) where n is size of s1 and m is size of s2

// now there can be overlapping subproblems also so we use memoization
// and there are i and j are changing parameters and i maximum value is n-1 and j maximum value is m-1 so dp[n][m]
// t.c for memoization: O(n*m)
// s.c for memoization: O(n*m)(for dp) + O(n+m)(for auxiliary stack space)

// recursion top-down approach where i go from n-1 to 0 and j go from m-1 to 0
int f1(int i, int j, string &s1, string &s2)
{
  // base case
  // i) when both the strings are exhausted(finish)
  if (i < 0 && j < 0)
    return true;
  // ii) when string s1 is only exhausted
  if (i < 0 && j >= 0)
    return false;
  // iii) when string s2 is only exhausted
  if (j < 0 && i >= 0)
  {
    // if in s1 all are '*' then true because '*' match with empty string else false
    for (int k = 0; k <= i; k++)
    {
      if (s1[k] != '*')
        return false;
    }
    return true;
  }

  // when char match or s1[i]=='?'
  if (s1[i] == s2[j] || s1[i] == '?')
    return f1(i - 1, j - 1, s1, s2);

  // when s1[i]=='*' we can take length 0 , length 1,length 2 and so on
  if (s1[i] == '*')
    return f1(i - 1, j, s1, s2) || f1(i, j - 1, s1, s2);

  // when char not match and s1[i]!='*'
  return false;
}

// memoization
int f2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{

  // base case
  // i) when both the strings are exhausted(finish)
  if (i < 0 && j < 0)
    return true;
  // ii) when string s1 is only exhausted
  if (i < 0 && j >= 0)
    return false;
  // iii) when string s2 is only exhausted
  if (j < 0 && i >= 0)
  {
    // if in s1 all are '*' then true because '*' match with empty string else false
    for (int k = 0; k <= i; k++)
    {
      if (s1[k] != '*')
        return false;
    }
    return true;
  }

  if (dp[i][j] != -1)
    return dp[i][j];
  // when char match or s1[i]=='?'
  if (s1[i] == s2[j] || s1[i] == '?')
    return dp[i][j] = f2(i - 1, j - 1, s1, s2, dp);

  // when s1[i]=='*' we can take length 0 , length 1,length 2 and so on
  if (s1[i] == '*')
    return dp[i][j] = f2(i - 1, j, s1, s2, dp) || f2(i, j - 1, s1, s2, dp);

  // when char not match and s1[i]!='*'
  return dp[i][j] = false;
}

// tabulation
// i) write base case
// ii) write changing parameters in opposite fashion of recursion
// iii) copy the recurrence

// base case
// in recursion we have i<0 and j<0 means negative index but tabulation does not goes into negative so we convert this into 1-based indexing so i<0 becomes i==0 and j<0 becomes j==0 because we =do 1-based indexing and for j>=0 it become j>0 and for i>=0 it become i>0 and dp become dp[n+1][m+1]

// now base case
// in recursion
// i) base case is if(i<0&&j<0)return true
// so in tabulation it become
// if(i==0&&j==0)dp[0][0]=true; // you can directly write this without if
// ii) base case in recursion is if(i<0&&j>=0)return false
// so in tabulation when i==0, j can be anything but from 1 to m because we already done with i==0 and j==0
// for(int j=1;j<=m;j++)dp[0][j]=false
// iii) base case in recursion if(j<0&&i>=0)then check in s1 all are '*'
// so in tabulation
// when j==0 we have check for all i from 1 to n because for j==0 and i==0 we already done so i from 1 to n we have to check it is '*' or not
// for(int i=1;i<=n;i++){
// bool flag=true;
// we go from 1 to i for k because we do 1-based indexing
// for(int k=1;k<=i;k++){
// if(s1[k-1]!='*'){
// flag=false;
// break;
//}
//}
// dp[i][0]=flag;
//}

// as in recursion we do top-down approach where i go from n-1 to 0 and j go from m-1 to 0
// so in tabulation we do bottom-up approach where i go from 1 to n and j go from 1 to m

// t.c for tabulation-O(n*m)
// s.c-O(n*m) for dp
int f3(int n, int m, string s1, string s2)
{
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

  // base case
  // i) when i==0 and j==0 means both strings are exhausted
  dp[0][0] = true;
  // ii) when i==0 means string s1 is exhausted but s2 still has some character
  for (int j = 1; j <= m; j++)
  {
    dp[0][j] = false;
  }
  // iii) when j==0 means string s2 is exhausted but s1 still has some character so we have to check is s1[i] '*' or not
  for (int i = 1; i <= n; i++)
  {
    bool flag = true;
    for (int k = 1; k <= i; k++)
    {
      if (s1[k - 1] != '*')
      {
        flag = false;
        break;
      }
    }
    // for every row we are assigning the 0th column value
    dp[i][0] = flag;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // when char match or s1[i]=='?'
      if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      // when s1[i]=='*' we can take length 0 , length 1,length 2 and so on
      else if (s1[i - 1] == '*')
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

      // when char not match and s1[i]!='*'
      else
        dp[i][j] = false;
    }
  }
  return dp[n][m];
}

// space optimization
// t.c -O(n*m)
// s.c-O(2*m) for prev,curr array
int f4(int n, int m, string s1, string s2)
{
  vector<bool> prev(m + 1, false), curr(m + 1, false);
  // base case
  // i) when i==0 and j==0 means both strings are exhausted
  prev[0] = true; // because when i==0 means it is prev row
  // ii) when i==0 means string s1 is exhausted but s2 still has some character and i==0 means prev row so
  for (int j = 1; j <= m; j++)
    prev[j] = false;
  // iii) when j==0 means string s2 is exhausted but s1 still has some character so i can be anything  so we have to check for s1[i] is '*' or not and this we do for every row we are assigning the 0th column value for every row so can we say every time we go across to i and curr is the current row so for that curr[0] has to be assigned every time so every time when you are at curr we have to take car of curr[0] so iii) base case we write in our main for loop so whenever curr is update we have to take care of curr[0] for every row
  for (int i = 1; i <= n; i++)
  {
    // iii) base case whenever there is new row we assign the 0th column value by checking s1[i] is '*' or not
    bool flag = true;
    for (int k = 1; k <= i; k++)
    {
      if (s1[k - 1] != '*')
      {
        flag = false;
        break;
      }
    }
    curr[0] = flag; // for 0th column we assign value for every row
    for (int j = 1; j <= m; j++)
    {
      // when char match or s1[i]=='?'
      if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
        curr[j] = prev[j - 1];

      // when s1[i]=='*' we can take length 0 , length 1,length 2 and so on
      else if (s1[i - 1] == '*')
        curr[j] = prev[j] || curr[j - 1];

      // when char not match and s1[i]!='*'
      else
        curr[j] = false;
    }
    prev = curr;
  }
  return prev[m];
}

bool wildcardMatching(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  // recursion
  // return f1(n - 1, m - 1, s1, s2);

  // // memoization
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // return f2(n - 1, m - 1, s1, s2, dp);

  // tabulation
  // return f3(n, m, s1, s2);

  // space optimization
  return f4(n, m, s1, s2);
}

// here s1 contains only lowercase English letters, '?' or '*'.
// and s2 contains only lowercase English letters.
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << wildcardMatching(s1, s2);
  return 0;
}