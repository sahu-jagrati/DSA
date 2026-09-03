// arrays are sorted and can be of different size or can be of same size and can have duplicates element

// brute and better aolution are same as median of two sorted arrays
// optimal also same but there are some change in value of low and high
// why changes because for example
// if a1.size()=6 and a2.size()=5 and k=2 then min(6,5)=5 then there is no need of 5 elts, we want only 2 elt then in that case high=min(k,min(n1,n2))
// and if k=7 if we take low=0 i.e 0 elt from maxi size array  but total n1+n2=11 and k=7 if we take all 5 elts of a2 then we also need of 2 more elt which i take from a1 so for that case we have to change low, so low =max(0,k-min(n1,n2)) if we take k=2 in that case low=(0,2-5)=(0,-3)=0 so valid in both case
// here left =k because we want only k element on left and
// answer=max(l1,l2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// time complexity-O(min(log n1(base 2),log n2(base 2)))
// space complexity-O(1)
int kthElement(vector<int> &a, vector<int> &b, int k)
{
  int n1 = a.size();
  int n2 = b.size();
  if (n1 > n2)
    return kthElement(b, a, k);
  int low = max(0, k - n1);
  int high = min(k, n1);
  int n = n1 + n2;
  int left = k;
  while (low <= high)
  {
    // mid1 is for 1st array
    // mid2 is for 2nd array
    // same l1 and r1 for 1st array
    // and l2 and r2 for 2nd array
    int mid1 = (low + high) >> 1; // same as (low+high)/2
    int mid2 = left - mid1;
    int l1 = INT_MIN;
    int l2 = INT_MIN;
    int r1 = INT_MAX;
    int r2 = INT_MAX;
    if (mid1 < n1)
    {
      r1 = a[mid1];
    }
    if (mid2 < n2)
    {
      r2 = b[mid2];
    }
    if (mid1 - 1 >= 0)
    {
      l1 = a[mid1 - 1];
    }
    if (mid2 - 1 >= 0)
    {
      l2 = b[mid2 - 1];
    }
    if (l1 < r2 && l2 < r1)
    {
      return max(l1, l2);
    }
    else if (l1 > r2)
    {
      high = mid1 - 1;
    }
    else
    {
      low = mid1 + 1;
    }
  }
  return 0;
}
int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> a(n1);
  vector<int> b(n2);
  // arrays should be sorted
  for (int i = 0; i < n1; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n2; i++)
  {
    cin >> b[i];
  }
  int k; // kth element that we have to find by merging two sorted arrays
  cin >> k;
  int result = kthElement(a, b, k);
  cout << result << endl;
  return 0;
}
