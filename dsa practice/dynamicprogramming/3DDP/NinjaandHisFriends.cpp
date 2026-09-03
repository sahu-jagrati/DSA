// We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙). When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once. They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect.

// Example 1:
// Input: ‘R’ = 3, ‘C’ = 4 // rows and columns given
// ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
// Output: 21

// Example 2:
// Input: ‘R’ = 2, ‘C’ = 3
// ‘GRID’ = [[4, 1, 2], [7, 3, 5]]
// Output: 18

// question in more summarize way
// Ninja has a 'Grid' of size N*M. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

// Initially, Alice is in the top-left position i.e (0,0), and Bob is in the top-right place i.i (0,M-1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will became zero. If both stay in the same cell, only one of them will pick the chocolates in it.

// If Alice or Bob is at (i,j) then they can move to (i+1,j), (i+1,j-1), or (i+1,j+1). They will always stay inside the 'Grid'.

// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

// example-
//         alice         bob stand there
//           2   3    1    2
//           3   4    2    2
//           5   6    3    5

// how many ways like how can you reach the last row and what is the maximum path(chocolate) some alice can give you and bob can give you

// Alice take - 2+4+6=12
// Bob take - 2+2+5=9
// total maximum chocolates we can have = 12+9=21

// now remember this uh there is this edge case like assume the cells are like this and alice and bob started so alice took this path for an example and bob took this path so if there is a cell which is common in both the path so it will just be counted once okay

// Intuition

// we have fixed starting point

// but we have variable ending point because you don't know where you will end, there can be multiple points of ending because you know it's gonna end at the last row but both of alice and bob can end anyway but we definitely know alice starts at (0,0) and bob starts at (0,m-1) that is something which we definitely know.

// Now will greedy work?
// Obivously not. Why? we have talked about this uniformity nature. Did uniformity nature greedy doesn't work because it might happen, you consider someone in a path but if you would have considered other path then in the future you would have got a bigger value so since the values are not uniform someone is small someone is growing someone is very less so don't know how is the values so due to uniformity greedy cannot be applied so if greedy cannot be applied what does come to your brain ?

// (all paths by alice + all paths by bob) together if i can together take them and making sure that if there is any common one and then i'll consider it as one if i can together take it then whatever is the maximum will be my answer

// so how do you generate all paths? recursion

// And we have to make sure alice and bob move together why because it might happenthere is a common cell that alice and bob passes so you have to consider it at once that's why it's very very important that you don't be like okay let's do the alice one and get the  maximum sum for alice then do the bob one and get the maximums up for bob and then just sum it up that can be done but then you have to trace the path then you have to subtract if there is anything common so it will be a very long process if you follow that path so instead of individually doing it i hope you understood why can't we do it individually because there might be a cell in common then you have to trace back the path and then you have to omit that common cell so that's something which we will not do because there might be a lot of common cells so what we will do is we will try to write a recursion together .

// Recursion rules:
// we known already recursion rules-

// 1. express everything in terms of index - i and j
// now there are two guys you are combining couple of recursions that is alice so for alice you can say (i1,j1)
// and then there is bob that's (i2,j2) so i can say that express everything in terms of i1 j1 and i2j2 that's the first thing and write down all the base cases.

// 2. explore all the paths

// how many paths are there?
// there are three ways-one is straightforward down, left diagonal, right diagonal

// 3. return the maximum sum possible

// Something to observe we are having a fixed starting point and generically when we have a fixed starting point and a variable ending point because we know it can end at any column in the last row so if there is a fixed starting point and a variable ending point we generally tend to write recursion from starting point and then going to ending point this we also done in problem TriangleSame

// since we have a fixed starting point I will always recommend you to not think so much and directly start from fixed starting point the problem can be solved in the other way yes it can be solved in the other way but i will always recommend you to not go that path so thereby we will write a recursion that starts from starting point so can i  say the starting point will be f(0,0,0,m-1) where (0,0) is the alice position and (0,m-1) is the bob's position so this is what alice is standing at and this is where the bob is standing at correct so we can start off with taking these four parameters so why don't we take these four parameters so let's take it

// f(i1,j1,i2,j2){ where (i1,j1) for alice and (i2,j2) for bob

//  now what are the base cases ?
// let's analyze what can be the base cases so if i'm thinking of what can be the future the future can we explore all the paths and it's a matrix if i'm exploring all the paths i might go left so i might just cross left boundary, i might go right so i might cross this right boundary
// will it have anything alse? i might cross this last row but i can say this is my base case or the destination so i should not care so much
// now can i say this that if I cross the boundary in the left or if i cross the boundary in the right then that path will not be considered make sense so base case can be of two types

