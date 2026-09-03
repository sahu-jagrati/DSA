#include <bits/stdc++.h>
using namespace std;

// by max-heap also
// t.c-O(klogn)(for while loop)+O(nlogn)(pq push)
int kthLargest(vector<int> &nums, int k)
{
  int n = nums.size();
  priority_queue<int> pq; // max-heap store elts in decreaing order- at top largest elt
  for (int i = 0; i < n; i++)
    pq.push(nums[i]);
  while (k > 1)
  {
    pq.pop();
    k--;
  }
  // when k=1 it is the elt we want access
  return pq.top();
}

// maintain heap of size k
// top=kth-largest
// t.c-O(nlogk)-  n for traverse array and logk for pq
// for kth smallest use max-heap
int findKthLargest(vector<int> &nums, int k)
{
  int n = nums.size();
  // we use priority queue - min-heap that store elt in increasing order at top smallest elt
  priority_queue<int, vector<int>, greater<int>> pq; // min-heap
  for (int i = 0; i < n; i++)
  {
    pq.push(nums[i]);
    // we remove elt from pq until the size >k when size =k we get k largest elt at top
    if (pq.size() > k)
    {
      pq.pop();
    }
  }
  return pq.top();
}

// usisng quick sort -kth smallest elt
// t.c- average-O(n)
// worst caseO(n^2) Worst case happens when pivot is always bad (like sorted array)
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = low;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
  if (low <= high)
  {
    int p = partition(arr, low, high);

    if (p == k)
      return arr[p];
    else if (p > k)
      return quickSelect(arr, low, p - 1, k);
    else
      return quickSelect(arr, p + 1, high, k);
  }
  return -1;
}

// kth largest elt
// int kLargest=n-k;
// example
// int k=2;
// int ans=quickSelect(nums,0,n-1,n-k);
// for optimization
// Use random pivot to avoid worst case:
// int randomIndex = low + rand() % (high - low + 1);
// swap(arr[randomIndex], arr[high]);

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int k;
  cin >> k;
  cout << findKthLargest(nums, k);
  return 0;
}