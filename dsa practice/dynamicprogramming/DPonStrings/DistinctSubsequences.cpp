// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

// Problem Statement : Given two strings s and t, return the number of distinct subsequences of s that equal t.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.

// The task is to count how many different ways we can form t from s by deleting some (or no) characters from s.

// Examples
// Input: s = "axbxax", t = "axa"
// Output: 2
// Explanation: In the string "axbxax", there are two distinct subsequences "axa":
// (a)(x)bx(a)x
// (a)xb(x)(a)x
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation: In the string "babgbag", there are five distinct subsequences "bag":
// (ba)(b)(ga)(g)
// (ba)(bg)(ag)
// (bab)(ga)(g)
// (bab)(g)(ag)
// (babg)(a)(g)

// how do we solve this problem? Obivously we have to apply something like recursion now why do we apply recursion and why not simple matching because what I can say is if I have a s1="babgbag" and s2="bag"  how do I approach this problem my generic point of view will be  let take a "bag" and let's try to compare with s1 so b of s1 compared with b of s2 , a of s1 compared with a of s2 next g gets compared over here that will be one but you could have said I will not compare this 'g' and I'll compare another 'g' then there will be another way also similarly you can say I'll not compare this 'b' with this b instead of that I'll compare this 'b' and this 'b' so you're saying that you have to follow different methodologies of comparing  like there can be multiple ways of comparing if I ask you different methods of comparing so it's kind of trying always what comes to our brain obviously it's recursion because that's the only way only way when we say that okay we're going to try this way this way this way and we take all the answers that that is what recursion is you basically try all the ways and sum up all the ways so what is the question stating it states count the number of ways.

//  Whenever there is something like count and we what do you think? let's write down the pattern it's generically a function which is the recursive function: f(){
// base case tends to retrun 1 or 0 because you're counting the ways and you call all the functions and you add up them and you return that is what you do whenever the problem is Count ways remember this whenever the problem is Count ways you write a function you know the base case has to return 1 or 0 and then you try out this is one of the possible ways this is one of the possible ways and if there are otherways you try out and you add up all the states and you return
//}

// how to write the recurrence now
// i) express everything in terms of indexes (i,j)
// now there are two strings so we use two parameters: one parameter is i for s1 and one parametere is j for s2
// ii) expore all possibilities
// iii) return sum of all possibilities

// i)
// as f(i,j) and here recursion go with top-down approach so if n is the length of s1 and m is the length of s2 then we are starting recursion with f(n-1,m-1).

// and f(n-1,m-1) means number of distinct subsequences of string s2[0...j] in string s1[0...i]

// f(i,j){
// base case as in this problem we have to count ways so in base case we return 1 or 0

// i) like in s1, pointer i comes to < 0 means in negative index it is reached and in s2 j is at 0 index of it, if we say i at 0 index in s1 then we could have matched s1[0]=b with s2[0]=b but if i=-1 i.e negative index and still we have some portion of the s2 to get so we can say that we can't match now because string s1 now finish so we return 0

// ii) base case is when i is somewhere in s1 >0 but all characters of s2 are done that is now j is at negative index means we finish string s2 i.e we matched all the characters of s2 so we return 1

// if(j<0)return 1; // when s2 finish
// if(i<0)return 0; // when s1 finish and still s2 portion remains

// explore all possibilities
// there can be two possibilites: i) if character of s1 match with character of s2 ii) if they don't match
// but when characters match they are also divide in two case: i) we take that character of s1 so we move both i and j ii) we don't take that character of s1 so only i move j still at the same char in s2 because we want all ways so there can be like same character can exist in future also so we can skip current character and take it in future so

// like in our above example we mention  I'm saying okay this is the 'g' this is the 'g' where this is the 'a' this is the 'a' where this is the 'b' this is the 'b' so I'll get one occurrence but what I could have also done is I could have said okay I'll not take this 'g' I'll take another 'g' then I'll take this 'a' then I'll take this 'b' perfect that's one more occurrence or what I could have said let's take another occurence of 'g' or 'a' or 'b'

// i) possibilities
// so when the characters are match also divide in two case: i) take  ii)not take and we want count all the ways so we add both ways
// if(s1[i]==s2[j]){
// f(i-1,j-1)(i.e when we take that then both move )+f(i-1,j(i.e when we don't take so only i in s1 move j in s2 still at the same char and we search in future) so
// return f(i-1,j-1)+f(i-1,j)
//}
// ii) possibilities
// when char not match so move i in s1 only j still at the same char because we want whole s2 in s1
// else  return f(i-1,j)
//  these are two different states so can I say I will either return i) guy as the answer if they're matching or I'll either return ii) guy
//}

// t.c of recursion : exponential
// assuming you're doing all type of comparisons there can be a lot of comparisons somewhere near about 2^n will be the number of subsequences of string s1 because those are the number of subsequences that you can generate if the string is of length n and 2^m of the string s2  so there will be matchings on them so it'll go exponential : ((2^n)*(2^m))

// s.c for recursion-O(n+m) auxiliary stack space

// there can be overlapping subproblems so we do memoization so we declare dp so what are the changing parameters: i and j and i is upto n-1 and j is m-1 so dp[n][m] we declare
// so we simply do that
// t.c for memoization: O(n*m)
// s.c-O(n*m)(for dp)+O(n+m)(for auxiliary stack space

#include <bits/stdc++.h>
using namespace std;