// base case - i) destination base case ii) out of bound

// so always write the out of bound first so can i say the outer bound is if alice might cross left boundary or might cross right boundary  or bob might cross

// first base case
// if(j1<0||j1>=m||j2<0||j2>=m)return -1e8 // very negative value because we want maximum and  if we return  INT_MIN now it will get added up to some integer, if that integer is negative so negative plus integer will go beyond the limits of integer thereby it will give you wrong answers so that's why i always recommend you to probably return something -1e8 when we want maximum or if we want answer minimum then return 1e8 or probably you can just convert that into long if you're wanting to return INT_MIN so  that's a that's a specific way why i don't return into being because on addition of entertainment to a negative integer it will go out of bound that says the shuttle reason so we have written uh the first base case which is out of bound

// ii) base case
// what is the destination
// i know one thing for sure now over here there is a case to consider alice is moving bob is also moving will both of them reach the destination at the same time is my question to you you'll be like yeah both of them will definitely reach the destination at the same time why let's analyze so what are the movements given up this no matter what you do no matter in which column. you go at every step you will move to the next row at the next step you will move to the next row be it alice or be it bob you will move to the next row that is for sure do you agree you do agree initially there where at the zeroth row next movement they will move to the first row next movement they will move to the second row together alice and bob will move to the next rows so i can say instead of maintaining i1 and i2 can't I write a single i

// because i(row) will be same only the columns will change but they will move to row simultaneously i'll be like yeah so what i'll do is I now just store a i instead of storing i1 and i2 let's have a common i
// so alice-(i,j1) and bob-(i,j2) so I have maintained i've just omitted one extra variable which because both of them were carrying similar values so can I say if i reaches uh the last row which is (n-1)
// so instead of f(i1,j1,i2,j2) we write f(i,j1,j2)
// if(i==n-1){
// now there are still a lot of things to think you just cannot return uh the alice's cell and bob's cell you have to think what do you have to think if i have reached the last cell alice would have reached to some column bob would have reached to some column make sense now assume alice and bob reaches last row but different columns so we simply added but what if alice and bob reaches same column in last row then it will only be added once
// if(j1==j2)return matrix[i][j1]; // or you can write j2
// else return matrix[i][j1]+matrix[i][j2]

// the destination has been written remember in this question you have to always think always think in deep because there is a condition as common you have to always write cases thinking those stuff what happens when you reach common
//}

// so we have done with the express everything in terms of i and j now next we explore all the paths so can i say this is nothing but (i+1,j),(i+1,j-1), or(i+1,j+1) these are the three directions

// now if we assume matrix alice is somewhere and bob is somewhere but in same row and can be in different column, i repeat in one step move alice and bob both together  because you're writing a recurrence together so you need to make sure that they move simultaneously that is very important so how do you make sure in one step they move alice and bob simultaneously that's very important now you'll be like there are three direction so there are nine combos can be possible
// 1. if alice move left diagonally then bob can have three different movements i) left diagonally ii) straight down iii) right diagonally
// 2. if alice move straight down then also  bob can have three different movements i) left diagonally ii) straight down iii) right diagonally
// 3. if alice move right diagonally then also bob can have three different movements i) left diagonally ii) straight down iii) right diagonally
// so you can say for every movement of alice there are three movements for bob
// can i say total there will be 3*3=9 combos of paths
// how can you try nine combos now one of the ways is you write all the nine like all the nine combos individually or probably we can do some trick here

//  let's think of this so can i say uh we have a moment here which is (i+1,j),(i+1,j-1),(i+1,j+1)
// so the change in row every time we are doing a +1 like if you carefully observe the row is always changing to plus one so there is no requirement of storing the row change

// let's store the column change can I say the first time the column changes by -1, next time by +0, next time by +1, it's like changing from [-1 to +1] so can i say there are three different possible values of column change thereby can i run it something like
// int maxi=0
// for(dj1=-1;dj1<=1;dj1++){
// for(dj2=-1;dj2<=1;dj2++){
// dj1 which is the change in column for alice and dj2 for bob's change so we are exploring all nine combos

// but you are at the current cell now can i say if alice and bob are both at the same cell then you will just add it once to this and if they are not in the same cell then alice's cell + bob's cell gets added to the same function

