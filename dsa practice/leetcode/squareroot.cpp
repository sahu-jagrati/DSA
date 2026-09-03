#include <iostream>
using namespace std;

// time complexity-O(x*logx(base2))
//  space complexity-O(1)
int mySqrt(int x)
{
  if (x == 0)
    return 0;
  int low = 1, high = x;
  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // int number = mid * mid; // time limit exceed
    long long number = 1LL * mid * mid;
    if (number == x)
      return mid;
    else if (number < x)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

int main()
{
  int x;
  cin >> x;
  int result = mySqrt(x);
  cout << result << endl;
  return 0;
}