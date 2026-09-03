// if the code become longer then break it in function

#include <iostream>
#include <vector>
using namespace std;

// 1. given row and column, find the element of that place
// time complexity-O(r)=O(col-1) or if we use proper formula then O(n)+O(r)+O(n-r)
// space complexity-O(1)
int combinationfunction(int row, int col)
{
  int n = row - 1;
  int r = col - 1;
  long long result = 1;
  for (int i = 0; i < r; i++)
  {
    result = result * (n - i);
    result = result / (i + 1);
  }
  return result;
  cout << " ";
}

// 2. print any Nth row of pascal triangle - Nth row has N no. of element
//  i) solution by using combinationfunction - time complexity-O(row*r) where r = col-1 which is different for each row
// space complexity-O(1)
void printRow(int row)
{
  for (int col = 1; col <= row; col++)
  {
    cout << combinationfunction(row, col);
    cout << " ";
  }
}

// ii) solution is by using previous answer make a relation with row and col
// time complexity-O(row)
// space complexity-O(row) for returning the answer not for solving the problem
vector<int> printrow(int row)
{
  long long ans = 1;
  vector<int> ansRow;
  ansRow.push_back(1);

  for (int col = 1; col < row; col++) // why col less than row because if col=row then row-col=0 and denominator can't be zero and also be start with ans=1 that is already pushback back row number decide how many element inside it like row=4 there is 4 col also inside it
  {
    ans = ans * (row - col);
    ans = ans / col;

    ansRow.push_back(ans);
  }
  return ansRow;
}

// 3. given N, print the pascal triangle
// i) solution by using combination function- time complexity-approx.O(N*N*r) where r=col-1
// space complexity for solving problem is nothing but for returning/storing the answer is O(ans.size())=O(N^2)
vector<vector<int>> printTriangle(int N)
{
  vector<vector<int>> ans;
  for (int i = 1; i <= N; i++)
  {
    vector<int> temp;
    for (int col = 1; col <= i; col++)
    {
      temp.push_back(combinationfunction(i, col));
    }
    ans.push_back(temp);
  }
  return ans;
}

// ii) solution is by using ii)solution of 2nd questiion
// time complexity-O(N*N) because N times outer for loop run and print row run approx N times beacuse N no. of row has N elements
// space complexity- for solving the problem O(1) butb for returning/storing the answer O(result.size())=O(N^2) approx.
vector<vector<int>> printPascalTriangle(int N)
{
  vector<vector<int>> result;
  for (int i = 1; i <= N; i++)
  {

    result.push_back(printrow(i));
  }
  return result;
}
int main()
{
  int row, col;
  cin >> row >> col;
  int N;
  cin >> N;
  int result = combinationfunction(row, col);
  cout << result << endl;
  // printRow(row);
  vector<int> res = printrow(row);
  for (auto it : res)
  {
    cout << it << " ";
  }
  cout << endl;
  // vector<vector<int>> print = printTriangle(N);
  vector<vector<int>> print = printPascalTriangle(N);
  for (const auto &it : print)
  {
    for (auto val : it)
    {
      cout << val << " ";
    }
  }
  cout << endl;
  return 0;
}