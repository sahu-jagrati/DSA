// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

// Problem Statement:

// We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:

// Deletion of a character.
// Replacement of a character with another one.
// Insertion of a character.
// We have to return the minimum number of operations required to convert S1 to S2 as our answer.

// Examples
// Example 1:
// Input: start = "planet", target = "plan"
// Output: 2
// Explanation:
// To transform "planet" into "plan", the following operations are required:
// 1. Delete the character 'e': "planet" -> "plan"
// 2. Delete the character 't': "plan" -> "plan"
// Thus, a total of 2 operations are needed.

// Example 2:
// Input: start = "abcdefg", target = "azced"
// Output: 4
// Explanation:
// To transform "abcdefg" into "azced", the following operations are required:
// 1. Replace 'b' with 'z': "abcdefg" -> "azcdefg"
// 2. Delete 'd': "azcdefg" -> "azcefg"
// 3. Delete 'f': "azcefg" -> "azceg"
// 4. Replace 'g' with 'd': "azceg" -> "azced"
// Thus, a total of 4 operations are needed.

// as we already done a problem where we insert or delete a character to convert string s1 to s2 and returm minimum steps for that, now here we have one more extra operation which is we can replace one character with another one.

// so before finding out the minimum number of operations let's understand Is it always possible to convert s1 to s2 by using given three operations? the answer to that is definitely it is possible. How? We delete all characters of string s1 perform the number of deletions and then s1 become empty then used insert operation and insert all characters of s2 in s1 like we have s1="horse" and s2="ros" so first we delete all char of s1 and s1 become empty and then we use insert and insert "ros" in s1 and convert s1 to s2 so delete all and insert the string s2 so possible maximum number of operations are (n+m) where n is size of s1 and m is size of s2.

// so Maximum number of operations required to convert s1 to s2 using given three operations are (n+m) where n is size of s1 and m is size of s2.

// let's find the minimal one

// so in our example : s1="horse" and s2="ros"
// so What we do is we will go across s1 and say okay the first operation that we will do is we will replace h-> r which makes s1 = "rorse"
// so next operation will be we will say let's remove  second 'r' which makes s1="rose"
// next operation we will say is remove 'e' which makes s1="ros" and this is nothing but the string s2 so we get s2 so how many operations did we need? we need 3 operations. We can try out all other ways and we'll not find any different combinations where we can get lesser number of  operations for above example, so 3 minimum operations required to convert s1 to s2. Did we use insert here? no, we were done with replace and two delete operations and we were able to convert s1 into s2 in above example.

// let's take one more example: s1="intention" s2="execution"
// so first thing that we will do is let's  remove first 't' which makes s1="inention"
// next we say replace first 'i' with 'e' which makes s1="enention"
// next we say replace  first 'n' with 'x' which makes s1="exention"
// next we say replace 'n' with 'c' which makes s1="exection"
// next we say insert 'u' between 'c' and 't' which makes s1="execution" and we get string s2 so thereby we required 5 minimum operations to convert s1 to s2

// so How do we solve this problem?
// we can say we can go across the string matching part we know that's recursion which is string matching path where we recursively try to match everything.

// let's take example: s1="horse" s2="ros"
// so what we try to do is Represent the problem using two indices i and j, pointing to the current character in S1 and S2 respectively.
// so if we start from back of the both strings so we get 'e' from s1 and 's' from s2 so they are not matching so if they're not matching theno how can we match this 's' with 'e' one thing that we can think is we will delete 'e' and say we don't require 'e' so if we delete 'e' then we will try to match "hors" with "ros" so now pointer i move j still at 's' in s2, now i point 's' in s1 and these are match then we'll be like fine if this 's' matches with this 's' we are done with 's' of s2 now i point 'r' and j point 'o' and they are not matching so we can be like what can we do? we will be like let's delete 'r' in s1 so now i point 'o' in s1 which match with 'o' in s2 so we got the second match next i point 'h' and j point 'r' so okay we need to make this 'h' as an 'r' so let's replace 'h' with 'r' so that it gets much so this is matched.

// so we are getting an intuition that we have to do a kind of string matching where we take one character from s1 and another character from s2 string and then try to compare them if they are matching it's well and if they are not matching then we have lot of options. So if they are not matching what options do we have? we know the operation that we can do is we can say we will do an insert of the same character or We can say we'll delete and try to match it on the back or we will try to replace and match similar

// so we have three options when characters are not match:
// i) insert of the same character
// ii) delete and try finding somewhere else
// iii) replace and match

