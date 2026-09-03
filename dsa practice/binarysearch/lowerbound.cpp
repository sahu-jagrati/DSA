// lower bound-smallest index such that arr[index]>= target
// if the arr[index] which is >= target not find in array then in that case we return hypothetical arr.size()
// in case of repeatition we have to find out the smallest index

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity-O(log n(base 2)) and space complexity-O(1)
int lowerBound(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = n; // if the arr[index] which is >= target not find in array then in that case we return hypothetical arr.size()
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= target)
    {
      ans = mid;
      high = mid - 1; // we have to find smallest index so
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}




int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // we assume that we have sorted array
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  int result = lowerBound(arr, target);
  cout << result << endl;
  // also in cpp we directly can get lowerbound by using already define method
  auto it1 = lower_bound(arr, arr + n, target);          // this is used when we declare array by using int not vector
  auto it = lower_bound(arr.begin(), arr.end(), target); //  returns iterator, it points to the element target inside arr
  cout << (it - arr.begin()) << endl;                    // print the index

  cout << *it << endl; // print the value
  return 0;
}