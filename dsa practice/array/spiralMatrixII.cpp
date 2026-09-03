// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

// Example 1:

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20

#include <bits/stdc++.h>
using namespace std;

// t.c- outer while loop and all inner loop together traverse each elt so
// t.c-O(n*n)
// s.c-O(n*n) which is required for return an answer
vector<vector<int>> generateMatrix(int n)
{
  vector<vector<int>> matrix(n, vector<int>(n));
  int num = 1; // because elt in matrix is from 1 to n^2
  int left = 0, right = n - 1;
  int top = 0, bottom = n - 1;
  while (left <= right && top <= bottom)
  {
    // move left to right
    // row is fix here now which is top
    for (int i = left; i <= right; i++)
    {
      matrix[top][i] = num;
      num++;
    }
    // move top to bottom
    // col is fix here now which is right
    top++;
    for (int i = top; i <= bottom; i++)
    {
      matrix[i][right] = num;
      num++;
    }
    // move right to left
    right--;
    // but for this we have to check top<=bottom
    // row is fix here now which is bottom
    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        matrix[bottom][i] = num;
        num++;
      }
      bottom--;
    }
    // move bottom to top already decrease bottom above
    //  but we have to check left<=right
    // col is fix here now which is left
    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        matrix[i][left] = num;
        num++;
      }
      left++;
    }
  }
  return matrix;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix = generateMatrix(n);
  for (auto it1 : matrix)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}