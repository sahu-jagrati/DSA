// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

// Example 1:

// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"

// Constraints:

// 1 <= s.length <= 100
// s consists of characters with ASCII values in the range [33, 122].
// s does not contain '\"' or '\\'.

#include <bits/stdc++.h>
using namespace std;

// done my me whole
// t.c-O(n) in worst case when only one pointer move
// s.c-O(1)
string reverseOnlyLetters(string s)
{
  int n = s.size();
  int l = 0, r = n - 1;
  while (l <= r)
  {
    if (((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z')) && ((s[r] >= 'a' && s[r] <= 'z') || s[r] >= 'A' && s[r] <= 'Z'))
    {
      int temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      l++;
      r--;
    }
    else if (!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z')))
      l++;
    else if (!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z')))
      r--;
  }
  return s;
}

// short version of above by using isalpha() function

string reverseonlyLetters(string s)
{
  int n = s.size();
  int l = 0, r = n - 1;
  while (l <= r)
  {
    if (isalpha(s[l]) && isalpha(s[r]))
    {
      int temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      l++;
      r--;
    }
    else if (!isalpha(s[l]))
      l++;
    else if (!isalpha(s[r]))
      r--;
  }
  return s;
}
int main()
{
  string s;
  cin >> s;

  // string answer = reverseOnlyLetters(s);
  string answer = reverseonlyLetters(s);
  cout << answer << endl;
  return 0;
}