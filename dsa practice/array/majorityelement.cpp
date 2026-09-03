// majority element(>n/2)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute approach- time complexity-O(n^2) and space complexity-O(1)
int majority(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }
    if (count > n / 2)
    {
      return arr[i];
    }
  }
}

// better approach- hashmap - time complexity-O(nlogn)+O(n) in ordered map and in unordered map-O(n*1)+O(n) in best and average or O(n*n)+O(n) in worst
// and space complexity-O(n)
int majorityelement(vector<int> &arr)
{
  int n = arr.size();
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
  }
  for (auto it : mpp)
  {
    if (it.second > n / 2)
    {
      return it.first;
    }
  }
  return -1;
}

// optimal approach-moore's voting algorithm/ Boyer-Moore Vote Algorithm-
// time complexity-O(n)+O(n)=O(2n)=O(n) if question said there is compulsory that array have majority element then O(n) for checking the elt is not done in that case time complexity-O(n) only
// space complexity-O(1)
int majorityElement(vector<int> &arr)
{
  int n = arr.size();
  int count = 0;
  int elt;
  for (int i = 0; i < n; i++)
  {
    if (count == 0)
    {
      count = 1;
      elt = arr[i];
    }
    else if (arr[i] == elt)
    {
      count++;
    }
    else
    {
      count--;
    }
  }
  int count1 = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == elt)
    {
      count1++;
    }
  }
  if (count1 > (n / 2))
  {
    return elt;
  }
  return -1;
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
  // int result = majority(arr);
  // int result = majorityelement(arr);
  int result = majorityElement(arr);
  cout << result << endl;
  return 0;
}