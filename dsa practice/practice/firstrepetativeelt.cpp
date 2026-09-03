#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// t.c=O(nlogn)(for sorting)+O(n)(linear scan)=O(nlogn)
// s.c=O(1) because temp is for teporary
int firstRepeated(vector<int> &arr)
{
  int n = arr.size();
  vector<pair<int, int>> temp; //{value,index}
  for (int i = 0; i < n; i++)
  {
    temp.push_back({arr[i], i});
  }
  sort(temp.begin(), temp.end());
  int miniIndex = INT_MAX;
  for (int i = 1; i < n; i++)
  {
    if (temp[i].first == temp[i - 1].first)
    {
      miniIndex = min(miniIndex, min(temp[i].second, temp[i - 1].second));
    }
  }
  if (miniIndex == INT_MAX)
    return -1;
  return arr[miniIndex];
}

// by using hash map
// t.c=O(n)
int firstrepeated(vector<int> &arr, int n)
{
  // unordered map does not store in sorting order
  unordered_map<int, int> mpp;
  for (int x : arr)
    mpp[x]++;
  for (int x : arr)
    if (mp[x] > 1)
      return x;

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
  return 0;
}