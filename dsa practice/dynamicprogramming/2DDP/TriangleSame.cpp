// You are given a triangular arraylist 'Triangle'. Your task is to return the minimum path sum to reach from the top to the bottom row.

// The triangle array will have N rows and the i-th row, where 0<=i<N will have i+1 elts.

// You can move only to the adjacent number of row below each step. For example. if you are at index i in row j, then you can move to i or i+1 index in row j+1 in each step.

// example- Triangle=[[1],[2,3],[3,6,7],[8,9,6,10]] will look like right angled triangle :
// 1  -> 0th row having 1 elt
// 2 3  -> 1st row having 2 elt
// 3 6 7  -> 2nd row having 3 elt
// 8 9 6 10  -> 3rd row having 4 elt

// you can move right to the bottom of the next row or you can move diagonally to the next row so basically

// so they have said that there is a starting point okay so over here we need to understand that the starting point is fixed okay so the starting point is fixed what about the ending point they're saying that the ending point might vary is the ending point might vary because what they are concerned is as long as you are reaching the last row you can either reach here to 8 or to 9 or to 6 or to 10
// in order to reach from the first row till the last row there might be a path uh how many different paths can be there? there can be some path like 1->2->3->8 or 1->3->7->10 or 1->3->6->9  here can be a lot of paths okay and in these paths whichever path takes the minimum path sum you have to tell me that so for an example i can say i can go from 1 to 2 to 3 and to 8 and this is like 8 plus 2 is 10 13 14 so 14 is the minimum path sum you can try out all the paths and the minimum that you will get is indeed 14.

// so going across how do you identify that a greedy solution is will fail again?  uniformity concept because it might happen over here greedily you choose to and again greedily you choose three and uh like greedily you're choosing right and might happen somewhere down the line there is a very smaller value you miss out just because you're choosing something which is very very small on the upper half so uniformity is not there because the values might be bigger might be lesser so whenever there is no uniformity in the increment of values or decrement of values then we can see that something like a greedy cannot be applied.

// so what do we tend to apply over there?
// yes we try out all the paths and um how do you do that?
// we know we just have one way to try out all the paths that is we travel through all the paths and that can be done using recursion and by using recursion what you need to do is you need to find the path which gives you the minimum sum and once you've done this you are done so in the great grid problems what have i told you i've told

// 1. represent everything in terms of indexes
// and what are the indexes over here i and j  because in a grid we will always have the row number and the column numbe

// 2.  explore all the paths
// what kind of paths are there either you can go straight right to the bottom or you can go diagonally right

// 3. and after that you take the minimal of all the paths

// question arises striver in all the previous videos we did know that the ending point was something like (m-1,n-1) so striver we started from the back like f(m-1,n-1) and we did write the recursion but over here there is not a  fixed ending point that is very obvious because  we can either end here in our example above at 8 or we can either end here 9 or we can either end here 6 or we can either end here 10 so there is no fixed ending point so logically it will not make sense if i write the recurrence because i might be ending here i might be ending here so there can be four different recurrence one that starts from here the  other that starts from here the other that starts from here the other that starts from here there'll be four different kind of recurrence in the previous video there was only one recurrence that you called and you got the answer but over here you have to call four different recurrence one is from here one is from here one is from here one is from here and in all the four recurrence whichever recurrence gives you the minimum path that will be your answer right but whenever you see that there is  a single fixed point like i can see that there is a single fixed point logically it is preferable that you start from right the top and you try to go down that's the preferable logic so we will try to implement that preferable logic instead of starting from the back which we have usually done in all the problems we will not do because over here we have to start from four different columns basically the number of columns is what i have to start that's not preferable that's why what we do is we start the recursion from f(0,0)

// f(0,0) signifies the minimum path sum from (0,0) to last and in last row it can be any column. it can start from (0 ,0) and go till the last row so we have figured out that the recurrence has to start from instead of f(m-1,n-1) we know the recurrence will start from (0,0) that is something which

// recurrence is something like

// i-row
// j-column

