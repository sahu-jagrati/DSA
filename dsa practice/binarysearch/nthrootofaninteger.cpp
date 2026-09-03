// nth root of an integer means like if n=3 then cube root of any number like cube root of 27=3 , n can be any
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// this function uses exponentiation by squaring, so its complexity is O(log n)
int func(int i, int n)
{
  int ans = pow(i, n); // here pow() function returns double, not int and in some case it can be overflow, so make your own power function or try given function()
  return ans;
}
// time complexity-
// loop runs in the worst case from i=1 to i=number and for each iteration call func() function which is O(log n)
// so total -O(number * log n) in worst case and in best case when number is a perfect power -O(log n)
int root(int number, int n)
{
  for (int i = 1; i <= number; i++)
  {
    if (func(i, n) == number)
      return i;
    else if (func(i, n) > number)
      break;
  }
  return -1;
}

int function(int mid, int n)
{
  long long ans = 1;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      ans = ans * mid;
      n = n - 1;
    }
    else
    {
      mid = mid * mid;
      n = n / 2;
    }
  }
  return ans;
}
// optimize solution- time complexiyt-O((log number(base 2)) * (log n(base 2))(for function()))

// but this can also be overflow like if number=10^9 then in that case finding mid and multiply it n times make it so large and large in the sense greater than number also so we write more optimize code
int Root(int number, int n)
{
  int low = 1, high = number;
  while (low <= high)
  {
    long long mid = low + (high - low) / 2;
    long long val = function(mid, n);
    if (val == number)
      return mid;
    else if (val > number)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}
// return 1 if == number
// return 0 if < number
// return 2 if > number
int optimizeFunction(int mid, int n, int number)
{
  long long ans = 1;
  for (int i = 1; i <= n; i++)
  {
    ans = ans * mid;
    if (ans > number)
      return 2;
  }
  if (ans == number)
    return 1;
  return 0;
}

// time complexity-O(n(for optimizeFunction)*log number(base 2))
int optimizeRoot(int number, int n)
{
  int low = 1, high = number;
  while (low <= high)
  {
    long long mid = low + (high - low) / 2;
    int val = optimizeFunction(mid, n, number);
    if (val == 1)
      return mid;
    else if (mid == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main()
{
  int n, number;
  cin >> n >> number;
  // int result = root(number, n);
  // int result = Root(number, n);
  int result = optimizeRoot(number, n);
  cout << result << endl;
  return 0;
}