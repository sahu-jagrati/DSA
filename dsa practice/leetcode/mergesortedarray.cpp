// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n

#include <iostream>
#include <vector>
using namespace std;

// time complexity-O(m+n)
//  space complexity-O(1)  we do not use extra space, we modify nums1
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int left = m - 1;
  int right = n - 1;
  int i = m + n - 1;
  while (left >= 0 && right >= 0)
  {
    if (nums1[left] > nums2[right])
    {
      nums1[i] = nums1[left];
      i--;
      left--;
    }
    else
    {
      nums1[i] = nums2[right];
      i--;
      right--;
    }
  }
  // if elements remain in nums2
  while (right >= 0)
  {
    nums1[i] = nums2[right];
    i--;
    right--;
  }
}
int main()
{
  int m, n;
  cin >> m >> n;
  vector<int> nums1(m + n);
  vector<int> nums2(n);
  for (int i = 0; i < m; i++)
  {
    cin >> nums1[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> nums2[i];
  }
  merge(nums1, m, nums2, n);
  for (int i = 0; i < m + n; i++)
  {
    cout << nums1[i] << " ";
  }
  cout << endl;
  return 0;
}