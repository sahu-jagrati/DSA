#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute approach- time complexity =O(n*n) and space complexity =O(1)

int numberAppearsOnce(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int num = arr[i];
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (num == arr[j])
      {
        count++;
      }
    }
    if (count == 1)
    {
      return num;
    }
  }
}

// better approach- time complexity =O(n)+O(n)+O(hash.size()) or O(n)+O(n)+O(n) depend on input which for loop is used for return and space complexity is O(hash size)

int numberOnceAppears(vector<int> &arr)
{
  int n = arr.size();
  int maxi = arr[0];
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, arr[i]);
  }
  vector<int> hash(maxi);
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }
  // for (int i = 0; i < hash.size(); i++)
  // {
  //   if (hash[i] == 1)
  //   {
  //     return i;
  //   }
  // }
  for (int i = 0; i < n; i++)
  {
    if (hash[arr[i]] == 1)
    {
      return arr[i];
    }
  }
}

// in better approach hashing is some difficult in case of negatives or in 10^7 large numbers so we used map with value-long long and key int - time complexity = O(nlog m)+O(n/2 +1) where n is array size and m is map size = (n/2+1) in case of orderd map
// space complexity is O(n/2+1)

int number(vector<int> &arr)
{
  int n = arr.size();
  map<long long, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
  }
  for (auto it : mpp)
  {
    if (it.second == 1)
    {
      return it.first;
    }
  }
}

// optimal approach-xor - time complexity = O(n) and space complexity is O(1)
int numberappearsonce(vector<int> &arr)
{
  int xor1 = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    xor1 = xor1 ^ arr[i];
  }
  return xor1;
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
  // int result = numberAppearsOnce(arr);
  // int result = numberOnceAppears(arr);
  // int result = number(arr);
  int result = numberappearsonce(arr);

  cout << result << endl;
  return 0;
}