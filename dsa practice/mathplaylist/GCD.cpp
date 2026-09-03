// how to find gcd of two numbers

#include <bits/stdc++.h>
using namespace std;

// Method 1: Using the Standard Library
// there is a built-in function __gcd(a,b) to find gcd of tw numbers present in library <numeric>

int usingBuiltInFunc(int a, int b)
{
  return __gcd(a, b);
}

// Method 2: The Optimized Eucledian Algo(Recursive)
// t.c.-O(log(min(a,b)))

// best for coding interview
int findGCD(int a, int b)
{
  if (b == 0)
    return a;
  return findGCD(b, a % b);
}

// Method 3: The Eucledian Algo(Iterative)
// t.c-O(log(min(a,b)))

int findGCDIterative(int a, int b)
{
  while (b != 0)
  {
    int remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << usingBuiltInFunc(a, b) << endl;
  cout << findGCD(a, b) << endl;
  cout << findGCDIterative(a, b) << endl;
}