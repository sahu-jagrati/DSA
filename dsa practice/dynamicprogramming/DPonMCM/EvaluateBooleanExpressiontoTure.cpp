// Problem Statement: Given an expression, A, with operands and operators (OR, AND, XOR), in how many ways can you evaluate the expression to be true, by grouping it in different ways?.

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 10^3 + 3.

// Example 1:
// Input: expression = “T|T&F”
// Output: 1
// Explanation: The only way to get the result as true is:
// (T) | (T&F) = T|F = T

// Example 2:
// Input: expression = “F|T^F”
// Output: 2
// Explanation: There are 2 possible ways to get the result as true:
// 		i. (F|T) ^ F = T ^ F = T
// 		ii. F | (T^F) = F | T = T

// as in answer we want true so we have to count number of ways we get true by solving given expression

// as expression format is that we have operand then operator then again operand again operator here operand is true/false and operators are : '|', '&', '^'.
// so if we have an expression like : "T|T&F" so if
//                                     i   j
// so if we see carefully operator start from i+1 and after every +2 steps they are aand go upto j-1

// this problem is like similar to MCM problem i.e Matrix Chain Multiplication like in that we have matrices : ABCD and try all ways to solve them like i) (A)(BCD) ii) (AB)(CD) iii) (ABC)(D)
// similarly here we can solve the problem like we have expressions : "T|T&F" so we can solve like them : i) (T)|(T&F) ii) (T|T)&(F) these are possible ways but we have to count the number of ways that give true as an answer

// so if we have operator='&' then how we get true:
// if both left and right subproblems return true then true & true=true otherwise it is always false
// so if there is x1 ways to get true from left subproblem and x2 ways to get true from right subproblem then total ways to get true is =  x1*x2

// if we have operator='|' then how we get true:
// i) if left return true and right subproblem also return true then true | true = true
// so if there is x1 ways to get true from left subproblem and x2 ways to get true from right subproblem then total ways x1*x2
// ii) if left return true and right subproblem  return false then true | false = true
// so if there is x1 ways to get true from left subproblem and x3 ways to get false from right subproblem then total ways x1*x3
// iii) if left return false and right subproblem return true then false | true = true
// so if there is x4 ways to get false from left subproblem and x2 ways to get true from right subproblem then total ways x4*x2
// so total ways to get true is  = x1*x2 + x1*x3 + x4*x2
// otherwise false return

// if we have operator='^' then how we get true:
// i) if left return false and right subproblem return true then false ^ true = true
// so if there is x1 ways to get true from left subproblem and x2 ways to get false from right subproblem then total ways x1*x2
// ii) if left return true and right subproblem  return false then true ^ false = true
// so if there is x3 ways to get false from left subproblem and x2 ways to get true from right subproblem then total ways x3*x2
// so total ways to get true is = x1*x2 + x3*x2
// otherwise false return

// so how we approach this problem
// we start from entire expression so initially i is at 0 and j is at n-1:  f(0,n-1,isTrue)  we take extra parameter isTrue which is 1 if it return 'True' or isTrue=0 if it return 'False' which say if we want left/right subproblem to return 'True ' then we say isTrue=1 and if we want left/right subproblem to return 'False' then we say isFalse=0

// initially we call the recursion with f(0,n-1,isTrue=1) because we want that whole expression returns 'True' where i is at 0 and j is at n-1 so f(i,j,isTrue) signifies the total number of ways to evaluate the expression from index i to j such that the result is True(if isTrue=1) or False (if isTrue=0).

// now base case is: i) when i crosses j so if(i>j) return 0; means there is no way to get true
// and  ii) also if we have only one character i.e expression[index]='T' or expression[index]='F' then if isTrue==1 and expression[index]=='T' then return 1 or if isTrue=0 and expression[index]=='F' return 1
// if(i==j){
// if(isTrue==1)return expression[i]=='T' so it return 1 if it is 'T' or return 0 if it is 'F'
// else return expression[i]=='F' so ot return 1 if it is 'F' or return 0 of it is 'T'
//}

// then we try all possible partition and here partition is done by operators so for partition we run a loop from
// i+1 to j-1 because we get operator at i+1 then after each +2 steps we get next operator
// for(int index=i+1;index<=j-1;index+=2){
// left subproblem=f(i,index-1,true/false)
// right subproblem=f(index+1,j,true/false)
// ways = left subproblem + right subproblem based on the isTrue value because of operators
//}

// return ways;

// here is the entire approach

// The problem asks us to find the number of ways to parenthesize a boolean expression such that it evaluates to True.The expression consists of operands 'T'(true), 'F'(false), and operators '&'(AND), '|'(OR), and '^'(XOR).

// To solve this, we realize that the result of the whole expression depends on how we split and combine smaller sub - expressions.Each operator serves as a possible partition point, and we recursively compute how many ways each sub - expression can be true or false.Depending on the operator, we combine the results in different ways to calculate the total number of ways the entire expression can evaluate to true.

