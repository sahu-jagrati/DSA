#include <iostream>
#include <vector>
using namespace std;

// brute-generate all the subarray
// time complexity-approx. O(n^3) and space complexity-O(1)
int maxProduct(vector<int> &arr)
{
  int n = arr.size();
  int INT_MIN = -2147483648;
  int maxi = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int product = 1;
      for (int k = i; k < j; k++)
      {
        product = product * arr[k];
      }
      maxi = max(product, maxi);
    }
  }
  return maxi;
}

// better- time complexity-approx. O(n^2) and space complexity-O(1)
int maxproduct(vector<int> &arr)
{
  int n = arr.size();
  int INT_MIN = -2147483648;
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int product = 1;
    for (int j = i; j < n; j++)
    {
      product = product * arr[j];
      maxi = max(product, maxi);
    }
  }
  return maxi;
}
// optimal has two approach 1. observation and 2. kadane's version but this is not use in interview because it doesn't have clear intution
// 1. observation- 1. all +ve  2. even negative 3. odd negative- prefix and suffix use 4. it has zeroes
// time complexity-O(n) and space complexity-O(1)
int maxiProduct(vector<int> &arr)
{
  int n = arr.size();
  int INT_MIN = -2147483648;
  int maxi = INT_MIN;
  int prefix = 1, suffix = 1;
  for (int i = 0; i < n; i++)
  {
    if (prefix == 0)
      prefix = 1;
    if (suffix == 0)
      suffix = 1;
    prefix = prefix * arr[i];
    suffix = suffix * arr[n - i - 1];
    maxi = max(maxi, max(prefix, suffix));
  }
  return maxi;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // int result = maxProduct(arr);
  // int result = maxproduct(arr);
  int result = maxiProduct(arr);
  cout << result << endl;
  return 0;
}