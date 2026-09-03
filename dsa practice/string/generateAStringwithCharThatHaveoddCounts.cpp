// Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

// The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.

// Example 1:

// Input: n = 4
// Output: "pppz"
// Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
// Example 2:

// Input: n = 2
// Output: "xy"
// Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
// Example 3:

// Input: n = 7
// Output: "holasss"

// Constraints:

// 1 <= n <= 500

// Hint 1
// If n is odd, return a string of size n formed only by 'a', else return string formed with n-1 'a' and 1 'b''.

// we use hint
// we can return any valid string so if n is odd then we add one char(i.e 'a') n times or if n is even then we add one char(i.e'a') n-1 times and other char(i.e'b')1 times
// in place of 'a' and 'b' you can select any char
// we simple want that each char freq in string is odd so it fulfiil

#include <bits/stdc++.h>
using namespace std;

// we take 'p' and 'q' in place of 'a' and 'b', you can take any char
// we simple want that each char freq in string is odd so it fulfiil
// instead of checking all chars randomly we do with only two char that is only required
string generateTheString(int n)
{
  string result;
  // when n is odd
  if (n % 2 != 0)
  {
    // it add 'p' n times
    result += string(n, 'p');
  }
  // when n is even
  else
  {
    result += string(n - 1, 'p');
    result += 'q';
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  cout << generateTheString(n);
  return 0;
}