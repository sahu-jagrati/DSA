#include <iostream>
#include <vector>
using namespace std;

// brute approach-time complexity-O(n^2) and space complexity-O(1)
void repeatingAndMissing(vector<int> &arr)
{
  int n = arr.size();
  int repeat = -1;
  int missing = -1;
  for (int i = 1; i <= n; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[j] == i)
        count++;
    }
    if (count == 2)
    {
      int repeat = i;
      cout << repeat << " ";
    }
    else if (count == 0)
    {
      int missing = i;
      cout << missing << " ";
    }
    if (repeat != -1 && missing != -1)
    {
      break;
    }
  }
}

// better approach-  time complexity = O(2n) and space complexity=O(n) because of hasharr
vector<int> missingAndRepeating(vector<int> &arr)
{
  int n = arr.size();
  int hasharr[n + 1] = {0};
  for (int i = 0; i < n; i++)
  {
    hasharr[arr[i]]++;
  }
  int repeating = -1, missing = -1;
  for (int i = 1; i <= n; i++)
  {
    if (hasharr[i] == 2)
    {
      repeating = i;
    }
    else if (hasharr[i] == 0)
    {
      missing = i;
    }
    if (repeating != -1 && missing != -1)
    {
      break;
    }
  }
  return {repeating, missing};
}

// optimalsolution-
// 1. mathematics solution- time complexity-O(n) and space complexity-O(1)
vector<int> rAndM(vector<int> &arr)
{
  long long n = arr.size();
  // repeating and y=missing
  // S-Sn=x-y
  // S2-S2n=x^2 - y^2
  long long Sn = (n * (n + 1)) / 2;
  long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
  long long S = 0;
  long long S2 = 0;
  for (int i = 0; i < n; i++)
  {
    S += arr[i];
    S2 += (long long)arr[i] * (long long)arr[i];
  }
  long long val1 = S - Sn;
  long long val2 = S2 - S2n;
  val2 = val2 / val1;
  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};
}

// 2. XOR solution- see explanation in diary
// time complexity-O(4n)= approx.O(n)
// space complexity-O(1)
vector<int> mAndR(vector<int> &arr)
{
  int n = arr.size();
  int xr = 0;
  for (int i = 0; i < n; i++)
  {
    xr = xr ^ arr[i];
    xr = xr ^ (i + 1);
  }
  // int bitNo = 0;
  // while (1)
  // {
  //   if ((xr & (1 << bitNo)) != 0)
  //   {
  //     break;
  //   }
  //   bitNo++;
  // }
  // upper part can be replace by this
  int number = xr & ~(xr - 1);
  int zero = 0;
  int one = 0;
  for (int i = 0; i < n; i++)
  {
    // part of 1 club
    // if ((arr[i] & (1 << bitNo)) != 0)
    if ((arr[i] & number) != 0)
    {
      one = one ^ arr[i];
    }
    // zeroth club
    else
    {
      zero = zero ^ arr[i];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    // part of 1 club
    // if ((i & (1 << bitNo)) != 0)
    if ((i & number) != 0)
    {
      one = one ^ i;
    }
    // zeroth club
    else
    {
      zero = zero ^ i;
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == zero)
      count++;
  }
  if (count == 2)
    return {zero, one};
  return {one, zero};
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
  // repeatingAndMissing(arr);
  // vector<int> result = missingAndRepeating(arr);
  // vector<int> result = rAndM(arr);
  vector<int> result = mAndR(arr);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}