// median is the middle number of the sorted array
// if n=even then it is (a[(n/2)-1]+a[n/2])/2
// if n=odd then it is a[n/2]
// arrays can be of different size or can be of same size
// and also can have duplicates element
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// brute-time complexity-O(n1+n2)
// space complexity-O(n1+n2)
double medianofTwoSortedArrays(vector<int> &a1, vector<int> &a2)
{
  int n1 = a1.size();
  int n2 = a2.size();
  vector<int> a3;
  int i = 0, j = 0;
  while (i < n1 && j < n2)
  {
    if (a1[i] < a2[j])
    {
      a3.push_back(a1[i]);
      i++;
    }
    else
    {
      a3.push_back(a2[j]);
      j++;
    }
  }
  while (i < n1)
  {
    a3.push_back(a1[i]);
    i++;
  }
  while (j < n2)
  {
    a3.push_back(a2[j]);
    j++;
  }
  int n = n1 + n2;
  if (n % 2 == 1)
    return a3[n / 2];                                                     // if n is odd
  return (double)((double)(a3[(n / 2) - 1]) + (double)(a3[n / 2])) / 2.0; // if n is even
}

// we don't have need of all elt
// better- in this we also use two pointer approach but we don't store elts in 3rd array
// time complexity-O(n1+n2)
// space complexity-O(1)
double Median(vector<int> &a1, vector<int> &a2)
{
  int n1 = a1.size();
  int n2 = a2.size();
  int n = n1 + n2;
  int i = 0;
  int j = 0;
  int ind1 = (n / 2) - 1;
  int ind2 = n / 2;
  int e1 = -1;
  int e2 = -1;
  int cnt = 0; // represent index
  while (i < n1 && j < n2)
  {
    if (a1[i] < a2[j])
    {
      if (cnt == ind1)
        e1 = a1[i];
      if (cnt == ind2)
        e2 = a1[i];
      cnt++;
      i++;
    }
    else
    {
      if (cnt == ind1)
        e1 = a2[j];
      if (cnt == ind2)
        e2 = a2[j];
      cnt++;
      j++;
    }
  }
  while (i < n1)
  {
    if (cnt == ind1)
      e1 = a1[i];
    if (cnt == ind2)
      e2 = a1[i];
    cnt++;
    i++;
  }
  while (j < n2)
  {
    if (cnt == ind1)
      e1 = a2[j];
    if (cnt == ind2)
      e2 = a2[j];
    cnt++;
    j++;
  }
  if (n % 2 == 1)
    return e2;
  return (double)(((double)e1 + (double)e2) / 2.0);
}

// optimal- we can see binary search pattern, possible or not possible
// we decide range on the basis of n=n1+n2 like if
// n is even like n =10 then we observe a symmetry, we can divide merged array in 5- 5 elts or
// if n is odd like n=5 in that we can divide in 3-2 elts or 2-3 elts
// so some elts are from a1 and some from a2
// how we determine how many from a1 and how many from a2?
// so we decide we focus only on small size array elts, then other  elts will automatically decide from second one array
// then range=[0 to min(n1,n2)]
// how we determine it is valid or not - just by comparing cross elt
// if n is even then median=(max(l1,l2)+min(r1,r2))/2
// if n is odd then median=max(l1,l2)
// how many element on left side is determined by left=(n1+n2+1)/2 in both case means when n1+n2 is even or odd

// time complexity-O(log (min(n1,n2)) (base 2)) or we can say that O(min(logn1 (base 2),logn2 (base 2)) )
// space  complexity-O(1)
double median(vector<int> &a1, vector<int> &a2)
{
  int n1 = a1.size();
  int n2 = a2.size();
  if (n1 > n2)
    return median(a2, a1); // because we want small size array first
  int low = 0, high = n1;
  int left = (n1 + n2 + 1) / 2;
  int n = n1 + n2;
  while (low <= high)
  {
    // mid1 is for 1st array
    // mid2 is for 2nd array
    // same l1 and r1 for 1st array
    // and l2 and r2 for 2nd array
    int mid1 = (low + high) >> 1; // here we used right shift operator
    int mid2 = left - mid1;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < n1)
      r1 = a1[mid1];
    if (mid2 < n2)
      r2 = a2[mid2];
    if (mid1 - 1 >= 0)
      l1 = a1[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = a2[mid2 - 1];
    if (l1 <= r2 && l2 <= r1)
    {
      if (n % 2 == 1)
        return max(l1, l2);
      return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
    }
    else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0;
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;

  // arrays should be sorted
  // you can have array of same size or can be of different size
  // also can have duplicates element
  vector<int> arr1(n1);

  for (int i = 0; i < n1; i++)
  {
    cin >> arr1[i];
  }

  vector<int> arr2(n2);
  for (int i = 0; i < n2; i++)
  {
    cin >> arr2[i];
  }
  // double result = medianofTwoSortedArrays(arr1, arr2);
  // double result = Median(arr1, arr2);
  double result = median(arr1, arr2);
  cout << result << endl;
  return 0;
}