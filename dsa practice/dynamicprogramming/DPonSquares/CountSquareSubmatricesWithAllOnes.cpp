// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix =
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation:
// There are 6 squares of side 1.
// There is 1 square of side 2.
// Total number of squares = 6 + 1 = 7.

// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1

#include <bits/stdc++.h>
using namespace std;

// for an example we have
// Input: matrix =
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]

// if we count square submatrices then
// for size 1 we have 6 squres
// for size 2 we have 1 square
// for size 3 we have 0 square
// so total we have 7 square submatrices

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]

// if we count square submatrices then
// for size 1 we have 10 squares
// for size 2 we have 4 squares
// for size 3 we have 1 square
// so total we have 15 square submatrices

// brute force is that for each cell we check how many square it's made if cell value is 1
// for an example we have matrix =
//   [1,1,1],
//   [1,1,1],
//   [1,1,1]

// for cell1 we have 3 squares it is possible only when cells have value=1
// for cell2 we have 2 squares
// for cell3 we have 1 square
// for cell4 we have 2 square
// for cell5 we have 2 squares
// for cell6 we have 1 square
// for cell7 we have 1 square
// for cell8 we have 1 square
// for cell9 we have 1 square
// so total we have 3+2+1+2+2+1+1+1+1=14 squares

// but this solution is very complex this is good for just telling in interview but it's very complex to write so just tell this in interview how we approach only
// // you don't have to code it in an interview you just have to say that this is what I'm thinking they'll ask you to code it because the code will be very very complex that's a brute force solution where we stand at a particular cell and we try to expand it

// now optimize solution- dynamic programming

// till now all the dp solutions that we have done was based on recursion, over here we can apply recursion but that is not intutive, generically in all square problems we tend to write the tabulation that is much more intutive and we'll understand why is that much more intutive we will try to write the tabulation format so what we do is?

// generically in all the square problems, we create the smiliar size of dp array that is given in matrix
// for an example  we have matrix =
//   [1,1,1],
//   [1,1,1],
//   [1,1,1]

// so we create dp matrix of size 3*3
// and what we state is dp[i][j] like i is from 0 to n-1 and j is from 0 to m-1 so here in this example i is from 0 to 2 and j is from 0 to 2
// now whatever value is here in dp that basically states how many squares end at (i,j) i.e dp[i][j] signifies that how many squares end at (i,j) like the right bottom is at (i,j) here right bottom means that upto that cell (i,j) how many squares we have

// for an above example if we ask for a cell (0,0) how many squares will end at (0,0) being the right bottom I can say only he himself so there'll be only 1 square so dp[0][0]=1 who say that I will be the right bottome which is this guy himself

// for (0,1) how many squares end at (0,1) like the right bottom is at (0,1)   means that upto that cell (0,1) how many squares we have only 1 which is himself because [1,1] is not a square it is a rectangle  so himself will be only a right bottom  upto (0,1) so dp[0][1]=1

// for (0,2)  how many squares end at (0,2) like the right bottom is at (0,2)   means that upto that cell (0,2) how many squares we have only 1 which is himself because [1,1,1] or [1,1] is not a square they are rectangles   so himself is only square upto (0,2) so dp[0][2]=1

// similarly for(1,0)  how many squares end at (1,0) like the right bottom is at (1,0)   means that upto that cell (1,0) how many squares we have only 1 which is himself  so dp[1][0]=1 because in vertical we have rectangle so he himself will be the right bottom

// for(2,0)  how many squares end at (2,0) like the right bottom is at (2,0)   means that upto that cell (2,0) how many squares we have only 1 which is himself  so dp[2][0]=1 because he himself will be the right bottom

// so we are sure that first row and first column gets copied from given matrix because there is the single elements that are single elements who will be the square

// so now if we ask you for right bottom (1,1) how many squares ? 1 square is he himself and other one is this [[1,1],[1,1]] where he is the right most bottom guy so I can say dp[1][1]=2

// now for right bottome (1,2) how many squares ? 1 he is himself where he is the right bottom guy and the other is [[1,1],[1,1]] start from [[(0,1),(0,2)],[(1,1),(1,2)]] where (1,2) is the right bottom so dp[1][2]=2

// for this (2,1) right bottom how many squares? 1 he is himself where he is the right bottom guy and the other is [[1,1],[1,1]] start from [[(1,0),(1,1)],[(2,0),(2,1)]] where (2,1) is the right bottom so dp[2][1]=2 we want those square whose right bottom is (2,1)

// now for (2,2) right bottom how many squares? 1 he is himself where he is the right bottom guy and the other is [[1,1],[1,1]] start from [[(1,1),(1,2)],[(2,1),(2,2)]] where (2,2) is the right bottom and the other one is [[1,1,1],[1,1,1],[1,1,1]] start from [[(0,0),(0,1),(0,2)],[(1,0),(1,1,),(1,2)],[(2,0),(2,1),(2,2)]] where (2,2) is the right bottom so dp[2][2]=3 we want those square whose right bottom is (2,2)

// dp=[[1,1,1],[1,2,2],[1,2,3]]

// so I know at every junction I have squares so how do I fill up this dp table is my question because I know for every guy how many squares are there and I need the total so I can probably 1+1+1+1+2+2+1+2+3=14 if I sum it up all I'll get all the squares that we can form because we are assuming every giy to be the square bit like the right bottom so but how do we fill up this dp table because manually looking we understand that okay

// so for that what I'll do is I'll take the next example and try to fill the dp table
// // for an example  we have matrix =
//   [1,1,1,1],
//   [1,1,1,1],
//   [1,1,1,1]

// we have n=3 and m=4 so we create dp of 3*4

