// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

// Constraints:

// 1 <= s.length <= 105
// s[i] is a printable ascii character.

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n/2)
// s.c-O(1)
void reverseString(vector<char> &s)
{
  int n = s.size();
  for (int i = 0; i < n / 2; i++)
  {
    char temp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = temp;
  }
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<char> s(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  reverseString(s);
  for (auto it : s)
  {
    cout << it << " ";
  }
  return 0;
}