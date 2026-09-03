#include <iostream>
using namespace std;

// either x=0 or n>0

// t.c=O(n)
// s.c=O(1)
double power(int x, int n)
{
  long long N = n;
  if (N < 0)
  {
    x = 1 / x;
    N = -N;
  }
  double result = 1.0;
  while (N > 0)
  {
    result *= x;
    N--;
  }
  return result;
}

// t.c-O(logn)
// s.c-O(1)
double powerFunction(int x, int n)
{
  long long N = n;
  if (N < 0)
  {
    x = 1 / x;
    N = -N;
  }
  double result = 1.0;
  while (N > 0)
  {
    if (N % 2 == 1)
    {
      result *= x;
    }
    x *= x;
    N /= 2;
  }
  return result;
}
int main()
{
  int x, n;
  cin >> x >> n;
  // int answer = power(x, n);
  int answer = powerFunction(x, n);
  cout << answer << endl;
  return 0;
}