#include <iostream>
#include <vector>
using namespace std;

// brute aproach is when we have sorted array then second largest is arr[n-2] if it is not equal to arr[n-1] and having time complexity O(nlogn)
// better approach is this of time complexity O(n+n)=O(2n)

// int secondLargest(vector<int> &arr, int n)
// {
//   int largest = arr[0];
//   for (int i = 0; i < n; i++)
//   {
//     if (largest < arr[i])
//     {
//       largest = arr[i];
//     }
//   }
//   int secondlargest = -1;  // when array does't have negative integers, if have then take secondlargest=INT_MIN
//   for (int j = 0; j < n; j++)
//   {
//     if (arr[j] != largest && secondlargest < arr[j])

//     {
//       secondlargest = arr[j];
//     }
//   }
//   return secondlargest;
// }

// optimal approach, time complexity is O(n)
int secondLargest(vector<int> arr, int n)
{
  int largest = arr[0];
  int secondlargest = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > largest)
    {
      secondlargest = largest;
      largest = arr[i];
    }
    else if (arr[i] < largest && arr[i] > secondlargest)
    {
      secondlargest = arr[i];
    }
  }
  return secondlargest;
}

// optimal approach, time complexity is O(n)
int secondSmallest(vector<int> &arr, int n)
{
  int int_max = INT32_MAX;
  int smallest = arr[0];
  int secondsmallest = int_max;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < smallest)
    {
      secondsmallest = smallest;
      smallest = arr[i];
    }
    else if (smallest < arr[i] && arr[i] < secondsmallest)
    {
      secondsmallest = arr[i];
    }
  }
  return secondsmallest;
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
  int result = secondLargest(arr, n);
  cout << result << endl;
  int res = secondSmallest(arr, n);
  cout << res << endl;
  return 0;
}