// f(i,j){
// what is the base case? what am i doing i know that i'm starting from (0,0) i know that i am going down i will go down and when do i end from this row can i go further down where is your destination generally the destination is your base case i know the destination is the (n-1) through so i know whenever i reach (n-1) at row whichever value is there that will simply get added to the answer. by any chance if i reach (n-1) through i can say that please return whatever is there on that jth column like if i'm reaching any of the columns yes if i'm reaching this guy i'll return 8 to be added to the answer or  i'll write a 9 or i'll written 6 or i'll written 10 whichever column i ended i'll be returning that so that is how we will be doing so we have figured out the first base case what can be the other base case can you try to think you probably can try to think so if i talk about where am i moving i'm moving till bottom and to the diagonally.
// will we ever uh go out of boundary try to think for this?
// in our example- this(1) is the extremist guy on the zeroth row does it have a diagonal yes it has 3 in daigonal does this(3) guy have a diagonal yes it has 7 in diagional does this(7) guy have a diagonal yes it has 10 in diagonal we've reached the last row so i know no matter how you move because we can only move down and diagonal we will never go outside this boundary so we know that there will be no out outside boundary condition so there is only one base case so step one complete

// base case
// if(i==n-1)return array[n-1][j]

// now step 2.  explore all the paths and we know we are looking for minimum paths- what kind of path is there? one is down and other is diagonally
// down path is like (i+1,j) and diagonally path is (i+1,j+1)
// down=array[i][j]+f(i+1,j)
// diagonally=array[i][j]+f(i+1,j+1)
// the next step is also done explore all the paths

// step 3. minimum of all the paths
// return min(down,diagonally)
//}

// t.c of recurrsion

// no. of rows - n
// how many columns are there
// the first row has one column
// next row has two column
// next row has three column
// and so on we have (n+1) columns at the last nth row that's i think n column rather we have exactly n column at the last row
// columns - 1+2+3+....+n
// so what we know is these are the number of rows and for every column we have couple of options either to go down or to go diagonally  so we can say twice across every one right so 2^(1+2+3+..+n) which is exponential in nature because you're going twice for every one right recursion and

// the space complexity there'll be a stack space involved one with the stack space you're going from the zeroth row to the bottom so the length of the rows
// s.c-O(n)

// how to convert a recursion like how to optimize
// this the best way is to figure out are there overlapping sub problems

// like from f(0,0) we have f(1,0) and f(1,1) from this we also have so on where you get overlapping sub problems whenever there are overlapping subproblems we can apply something as memoization

// but if i can apply memoization i had to figure out what can be the maximum value of i and what can be the maximum value of j?
// i know we can at max have n rows and n columns so we will be requiring an dp[n][n] which is initialized with -1

// t.c of memoization-  will be the number of states- O(n*n)
// s.c- it will not be exactly n into n because so it's a right angled trangle not a square if you think it properly it's a triangle so one state two states so these will be the number of states which is one plus two plus three plus  and the other side of the dp matrix will not be required
// s.c-O(n)(recursion stack space)+O(n*n)dp matrix

// tabulation method
// so first this is going to be slightly different from the previous problems because we genearlly did recursion from (n-1 to 0) but over here we did the recursion from (0 to the last row) so it isn't like now we will be calling just because we wrote the recursion from(0 to last row ) it doesn't mean it is bottom-up recursion, it is top-down recursion now because this is where we go down

// so the base case will be like the tabulation will be the opposite

// it is a thumb rule whatever you write for recursion the opposite is the tabulation

// here in recursion we have (0 to last row)
// so in tabulation we have (last row to 0)

// the first thing in tabulation everyone knows is declare a dp of size n*n- dp[n][n]

// what do i see in the recursion this is the base case - if(i==n-1) how many base cases can we have if i'm saying (i==n-1){return array[i][j]}what will the possible values of j the possible values of j if i just go to the example 0 1 2 3. there can be four different columns because once you might reach here 0 column this is a base case, you might reach here 1 column this is a base case you might reach here 2 column this is a base case, you might reach here 3 column this is a beast case so there can be four different base cases  i just need to write it so i know for sure

// for tabulation
// base case
// for(int j=0;j<n;j++){
// dp[n-1][j]=array[n-1][j]  // i==n-1

// tabulation is opposite of recursion so we go from (n-1 to 0 ) here and for (n-1) row we already manage as a base case now for remaining rows
// for(i=n-2;i>=0;i--){
// what can be the columns
// if i is zero the possible j is 0
// if i is 1 the possible j is 0,1
// if is is 2 the possible j is 0,1,2
// so can i say whatever is the value of i that's equivalent to the number of columns it can have so I figured out how many possible columns will I have for a particular i so first variable you will write and then you will create a nested loop that's a tabulation concept for j so
// so can i say whatever is the value of i that's equivalent to the number of columns it can have so I figured out how many possible columns will I have for a particular i so first variable you will write and then you will create a nested loop that's a tabulation concept for j so create the nested loop for the tabulation concept so i create a nested loop and how will the nested loop run now the nested loop will also run in the similar fashion
// for(int j=i;j>=0;j--){
// down=array[i][j]+dp[i+1][j]
// diagonally=array[i][j]+dp[i+1][j+1]
// dp[i][j]=min(down,diagonally)
//}
//}
// in recursion answer is f(0,0) so in tabulation
// return dp[0][0]
//}