// recursion top-down approach used here
int f1(int i, int j, string &s, string &t)
{
  // base case when s2 finish means we match all char of s2 in s1
  if (j < 0)
    return 1;
  // base case when s1 finish but still we have some portion of s2
  if (i < 0)
    return 0;

  // when char match there is two case: take it and both move and nottake only i move and we want to count all ways so we add them number of ways we get from both
  if (s[i] == t[j])
    return f1(i - 1, j - 1, s, t) + f1(i - 1, j, s, t);
  // when not match char  then move i only in s1 j still at same
  return f1(i - 1, j, s, t);
}

// memoization
int f2(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
  // base case
  if (j < 0)
    return 1;
  if (i < 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  // when char match there is two case take it and both move and nottake only i move  and we want to count all ways so we add them number of ways we get from both
  if (s[i] == t[j])
    return dp[i][j] = f2(i - 1, j - 1, s, t, dp) + f2(i - 1, j, s, t, dp);
  // when not match char  then move i only in s1 j still at same
  return dp[i][j] = f2(i - 1, j, s, t, dp);
}

// tabulation
// i) write down the base case
// ii changing paramter in opposite fashion of recursion
// iii) copy the recurrence

// here also there can be a negatvive index and in dp we can't store negatove index so as we remember in LCS(longest common subsequence) problem we do one index right shift
// in recurrnec we writing something as j<0 and i<0 so what we are doing basically is we are as of now dealing with 0 based indexing so there will be cases whener a call for f(-1,0) or f(0,-1) will go which means the string  is exhausted so we are moving to negative index in that case so in order to deal with it we shift index one step right so we declare dp[n+1][m+1] and we know one thing for sure this i<0 and j<0 will not be lesser than instead of this it will be i==0 and j==0 but one thing we know for sure if you're dealing with i=n then in string s1 it means n-1 and if j=m then in s2 it means m-1

// now base case is
// i) when j==0 means string s2 finish there is nothing left so we can say that i can be anything in that case so
// for(i=0;i<=n;i++)dp[i][0]=1; means s2 done
// ii) when i==0 means s1 finish but there can be like j can be anything means there can be some portion of s2 left means j can be anything and also we done with j==0 so we go with j=1 to m
// for(int j=1;i<=m;j++)dp[0][j]=0; // still s2 remain but s1 finish

// next changing parameters
// as in recursion we go top-down approach for i we go from n-1 to 0 and for j we go from m-1 to 0
// so now in tabulation we go bottom-up approach so as we do one index right shift so for i we go from 1 to n and for j we go from 1 to m and we already done with i==0 and j==0 as base case
// for(int i=1;i<=n;i++){
// for(int j=1;j<=m;j++){// copy the recurrence}
//}

// there can be integer overflow so we use double datattype dp table
// t.c-O(n*m)
// s.c-O(n*m) for dp
int f3(int n, int m, string s, string t)
{
  vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
  // base case
  // when j==0
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1; // when s2 finish
  // when j==0 as aboev we already done with j=0 so we start from j=1
  for (int j = 1; j <= m; j++)
    dp[0][j] = 0; // when s1 finish ans s2 still remain

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // when char match there is two case take it and both move and nottake only i move  and we want to count all ways so we add them number of ways we get from both
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
      // when not match char  then move i only in s1 j still at same
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return (int)dp[n][m];
}

// space optimization- we convert 2D dp matrix into two 1D array
// t.c-O(n*m)
// s.c-O(2*m) for prev,curr
int f4(int n, int m, string s, string t)
{
  vector<double> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  // here only one when j=0 because we go with prev row and curr row, not with every row together
  prev[0] = curr[0] = 1; // and all are 0 as initial values
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // when char match there is two case take it and both move and nottake only i move  and we want to count all ways so we add them number of ways we get from both
      if (s[i - 1] == t[j - 1])
      {
        curr[j] = prev[j - 1] + prev[j];
      }
      // when not match char  then move i only in s1 j still at same
      else
        curr[j] = prev[j];
    }
    prev = curr;
  }
  return (int)prev[m];
}

// space optimzation from two 1D array(prev,curr) to single 1D array(prev)
// t.c-O(n*m)
// s.c-O(m) for single 1D array prev
// as we see above code: curr[j]=prev[j-1]+prev[j] means we are using only previous row to get curr[j] means there is no required to compute entire curr because basically for current column we need previous row j and j-1 column so the first thing that I'll say is okay that means I can just do a slight shuttle change so if we say if we run j from m to 1 it is still fine so if we run j from back(i.e from m to 1) then we first use the prev value for that column and then change it because after that we don't want it because for j column we want only prev[j] and prev[j-1] and for j-1 column we want prev[j-1] and prev[j-2] so if we start j from m to 1 we first use value and then update it
int f5(int n, int m, string s, string t)
{
  vector<double> prev(m + 1, 0);
  // base case
  prev[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    // we travel back for j so first we use prev value then we update it with new value
    for (int j = m; j >= 1; j--)
    {
      // when char match there is two case take it and both move and nottake only i move  and we want to count all ways so we add them number of ways we get from both
      if (s[i - 1] == t[j - 1])
      {
        prev[j] = prev[j - 1] + prev[j];
      }
      // not necessary to write else condition because it remain same
      // when not match char  then move i only in s1 j still at same
      else
      {
        prev[j] = prev[j];
      }
    }
  }
  return (int)prev[m];
}
int countDistinctSubsequ(string s, string t)
{
  int n = s.size();
  int m = t.size();

  // recursion
  // return f1(n - 1, m - 1, s, t);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // return f2(n - 1, m - 1, s, t, dp);

  // tabulation
  // return f3(n, m, s, t);

  // space optimization we convert 2D dp matrix into two 1D array
  // return f4(n, m, s, t);

  // space optimization from two 1D array(prev,curr) to single 1D array(prev)
  return f5(n, m, s, t);
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << countDistinctSubsequ(s, t);
  return 0;
}