// so we know we have to try all possible ways because we can either insert or we can either delete or we can either replace and match we can do a lot of stuffs so if we're trying to do all possible stuffs we know among all these ways we need to figur out what is the best and that takes me to the place where we say  try all ways and whenever it comes us to try all ways we know we do recursion

// we know how we write the recursion
// i) express in terms of index
// ii) explore all possibilities
// iii) return min(of all ways )
// iv) base case

// i) we have two strings so we express in terms of (i,j) where i traverse s1 and j traverse s2
// ii) explore all paths of matching
// iii) return min(all paths)
// iv) base case

// so let's write recurrence
// we start recurrence here is top-down approach where pointer i is from n-1 to 0 and pointer j is from m-1 to 0.
// we start with f(n-1,m-1) so  what does this signify? this signifies find the minimum number of operations to convert string s1 which is from 0 to i  to string s2 which is from 0 to j
// f(i,j){

// base case : when it's over what does that signify? we were comparing someone got exhausted
// i) if string s1 gets exhausted(i.e finish) suppose if pointer i is at index -1 means s1 string finish and pointer j in tring s2 is somewhere like index 2 so there is a portion of string s2 still left and we have exhaustesd string s1 i.e s1 finish so how many opeartions will we required to make remaining portion of s2 in s1 is equal to the number of remaining characters of s2 let we have f(-1,1) that means minimum operations to convert empty string s1 because -1 means we don't have any string so convert an empty string to a string from 0 to 1 so what are the minimum operations we will take to convert an empty string s1 to string s2 from 0 to 1 obivously we will require 2 insert opeartions because s1 is empty so we have only insert operation to make s1 to s2 and we are at index=1 and we have zero based indexing so we require 2 insert operations for s2[0] and s2[1] so means it is equal to remaining characters of s2 which is (j+1)
// if(i<0)return (j+1) // remaining character of s2 to insert in s1 empty string
// ii) if string s2 gets exhausted like suppose string s2 get exhausted menas j=-1 and in string s1 pointer i is at somewhere like we say i is at index=2 so f(2,-1) what does this signify? this means minimum number of operations to convert string s1 from 0 to 2 to an empty string s2 so how many operations required? we requried number of remaining characters of string s1 because we have to delete them so here we require 3 delete operations because we are ta index=2 and we have zero based indexing so 3 delete operations required which is remaining char of string s1 so we return (i+1)
// if(j<0)return (i+1)

// so now what cases are there? we know whenever we are doing string matching there are always two possible set of cases: i) match ii) if they do not match so

// if the character of s1 match with character of s2 then do we need to do anything else do we need to perform an operation to try to match them? no we have no operation to do so if they are matching we shrink the both string and if they are matching Is we actually applying any number of steps? No we are not appling so we add 0 in number of steps. If S1[i] == S2[j], no operation is needed. Move both pointers one step back: 0 + f(i - 1, j - 1).
// if(s1[i]==s2[j]){
// return 0+f(i-1,j-1);
//}
// if they don't match what can we do? there are three options that we can do:  i) insert ii) delete iii) replace
// If S1[i] != S2[j], we explore all three operations:
// Insert: Insert S2[j] into S1. This keeps i unchanged and decreases j because now after insertion they match so j decrease and i remains unchanged becuase it can match in future: and we do an insert operation so we add 1 in number of steps so :  1 + f(i, j - 1).
// Delete: Remove S1[i]. This decreases i and keeps j unchanged because you still looking for that char and we do an delete operation so we add 1 in number of steps so : 1 + f(i - 1, j).
// Replace: Replace S1[i] with S2[j]. Decrease both indices because after replacing they are match so we move both pointer and we do a replace operation so we add 1 in number of steps so : 1 + f(i - 1, j - 1).
// so these are the three operations when they are not matching so after that  return the minimum value of all of these three  operations
//}

// t.c for recursion is exponential because we are trying all possible ways there are three states(insert,delete,replace)so it'll go up to ((3^n)*(3^m))
// s.c for recursion: O(n+m) auxiliary stack space where n is size of string s1 and m is size of string s2

// so there can be overlapping subproblems so we use memoization
// there are i and j are changing parameters and i maximum go n-1 and j maximum go m-1
// so we declare a dp[n][m]
// t.c for memoization-O(n*m)
// s.c-O(n*m)(for dp)+O(n+m)(for auxiliary stack space)

#include <bits/stdc++.h>
using namespace std;