// if(j1==j2)maxi=max(maxi,matrix[i][j1]+f(i+1,j1+dj1,j2+dj2)) when both are at same cell
// else maxi=max(maxi,matrix[i][j1]+matrix[i][j2]+f(i+1,j1+dj1,j2+dj2))

//}
//}
// return maxi;
// }

// time complexity of recursive code
// i can say at max you will travel the number of rows alice will travel the number of rows and bob will also travel the number of rows for every  time alice has three options and bob also has three options so
// t.c-O((3^n)(for alice)*(3^n)(for bob)) that's it alice has three options for every column and bob also has three options for every column so it is near about exponential

// space complexity of recursive code
// s.c-O(n) where n is no. of rows because that is the auxiliary stack space

// how do you optimize it? in order to optimize this you just need to see if there are overlapping subproblems and since there will be overlapping sub problems you can definitely apply something as memoization so in order to apply memoization you see in the recursion which parameters are there first parameter is i, next parameter is j1, next parameter is j2 so there are three parameters tell me what is the maximum value of the

// maximum value of the first parameter is n( from 0 to n-1) n different values
// what will be the possible different possible values of j1-(0 to m-1)
// and j2-(0 to m-1)

// so we have n*m*m dp
// dp[n][m][m] initialized to -1 which is 3d array
// now you just simply convert recursive to memization and return dp[i][j1][j2]=maxi and also first we check it calculated or not then

// t.c of memoization-O(n*m*m)*9 - where n*m*m which is the number of states and for every state we are running the loop of 3*3, we are running 9 states

// s.c of memoization-O(n*m*m)(for dp array)+O(n) for auxiliary stack space

#include <bits/stdc++.h>
using namespace std;

// recursive code
// t.c-O((3^n)*(3^n))
// s.c-O(n)
int f1(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m)
{
  // base case
  // first base case - out of bound
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
  {
    return -1e8;
  }
  // second base case - destination
  if (i == n - 1)
  {
    // common cells both are stand at same cell
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }
  int maxi = -1e8;
  // now we have nine combos
  // explore all paths of alice and bob simulatneously
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (j1 == j2)
        maxi = max(maxi, grid[i][j1] + f1(i + 1, j1 + dj1, j2 + dj2, grid, n, m));
      else
        maxi = max(maxi, grid[i][j1] + grid[i][j2] + f1(i + 1, j1 + dj1, j2 + dj2, grid, n, m));
    }
  }
  return maxi;
}

// memoization
// t.c-O(n*m*m*9)
// s.c-(n*m*m)(for dp)+O(n)(for auxiliary stack space)
int f2(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
  // base case
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e8;
  if (i == n - 1)
  {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }
  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = -1e8;

  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (j1 == j2)
        maxi = max(maxi, grid[i][j1] + f2(i + 1, j1 + dj1, j2 + dj2, grid, n, m, dp));
      else
        maxi = max(maxi, grid[i][j1] + grid[i][j2] + f2(i + 1, j1 + dj1, j2 + dj2, grid, n, m, dp));
    }
  }
  return dp[i][j1][j2] = maxi;
}

// tabulation-
// first things that i have told you so in order to convert tabulation i've taught you some steps first write the base case so in order to write the base case exact same dp will be declared - dp[n][m][m] so base case is if(i==n-1)there can be different possible j's that is the base case but can i say uh for this particular dp[n-1]  that's the last row because that's the base case the other two parameters might vary it might vary because if you go in the base case what can be the other two parameters j1 can be can be anywhere between the first column and the lastcolumn, j2 can be anywhere between the first column and the last column so there can be multiple base cases where they might end up anywhere so can i say this can i say this that if there are multiple cases can i write something like this for(j1 from 0 to m-1){for(j2 from 0 to m-1)} and then also see if they are at same cell so A.T that return so can i say this is what the base case will be absolutely makes sense because these are the different base cases so done with the base cases so base case was (n-1) remember

// next step in tabulation comes express every state in for loops - state was i , state was j1, state was j2 so there will be three nested loops always

// we are done with i==n-1 so now we go with i=n-2 to 0 because in recursion we start from (0 to n-1) so in tabulation it is opposite so we go from (n-2 to 0) because we done with i==n-1 as a base case and what about j1 you can run this from anywhere because we are basically concerned about the i because that is what is the base case if you see in the base case if you see in the base case we are concerned about i so j1 can run from anywhere so what you will do is you know what are the possible values of j1 for any given i the j1 can be from (0 to m-1) and this j2 can be also anything from (0 to m-1) and all are same from memization now

