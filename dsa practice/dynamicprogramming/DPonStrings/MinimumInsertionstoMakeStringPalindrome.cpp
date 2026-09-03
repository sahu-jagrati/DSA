// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

// we solve this problem using two previous problem which is i) longest common subsequence ii) longest palindromic subsequence

// now take an example:
// s=abcaa does this is a palindrome? no, it's not a palindrome

// now how can we make it palindromic string how many insertions do we need to make it palindrome
// What we will do like let's write string and then just write reverse of it like this : abcaaaacba now this is a palindrome if we just add the reversed portion of the given string to it then it is bound to be palindrome so we know the number of operations required over here is the length of the string which is the maximum operations that required to make given string as palindrome.

// We need to find the minimum insertions required to make a string palindrome. Let us keep the 'minimum' criteria aside and think, how can we make any given string palindrome by inserting characters?

// The easiest way is to add the reverse of the string at the back of the original string as shown below. This will make any string palindrome.

// str="abcaa"
// abcaaaacba  -> now it's a palindromic string by inserting reverse of the string at the end of the original string to make it palindrome

// Here the number of characters inserted will be equal to n (length of the string). This is the maximum number of characters we can insert to make strings palindrome. To minimize the insertions, we will first try to refrain from adding those characters again which are already making the given string palindrome. For the given example, “aaa”, “aba”,”aca”, any of these are themselves palindromic components of the string. We can take any of them( as all are of equal length) and keep them intact.

// if str="abcaa" then we keep "aaa" intact as it is itself palindromic and this is the longest palindromic subsequence and of same length there are more for this like "aba" or "aca" for now we keep intact "aaa" Now, there are two characters(‘b’ and ‘c’) remaining which prevent the string from being a palindrome. We can reverse their order and add them to the string to make the entire string palindrome. so we adding reverse of the remaining characters to the string for here remaining characters are 'b' and 'c' if we keep "aaa" so In order to minimize the insertions, we need to find the length of the longest palindromic component or in other words, the longest palindromic subsequence.
// Minimum Insertion required = n(length of the string) - length of longest palindromic subsequence.

// as we just need the number of operations not the string after insertion

#include <bits/stdc++.h>
using namespace std;

// here we just copy the space optimization code of longest palindromic subsequence for recursion/memoization/tabulation see file of longest palindromic subsequence

// and we know for finding longest palindromic subsequence we do this by longest common subsequence

// space optimization code of longest common subsequence

// t.c-O(n*m)
// s.c-O(m) we make row of size m
//   // since s2 is the reverse of s so having same size so m=n
int f4(int n, int m, string s1, string s2)
{
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  // we have single row only so we write when i==0
  for (int j = 0; j <= m; j++)
    prev[j] = 0; // if you don't want then  also there is no need to write base case because we already start with 0
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        curr[j] = 1 + prev[j - 1];
      else
        curr[j] = max(prev[j], curr[j - 1]);
    }
    prev = curr;
  }
  return prev[m];
}

// so in this problem we just pass second string as reverse of given string and all are same of longest common subsequence

int longestPalindromicSubseq(string s)
{
  int n = s.size();
  string t = s;
  reverse(t.begin(), t.end());

  return f4(n, n, s, t);
}

// Minimum Insertion required = n(length of the string) - length of longest palindromic subsequence.
int minInsertions(string s)
{
  int n = s.size();
  return (n - longestPalindromicSubseq(s));
}

int main()
{
  string s;
  cin >> s;
  cout << minInsertions(s);
  return 0;
}

//  the length of the string which is the maximum operations that required to make given string as palindrome by adding reverse of the original string to original string.