// This is a classic example of partition DP,where we break a problem into subproblems, solve them recursively, and combine their results.

// Define a recursive function f(i, j, isTrue) that returns the number of ways to evaluate the expression from index i to j such that the result is True(if isTrue = 1) or False(if isTrue = 0).

// Base Cases :
//  If i > j, return 0(invalid sub - expression).

// ii) If i == j, return : 1 if the single character matches the required boolean value.0 otherwise.

// Recursive Step :

// Try all possible partition points(operators) between i and j.

// For each operator at index k, divide the expression into two parts: left = f(i, k-1, true/false) and right = f(k+1, j, true/false).

// Combine left and right results based on the operator:
// AND (&): Result is true only if both sides are true.
// OR (|): Result is true if either side is true.
// XOR (^): Result is true if one side is true and the other is false.

// Repeat this recursively for all sub-expressions and return the total count of valid parenthesizations that lead to True.

// Use memoization (3D DP table) to optimize overlapping subproblems.
// Since the result can be large, return it modulo 10^9 + 7.

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

// recursion
// t.c- exponential in nature
// s.c-O(n) auxiliary stack space where n is size of expression

long long f1(int i, int j, int isTrue, string &expression)
{
  // base case
  // i) when i>, invalid expression when i crosses j
  if (i > j)
    return 0;
  // when i==j, single character left
  if (i == j)
  {
    // when we looking for true
    if (isTrue == 1)
      return expression[i] == 'T';
    // when we looking for false
    else
      return expression[i] == 'F';
  }
  long long ways = 0;
  // now we try all partitions and we know each operator serve as a possible partition and operators are located at +2 position
  // here ope represents operator
  for (int ope = i + 1; ope <= j - 1; ope += 2)
  {
    // when we looking for true in left subproblem so we take isTrue=1
    long long leftTrue = f1(i, ope - 1, 1, expression);
    // when we looking for false in left subproblem so we take isTrue=0
    long long leftFalse = f1(i, ope - 1, 0, expression);
    // when we looking for true in right subproblem so we take isTrue=1
    long long rightTrue = f1(ope + 1, j, 1, expression);
    // when we looking for false in right subproblem so we take isTrue=0
    long long rightFalse = f1(ope + 1, j, 0, expression);

    // when operator=='&'
    if (expression[ope] == '&')
    {
      // when we looking for true
      if (isTrue == 1)
        ways = (ways + (leftTrue * rightTrue) % MOD) % MOD;
      // when we looking for false
      else
        ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
    }
    // when operator=='|'
    else if (expression[ope] == '|')
    {
      // when we looking for true
      if (isTrue == 1)
        ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
      // when we looking for false
      else
        ways = (ways + (leftFalse * rightFalse) % MOD) % MOD;
    }
    // when operator=='^'
    // T^T=F, F^F=F, T^F=T, F^T=T
    else
    {
      // when we looking for true
      if (isTrue == 1)
        ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD) % MOD;
      // when we looking for false
      else
        ways = (ways + (leftFalse * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
    }
  }
  return ways; // total number of ways to get true from a given expressions
}

// memoization
// as there can be overlapping subproblems so we apply memoization
// we have three changing parameters here i,j, and isTrue
// i can be go somewhere from 0 to n-1 and j can be go somewhere from n-1 to 0 and isTrue can have value either 1 or 0 so we declare dp[n][n][2]

// t.c-
// i,j and isTrue runs n*n*2 and the operator loop run each time for each(i,j,isTrue) so it run in worst case n times for each (i,j,isTrue) so total t.c-O(n*n*2)*n= approx. O(n^3)
// s.c-O(n*n*2)(for dp)+O(n)(for auxiliary stack space)
int f2(int i, int j, int isTrue, string &expression, vector<vector<vector<long long>>> &dp)
{
  // base case
  // i) when i>j, invalid expression when i crosses j
  if (i > j)
    return 0;
  // when i==j, single character left
  if (i == j)
  {
    // when we looking for true
    if (isTrue == 1)
      return expression[i] == 'T';
    // when we looking for false
    else
      return expression[i] == 'F';
  }
  if (dp[i][j][isTrue] != -1)
    return dp[i][j][isTrue];
  long long ways = 0;
  // now we try all partitions and we know each operator serve as a possible partition and operators are located at +2 position
  // here ope represents operator
  for (int ope = i + 1; ope <= j - 1; ope += 2)
  {
    // when we looking for true in left subproblem so we take isTrue=1
    long long leftTrue = f2(i, ope - 1, 1, expression, dp);
    // when we looking for false in left subproblem so we take isTrue=0
    long long leftFalse = f2(i, ope - 1, 0, expression, dp);
    // when we looking for true in right subproblem so we take isTrue=1
    long long rightTrue = f2(ope + 1, j, 1, expression, dp);
    // when we looking for false in right subproblem so we take isTrue=0
    long long rightFalse = f2(ope + 1, j, 0, expression, dp);

    // when operator=='&'
    if (expression[ope] == '&')
    {
      // when we looking for true
      if (isTrue == 1)
        ways = (ways + (leftTrue * rightTrue) % MOD) % MOD;
      // when we looking for false
      else
        ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
    }
    // when operator=='|'
    else if (expression[ope] == '|')
    {
      // when we looking for true
      if (isTrue == 1)
        ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
      // when we looking for false
      else
        ways = (ways + (leftFalse * rightFalse) % MOD) % MOD;
    }
    // when operator=='^'
    // T^T=F, F^F=F, T^F=T, F^T=T
    else
    {
      // when we looking for true
      if (isTrue == 1)
        ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD) % MOD;
      // when we looking for false
      else
        ways = (ways + (leftFalse * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
    }
  }
  return dp[i][j][isTrue] = ways; // total number of ways to get true from a given expressions
}

// tabulation
// step1: write base case
// step2: write changing parameter in opposite fashion of recursion
// step3: copy the recurrence

// t.c-
// i,j and isTrue runs n*n*2 and the operator loop run each time for each(i,j,isTrue) so it run in worst case n times for each (i,j,isTrue) so total t.c-O(n*n*2)*n= approx. O(n^3)
// s.c-O(n*n*2)(for dp)
int f3(string &expression, int n)
{
  // as when i=n-1 then i+1 = n so we want size of [n+1]
  vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));
  // base case
  // i) if(i>j) return 0 ; as we already initialize dp with 0 so no need to write this base case separately
  // ii) if i==j we write this base case in internal loop

  // as in recursion i go from 0 to n-1 and j go from n-1 to 0 and isTrue can be either 0 or 1 so in tabulation we go in opposite fashion so i go from n-1 to 0 and j go from 0 to n-1
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j <= n - 1; j++)
    {
      // base case : i) if i>j means invalid expression when i crosses j
      if (i > j)
        continue; // i.e skip the remaining given below process when i>j it is a base case
      for (int isTrue = 0; isTrue <= 1; isTrue++)
      {
        // base case : ii) if i==j, single character left
        if (i == j)
        {
          if (isTrue == 1)
          {
            dp[i][j][isTrue] = expression[i] == 'T'; // means when we are looking for true i.e isTrue=1 and expression[i]='T' so it is 1 or when we looking for true i.e isTrue=1 but expression[i]='F' then it is 0
          }
          else
          {
            dp[i][j][isTrue] = expression[i] == 'F'; // means when we are looking for false i.e isTrue=0 and expression[i]='T' so it is 0 or when we looking for false i.e isTrue=0 but expression[i]='F' then it is 1
          }
          continue; // skip the remaining given below process when i==j it is a base case
        }
        long long ways = 0;
        // now we try all partitions and we know each operator serve as a possible partition and operators are located at +2 position
        // here ope represents operator
        for (int ope = i + 1; ope <= j - 1; ope += 2)
        {
          // when we looking for true in left subproblem so we take isTrue=1
          long long leftTrue = dp[i][ope - 1][1];
          // when we looking for false in left subproblem so we take isTrue=0
          long long leftFalse = dp[i][ope - 1][0];
          // when we looking for true in right subproblem so we take isTrue=1
          long long rightTrue = dp[ope + 1][j][1];
          // when we looking for false in right subproblem so we take isTrue=0
          long long rightFalse = dp[ope + 1][j][0];

          // when operator=='&'
          if (expression[ope] == '&')
          {
            // when we looking for true
            if (isTrue == 1)
              ways = (ways + (leftTrue * rightTrue) % MOD) % MOD;
            // when we looking for false
            else
              ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
          }
          // when operator=='|'
          else if (expression[ope] == '|')
          {
            // when we looking for true
            if (isTrue == 1)
              ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
            // when we looking for false
            else
              ways = (ways + (leftFalse * rightFalse) % MOD) % MOD;
          }
          // when operator=='^'
          // T^T=F, F^F=F, T^F=T, F^T=T
          else
          {
            // when we looking for true
            if (isTrue == 1)
              ways = (ways + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD) % MOD;
            // when we looking for false
            else
              ways = (ways + (leftFalse * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
          }
        }
        dp[i][j][isTrue] = ways;
      }
    }
  }
  return dp[0][n - 1][1];
}

int evaluateExpToTrue(string &expression)
{
  int n = expression.size();
  // recursion: initially start from entire expression so i is 0 and j is n-1 and we are looking for true so isTrue=1 initially
  // return f1(0, n - 1, 1, expression);

  // memoization
  // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
  // return f2(0, n - 1, 1, expression, dp);

  // tabulation
  return f3(expression, n);
}

int main()
{
  string expression;
  cin >> expression;
  cout << evaluateExpToTrue(expression);
  return 0;
}