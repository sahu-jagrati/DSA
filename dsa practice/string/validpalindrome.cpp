// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// Constraints:

// 1 <= s.length <= 2 * 10^5
// s consists only of printable ASCII characters.

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string phrase)
{
  string result;
  for (char ch : phrase)
  {
    if (isalnum(ch))
    {
      if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
      {
        result += ch;
      }
      else if (ch >= 'A' && ch <= 'Z')
      {
        ch = tolower(ch);
        result += ch;
      }
    }
  }
  int n = result.size();
  int l = 0, r = n - 1;
  while (l <= r)
  {
    if (result[l] == result[r])
    {
      l++;
      r--;
    }
    else if (result[l] != result[r])
      return false;
  }
  return true;
}

int main()
{
  string phrase;
  getline(cin, phrase);
  bool answer = isPalindrome(phrase);
  cout << "Given phrase is palindrome or not: " << answer << endl;
  return 0;
}