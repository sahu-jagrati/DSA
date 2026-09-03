// Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

// Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
// The subarrays must be adjacent, meaning b = a + k.
// Return true if it is possible to find two such subarrays, and false otherwise

#include <iostream>
#include <vector>
using namespace std;

// this is wrong you have no limit on j+k+1 and also you want two subarray so you have to write if(2*k>n)return false
// you have so many mistakes in this code
// bool adjacentIncreasingSubarrays(vector<int> &arr, int n, int k)
// {
//   if (k >= n)
//     return false;
//   for (int i = 0; i < n; i++)
//   {
//     int j = i;
//     int a = 0;
//     int b = 0;
//     while (j < n)
//     {
//       if ((arr[j] < arr[j + 1]) && (arr[j + k] < arr[j + k + 1]))
//       {
//         a++;
//         b++;
//         if ((a == k) && (b == a + k))
//         {
//           return true;
//         }
//         j++;
//       }
//       else
//       {
//         break;
//       }
//     }
//   }
//   return false;
// }

// t.c=O(n*(2(k-1)))=approx.O(n*k)
// s.c=O(1)
bool adjacentIncreasingSubarrays(vector<int> &arr, int n, int k)
{
  if (2 * k > n)
    return false;
  for (int i = 0; i + 2 * k <= n; i++)
  {
    bool a = true, b = true;
    // check for first subarray
    for (int j = i; j < i + k - 1; j++) // a=i to a+k-1=i+k-1
    {
      if (arr[j] >= arr[j + 1])
      {
        a = false;
        break;
      }
    }
    // check for second subarray
    for (int j = i + k; j < i + 2 * k - 1; j++) // b=a+k=i+k to b+k-1=a+k+k-1=a+2*k-1=i+2*k-1
    {
      if (arr[j] >= arr[j + 1])
      {
        b = false;
        break;
      }
    }
    if (a && b)
      return true;
  }

  return false;
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
  int k;
  cin >> k;
  bool result = adjacentIncreasingSubarrays(arr, n, k);
  cout << result << endl;
  return 0;
}