// You are given a binary string s and a positive integer k.

// A substring of s is beautiful if the number of 1's in it is exactly k.

// Let len be the length of the shortest beautiful substring.

// Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a beautiful substring, return an empty string.

// A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.

// For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.

// Example 1:

// Input: s = "100011001", k = 3
// Output: "11001"
// Explanation: There are 7 beautiful substrings in this example:
// 1. The substring "100011001".
// 2. The substring "100011001".
// 3. The substring "100011001".
// 4. The substring "100011001".
// 5. The substring "100011001".
// 6. The substring "100011001".
// 7. The substring "100011001".
// The length of the shortest beautiful substring is 5.
// The lexicographically smallest beautiful substring with length 5 is the substring "11001".
// Example 2:

// Input: s = "1011", k = 2
// Output: "11"
// Explanation: There are 3 beautiful substrings in this example:
// 1. The substring "1011".
// 2. The substring "1011".
// 3. The substring "1011".
// The length of the shortest beautiful substring is 2.
// The lexicographically smallest beautiful substring with length 2 is the substring "11".
// Example 3:

// Input: s = "000", k = 1
// Output: ""
// Explanation: There are no beautiful substrings in this example.

// Constraints:

// 1 <= s.length <= 100
// 1 <= k <= s.length

#include <bits/stdc++.h>
using namespace std;

// here we want a substring : substring is a contiguous part of string, it can be a string itself

// Lexicographically:

// Suppose we have two strings s1 and s2

// i) if length of the string s1 < length of the string s2 then we can directly say s1 is lexicographically smallest string than s2. example: s1="ab" and s2="abc" here s1.size()=2 and s2.size()=3 so s1.size<s2.size so we can directly say s1 is lexicographically smallest string than s2

// if length of the string s1 == length of the string s2 then string s1 is lexicographically larger than string s2 if in the first position where s1 and s2 differ, s1 has a character strictly larger than the corresponding character in s2. So , in that case s2 is lexicographically smallest string than s1.  For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c and both string are of same length.

// for solving this problem we use sliding window
// given string is a binary string so have only '0' and '1' so we don't use map to store frequency we use cnt variable and we want to know about only frequency of 1 then we take only 1 variable cnt1

// we want Shortest and Lexicographically Smallest Beautiful String
// It can be given string itself or any substring of s if it has cnt1==k and it is shortest in length from all substring having cnt1==k and it should also be lexicographically smallest .

// t.c-O(n)(for traversing each char once for outer while loop)+O(n)( by combining both inner while loop throughout the whole journey not for each index)=O(2n)=O(n)
// s.c-O(1) or we can say ans.size which is required
string shortestBeautifulSubString(string s, int k)
{
  int n = s.size();
  string ans = "";
  int minLen = INT_MAX;
  int l = 0, r = 0; // using sliding window
  // we want to know about only number of '1' in current substring so we use only cnt1 variable to store number of '1' upto current index=r, no need to store cnt0
  int cnt1 = 0;
  while (r < n)
  {
    if (s[r] == '1')
      cnt1++;
    // when cnt1>k means in our substring number of '1' are greater than k so we compress substring by moving l and if s[l]=='1' then we do cnt1--
    while (cnt1 > k)
    {

      if (s[l] == '1')
        cnt1--;
      l++;
    }
    // when cnt1==k but when we have extra '0' in starting of the substring that are not needed because we want shortest substring so we can remove '0' also
    // example: s="001011" and k=2
    // when our window becomes: 00101 it contain exactly two 1's but the first two zeros are not needed so we remove them and get 101 this given the shortest possible substring ending at r that contains exactly k 1's
    while (cnt1 == k && s[l] == '0')
    {
      l++; // simply removing starting '0' to get shortest substring
    }
    // when cnt1==k and we don't have extra '0'
    // we have two cases:
    // i) if current len < minLen in that case we simply replace ans by current substring because current substring is shorest in length and we can say when it is shoretest length then we can directly say  current string is lexicographically smallest than ans
    // ii) when current length == minLen in that case we check if current string is lexicographically smallest than ans string then we can replcase ans string also

    if (cnt1 == k)
    {
      int len = r - l + 1;
      string curr = s.substr(l, len); // it give me string starting from index l and of length =len
      // i) case
      if (len < minLen)
      {
        // directly currnet string is  smallest lexicographically
        ans = curr;
        len = minLen;
      }
      // ii) case
      else if (len == minLen && curr < ans)
      {

        // when both curr and ans string (i.e len==minLen)have same length than we compare lexicographically smallest by relational operator
        ans = curr;
      }
    }
    r++; // move r everytime
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << shortestBeautifulSubString(s, k);
  return 0;
}