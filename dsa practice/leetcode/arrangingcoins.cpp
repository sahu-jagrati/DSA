// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

// Given the integer n, return the number of complete rows of the staircase you will build.

#include <iostream>
#include <cmath>
using namespace std;

// we know we consist k rows where ith rows has i coins i.e 1st row has 1 coin , 2nd row has 2 coin and so on kth row has k coin
// sum of these coin is <=n
// 1+2+3+_ _ _ +k<=n which imply k(k+1)<=2n

// time xomplexity-O(log n(base 2))
// space complexity-O(1)
int arrangeCoins(int n)
{
  int low = 0, high = n;
  int ans = 0;
  while (low <= high)
  {
    long long mid = low + (high - low) / 2;
    long long coins = (mid * (mid + 1)) / 2;
    if (coins == n)
      return mid;
    else if (coins < n)
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

// optimal-k*(k+1)<=2n i.e k^2 +k -2n <=0
// find roots by aaryabhatt formula
// k should be positive so
// k=(sqrt(1+8n) - 1)/2

// time complexity-O(1)
// space complexity-O(1)
int arrangecoins(int n)
{
  long double discriminant = sqrt(1.0L + 8.0L * (long double)n);
  long long k = (long long)((discriminant - 1.0L) / 2.0L);

  return (int)k;
}
int main()
{
  int n;
  cin >> n;
  // int result = arrangeCoins(n);
  int result = arrangecoins(n);
  cout << result << endl;
  return 0;
}
