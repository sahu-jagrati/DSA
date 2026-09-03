#include <bits/stdc++.h>
using namespace std;

// t.c-O(n^3)
// s.c-O(1)
int CountTriples(int n)
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {

        long i2 = i * i;
        long j2 = j * j;
        long k2 = k * k;
        if (i2 + j2 == k2)
          cnt++;
      }
    }
  }
  return cnt;
}

// t.c-O(n^2)
// s.c-O(1)
int countTriples(int n)
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int sum = i * i + j * j;
      int k = sqrt(sum);
      if (k * k == sum && k <= n)
      {
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  int result = countTriples(n);
  cout << result << endl;

  return 0;
}