// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.

#include <bits/stdc++.h>
using namespace std;

// here we solve  the problem by using the problem "Largest Rectangle in Histogram" that we done with the help of stack

// In the article, Area of largest rectangle in Histogram, we have learned how to figure out the area of the largest rectangle in a given histogram. Here, in order to solve this problem, we are going to use a similar approach. Consider the following example:
// // Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

// 1  0  1  0  0
// 1  0  1  1  1
// 1  1  1  1  1
// 1  0  0  1  0

// If we carefully observe, we can convert each row of the given matrix into a histogram. Let's try it out with the first row: We can consider the first and third columns in first row to be rectangles with height 1 and the rest to be rectangles with height 0. The histogram will look like the following: heights=[1,0,1,0,0]

// Similarly, if we try for the second row, we can observe the following: heights=[2,0,2,1,1]
// The first and third colums represent rectangles of height 2, the second columns represents a rectangle of height 0 and the fourth and fifth columns represent rectangles of height 1.

// for the third row, The histogram will look like the following: heights=[3,1,3,2,2]

// and for the fourth column, The histogram will look like the following: heights=[4,0,0,3,0].

// Similarly, following the same process, we can convert every row of any matrix into a histogram. Now, if we pass each histogram(i.e Each row) to the function used in finding the Area of the largest rectangle in Histogram, it will give us the maximum area for each histogram. Among all the answers to the histograms that we get from each row, we will consider the maximum one.

// Create an array to store heights of histogram bars, one for each column in the matrix.

// Traverse the matrix row by row and for each cell in the row:
//  i) If the value is '1', increase the height  at that column by 1.
//  ii) If the value is '0', reset the height at that column to 0.

// After updating the histogram for the current row, calculate the largest rectangle area in that histogram.

// Keep track of the maximum area seen so far across all rows. After processing all rows, the stored maximum will be the area of the largest rectangle consisiting of only 1s.

// code from the problem "Largest Rectangle in Histogram" for understanding code see this problem
// for this function
// t.c-O(m)(for traversing)+O(m)(for throughout the process to maintain the stack ), there is not O(m^2) because every time we are not removing every elt from the stack hence O(m)+O(m)=O(2m)
// s.c-O(m) for stack
int largestRectangleArea(vector<int> &heights)
{
  int m = heights.size();
  // stack to store indexes of heights in where heights are in linearly increasing order, it is monotonic stack
  stack<int> st;
  int maxArea = 0;
  // we go one with n iteration instead of (0 to n-1) we go (0 to n)
  for (int i = 0; i <= m; i++)
  {
    // we compare the current height with the top of the stack and if st.top() has greater height than current than we calculate area for it and pop it from the stack else if st.top() has smaller height than current then we do nothing we just put current in the stack
    // and if i==n then we do nothing we just pop from stack and calculate area for those heights
    while (!st.empty() && (i == m || heights[st.top()] >= heights[i]))
    {
      int height = heights[st.top()];
      st.pop();
      int width;
      // if stack is empty means there is no left smaller means left smaller index=0 so in that case width is total right smaller index which is current index
      if (st.empty())
        width = i; // where i is the current index so i is the right smaller index for st.top() index
      else
        width = i - st.top() - 1; // where i is right smaller index and st.top() is left smaller index
      maxArea = max(maxArea, height * width);
    }
    // we push current height index in stack when in stack at top we have smaller height than current we do nothing we just put it in stack and move to next so with the help of stack we can maintain the linearly increasing order and whenever we get elts  that are greater we can just compute the area for that and pop it from the stack that we do in while loop
    st.push(i);
  }
  return maxArea;
}

// t.c-
// we traverse each row
// and for each row first we update the heights array and then we calculate the area for that histogram so for each row we have - O(m)(for update heights array)+O(2m)(for calculating area for histogram)
// and we have total n rows so total t.c-O(n*(m+2m)) where n=total no.of rows and m = total no. of columns
// s.c-O(m)(for heights array)+O(m)(for stack use in calculating area)
int maximalRectangle(vector<vector<char>> &matrix)
{
  // return 0 if matrix is empty
  if (matrix.empty())
    return 0;
  int m = matrix[0].size();
  // heights array to build histogram row-wise
  vector<int> heights(m, 0);
  int maxArea = 0;
  // traverse each row of the matrix
  for (auto &row : matrix)
  {
    // update histogram based on current row
    // current row has m columns
    for (int i = 0; i < m; i++)
    {
      if (row[i] == '1')
        heights[i]++;
      else
        heights[i] = 0; // reset when it is '0'
    }
    // compute area for this histogram
    maxArea = max(maxArea, largestRectangleArea(heights));
  }
  return maxArea;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> matrix(n, vector<char>(m)); // having only '0' and '1'
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> matrix[i][j];
    }
  }
  cout << maximalRectangle(matrix);
  return 0;
}