// so as I know first row and first column of dp will be the copy of given matrix so first row will be : dp[0][0]=1,dp[0][1]=1,d[0][2]=1,dp[0][3]=1 and first column will be: dp[1][0]=1,dp[2][0]=1,d[3][0]=1

// now over here (1,1) cell can I see if this (0,1) is forming 1 square and (1,0) is forming 1 square and (0,0) is forming 1 saqure if I add a 1 i.e cell(1,1) that's bound to form one more square okay so that's dp[1][1]=2

// now over here (1,2) cell Can I see if this (0,2) is forming 1 square and (1,1) forming 2 square but if I attaches  a 1 i.e a cell (1,2) then this will be a rectangle and this (0,1) is forming a 1 sqaure so Can I say I don't need to take this 2 i.e (1,1) cell because this on attaching will be a rectangle but what I can do is since (0,2) is forming 1 sqaure and (0,1) forming 1 square and I am very much sure if (1,1) is forming a 2 square this will also form a 1 square thereby can I say I'll take the minimal of this min((0,1),(0,2),(1,1)) cell which is 1 and do a plus one for (1,2) cell for himself is that will be two so dp[1][2]=2

// now over here (1,3) cell same logic happen here also that we done in (1,2) : Can I see if this (0,3) is forming 1 square and (1,2) forming 2 square but if I attaches  a 1 i.e a cell (1,3) then this will be a rectangle and this (0,2) is forming a 1 sqaure so Can I say I don't need to take this 2 i.e (1,2) cell because this on attaching will be a rectangle but what I can do is since (0,3) is forming 1 sqaure and (0,2) forming 1 square and I am very much sure if (1,2) is forming a 2 square this will also form a 1 square thereby can I say I'll take the minimal of this min((0,2),(0,3),(1,2)) cell which is 1 and do a plus one for (1,3) cell for himself is that will be two so dp[1][3]=2

// similarly for over (2,1) cell : there is 2 sqaure for (1,1) and 1 square for (1,0) and 1 sqaure for (2,0) so can I say again the minimal of all and plu 1 for (2,1) himself so dp[2][1]=2

// now over (2,2) cell : this guy (1,1) form 2 sqaure and this guy also (1,2) also form 2 square and (2,1) also form 2 squares and these form sqaures because all of them are filled with 1's so I can assume we see all of these are filled with ones so if I attach one more one for himself I know I'll form a sqaure of size 3 so dp[2][2]=3

// now over here cell (2,3): I see  (1,3) form 2 squares and (1,2) form 2 squares and (2,2) form 3 squares but this guy (2,3) at max form 3 squares if we see so we take minimal of ((1,3),(1,2),(2,2)) which is 2 and attach 1 for (2,3) himself so it was 2 and I am adding 1 so that's 3 so dp[2][3]=3

// so dp=[
// [1,1,1,1]
// [1,2,2,2]
// [1,2,3,3]
//]
// so total squares will be 1+1+1+1+1+2+2+2+1+2+3+3=20

// if I take another example : matrix =
//   [1,1,0],
//   [1,1,1],
//   [1,1,0]
// we create dp of 3*3
// and copy first row and first column
// dp=[
// [1,1,0]
// [1,]
// [1,]
//]

// in order to fill this dp[1][1] we take this (0,1),(0,0),(1,0) and take the minimal and if the current cell is 1 then we add one to the minimal so there's one for (1,1) so we add 1 to the minimal which is also 1 so dp[1][1]=2
// now for (1,2): we take (0,2),(0,1),(1,1) and take the the minimal which is 0 and current cell is 1 sn we atke 0+1 because he (1,2) will be himself only the square so dp[1][2]=1
// now for (2,1): we take (1,1),(1,0),(2,0) and take minimal which is 1 and for currenct cell we have 1 so add 1 to 1 we have dp[2][1]=2
// now for (2,2): which is 0 so can't amke square so dp[2][2]=0

// so can I say if matrix[i][j]==0 then dp[i][j]=0 becuase it cannot make a square
// if matrix[i][j]==1 then dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1, we do +1 for himself

// we do with tabuation because here in this problem tabulation is more intutive then recursion

// t.c-O(m)+O(n)+O(n*m)*2=O(n*m)
// s.c-O(n*m) for dp
int countSquares(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  // create dp of size n*m
  vector<vector<int>> dp(n, vector<int>(m, 0));
  // copy the first row as it is from matrix
  for (int j = 0; j < m; j++)
    dp[0][j] = matrix[0][j];
  // copy the first column as it is from matrix
  for (int i = 0; i < n; i++) // here you can skip i=0 because we already done in above roop (0,0)
    dp[i][0] = matrix[i][0];
  // traverse for rest of the cell
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (matrix[i][j] == 0)
        dp[i][j] = 0; // because it cannot make a square for sqaure we want 1
      // when we have 1
      else
      {
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])); // +1 for himself
      }
    }
  }
  // now find total square we can take sum with above computation also
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      sum += dp[i][j];
    }
  }
  return sum;
}

// for cimputing sum with simultaneously
int CountSquares(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  int sum = 0;
  for (int j = 0; j < m; j++)
  {
    dp[0][j] = matrix[0][j];
    sum += dp[0][j];
  }
  // here we start with 1 because we compute sum simultaneously so if we atke here i=0 then it count two times because in above loop we already done with (0,0)
  for (int i = 1; i < n; i++)
  {
    dp[i][0] = matrix[i][0];
    sum += dp[i][0];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (matrix[i][j] == 0)
        dp[i][j] = 0;
      else
      {
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
      }
      sum += dp[i][j];
    }
  }
  return sum;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> matrix[i][j];
    }
  }
  cout << countSquares(matrix);
  return 0;
}