// recursion
int f1(int i, int j, string &s1, string &s2)
{
  // base case
  // i) when string s1 is exhausted
  if (i < 0)
    return (j + 1);
  // ii) when string s2 is exhausted
  if (j < 0)
    return (i + 1);

  // when they match, no operations done and both pointer move so
  if (s1[i] == s2[j])
    return 0 + f1(i - 1, j - 1, s1, s2);
  // when they don't match we have three options:insert,delete,replace and return min of all and we do operations so add 1
  return 1 + min(f1(i, j - 1, s1, s2), min(f1(i - 1, j, s1, s2), f1(i - 1, j - 1, s1, s2)));
}

// memoization
int f2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
  // base case
  // i) when string s1 is exhausted
  if (i < 0)
    return (j + 1);
  // ii) when string s2 is exhausted
  if (j < 0)
    return (i + 1);

  if (dp[i][j] != -1)
    return dp[i][j];
  // when they match, no operations done and both pointer move so
  if (s1[i] == s2[j])
    return dp[i][j] = 0 + f2(i - 1, j - 1, s1, s2, dp);
  // when they don't match we have three options:insert,delete,replace and return min of all and we do operations so add 1
  return dp[i][j] = 1 + min(f2(i, j - 1, s1, s2, dp), min(f2(i - 1, j, s1, s2, dp), f2(i - 1, j - 1, s1, s2, dp)));
}

// tabulation
// rules are
// i) write base case
// ii) write changing parameters in opposite fashion of recursion solution
// iii) copy recurrence

// in recursion we have base case : if(i<0) return (j+1) and if(j<0) return (i+1) means i and j can be a negative and we don't usually want negative so what we do? we shift index one step right so in that case we declare dp[n+1][m+1] and in base case we have if(i==0) return j(now because now we step index one by right) and if(j==0) return i but both strings still we have zero based indexing

// base cases in tabulation:
// i) if(i==0) means string s1 is exhausted we return j so for i==0, j can be anything from 0 to m
// for(int j=0;j<=m;j++)dp[0][j]=j;
// ii) when if(j==0) means string s2 is exhausted we return i so for j==0, i can be anything from 0 to n
// for(int i=0;i<=n;i++)dp[i][0]=i

// as in recursion we go top-down approach where pointer i is from n-1 to 0 and pointer j is from m-1 to 0.
// so in tabulation we go bottom-up approach where i go from 1 to n and j go from 1 to m and for i==0 and j==0 we already done

int f3(int n, int m, string s1, string s2)
{
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  // base case
  // i) when i==0, j can be anything
  for (int j = 0; j <= m; j++)
    dp[0][j] = j;
  // ii) when j==0, i can be anything
  for (int i = 0; i <= n; i++)
    dp[i][0] = i;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // when they match, no operations done and both pointer move so
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 0 + dp[i - 1][j - 1];
      // when they don't match we have three options:insert,delete,replace and return min of all and we do operations so add 1
      else
      {
        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
      }
    }
  }
  return dp[n][m];
}

// space optimization- we convert 2D dp matrix into two 1D array
// t.c-O(n*m)
// s.c-O(2*m) for prev,curr
int f4(int n, int m, string s1, string s2)
{
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  // here only one when i==0 because we go with prev row because prev row here is nothing but the 0th row
  for (int j = 0; j <= m; j++)
    prev[j] = j;

  for (int i = 1; i <= n; i++)
  {
    // as when j==0 we have to update curr every time = i i.e return i because as in base case when j==0 i can be anything from 0 to n so here also when we update our curr row so for evry row j==0 we have to update curr[0] with i also
    curr[0] = i; // so at any current row the first guy will be i
    for (int j = 1; j <= m; j++)
    {
      // when they match, no operations done and both pointer move so
      if (s1[i - 1] == s2[j - 1])
        curr[j] = 0 + prev[j - 1];
      // when they don't match we have three options:insert,delete,replace and return min of all and we do operations so add 1
      else
      {
        curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
      }
    }
    prev = curr;
  }
  return prev[m];
}

// can we optimize space optimization solution(of two 1D array) to single 1D array? the answer is no because we are dependent on the previous state of the current  as well as previous state of the previous so we need to store both the rows the previous and the current  so we cannot space optimize to single 1D array
int editDistance(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  // recursion- top down approach
  // return f1(n - 1, m - 1, s1, s2);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // return f2(n - 1, m - 1, s1, s2, dp);

  // tabulation
  // return f3(n, m, s1, s2);

  // space optimization
  return f4(n, m, s1, s2);
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << editDistance(s1, s2);
  return 0;
}