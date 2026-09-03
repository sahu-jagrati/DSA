// You are given an integer n.

// Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

// Let sum be the sum of digits in x.

// Return an integer representing the value of x * sum.

// Example 1:

// Input: n = 10203004

// Output: 12340

// Explanation:

// The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
// The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
// Therefore, the answer is x * sum = 1234 * 10 = 12340.
// Example 2:

// Input: n = 1000

// Output: 1

// Explanation:

// The non-zero digit is 1, so x = 1 and sum = 1.
// Therefore, the answer is x * sum = 1 * 1 = 1.

// Constraints:

// 0 <= n <= 10^9

#include <bits/stdc++.h>
using namespace std;

// t.c-O(maximum number of digits in n)+O(temp size)
// s.c-O(temp size)
long long sumAndMultiply(int n)
{
  long long sum = 0;
  vector<int> temp;
  while (n > 0)
  {
    int digit = n % 10;
    n /= 10;
    if (digit != 0)
    {
      temp.push_back(digit);
      sum += digit;
    }
  }
  int x = 0;
  for (int i = temp.size() - 1; i >= 0; i--)
  {
    x = x * 10 + temp[i];
  }
  return (x * sum);
}
int main()
{
  int n;
  cin >> n;
  cout << sumAndMultiply(n);
  return 0;
}