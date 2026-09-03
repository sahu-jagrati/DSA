#include <iostream>
#include <set>
#include <vector>
using namespace std;

// set is a container that stores unique element in a sorted order
// by default order is ascending
// set insertion takes - O(logn) time complexity

int removeduplicateAndgetIndex(vector<int> &arr, int n)
{
  // optimal approach-two pointer approach whose time complexity is O(n) and space complexity is O(1)
  int i = 0;
  for (int j = 1; j < n; j++)
  {
    if (arr[j] != arr[i])
    {
      arr[i + 1] = arr[j];
      i++;
    }
  }
  return i + 1; // which return index from which array have duplicate element
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

  // brute approach,time complexity is O(nlogn + n)
  // space complexity is O(n) because if there is all unique element in aa array
  set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(arr[i]); // O(nlogn) from there because n times loop run for O(logn) complexity means outer loop run n times
  }
  for (int i : st) // this is for printing set
  {
    cout << i << " ";
  }
  cout << endl;
  int index = 0;
  for (auto i : st) // auto- automatically detect datatypes- so here it assign int
  {
    arr[index] = i; // O(n) from there
    index++;        // when there is no element in set, so there is no further insertion in an array, after that there is 0(zero)based index so we get size of array and return index
  }
  cout << index << endl;
  int getIndex = removeduplicateAndgetIndex(arr, n);
  cout << getIndex << endl;
  return 0;
}