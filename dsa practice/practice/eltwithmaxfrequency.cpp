#include <iostream>
#include <vector>
#include <map>
using namespace std;

// t.c=O(n^2)
int eltWithMaxFrequency(vector<int> &arr, int n)
{
  int max = 0;
  int elt;
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
        count++;
    }
    if (count > max)
    {
      max = count;
      elt = arr[i];
    }
  }
  return elt;
}

// t.c=O(nlogk)+O(k)=approx.O(nlogn)
// O(nlogk) = O(logk) for each insertion where k=number of distinct elements
// if we have all elements are distinct k=n so, =O(nlogn)

// O(k) for iterating over the map if all elements are unique then k=n

// space complexity-o(k) if all are unique then k=n
int maxFrequencyElt(vector<int> &arr, int n)
{
  map<int, int> hashmap;
  int elt;
  for (int i = 0; i < n; i++)
  {
    hashmap[arr[i]]++;
  }
  int max = 0;
  for (auto it : hashmap)
  {
    int count = 0;
    if (it.second > count)
    {
      count = it.second;
    }
    if (count > max)
    {
      max = count;
      elt = it.first;
    }
  }
  return elt;
}

// we can use unordered map in that case t.c=O(N*1) in best and average, in worst case t.c=o(n*n)
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // int result = eltWithMaxFrequency(arr, n);
  int result = maxFrequencyElt(arr, n);
  cout << result << endl;
  return 0;
}