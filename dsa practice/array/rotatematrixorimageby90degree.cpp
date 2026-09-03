// rotate clockwise

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute approach- time complexity-O(n^2)
// space complexity-O(n^2) because of temp array
vector<vector<int>> rotatematrix(vector<vector<int>> &arr, int n)
{
  vector<vector<int>> temp(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // if we write arr[i][j]=arr[j][n-1-i] there should be a overwrite which is not a safe transformation
      // temp[i][j] = arr[n-1-j][i];
      temp[j][n - 1 - i] = arr[i][j];
    }
  }
  return temp;
}

// optimal approach-first we transpose the matrixe and then reverse it row wise
// time complexity-O(n)+O(n)=O(n)
// space complexity-O(1)
void rotateMatrix(vector<vector<int>> &arr, int n)
{
  // this is not coorect because it swap some elts. twice like first swap arrr[1][2] with arr[2][2] and again arr[2][1]with arr[1][2]
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     if (i != j)
  //     {
  //       swap(arr[i][j], arr[j][i]);
  //     }
  //   }
  // }
  // transpose- Transpose the matrix (swap only upper triangle)
  // you can also go from 0 to n in both loop but take more time complxity which is O(n^2) but in this we get
  // time complexity-O(n/2+n/2)=O(n)
  for (int i = 0; i <= n - 2; i++)
  {
    for (int j = i + 1; j <= n - 1; j++)
    {
      swap(arr[i][j], arr[j][i]);
    }
  }
  // we have to do reverse row wise-
  // for (int i = 0; i < n/2; i++)
  // {
  //   int temp = arr[i];  // arr[i ] is a vector, you cannot assign to int
  //   arr[i] = arr[n - 1 - i];
  //   arr[n - 1 - i] = temp;

  // }
  // here time complexity is -O(n)+O(n/2)(this is for reversing)=O(n)
  for (int i = 0; i < n; i++)
  {
    reverse(arr[i].begin(), arr[i].end());
  }
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  // vector<vector<int>> result = rotatematrix(arr, n);
  // for (const auto &ans : result)
  // {
  //   for (auto it : ans)
  //   {
  //     cout << it << " ";
  //   }
  //   cout << endl;
  // }
  rotateMatrix(arr, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}