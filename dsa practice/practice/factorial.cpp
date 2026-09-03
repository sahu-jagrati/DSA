#include <iostream>
using namespace std;

int iterative(int n)
{
  int fac = 1;
  for (int i = 1; i <= n; i++)
  {
    fac *= i;
  }
  return fac;
}

int recursive(int n)
{
  if (n == 1)
    return 1;
  return n * recursive(n - 1);
}
int main()
{
  int n;
  cin >> n;

  // int answer = iterative(n);
  int answer = recursive(n);
  cout << answer << endl;
  return 0;
}