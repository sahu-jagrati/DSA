// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2^x.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 2^0 = 1

// Example 2:
// Input: n = 16
// Output: true
// Explanation: 2^4 = 16

// Example 3:
// Input: n = 3
// Output: false

// Constraints:

// -(2^31) <= n <= (2^31) - 1

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
  if (n <= 0)
    return false;
  if (n == 1)
    return true;
  if (n % 2 != 0)
    return false;
  return isPowerOfTwo(n / 2);
}
bool isPowerOfThree(int n)
{
  if (n <= 0)
    return false;
  if (n == 1)
    return true;
  if (n % 3 != 0)
    return false;
  return isPowerOfThree(n / 3);
}
bool isPowerOfFour(int n)
{
  if (n <= 0)
    return false;
  if (n == 1)
    return true;
  if (n % 4 != 0)
    return false;
  return isPowerOfFour(n / 4);
}
int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << "The number is power of two or not: " << isPowerOfTwo(n) << endl;
  return 0;
}