// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

// Example 1:

// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3
// Example 2:

// Input: n = 1
// Output: true
// Explanation: 1 has no prime factors.
// Example 3:

// Input: n = 14
// Output: false
// Explanation: 14 is not ugly since it includes the prime factor 7.

// Constraints:

// -2^31 <= n <= 2^31 - 1

#include <bits/stdc++.h>
using namespace std;

// first point- ugly number is positive integer also not include 0 so
// if n<=0 return directly false

bool checkPrime(int m)
{
  if (m < 2)
    return false;
  int cnt = 0;
  for (int i = 1; i * i <= m; i++)
  {
    if (m % i == 0)
    {
      cnt++;
      if (m / i != i)
        cnt++;
    }
    if (cnt > 2)
      return false;
  }
  return cnt == 2;
}
// my thinking
// this is correct process but very lengthy, not good for interview and cp

// t.c-
//  outer loop - O(sqrt(n))
//  prime check(worst case)-
//  checkPrime(i)-O(sqrt(i))
//  checkPrime(i)-O(sqrt(n/i))=O(sqrt(n)) worst case when i=1
// worst case when n is prime- t.c-O(sqrt(n)*sqrt(n))=O(n)
// s.c-O(1)
bool isUgly(int n)
{
  if (n <= 0)
    return false;
  if (n == 1)
    return true; // no prime factor

  // loop i = 1 to sqrt(n)
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      // upto sqrt(i)
      if (checkPrime(i))
      {
        if (i != 2 && i != 3 && i != 5)
          return false;
      }
      int other = n / i;
      // upto sqrt(n/i)
      if (other != i && checkPrime(other))
      {
        if (other != 2 && other != 3 && other != 5)
          return false;
      }
    }
  }
  return true;
}
// optimal version of my code-

// we don't need a full prime check
// we only care about prime factors other than 2, 3, or 5.
bool hasOtherPrimeFactor(int x)
{
  while (x % 2 == 0)
    x /= 2;
  while (x % 3 == 0)
    x /= 3;
  while (x % 5 == 0)
    x /= 5;

  return x != 1; // true means some other prime exists
}
// Time Complexity Analysis (after optimization)

// Divisor loop: O(√n)

// Factor reduction per divisor: O(log n) (very small)

// ✅ Final complexity:
// Time:  O(√n)
// Space: O(1)
bool isugly(int n)
{
  if (n <= 0)
    return false;
  if (n == 1)
    return true;

  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {

      // check divisor i
      if (hasOtherPrimeFactor(i))
        return false;

      // check paired divisor n/i
      int other = n / i;
      if (other != i && hasOtherPrimeFactor(other))
        return false;
    }
  }
  return true;
}
// optimal solution for interview-

// and we want it does not have a prime factor other than 2, 3, and 5.
// so we use lcm process this is very good approach for interview

// t.c-
//  each division reduces n
//  each loop runs log(n)(base k) times
//  total operations are very small

// t.c-O(logn)
// s.c-O(1)
bool isUglyNumber(int n)
{
  if (n <= 0)
    return false;
  while (n % 2 == 0)
    n = n / 2;
  while (n % 3 == 0)
    n = n / 3;
  while (n % 5 == 0)
    n = n / 5;

  // in last if n==1 means it has no prime factor other than 2,3 or 5
  // or if n!=1 means if has prime factor which is not 2,3 or 5

  return n == 1;
}

int main()
{
  int n;
  cin >> n;
  bool answer = isUgly(n);
  cout << answer << endl;
  bool result = isUglyNumber(n);

  cout << result << endl;
  return 0;
}

// Why interviewers prefer the optimal one

// Ugly number has restricted primes

// No need to find all primes

// Shows problem insight, not brute force

// If you present your approach first, interviewer may say:

// “Can you do better?”

// And they expect the while (n % 2 == 0) solution.

// 5️⃣ When your approach is still acceptable

// ✔ If problem was:

// “Check whether prime factors belong to a given set dynamically”

// Then your divisor–prime logic makes sense.

// 🎯 Final takeaway

// Your logic = correct but heavy

// Optimal logic = clean, faster, interview-ready

// Knowing both = strong problem-solving signal