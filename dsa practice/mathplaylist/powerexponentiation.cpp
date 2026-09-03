// Given x and n we have to find x^n
// in cpp we have pow(x,n) function = x^n
// we know here what is algo behind pow() function

#include <bits/stdc++.h>
using namespace std;

// naive solution-
// when both x and n are positive
// if power is negative i.e n is negative in tthis case
// x^n= 1/ans where ans is  when n is positive

// if x is double then use double datatype

// t.c-O(n), where n is power
// s.c-O(1)
int power(int x, int n)
{
  int ans = 1;
  for (int i = 1; i <= n; i++)
  {
    ans = ans * x;
  }
  return ans;
}

// optimized solution- when n is even, we make x=x*x and n=n/2
//  and when n is odd we take x in ans and reduce n by 1 to make it even

// by double we can take double type x also and 1/ans in negative case also return proper answer

// t.c-O(log(n)(base 2)), where n is power, most time we do n=n/2
// s.c-O(1)
double powerExponentiation(int x, int n)
{
  int m = n; // if n is negative then in last we reverse the answer for positive
  if (n < 0)
    n = -(n); // make it positive when it is negative
  double ans = 1;
  while (n > 0)
  {
    // if n is odd
    if (n % 2 == 1)
    {
      ans = ans * x;
      n = n - 1; // reduce n by 1 to make it even
    }
    // if n is even
    else
    {
      n = n / 2;
      x = x * x;
    }
  }
  if (m < 0)
  {
    ans = 1 / ans;
  }
  return ans;
}
int main()
{
  int x, n;
  cout << "Enter the value of num and power: ";
  cin >> x >> n;

  // int result = power(x, n);
  double result = powerExponentiation(x, n);
  cout << "Power exponentiation is: " << result << endl;
  return 0;
}