// given- in this you have an image in form of n*m matrix with entity 0/1/2 and so on, given startin row(sr) and starting column(sc) and new color, so go to (sr,sc) in image and change its pixel or value with newcolor and those who are connected with this and having same value as of (sr,sc) also change it's value with newcolor and their connectives with same value also change their value with newcolor so on

// you can move only in four directions-left,right,up,down

// first we make copy of given image because always remind that in engineering we do nothing with input data, we copy it and do process on that copy data

#include <bits/stdc++.h>
using namespace std;

// let we have N*M no of nodes and if in worst case all have same iniColor and for each we move in 4 direction, let N*M=X
// t.c-O(X)(for dfs traversal X times)+ O(X*4)(for every X we run 4 times )= approx O(X)=O(N*M)
// s.c-O(N*M(for storing answer)+O(N*M) for recursion stack space of dfs in worst case +O(4*2) for delRow and delCol
class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor, vector<int> &delRow, vector<int> &delCol)
  {
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;
    // we move only in four direction so number of neighbours are 4
    for (int i = 0; i < 4; i++)
    {
      int neighbourRow = row + delRow[i];
      int neighbourCol = col + delCol[i];
      if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && image[neighbourRow][neighbourCol] == iniColor && ans[neighbourRow][neighbourCol] != newColor)
      {
        dfs(neighbourRow, neighbourCol, ans, image, newColor, iniColor, delRow, delCol);
      }
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image; // copy input

    // for going in four direction we use this
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, newColor, iniColor, delRow, delCol);

    return ans;
  }
};
// input type-image-{{1,1,1},{2,2,0},{2,2,2}} and sr=2,sc=0,newColor=3
int main()
{
  int n, m;
  cout << "Enter the row and column size: ";
  cin >> n >> m;
  vector<vector<int>> image(n, vector<int>(m));
  cout << "Enter the row and column value (it can be any number): ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> image[i][j];
    }
  }
  int startRow, startCol, newColor;
  cout << "Enter startrow,startcol,newcolor value: ";
  cin >> startRow >> startCol >> newColor;
  Solution result;
  vector<vector<int>> answer = result.floodFill(image, startRow, startCol, newColor);
  for (auto row : answer)
  {
    for (auto it : row)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}