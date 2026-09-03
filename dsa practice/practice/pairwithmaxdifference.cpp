#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// t.c-O(n)
vector<int> pairWithMaxDifference(vector<int> &arr, int n)
{
  int maxi = INT_MIN;
  int mini = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > maxi)
      maxi = arr[i];
    if (arr[i] < mini)
      mini = arr[i];
  }
  return {maxi, mini};
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
  vector<int> result = pairWithMaxDifference(arr, n);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}