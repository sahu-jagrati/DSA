#include <iostream>
#include <set>
#include <vector>
using namespace std;

// brute approach - time complextity is = O(n1logn+n2logn)+O(n1+n2)
// n is the set size which vary continously
// space complexity in worst case is = O(n1+n2 )+O(n1+n2) first one because of set using to solve the problem and second one for only returning not for solving the problem 
// vector<int> unionOfTwoSortedArray(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
// {

//   set<int> st;  from here for S.C - O(n1+n2) 
//   for (int i = 0; i < n1; i++)
//   {
//     st.insert(arr1[i]);   // from here for T.C O(n1logn)
//   }
//   for (int i = 0; i < n2; i++)
//   {
//     st.insert(arr2[i]);   // from here for T.C O(n2logn)
//   }
//   int n3 = st.size();
//   vector<int> unionArr(n3);
//   int i = 0;
//   for (auto it : st)
//   {
//     unionArr[i] = it;   // from here for T.C O(n1+n1)
//     i++;
//   }
//   return unionArr;  // from here for S.C O(n1+n2)
// }

// optimal approach- two pointer approach - time complexity = O(n1+n2) because in any case somehow we travel both array completely
// space complexity is O(n1+n2) in worst case for returning array not for solving the problem 
vector<int> UnionOfSortedArray(vector<int> &arr1, vector<int> &arr2)
{
  int n1 = arr1.size();
  int n2 = arr2.size();
  int i = 0;
  int j = 0;
  vector<int> unionArr;
  while (i < n1 && j < n2)
  {
    if (arr1[i] <= arr2[j])
    {
      if (unionArr.size() == 0 || unionArr.back() != arr1[i])
      {
        unionArr.push_back(arr1[i]);
      }
      i++;
    }
    else
    {
      if (unionArr.size() == 0 || unionArr.back() != arr2[j])
      {
        unionArr.push_back(arr2[j]);
      }
      j++;
    }
  }
  while (j < n2)
  {
    if (unionArr.size() == 0 || unionArr.back() != arr2[j])
    {
      unionArr.push_back(arr2[j]);
    }
    j++;
  }
  while (i < n1)
  {
    if (unionArr.size() == 0 || unionArr.back() != arr1[i])
    {
      unionArr.push_back(arr1[i]);
    }
    i++;
  }
  return unionArr;
}

int main()
{
  int n1;
  int n2;
  cin >> n1 >> n2;
  vector<int> arr1(n1);
  vector<int> arr2(n2);
  cout << "Enter a first array" << endl;
  for (int i = 0; i < n1; i++)
  {
    cin >> arr1[i];
  }
  cout << endl;
  cout << "Enter a second array" << endl;
  for (int i = 0; i < n2; i++)
  {
    cin >> arr2[i];
  }
  // vector<int> result = unionOfTwoSortedArray(arr1, arr2, n1, n2);
  vector<int> result = UnionOfSortedArray(arr1, arr2);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}