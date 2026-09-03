// You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

// Example 1:

// Input: n = 10, t = 2

// Output: 10

// Explanation:

// The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

// Example 2:

// Input: n = 15, t = 3

// Output: 16

// Explanation:

// The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

// Constraints:

// 1 <= n <= 100
// 1 <= t <= 10

// Hint 1
// You have to check at most 10 numbers.
// Hint 2
// Apply a brute-force approach by checking each possible number.

#include <bits/stdc++.h>
using namespace std;

// as t can be from 1 to 10 so getting smallest divisible number greater than or equal to n is from (n to n+9) such that the product of its digit is divisible by t. Because  from (n to n+9) there is a multiple of t , t can be anything from 1 to 10  because n to n+9 covers 10 numbers so there is one whose product is divisbly by 1 to 9. think it logically

bool productOfDigit(int num, int t)
{
  int product = 1;
  while (num > 0)
  {
    product *= num % 10;
    num /= 10;
  }
  if (product % t == 0)
    return true;
  return false;
}

// t.c-O((n+10)*(max number of digits in num))
// s.c-O(1)
int smallestNumber(int n, int t)
{
  int ans;
  for (int i = n; i < n + 10; i++)
  {
    if (productOfDigit(i, t))
    {
      ans = i;
      break;
    }
  }
  return ans;
}

int main()
{
  int n, t;
  cin >> n >> t; // t is from 1 to 9
  cout << smallestNumber(n, t);
  return 0;
}