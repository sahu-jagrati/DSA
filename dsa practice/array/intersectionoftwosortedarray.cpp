#include <iostream>
#include <vector>
using namespace std;

// in union there is space of unionarray in space complexity because unionarray size can be larger than both array size

// brute approach- time complexity is O(n1*n2) in worst case
// space complexity is O(n2) because of visited array, we take visited array smaller one so minimum space will be taken
vector<int> intersectionOfTwoSortedArray(vector<int> &a, vector<int> &b)
{
  int n1 = a.size();
  int n2 = b.size();
  vector<int> visited(n2);
  vector<int> inter;
  for (int i = 0; i < n2; i++)
  {
    visited[i] = 0;
  }
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++)
    {
      if (a[i] == b[j] && visited[j] == 0)
      {
        inter.push_back(a[i]);
        visited[j] = 1;
        break;
      }
      if (b[j] > a[i])
      {
        break;
      }
    }
  }
  return inter;
}

// optimal approach- time complexity in worst case =O(n1+n2) when one by one i increase and j increase i.e first i increase and then j and then i and then j so on
// space complexity =O(1) no extra space used
vector<int> intersectionOfSortedArray(vector<int> &a, vector<int> &b)
{
  int n1 = a.size();
  int n2 = b.size();
  int i = 0;
  int j = 0;
  vector<int> intersec;
  while (i < n1 && j < n2)
  {
    if (a[i] == b[j])
    {
      intersec.push_back(a[i]);
      i++;
      j++;
    }

    else if (a[i] < b[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  return intersec; // intersec size always less than or equal to minimum size array
}
int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> a(n1), b(n2);
  for (int i = 0; i < n1; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n2; i++)
  {
    cin >> b[i];
  }
  // vector<int> result = intersectionOfTwoSortedArray(a, b);
  vector<int> result = intersectionOfSortedArray(a, b);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}