// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
// Example 2:

// Input: n = 7
// Output: 0
// Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
// Example 3:

// Input: n = 10
// Output: 5
// Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

// Constraints:

// 0 <= n < 109

#include <bits/stdc++.h>
using namespace std;

// done by me-
// t.c-O(log n)+O(2m)
// s.c-O(1)
int bitwiseComplement(int n)
{
  if (n == 0)
    return 1;
  string binary;
  // O(log n)
  while (n > 0)
  {
    binary += (n % 2) + '0';
    n /= 2;
  }
  reverse(binary.begin(), binary.end());
  //  flip all the 0's to 1's and all the 1's to 0's
  // O(binary.size())
  for (int i = 0; i < binary.size(); i++)
  {
    if (binary[i] == '0')
      binary[i] = '1';
    else
      binary[i] = '0';
  }
  // convert binary to decimal
  int answer = 0;
  int m = binary.size();
  // O(m)
  for (int i = 0; i < m; i++)
  {
    answer = answer + pow(2, m - 1 - i) * (binary[i] - '0'); // we have to convert binary[i] as a character into integer
  }
  return answer;
}

// shorter bit manipulation solution

// this is we learn when we learn bit manipulation
// t.c-O(log n)
// s.c-O(1)
int bitWiseComplement(int n)
{
  if (n == 0)
    return 1;
  int mask = 0, temp = n;
  while (temp > 0)
  {
    mask = (mask << 1) | 1;
    temp >>= 1;
  }
  return (~n) & mask;
}
int main()
{
  int n;
  cin >> n;
  cout << bitwiseComplement(n) << endl;
  cout << bitWiseComplement(n) << endl;
  return 0;
}