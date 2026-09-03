// A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

// Given an integer n, return true if n is a perfect number, otherwise return false.

// Example 1:
// Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.

// Example 2:
// Input: num = 7
// Output: false

#include <bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num)
{
  int sum = 0;
  for (int i = 1; i * i < num; i++)
  {
    if (num % i == 0)
    {
      sum += i;
      if (num / i != i && num / i != num)
        sum += (num / i);
    }
  }
  if (sum == num)
    return true;
  return false;
}

int main()
{
  int num;
  cout << "Enter the number: ";
  cin >> num;
  cout << "Perfect number or not: " << checkPerfectNumber(num) << endl;
  return 0;
}