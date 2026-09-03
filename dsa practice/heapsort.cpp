#include <bits/stdc++.h>
using namespace std;

// Function to maintain the max-heap property for a subtree rooted at index i
void maxHeapify(vector<int> &arr, int n, int i)
{
  int largest = i;       // Assume current index is largest
  int left = 2 * i + 1;  // Left child
  int right = 2 * i + 2; // Right child

  // If left child exists and is greater than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child exists and is greater than current largest
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root, swap and continue heapifying
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    maxHeapify(arr, n, largest);
  }
}

// Function to build a max heap from an unsorted array
void buildMaxHeap(vector<int> &arr, int n)
{
  // Start from last non-leaf node and heapify each node
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    maxHeapify(arr, n, i);
  }
}

// Heap Sort function
void heapSort(vector<int> &arr)
{
  int n = arr.size();

  // Step 1: Build a max heap
  buildMaxHeap(arr, n);

  // Step 2: Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);  // Move current max (root) to the end
    maxHeapify(arr, i, 0); // Heapify the reduced heap
  }
}

// Utility function to print an array
void printArray(const vector<int> &arr)
{
  for (int x : arr)
    cout << x << " ";
  cout << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 7};

  cout << "Original array:\n";
  printArray(arr);

  heapSort(arr);

  cout << "Sorted array (using Heap Sort):\n";
  printArray(arr);

  return 0;
}
