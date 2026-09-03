#include <iostream>
#include <vector>
using namespace std;

// brute approach- time complexity in worst case when missing number is last one(or not found until i=number) = O(number*array size) and in best case =O(array size) when missing number is the first one
// space complexity is O(1)
int missingNumber(vector<int> &arr, int number, int n)
{
  for (int i = 1; i <= number; i++)
  {
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[j] == i)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      return i;
    }
  }
}
// better approach- time complexity =O(number)+O(n)
// space complexity =O(number)
int missing(vector<int> &arr, int number, int n)
{
  vector<int> hash(number);
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }
  for (int i = 1; i < number; i++)
  {
    if (hash[i] == 0)
    {
      return i;
    }
  }
}

// optimal approach- 2nd method is better than 1st one because in 1st over 10^5 there is storage problem so we have to use long which takes slightly more space than int
// 1. by sum of first natural number - time complexity=O(n) and space complexity =O(1)
int missingnumber(vector<int> &arr, int number, int n)
{
  long sum = (number * (number + 1)) / 2;
  long sum1 = 0;
  for (int i = 0; i < n; i++)
  {
    sum1 += arr[i];
  }
  return sum - sum1;
}

// 2. by XOR-a^a=0 and 0^(with any number)=number -
// XOR of all numbers will not be that big, at max 10^5 from that never exceed
// 2(i)-time complexity =O(number)+O(n) and space complexity is O(1)
int missnumber(vector<int> &arr, int number, int n)
{
  int xor1 = 0;
  for (int i = 1; i <= number; i++)
  {
    xor1 = xor1 ^ i;
  }
  int xor2 = 0;
  for (int i = 0; i < n; i++)
  {
    xor2 = xor2 ^ arr[i];
  }
  return (xor1 ^ xor2);
}
// 2(ii) - time complexity =O(n) and space complexity =O(1)
int miss(vector<int> &arr, int number, int n)
{
  int xor1 = 0;
  int xor2 = 0;
  for (int i = 0; i < n; i++)
  {
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ (i + 1);
  }
  xor1 = xor1 ^ number;
  return (xor1 ^ xor2);
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
  int number;
  cin >> number;
  // int result = missingNumber(arr, number, n);
  // int result = missing(arr, number, n);
  // int result = missingnumber(arr, number, n);
  // int result = missnumber(arr, number, n);
  int result = miss(arr, number, n);

  cout << result << endl;
  return 0;
}