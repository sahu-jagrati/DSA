// printing all subsequence
// sunsequence is a contiguous and non-contiguous sequence which follows the oder
// it can be done by - powerset or by recursion

#include <iostream>
#include <vector>
using namespace std;

// print all subsequence, also include empty set- number of subsequence=2^n (we know by power set)

// time complexity-we observe for each index we have two option take or not take - O(2^n * n(for loop))
// space complexity-O(n) auxiliary stack space. how many recursion we do? not more than n we do, the depth of recursion at max we take is  n
void printF(int index, vector<int> &ds, vector<int> &arr, int n)
{
  if (index == n)
  {
    for (auto it : ds)
    {
      cout << it << " ";
    }
    cout << endl;
    return;
  }

  // take into subsequence
  ds.push_back(arr[index]);
  printF(index + 1, ds, arr, n);
  ds.pop_back();

  // not take into subsequence
  printF(index + 1, ds, arr, n);
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
  vector<int> ds; // empty array
  printF(0, ds, arr, n);

  return 0;
}