// t.c-O(n*m*m*9) The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times.
// s.c-O(n*m*m) for dp array
int f3(int n, int m, vector<vector<int>> &grid)
{
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0))); // 3d array

  // base case when i==n-1(last row) and all out of bound also done with this
  for (int j1 = 0; j1 < m; j1++)
  {
    for (int j2 = 0; j2 < m; j2++)
    {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1]; // when alice and bob are at same cell
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }
  // in recursion we go from starting point to end point so in tabulation it is opposite. it is from (n-2 to 0) for i and n-1 we already done in base case
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j1 = 0; j1 < m; j1++)
    {
      for (int j2 = 0; j2 < m; j2++)
      {
        int maxi = -1e8;
        // for each cell we can have three movements
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
          for (int dj2 = -1; dj2 <= 1; dj2++)
          {
            int value = 0;
            if (j1 == j2)
              value = grid[i][j1];
            else
              value = grid[i][j1] + grid[i][j2];
            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
            {
              value += dp[i + 1][j1 + dj1][j2 + dj2];
            }
            else
            {
              value += -1e8;
            }
            maxi = max(maxi, value);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }
  return dp[0][0][m - 1]; // After filling the table, the top row’s starting positions give the maximum chocolates Alice and Bob can collect together.
}

// space optimization
// To fill each cell, we only need values from the next row. So, instead of keeping a full 3D table, we can use two 2D tables and update them as we move row by row.

// Steps to Space Optimize the Tabulation Approach

// First, create one 2D table (call it "front") and fill it like we did for the last row in the normal tabulation method.
// Create another 2D table (call it "cur") that we will use while going through the rows.
// Move row by row (starting from the second last row), just like in tabulation, checking all possible moves to find the highest chocolates for each cell. Use values from the "front" table for calculations.
// Instead of filling a 3D table, store the best value directly in "cur".
// After finishing one row, copy "cur" into "front", as "front" will now represent the next row for the upcoming calculation.
// Final Answer

// After completing all rows, the answer will be in front[0][m-1], which represents Alice starting at column 0 and Bob at the last column in the first row.

// t.c-O(n*m*9) The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times.
// s.c-O(m*m) for front and curr array
int f4(int n, int m, vector<vector<int>> &grid)
{
  // like when we have 1D dp we convert it in two variables in space optimization
  // when we have 2D dp we convert it in 1D dp
  // now we have 3D dp so we convert it in 2D so it optimized space one dimension less
  // how can I make sure that it is a space optimized to one dimension less because we see in tabulation there is an use of (i+1) so front and current concept because the just the front row will be required so we will be just using that concept so instead of having this entire stuff i can definitely have something like dp[m][m] we just require 2d

  vector<vector<int>> front(m, vector<int>(m)); // front means next row dp array because if we curr at i then we want i+1 so next
  vector<vector<int>> curr(m, vector<int>(m));  // current row dp array

  // base case: last row
  for (int j1 = 0; j1 < m; j1++)
  {
    for (int j2 = 0; j2 < m; j2++)
    {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  // filled dp table bottom-up
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j1 = 0; j1 < m; j1++)
    {
      for (int j2 = 0; j2 < m; j2++)
      {
        int maxi = -1e8;
        // for each cell we can have three movements
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
          for (int dj2 = -1; dj2 <= 1; dj2++)
          {
            int value = 0;
            if (j1 == j2)
              value = grid[i][j1];
            else
              value = grid[i][j1] + grid[i][j2];
            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
            {
              value += front[j1 + dj1][j2 + dj2];
            }
            else
            {
              value += -1e8;
            }
            maxi = max(maxi, value);
          }
        }
        curr[j1][j2] = maxi;
      }
    }
    front = curr;
  }
  return front[0][m - 1]; // After completing all rows, the answer will be in front[0][m-1], which represents Alice starting at column 0 and Bob at the last column in the first row.
}
int maximumChocolates(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  // recursion - we start from starting point because it is fixed
  // return f1(0, 0, m - 1, grid, n, m);

  // in memoization
  // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1))); // 3d array
  // return f2(0, 0, m - 1, grid, n, m, dp);

  // in tabulation
  // return f3(n, m, grid);

  // space optimization
  return f4(n, m, grid);
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  cout << maximumChocolates(grid);
  return 0;
}