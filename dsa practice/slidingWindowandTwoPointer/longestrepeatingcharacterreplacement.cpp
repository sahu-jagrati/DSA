// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

// example- s=AAABBCCD,k=2
// answer- maxlen=5

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

// we have string s and integer k we have to return length of longet substring haveing all letter same after performing atmost k operation
// k opeation means we can change atmost k character of the string to any other upper case english character

// example- s="ABAB" , k=2
// we replace all A's to B's then longest substring containing the same letter we get after performing the k operations is len=4
// or we can do vice versa change B's in A's

// example- s="AABABBA", k=1
// if we replace third B with A then len=4
// if we replcae fourth A with B then len=4
// if we replace last A to B then len=3
// so max len we get after atmost k operation is 4

// example- s="AAABBCCD",k=2
// if we replce fourth and fifth B with A then we get len=5
// if we replace both C to B then len=4
// so maxlen=5 after atmost k operation

// the maximum number of conversions we can do is (len-maxFreq) to get maxlen substring of same character where len is length of the string where we stand and maxfreq is maximum frequency of character in the given string s
// we know maxconversion and we can do atmost k
#include <bits/stdc++.h>
using namespace std;

// naive solution- generate all substring with given condition
// we use hasharryr for frequency of char

// t.c-o(n^2), hasharray takes O(1) time
// s.c-O(26) for hasharray
int longestSameCharSubString(string s, int k)
{
  int n = s.size();
  int maxlen = 0;
  int maxfreq = 0;
  for (int i = 0; i < n; i++)
  {
    vector<int> hasharray(26, 0); // initiall have freq=0 and string has only uppercase english alphabet so 26
    for (int j = i; j < n; j++)
    {
      hasharray[s[j] - 'A']++;
      maxfreq = max(maxfreq, hasharray[s[j] - 'A']);
      // formula of maxconversion for that string where we stand now is (len-maxfreq)
      int changes = (j - i + 1) - maxfreq;
      if (changes <= k)
      {
        maxlen = max(maxlen, j - i + 1);
      }
      // when changes>k
      else
        break;
    }
  }
  return maxlen;
}

// better solution- two pointers/sliding window
// we use hasharray here also, we can use hashmap but it take logarithmic time so we use hasharray to avoid logarithmic time
// and whenever  we shrink the window we also have to update maxfreq by checking whole hasharray

// t.c-O(n(for outer while loop)+O(n)(for inner while loop))*(26)(inner for loop for update maxfreq whenever  we shrink the window)
// s.c-O(26) for hasharray
int longestSubStringWithSameCharacter(string s, int k)
{
  int n = s.size();
  int l = 0, r = 0, maxlen = 0, maxfreq = 0;
  vector<int> hasharray(26, 0);
  // run n times
  while (r < n)
  {
    hasharray[s[r] - 'A']++;
    maxfreq = max(maxfreq, hasharray[s[r] - 'A']);

    // this while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    // formula of maxconversion for that string where we stand now is (len-maxfreq) here len is (r-l+1)
    while ((r - l + 1) - maxfreq > k)
    {
      hasharray[s[l] - 'A']--;
      maxfreq = 0; // because we have to update maxfreq whenever  we shrink the window by checking whole hasharray
      // run 26 time when shrink the window
      for (int i = 0; i < 26; i++)
        maxfreq = max(maxfreq, hasharray[i]);
      l = l + 1;
    }
    if ((r - l + 1) - maxfreq <= k)
    {
      maxlen = max(maxlen, (r - l + 1));
    }
    r++;
  }
  return maxlen;
}

// // the maximum number of conversions we can do is (len-maxFreq) to get maxlen substring of same character where len is length of the string where we stand and maxfreq is maximum frequency of character in the given string s

// optimal solution- we try to remove inner for loop and inner while loop
// but this used only for getting maxlen, we cannot use to print subarray of maxlen
// using pattern 2 optimal solution of two pointers.sliding window
// here we don't shrink l until the maxconversion for that substring>k, here we shrink l only by one place to match current len to maxlen and not go current len to beyond maxlen because we know maxlen till that so no need to go beyond that if maxlen incerease then we move forward
// so whenever maxconversion for that substring>k we shrink l only by 1 to macth curr len to maxlen only, not shrink l completely to valid the given condition(maxconversion for that substring<=k)

// similarly for maxfreq we can do
// we know if len current length of substring increase and if maxfreq after update decrease then it still not valid the condition len-maxfreq<=k
// so if we reduce maxfreq when we shrink the window by updating maxfreq then still it does not valid the condition

// so not necessary to update the maxfreq when we shrink the window, if maxfreq increase from previous then increase it only

// when both current length and maxfreq increase then they satisfy condition

// we do not reduce maxfreq when we shrink the window and we do not make len to go beyond max len

// t.c-O(n)(for outer while loop)*1 for hasharray
//  s.c-O(26) for hasharray

int longestSubstringWithSameChar(string s, int k)
{
  int n = s.size();
  int l = 0, r = 0, maxlen = 0, maxfreq = 0;
  vector<int> hasharray(26, 0);
  // run n times
  while (r < n)
  {
    hasharray[s[r] - 'A']++;
    maxfreq = max(maxfreq, hasharray[s[r] - 'A']);
    // we shrink l only by one place and not update maxfreq because of reduction
    // now take O(1)
    if ((r - l + 1) - maxfreq > k)
    {
      hasharray[s[l] - 'A']--;
      l = l + 1;
    }
    if ((r - l + 1) - maxfreq <= k)
    {
      maxlen = max(maxlen, (r - l + 1));
    }
    r++;
  }
  return maxlen;
}

int main()
{
  string s; // string has only uppercase english alphabets
  cout << "Enter the string: ";
  cin >> s;
  int k;
  cout << "Enter the value of k: ";
  cin >> k;
  // int answer = longestSameCharSubString(s, k);
  // int answer = longestSubstringWithSameChar(s, k);
  int answer = longestSubStringWithSameCharacter(s, k);
  cout << "Length of the longest substring containing the same letter we get after performing the k operations: " << answer << endl;
  return 0;
}