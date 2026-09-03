#include <bits/stdc++.h>
using namespace std;

// gcd- greatest common divisor- largest number that divides both of them
// time complexity-O(min(n1,n2))
int gcd1(int a, int b)
{
  while (a > 0 && b > 0)
  {
    if (a > b)
    {
      a = a % b;
    }
    else
    {
      b = b % a;
    }
  }
  if (a == 0)
    return b;
  return a;
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  int gcd = 1;
  for (int i = 1; i <= min(n1, n2); i++)
  {
    if (n1 % i == 0 && n2 % i == 0)
    {
      gcd = i;
    }
  }
  cout << gcd << endl;

  // another method to find gcd
  // in this case T.C is also O(min(n1,n2))
  for (int i = min(n1, n2); i >= 1; i--)
  {
    if (n1 % i == 0 && n2 % i == 0)
    {
      cout << i << endl;
      break;
    }
  }
  int c = gcd1(n1, n2);
  cout << c << endl;

  return 0;
}