// t.c in tabulation
//  O(n*n) not exactly you can say that it's slightly less than that by a near about
// s.c-O(n*n) dp matrix - can we optimize this? yes, why i did tell you if there is something like (i+1) you can always do it so space optimization

// space optimization
// whenever you see something like (i-1) till now in previous problem
// over here we are seeing something as what are we seeing (i+1) how will this  dp table fill up so i'll always recommend in order to understand space complexity better like our space optimization better try to do a dry run of this table format tabulation now you can just fill up the dp table so if you try to fill up the dp table what happens is the last row is the base case which is automatically like i'm just filling up like random numbers it's not zero it's some numbers and then you start from n-2 then n-3 and so on to 0 th row and the answer is dp[0][0] so how did the dp table fill up first the base case  and in order to get n-2 row elts we do down and diagonal

// so can i say in order for like in order to solve any row
// i'm just requiring this particular(previous) row in order to solve this(current) row so can i say once this is the base case I compute the n-2 particular row and after computation I don't require previous row I updat ethe previous to current and current to n-3 and so on. so can i say instead of storing the entire triangle i just need to store two rows one is the previous or like the front row and one is the current row that you are traversing and once this current row is computed and you move to this guy this current row becomes the front row that's the space optimization

// return temp[0] // answer
// t.c in space optimization
// O(n*n)
// but the s.c-O(2n) for current row and for prev row

#include <bits/stdc++.h>
using namespace std;

// time and space complexity all mention above for each in their discussion

// recursion- here in this problem we do from top-down - (0 to n-1)
int f1(int i, int j, vector<vector<int>> &triangle, int n)
{
  // base case
  if (i == n - 1)
  {
    return triangle[n - 1][j];
  }
  int down = triangle[i][j] + f1(i + 1, j, triangle, n);
  int diagonal = triangle[i][j] + f1(i + 1, j + 1, triangle, n);

  return min(down, diagonal);
}

// in memoization
int f2(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n)
{
  if (i == n - 1)
  {
    return triangle[n - 1][j];
  }
  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }
  int down = triangle[i][j] + f2(i + 1, j, triangle, dp, n);
  int diagonal = triangle[i][j] + f2(i + 1, j + 1, triangle, dp, n);

  return dp[i][j] = min(down, diagonal);
}

// in tabulation- here in this problem we do from bottom-up- (n-1 to 0)
int f3(vector<vector<int>> &triangle, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, -1));
  // base case- last row fill
  for (int j = 0; j < n; j++)
  {
    dp[n - 1][j] = triangle[n - 1][j];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = i; j >= 0; j--)
    {
      int down = triangle[i][j] + dp[i + 1][j];
      int diagonal = triangle[i][j] + dp[i + 1][j + 1];
      dp[i][j] = min(down, diagonal);
    }
  }
  return dp[0][0];
}

// space optimization
int f4(vector<vector<int>> &triangle, int n)
{
  // prev row which is here is last row
  vector<int> prev(n, 0), curr(n, 0);
  for (int j = 0; j < n; j++)
  {
    prev[j] = triangle[n - 1][j];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = i; j >= 0; j--)
    {
      int down = triangle[i][j] + prev[j];
      int diagonal = triangle[i][j] + prev[j + 1];

      curr[j] = min(down, diagonal);
    }
    prev = curr;
  }
  return prev[0];
}

int minimumTotal(vector<vector<int>> &triangle, int n)
{

  // recursion
  // return f1(0, 0, triangle, n);

  // in memoization
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // return f2(0, 0, triangle, dp, n);

  // in tabulation
  // return f3(triangle, n);

  // in space optimization
  return f4(triangle, n);
}

int main()
{
  int n;
  cin >> n; // number of rows
  vector<vector<int>> triangle(n);
  for (int i = 0; i < n; i++)
  {
    // ith row has i+1 elts
    for (int j = 0; j <= i; j++)
    {
      int x;
      cin >> x;
      triangle[i].push_back(x);
    }
  }
  cout << minimumTotal(triangle, n);
  return 0;
}