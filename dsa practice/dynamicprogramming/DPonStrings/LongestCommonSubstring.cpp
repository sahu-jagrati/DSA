// Problem Statement: Given two strings str1 and str2, find the length of their longest common substring.

// A substring is a contiguous sequence of characters within a string.

// Examples
// Example 1:
// Input:
//  str1 = "abcde", str2 = "abfce"
// Output:
//  2
// Explanation:
//  The longest common substring is "ab", which has a length of 2.

// Example 2:
// Input:
//  str1 = "abcdxyz", str2 = "xyzabcd"
// Output:
//  4
// Explanation:
//  The longest common substring is "abcd", which has a length of 4.

// as we already do a problem longest common susequence where we find the length of longest common subsequence and here we have to find the length of longest common substring so the difference is only of subsequence and substring.

// the difference between subsequence is:
// A subsequence of a string is a list of characters of the string where zero or more characters are deleted and they should be in the same order in the subsequence as in the original string.

// while
// // A substring is a contiguous sequence of characters within a string.

// so in longest common subsequence we do
// when match: dp[i][j]=1+dp[i-1][j-1]
// when not match: dp[i][j]=max(dp[i-1][j],dp[i][j-1]) this line works in longest common subsequence because you are allowed to have not consecutive characters you can omit some charatcers

// but here  not match line does not works because here you need to be  consecutive in nature so you cannot use the line not match here

// so how we solve this problem
// can we write recursion? we can but then we have to use one more third variable thereby there will be three states which is probably we don't recommend thereby what we will do is? we will try to write the tabulation format but in order to write the tabulation format you have to actually learn how the longest common subsequence tabulation works.

// let's take example-
// s1=abcd, s2=abzd
// so longest common subsequence is abd
// and longest common substring is ab

// as usual we will be following one based indexing so dp[n+1][m+1] where n=s1.size and m=s2.size

// so our dp matrix is dp[5][5] where n=4 and m=4

// dp matrix write here i for s1 and j for s2 string iterators
// indexing : j->for s2  a   b   z   d
//     i here row     0   1   2   3   4
//                0   0   0   0   0   0
//           a    1   0   1   0   0   0
//           b    2   0   0   2   0   0
//           c    3   0   0   0   0   0
//           d    4   0   0   0   0   1

// so how do you usually fill up the above dp ? you usually fill up on the column wise.
// as by base case when i==0 or j==0 return 0 so fill in dp
// now we fill 1st row
// when i=1 then dp[1][1]=1 because a and a match
// and dp[1][2]=0 because a!=b
// dp[1][3]=0 because a!=z
// dp[1][4]=0 because a!=d

// now 2nd row
// when i=2 then  for dp[2][1] we have a and b here so does this b match with this a no ideally since this is consecutive you are not dependent on the previous guys so if they do not match I don't want any interruptions to be carried forward else in longest common subsequence we would have taken the maximum of dp[i-1][j] and dp[i][j-1] because in this we can omit some characters but in substring we don't carry anything because we don't have a substring thereby it is 0 so dp[2][1]=0
// next dp[2][2] here we have b and b and they match like okay they are matching let's see in the previous guy  dp[i-1][j-1] did the match  which is here dp[1][1] they match a and a and dp[1][1] there's =1 so if they matched and they had a length of 1 why can't I take that 1? 1 for himself and 1 for previous guy so I will be like okay dp[2][2]=2 so whenver they are matching I can actually take the previous guy because I don't need any break and there is no breaking, I can directly go to the previous guy if we see the strings

// next dp[2][3] here we have b and z not match so 0
// next dp[2][4] here we have b and d not match so 0

// next we come to i=3
// so dp[3][1] we have c and a not match so 0
// next dp[3][2] we have c and b not match so 0
// next dp[3][3] we have c and z not match so 0
// next dp[3][4] we have c and d not match so 0

// next we come to i=4
// so dp[4][1] we have d and a not match so 0
// next dp[4][2] we have d and b not match so 0
// next dp[4][3] we have d and z not match so 0
// next dp[4][4] we have d and d  match so 1 why 1? because d and d matching so you went to the previous guy dp[3][3] and here we have c and z and they did not match so they had a zero value thereby there's no one from the previous consecutive so you only had a 1 for dp[4][4]

// let if we have c and c at dp[3][3] what would have happened ? so this c and c matched so we go to the previous and see they have a two match so you take 2 and for c and c  2+1=3 here so dp[3][3]=3 then again when you come over d and d they match then you see previous guy and they have three consecutive match so dp[4][4]=3+1=4
// so What I analyzed was since it is for consecutive (i.e substring) thereby this guy can be said we do not need to do any breakings thereby we can directly put a zero when they don't match so this is the slight change we to do in the previous code longest common subsequence

// so coming back in our example we have s1=abcd and s2=abzd what is the longest common substring can I say the maximum value in the entire dp matrix is 2 because this 2 signifies 'ab' of s1 is equivalent to 'ab' of s2 so that is the answer

// so here in this problem all are same to longest common subsequence only here when they don't match we directly put 0 instead of taking max of left and up guy

#include <bits/stdc++.h>
using namespace std;

// can we write recursion? we can but then we have to use one more third variable thereby there will be three states which is probably we don't recommend thereby what we will do is? we will try to write the tabulation format
// we do tabulation
// t.c-O(n*m)
// s.c-O(n*m) for dp
int f1(int n, int m, string text1, string text2)
{
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // 1 based indexing in tabulation we do here
  // base case
  // when i==0
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  // when j==0
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;

  // for not traversing againg dp to get max od entire matrix we together calculate it also so
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // when match
      if (text1[i - 1] == text2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      }
      // when they don't match directly put zero
      // this is the minor change we did from longest common subsequence code
      else
        dp[i][j] = 0;
    }
  }
  return ans;
}

// space optimization
// t.c-O(n*m)
// s.c-O(m)
int f2(int n, int m, string text1, string text2)
{
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  // we have single row only so we write when i==0
  for (int j = 0; j <= m; j++)
    prev[j] = 0; // and also there is no need to write base case because we already start with 0

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (text1[i - 1] == text2[j - 1])
      {
        curr[j] = 1 + prev[j - 1];
        ans = max(ans, curr[j]);
      }
      else
        curr[j] = 0;
    }
    prev = curr;
  }
  return ans;
}

int longestCommonSubstring(string text1, string text2)
{
  int n = text1.size();
  int m = text2.size();

  // tabulation
  //  return f1(n,m,text1,text2);

  // space optimization
  return f2(n, m, text1, text2);
}

int main()
{
  string text1, text2;
  cin >> text1 >> text2;
  cout << longestCommonSubstring(text1, text2);
  return 0;
}