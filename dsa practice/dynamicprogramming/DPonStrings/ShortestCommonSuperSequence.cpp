// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation:
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"

// Constraints:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.

//  We are given two strings ‘S1’ and ‘S2’. We need to return their shortest common supersequence. A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.

// Examples
// Input : str1 = "mno", str2 = "nop"
// Output :"mnop"
// Explanation : The shortest common supersequence is "mnop". It contains "mno" as the first three characters and "nop" as the last three characters, thus including both strings as subsequences.

// Input :str1 = "dynamic", str2 = "program"
// Output : "dynprogramic"
// Explanation :The shortest common supersequence is "dynprogramic". It includes all characters from both "dynamic" and "program", with minimal overlap. For example, "dynamic" appears as "dyn...amic" and "program" appears as "...program..." within "dynprogramic".

// let's take an example
// s1="brute" and s2="groot"
// for this if we say supersequence can be this by combined s1 and s2 : "brutegroot" so  here brute is also and groot is also there so this can be called as a supersequence, common supersequence means both of s1 and s2 are in supersequence so this can be called as a common supersequence but question say we want shortest common supersequence so can I get something smaller than this ("brutegroot") for this example because it's basically we are just taking s1 and s2 and then combined them and saying that this is the supersequence so can We get something which is smaller than this.

// let's see like probably I can have something like "bgruoote" if I take a string like this does it have s1 and s2 both let's check out remember the order has to be same, so s1=brute is there and s2=groot is also there so I can say in this string "bgruoote" we have both s1 and s2 and the length of the string = 8 and the string="brutegroot" that we have combiniing s1 and s2 have length=10 and in question it ask shortest so string "bgruoote" is indeed the shortest you can try out all other supersequences but you'll find that the shortest common supersequence is for this is "bgruoote "

// so now question is how did you actually get the shortest one for let's take another example : s1="bleed" and s2="blue"
// ideally "bleedblue" will be a supersequence but we ask you which is the shortest supersequence then it will be "bleued" this will be the shortest supersequence of length=6

// so let's first analyze how do we figure out the length of shortest common subsequence once we have analyzed how to figure out the length then we will see how do we print the shortest common supersequence

// so our example is
// s1="brute" and s2="groot"
// we use tow pointer i and j,  i traverse s1 and j traverse s2
// so logically like if I pointer i at 'b' in s1 and j at 'g' in s2 and what we can say is we know one thing the string has to have a root so if I need a 'b' why don't we take 'b' in supersequence and ans='b' and after that we move i to 'r' and if we need 'g' why can't we take a 'g' so we take 'g' also ans='bg' and move j also to 'r' but over here when i standing at 'r' and j also standing at 'r' then can I say actually take a single 'r' because that single 'r' will also suffice(i.e enough) for "brute" and that single 'r' will also suffice for "groot" can I say that? I can so we'll be like okay we'll take a single'r' in our answer so ans='bgr' and move both i and j, i to 'u' and j to 'o' now take 'u' in ans and also take 'o' in ans and move i and j to next so ans='bgruo' now i will move to 't' and I know on a very high level this 't' can match with the 'groot' 't' so what we'll do is we'll copy paste both the 'oo' in ans so ans='bgruoo' and j move to 't' now i and j both stands at 't' so we'll write one 't' for it then ans='bgruoot' now i move to 'e' and j finish the s2 so we simply add 'e'to ans so ans="bgruoote" so overall we get this particular string and if we carefully see is that what we discuss above so this  is our answer , there can be multiple answers

// but what was the intutions while we are doing this since in above example there is a 'r' that is common in both of them and also 't' is common in both of them so why shall we take 'r' twice or 't' twice,  we 'll just be using 'r' once and 't' once that's suffice(i.e enough) for both s1 and s2

// so we can say that common guys taken once
// what does common guys in two string means? It is longest common subsequence that we already done

// If we keep the “shortest” criteria aside, what can be a way to generate a supersequence given two strings. One easy way is to concat the given strings (write one after the other), this will always give us a supersequence for any pair of given strings.

// This can be said as the worst case with time complexity of O(n+m), where n and are the lengths of strings S1 and S2 respectively. How can we improve from this naive approach?
// If we think a little, there are some common characters that we can avoid writing for both the strings separately. These common characters can’t be all the common characters. They are the characters that are common and come in the same order. In other words, they are the characters of the longest common subsequence.

