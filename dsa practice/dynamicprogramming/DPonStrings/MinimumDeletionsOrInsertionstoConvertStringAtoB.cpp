// Problem Statement: We are given two strings, str1 and str2. We are allowed the following operations:
// 1. Delete any number of characters from string str1.
// 2. Insert any number of characters in string str1.
// Return the minimum number of operations required to convert str1 to str2

// In one step, you can delete or insert exactly one character in  string str1.

// Examples
// Input:  str1 = "kitten", str2 = "sitting"
// Output: 5
// Explanation: To transform "kitten" to "sitting", delete "k" and insert "s" to get "sitten", then delete 'e' and insert "i" to get "sittin", and insert "g" at the end to get "sitting".
// Input : str1 = "flaw", str2 = "lawn"
// Output: 2
// Explanation : To transform "flaw" to "lawn", delete "f" and insert "n" at the end. Hence minimum number of operations required is 2".

// Constraints:

// 1 <= str1.length, str2.length <= 500
// str1 and str2 consist of only lowercase English letters.

// We need to find the minimum operations required to convert string str1 to str2. Let us keep the 'minimum' criteria aside and think, what maximum operations will be required for this conversion?

// The easiest way is to remove all the characters of str1 and then insert all the characters of str2. In this way, we will convert str1 to str2 with total of ‘n+m’ operations (where n and m are the length of strings str1 and str2 respectively).

// for maximum operations
// let str1="abcd" and str2="anc"
// if we frist delete all characters of str1 then there are 4 operations and then insert all characters of str2 to str1 then there are 3 operations so Number of operations required=4+3=7 which is the sum of length of both the strings.

// To minimize the operations, we will first try to refrain from deleting those characters which are already present in str2. More extensively, we refrain from deleting those characters which are common and come in the same order. To minimize the operations, we would like to keep the maximum common characters coming in the same order intact. These maximum characters are the characters of the longest common subsequence.

// Keep all the characters of longest common subsequence in str1 and delete all the other characters.

// str1="abcd" and str2="anc"
// and longest common subsequence ="ac"
// so we keep  longest common subsequence="ac" intact(i.e as it is) and delete all other characters from str1
// so if we delete all other characters then there are 2 opeartions because we delete 'b' and 'd'
// Next, we will insert all the remaining characters of str2 to str1.
// insert the remaining characters in str1 which is 'n' here so now str1 become "anc" and this is 1 operations
// Minimum operations required=2+1=3

// In order to minimize the operations, we need to find the length of the longest common subsequence.
// let length=length of the longest common subsequence.
// number of deletions operation=(n-length)
// number of insertions operations =(m-length)
// where n is size of str1 and m is size of str2
// so minimum operations required=(n-length)+(m-length)=(n+m-2*length)

#include <bits/stdc++.h>
using namespace std;

// so we just copy the space optimization code of longest common subsequence for recursion,meoization,tabualtion see in it file
// t.c-O(n*m)
// s.c-O(m) for prev,curr
int longestCommonSubsequence(int n, int m, string str1, string str2)
{
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  for (int j = 0; j <= m; j++)
    prev[j] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        curr[j] = 1 + prev[j - 1];
      }
      else
      {
        curr[j] = max(prev[j], curr[j - 1]);
      }
    }
    prev = curr;
  }
  return prev[m];
}

// so minimum operations required=(n-length)+(m-length)=(n+m-2*length)
int minimumInsertionOrDeletion(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  int length = longestCommonSubsequence(n, m, str1, str2);
  int deletions = n - length;
  int insertions = m - length;
  return (deletions + insertions);
}

int main()
{
  string str1, str2;
  cin >> str1 >> str2;
  cout << minimumInsertionOrDeletion(str1, str2);
  return 0;
}