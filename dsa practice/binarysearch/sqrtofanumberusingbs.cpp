// in finding sqrt(n)- we find floor of sqrt(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// time complexity-approx.O(n)
int squareRoot(int n)
{
  int ans = 1;
  for (int i = 1; i <= n; i++)
  {
    if (i * i <= n)
    {
      ans = i;
    }
    else
    {
      break;
    }
  }
  return ans;
}

// using binary search
// time complexity-O(log n(base 2))
int SquareRoot(int n)
{
  int low = 1, high = n;
  int ans = 1;
  while (low <= high)
  {
    long long mid = low + (high - low) / 2; // use long long otherwise in some case it will overflow by using int
    long long val = mid * mid;
    if (val <= n)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans; // you can also return high because when it crosses low the high is the sqrt(n)
}
int main()
{
  int n;
  cin >> n;
  // cout << sqrt(n) << endl;
  // int result = squareRoot(n);
  int result = SquareRoot(n);
  cout << result << endl;
  return 0;
}
