#include <iostream>
#include <vector>
using namespace std;

// time xomplexity = O(n),there is no extra space taken by problem space complexity =O(1)
int maximumconsecutiveOnes(vector<int> &arr)
{
  int n = arr.size();
  int count = 0;
  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 1)
    {
      count++;
      maxi = max(maxi, count);
    }
    else
    {
      count = 0;
    }
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
  int result = maximumconsecutiveOnes(arr);
  cout << result << endl;
  return 0;
}
