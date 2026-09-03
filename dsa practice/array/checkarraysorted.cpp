#include <iostream>
#include <vector>
using namespace std;

bool checkArraySorted(vector<int> &arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < arr[i + 1])
    {
    }

    else
      return false;
  }
  return true;
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
  bool result = checkArraySorted(arr, n);
  cout << result << endl;
  return 0;
}