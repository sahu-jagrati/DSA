// You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.

// You can apply the following operation on any of the two strings any number of times:

// Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
// Return true if you can make the strings s1 and s2 equal, and false otherwise.

// Example 1:

// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: We can do the following operations on s1:
// - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
// - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
// Example 2:

// Input: s1 = "abcd", s2 = "dacb"
// Output: false
// Explanation: It is not possible to make the two strings equal.

// input- s1="bnxw",s2="bwxn"
// output=true

// input-s1="kina",s2="kina"
// output-true
// Constraints:

// s1.length == s2.length == 4
// s1 and s2 consist only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(string s1, string s2)
{
  if (s1 == s2)
    return true;
  // we apply opeartions on string1 or we can apply also on s2

  // we go to upto index 1 only because for j=2 or else, k=2+2=4 which is out length
  // and we use two loop because if s1=bnxw,s2=bwxn then for i=1 we have to swap the j and k index character i=0 remains same
  for (int i = 0; i <= 1; i++)
  {
    string temp = s1;
    for (int j = i; j <= 1; j++)
    {
      int k = j + 2;
      if (k < 4)
      {
        swap(temp[j], temp[k]);
        if (temp == s2)
          return true;
      }
    }
  }
  return false;
}
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << canBeEqual(s1, s2);
  return 0;
}