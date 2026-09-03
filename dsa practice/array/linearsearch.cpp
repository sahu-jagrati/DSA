#include <iostream>
#include <vector>
using namespace std;

// time complexity in best case is O(1) and in worst case is O(n)
int linearSearch(vector<int> arr, int n, int numSearch)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == numSearch)
    {
      return i + 1;
    }
    else
    {
      return -1;
    }
  }
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
  int numSearch;
  cin >> numSearch;
  int result = linearSearch(arr, n, numSearch);
  cout << result << endl;
}