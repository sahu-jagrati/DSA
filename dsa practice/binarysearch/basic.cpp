// binary search - time complexity-O(log n (base 2))
#include <iostream>
#include <vector>
using namespace std;

int iterativeCode(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}

// not correct for more than one occurence
int recusiveCode(vector<int> &arr, int target, int low, int high)
{
  int n = arr.size();
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (arr[mid] == target)
    return mid;
  else if (arr[mid] > target)
    return recusiveCode(arr, target, low, mid - 1);
  else
    return recusiveCode(arr, target, mid + 1, high);
}
int answer(vector<int> &arr, int target)
{
  return recusiveCode(arr, target, 0, arr.size() - 1);
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
  int target;
  cin >> target;
  // int result = iterativeCode(arr, target);
  // int result = recusiveCode(arr, target, 0, n - 1);
  int result = answer(arr, target);

  cout << result << endl;
  return 0;
}

// arr is of max. size 10^5 or 10^6 or 10^7 but we can use binary search in more size also like 0 to INT_MAX
// binary search is not only applicable upto array, it is so many application like also used in dictionary and so on
// overflow case-
// e.g. low=high=INT_MAX in that case low+high=2*INT_MAX, it is overflow because it is so large se we store it in long long instead of int, assign low,high long long
// so we can also alter the formula mid=(low+(high-low))/2 so when we use this, in case of low=high=INT_MAX, high-low become 0 and we get INT_MAX only, so we don't have to use long long but this formula is used upto INT_MAX