// In an optimum solution, the characters of the longest common subsequence are written only once and other characters are placed around them. For every character that belongs to the longest common subsequence, the non-lcs characters coming before them in the strings S1 and S2 are placed before the lcs-character in the answer string.

// Length of Shortest Common Supersequence?
// From the explanation above, we can see that characters of lcs need to be covered only once. Therefore, the length of the shortest Common supersequence = n + m -k, where (n and m are lengths of S1 and S2, and k is the length of the lcs string).

// Finding the supersequence string
// Now, instead of the length, we are interested in finding the shortest supersequence string itself. Readers are highly advised to read the article Print Longest Common Subsequence.
// When we form the DP table to calculate the longest common subsequence (as done in Print Longest Common Subsequence) we have all the information of characters that are coming in the lcs string and characters that don’t. We use this same DP table to form the shortest common supersequence.
// To frame the string, we need to understand how the dp table was formed and work in the reverse process.Now, let us see what were the conditions that we used while forming the dp array:
// if(S1[i-1] == S2[j-1]), then return 1 + dp[i-1][j-1]
// if(S1[i-1] != S2[j-1]) , then return 0 + max(dp[i-1][j],dp[i][j-1])

// We will start from the right-most cell of the dp array, initially i=n and j=m. To form the string, we will work in a reverse manner.

// if(S1[i-1] == S2[j-1]), this means the character is an lcs character and needs to be included only once from both the strings, so we add it to the ans string and reduce both i and j by 1. We reduce them simultaneously to make sure the character is counted only once.

// if(S1[i-1] != S2[j-1]), this means that the character is a non-lcs character and then we move the pointer to the top cell or left cell depending on which is greater. This way non-lcs characters will be included separately in the right order.

// We start from cell dp[n][m]. Initially i=n and j=m.

// At every cell, we will check if S1[i-1] == S2[j-1], if it is then it means this character is a part of the longest common subsequence. So we will push it to the ans string str. Then we will move to the diagonally top-left   cell by assigning i to i-1 and j to j-1.

// Else, this character is not a part of the longest common subsequence so we include it in ans string.Originally this cell got its value from its left cell (←) or from its top cell (↑). Whichever cell’s value will be more of the two, we will move to that cell.

// We will continue till i>0 and j>0, failing it we will break from the loop.

// After breaking, either i>0 or j>0 (only one condition will fail to break from the while loop), if(i>0) we push all the characters from S1 to ans string, else if(j>0), we push all the remaining characters from S2.

// At last, we reverse the ‘ans’ string and we get our answer.

#include <bits/stdc++.h>
using namespace std;

// as we want entire dp matrix after fill for printing the string so we use tabulation code of longest common subsequence

// Function to return the shortest common supersequence of two strings

// t.c-O(n*m)(for tabulation)+O(n+m)(for print we traverse each character of both the strings)
// s.c-O(n*m) for dp
string shortestSuperSequence(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  // tabulation code of lcs(longest common subsequence )
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  // base case
  // when j==0
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  // when i==0
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  // Fill the DP table using bottom-up approach
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // when characters are match
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      // if not match then
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // for print supersequence
  // Start from bottom-right of the DP table to build the supersequence
  int i = n;
  int j = m;
  string ans = ""; // here we don't know the length of ans

  while (i > 0 && j > 0)
  {
    // If characters are equal, include it once
    if (s1[i - 1] == s2[j - 1])
    {
      ans += s1[i - 1];
      i--;
      j--;
    }
    // when not match Move in the direction of greater value
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      // so when we move to greater value then we have to include the character that we left for not match from string for which we move the pointer
      ans += s1[i - 1]; // beacuse here dp[i-1][j]>dp[i][j-1] so we move i pointer from s1 so we add not match character of s1 because i move only, j still at the same character
      i--;
    }
    else
    {
      ans += s2[j - 1]; // beacuse here dp[i][j-1]>dp[i-1][j] so we move j pointer from s2 so we add not match character of s2 because j move only, i still at the same character
      j--;
    }
  }
  // If any characters are left in s1, add them
  while (i > 0)
  {
    ans += s1[i - 1];
    i--;
  }
  // If any characters are left in s2, add them
  while (j > 0)
  {
    ans += s2[j - 1];
    j--;
  }
  // Since we added characters in reverse order, reverse the result because we start from the bottom-right of the dp table
  reverse(ans.begin(), ans.end());

  // Return the final shortest supersequence
  return ans;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << shortestSuperSequence(s1, s2);
  return 0;
}