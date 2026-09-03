#include <iostream>
using namespace std;

// either x=0 or n>0

// time complexity-O(log n)
// space complexity-O(1)
double myPow(double x, int n)
{
  long long N = n; // because n can be so large
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

// time complexity-O(n)
// space complexity-O(1)
double MyPow(double x, int n)
{
  long long N = n; // because n can be so large
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

int main()
{
  double x;
  cin >> x;
  int n;
  cin >> n;
  // double answer = myPow(x, n);
  double answer = MyPow(x, n);
  cout << answer << endl;

  return 0;
}