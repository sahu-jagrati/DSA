#include <bits/stdc++.h>
using namespace std;

// Brute force

// t.c
// inserting elts - we have total (n^2) elts and each insertion costs O(log(n^2))=O(log(n)) so total O((n^2)(log n))
// popping k-1 elts
// each pop costs: O(log(n^2))=O(log(n)) so total : O(k log n)
// total t.c-O(((n^2)(log n))+klogn)
// since k<= (n^2) so total t.c is written as: O((n^2)(log n))

// s.c-O(n^2) because heap stores all elts

// but this is not optimal solution
int kthSmallest(vector<vector<int>> &matrix, int k)
{
  int n = matrix.size();
  priority_queue<int, vector<int>, greater<int>> min_pq; // min-heap store elts in increasing order- at top smallest elt

  // first we push all elts in min_pq
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      min_pq.push(matrix[i][j]);
    }
  }
  while (k > 1)
  {
    min_pq.pop();
    k--;
  }
  // when k=1 it is the elt we want access
  return min_pq.top();
}

// above solution is not optimal because The matrix is already sorted by rows and columns. Our solution ignores this property and treats it as an unsorted array.

// A better heap-based solution stores only one element from each row, reducing:

// Time: O(k log n)
// Space: O(n)

// The most optimal solution uses binary search on the value range, achieving:

// Time: O(n log(maxValue − minValue))
// Space: O(1)

// Better solution by using min-heap
// heap-based solution stores only one element from each row, reducing:

// Time: O(k log n)
// Space: O(n)

// the key idea is that we have each row sorted so we don't need to insert all n^2 elts into the heap

// given a matrix where every row is sorted and every column is sorted

// why does this work?
// At any time, the heap contains the smallest unprocessed element from each row.

// complexity:
// matrix size is n*n
// heap size: At most n elements (one per row)
// initial insertion: n pushes - O(n log n)
// loop: runs k-1 times Each iteration performs one pop and at most one push, each costing O(log n).
// so total : O(nlogn + klogn)
// since typically k>=n so t.c-O(klogn)
// s.c-O(n) for heap because the heap never stores more than one active element from each row.
int KthSmallest(vector<vector<int>> &matrix, int k)
{

  int n = matrix.size();

  // here pq stores vector<int>, not just integers
  // where vector<int> contains 3 elts -{value,row,column}
  // value =the matric elt
  // row=row index
  // column - column index
  // so we insert only one element from each row and column =0

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // min-heap

  // push in pq
  // insert the first elt of every row
  // why only first column? because every row is sorted.
  // example: 1 5 9 If 1 hasn't been removed yet then 5 9 cannot possibly be the smallest. so we only keep the first unseen elt of each row
  for (int i = 0; i < n; i++)
  {
    pq.push({matrix[i][0], i, 0});
  }

  // suppose k=8 then --k=7 so loop runs 7 times meaning removing the smallest 7 elts and the next top will be the 8th smallest

  while (--k)
  {
    auto cur = pq.top();
    pq.pop();

    int val = cur[0];
    int row = cur[1];
    int col = cur[2];

    // insert next elt from same row
    //  for example we have row : 1 5 9 so we removed 1 next candidate becomes 5 so push {5,0,1} means next elt from row=0 having col=1
    if (col + 1 < n)
    {
      pq.push({matrix[row][col + 1], row, col + 1});
    }
  }
  return pq.top()[0];
}

// optimal solution: Binary Search
// Binary search on the value range instead of indices.

// For each middle value, count how many numbers are <= mid.

// Time: O(n log(maxValue-minValue))

// Space: O(1)

// It uses binary search on the answer, not on the indices.
// we're not searching the matrix directly. Instead, we're searching the range of possible values.

// and the possible range of answer  is smallest elt of matrix to largest elt of matrix and in given matrix every row and colum is sorted so smallest possible answer is matrix[0][0] and largest possible answer is matrix[n-1][n-1] so range of answer is : [matrix[0][0]...matrix[n-1][n-1]]
// example
// matrix - [[1 5 9],[10 11 13], [12 13 15]]
// answer range [1...15]  we binary search the values between 1 and 15.
int kthsmallest(vector<vector<int>> &matrix, int k)
{
  int n = matrix.size();

  int low = matrix[0][0];
  int high = matrix[n - 1][n - 1];

  while (low < high)
  {
    int mid = low + (high - low) / 2;

    int count = 0;
    // we start from the bottom-left corner because from the bottom-left:
    // moving up decreases values
    // moving right increases values
    // That lets us eliminate an entire row or column in one step.
    int row = n - 1;
    int col = 0;

    while (row >= 0 && col < n)
    {
      // Since columns are sorted, if matrix[row][col] <= mid, then everything above it in the same column is also ≤ mid.
      if (matrix[row][col] <= mid)
      {
        // Why does count+=row+1 work?
        // suppose in above example current cell=11
        // and mid=12 since 11<=12  everything above it in the same column is also ≤12.
        // column 5 11 that's row+1=2 Instead of checking one by one, we add both at once:count+=row+1 Then move right to the next column.
        count += row + 1;
        col++;
      }
      else
      {
        row--;
      }
    }
    if (count < k)
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  int k;
  cin >> k;
  // cout << KthSmallest(matrix, k);
  cout << kthsmallest(matrix, k);
  return 0;
}