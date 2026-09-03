// You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:

// sumOdd: the sum of the smallest n positive odd numbers.

// sumEven: the sum of the smallest n positive even numbers.

// Return the GCD of sumOdd and sumEven.

// Example 1:

// Input: n = 4

// Output: 4

// Explanation:

// Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
// Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
// Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4.

// Example 2:

// Input: n = 5

// Output: 5

// Explanation:

// Sum of the first 5 odd numbers sumOdd = 1 + 3 + 5 + 7 + 9 = 25
// Sum of the first 5 even numbers sumEven = 2 + 4 + 6 + 8 + 10 = 30
// Hence, GCD(sumOdd, sumEven) = GCD(25, 30) = 5.

// Constraints:

// 1 <= n <= 10​​​​​​​00

#include <bits/stdc++.h>
using namespace std;

// solution by me
int gcdOfOddEvenSums(int n)
{
  int sumOdd = 0, sumEven = 0;
  for (int i = 1; i <= 2 * n; i++)
  {
    if (i % 2 == 0)
      sumEven += i;
    else
      sumOdd += i;
  }
  // there is a built-in gcd function in c++
  return __gcd(sumEven, sumOdd);
}

// the solution get from hint is
// Hint 1
// The first n odd numbers sum to n * n
// Hint 2
// First n even numbers sum to n * (n + 1)
// Hint 3
// gcd(n, n + 1) = 1, so the answer is n

// as sum of first n odd numbers is n*n
// and sum of first n even numbers is n*(n+1)
// gcd(n*n,n*(n+1))=n*gcd(n,n+1)=n

int gcdofOddEvenSums(int n)
{
  return n;
}

int main()
{
  int n;
  cin >> n;
  cout << gcdOfOddEvenSums(n);
  cout << gcdofOddEvenSums(n);
  return 0;
}