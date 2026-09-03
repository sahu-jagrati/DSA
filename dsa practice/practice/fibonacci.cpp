// 0 1 1 2 3 5 .....

#include <iostream>
using namespace std;

void iterative(int n)
{
  long long a = 0, b = 1;
  for (int i = 1; i <= n; i++)
  {
    cout << a << " ";
    long long next = a + b;
    a = b;
    b = next;
  }
  cout << endl;
}

long long recursive(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  // if(n<=1)return n;
  return recursive(n - 1) + recursive(n - 2);
}
int main()
{
  int n; // number of terms
  cin >> n;
  iterative(n);
  for (int i = 0; i < n; i++)
  {
    cout << recursive(i) << " ";
  }
  cout << endl;
  return 0;
}