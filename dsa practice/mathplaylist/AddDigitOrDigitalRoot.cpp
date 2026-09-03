// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

// Example 1:

// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2
// Since 2 has only one digit, return it.
// Example 2:

// Input: num = 0
// Output: 0

// Constraints:

// 0 <= num <= 2^31 - 1

// Follow up: Could you do it without any loop/recursion in O(1) runtime?

#include <bits/stdc++.h>
using namespace std;

// here problem ask repeatedly add digits until we get single digit number so it is called "Digital Root"

// Given a number n, find the digital root of n. Digital Root of a number is the recursive sum of its digits until we get a single digit number.

// Examples :

// Input: n = 1
// Output:  1
// Explanation: Digital root of 1 is 1.

// Input: n = 99999
// Output: 9
// Explanation: The sum of digits of 99999 is 45 which is not a single digit number, hence the sum of digits of 45 is 9 which is a single digit number.

// we have two types of approach:

// Naive approach: Repeatedly adding digits
// The approach computes the digital root of a number by repeatedly summing its digits until a single digit value is obtained. It starts by adding all the digits of the given number; if the result is a single digit, it is returned. Otherwise, the same process is repeated on the new sum until a single digit result is reached.

// t.c-O(d), where d is the number of digits in n.
// s.c-O(1)

int digitalRoot(int n)
{
  // result to store sum of the digits
  int result = 0;
  // repeatedly calculate sum until it becomes single digit
  // we say n>0 || result>9 because suppose n=9999 so in that case if n==0 but result=36 means it is a two digit number so we have to call again or n=999 and result=9 but n is still not done so we use ||
  while (n > 0 || result > 9)
  {
    // if n becomes 0, reset it to result and start a new iteration
    if (n == 0)
    {
      n = result;
      result = 0; // sum again start with 0
    }
    // store sum of digits
    result += n % 10;
    n /= 10;
  }
  return result; // as a single digit
}

// Optimal/Expected Approach- Using Mathematical Formula
// When base =10 means we have decimal number

// This approach computes the digital root using a mathematical property instead of repeatedly summing the digits. If the number is 0, the digital root is 0. Otherwise, the digital root is equal to the remainder when the number is divided by 9; however, if the remainder is 0, the digital root is 9 because every non-zero multiple of 9 has a digital root of 9.

// Divisibility rule of 9: The number is divisible by 9 if the sum of its digit is divisible by 9.
// A number and the sum of its digits always leave the same remainder when divided by 9. For example, 572 → 5 + 7 + 2 = 14 → 1 + 4 = 5, and both 572 and 5 have the same remainder modulo 9.
// Repeatedly summing the digits (finding the digital root) does not change this remainder.
// Therefore, for any non-zero number, the digital root is simply n % 9.
// The only exception is when n is a non-zero multiple of 9. In this case, n % 9 is 0, but the digital root is 9, so the function returns 9.
// If n is 0, its digital root is also 0, which is handled separately.

// t.c-O(1)
// s.c-O(1)
int addDigits(int n)
{
  // if the given number is zero its digit sum will be zero only
  if (n == 0)
    return 0;
  // if the number is multiple of 9 that is remainder =0 so digital root is 9
  // If result of modulo operator is 0 then, the digit sum is 9
  if (n % 9 == 0)
    return 9;

  // for any non-zero number, the digital root is
  return (n % 9);
}

int main()
{
  int n;
  cin >> n;
  cout << digitalRoot(n) << endl;
  cout << addDigits(n) << endl;
  return 0;
}
