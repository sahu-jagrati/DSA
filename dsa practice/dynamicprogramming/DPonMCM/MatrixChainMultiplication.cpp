// Problem Statement: Given a chain of matrices A1,..., An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices .

// Examples

// Input :  [40, 20, 30, 10, 30]
// Output :  26000
// Explanation :  Best parenthesization is ( (A1 x (A2 x A3)) x A4 ).

// Input :  [10, 20, 30, 40, 30]
// Output :  30000
// Explanation :  Optimal parenthesization minimizes cost.

#include <bits/stdc++.h>
using namespace std;

// here we learn new pattern that is "Partition DP" it is a tough pattern

// let's understand what's this partition dp?
// so generally in all the problems where we will said to solve a problem in a particulary way i.e pattern
// now what is the pattern for an example whenever we do  mathematical caluculations so assume we have been given something like 1+2+3*5 but if we put it like this (1+2+3)*5 then the answer is different but if we put it like this (1+2)+(3*5) then the answer is different so whenever we will find questions similar to these like if we solve a particluar factor like but in a particular way we get some other answers or we solve in some other particluar way we get some other answer that's when we can relate that to partition dp so whenever there are multiple ways to solve and probably they will ask you to find the best possible way that's when we relate the problem to partition dp

// so generally how will we solve a partition dp problem ?
// so as of now till we learned some rules of dynamic programming to solve the problems but for partition dp there will be a different set of rules

// let's understand so generally in all the problems we will have an array and as we saw over above that we solve (1+2+3) this portion first and then multiply it with 5 or we can solve the (1+2) portion first and then (3*5) portion so similarly in partition dp problems we'll be given an entire array and we will have to solve it probably like we solve some portion first and then next remaining portion or take do portion from other elts so like we have an array- [] of size n so in this i) first we solve from 0 to 1 index in one portion and in other portion we solve from 2 to n-1 index ii) we take two portions like (0,...2) and (3,...n-1)
// so there can be a lot of partitions
// let's assume starting point is i and end point is j and take  partition key is k so there can be multiple partitions as k changes so partition also change so out of all these partitions whichever will yield the best answer we have to tell us that

// so we have to basically I can say whenever we try to partition it like we do partition here like (i,k) and (k+1,j) so we have to solve (i,k) portion and (k+1,j) portion and again when we change k so again we solve that two portion so similar pattern of problems can be solved using partition dp

// so first problem we will be solve by using partition dp is "Matrix Chain Multiplication" (MCM)

// so now what is MCM?
// assume we have three different matrices - A,B,C and the dimension of each matrix is:
// A - 10*30
// B - 30*5
// C - 5*60
// so when we multiply two matxix - when number of columns so first matrix is same as of number of rows of second matrix so we can multiply two matrix
// and number of operations to multiply two matrices are : take the number of row of first matrix then multiply with common dimension of matrices and then multiply with number of column of second matrix
// so if we multiply matrix A and B then number of operations are - 10*30*5=1500
// now what is these operations are ? we know when we multiply matrices like for an example we have matrix A=[[1,2],[3,1]] and B=[[2],[3]] so A is of 2*2 and B is of 2*1 so we can multiply A and B so result matrix is of 2*1 , result=[[1*2+2*3],[3*2+1*3]] so if we see here there are 4 operations that we did i) 1*2 ii) 2*3 ii)3*2  iv) 1*3 so we do 4 operations here which is = 2*2*1

// so assume we have three different matrices - A,B,C and the dimension of each matrix is:
// A - 10*30
// B - 30*5
// C - 5*60
// and try to multiply them what are the ways that we can multiply them so there are two ways we can multiply three matrices:
// i) (AB)C - first I will multiply A and B them multiply it with C so if we do this way then number of operations are : first (AB) so we have A = 10*30 and B = 30*5 so here number of operations are 10*30*5=1500 and resultant matrix is of 10*5 now multiply it with C = 5*60 so now number of operations are 10*5*60=3000 so total operations are 1500+3000=4500 operations
// ii)A(BC) or first I will multiply B and C then multiply it with A so if we do this way then number of operations are : first (BC) so we have B = 30*5 and c = 5*60 so here number of operations are 30*5*60=9000,and resultant matrix is of 30*60 now multiply it with A = 10*30 so now number of operations are 10*30*60=18000 so total operations are 9000+18000=27000 operations
// so which way of multiplying these three matrices was a better way? I can say if we multiply with i) way we have to do only 4500 operations and if we do ii) way then we have to do 27000 operations so better way is 4500 operations  so minimum operations required is 4500

// so in problem basically given the 'n' matrix dimension, tell me the minimum cost to multiply them to a single one .

// for an example if we take 4 matrices like A,B,C,D then there are also different ways to multiply them like we can like d this i) A(B(CD)) ii) A(BC)D iii) (AB)(CD) iv((AB)C)D so there is a lot of ways in which we can multiply so which kind of dp - partition dp because whenever a problem can be solved in different patterns we use partition dp
// as we saw for multiplying three matrices we have two ways and also when we multiply 4 matrices there are also multiple different ways so whenever such a problem arises we think of partition dps

// What is given in question?
// Problem Statement: Given a chain of matrices A1,..., An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices .

// Examples

// Input :  [40, 20, 30, 10, 30]
// Output :  26000
// Explanation :  Best parenthesization is ( (A1 x (A2 x A3)) x A4 ).

// Input :  [10, 20, 30, 40, 30]
// Output :  30000
// Explanation :  Optimal parenthesization minimizes cost

// given an array[], I take an example of 4 matrices so imagine we have arr[]=[10,20,30,40,50] and here n is 5 this array resembles the dimension of (n-1) matrices i.e dimension of 4 matrices
// What is the dimension of first matrix? A = 10*20
// B = 20*30
// C = 30*40
// D = 40*50
// so if we try to index our given array then Can I say for the first matrix the dimension is arr[0]*arr[1]
// B - arr[1]*arr[2]
// C - arr[2]*arr[3]
// D - arr[3]*arr[4]

// so (ith) matrix has dimension of arr[i-1]*arr[i]
// so we will be given this dimensions and we know the number of matrices are 4 so now tell me the minimum number of operations required in order to multiply these 4 matrices this is the question

// so how do we solve this problem?
// definitely by partition dp
// whenever there is a pattern of dp we have certain rules

// so for solving problem with partition dp we have rules:
// Rule i)- Start with entire block or array and always represent them by (i,j) where i is the starting point and j is the end point

// what does this mean over here in above example we have 4 matrixes so we say the function take the 4 guys and give me the answer like let me just explain so if I'm writing  ABCD so these are the four guys, we start with all the four guys and we are like okay how can I solve this - i) I can either go like (AB)(CD) ii) or like (A)(BCD) iii) or like (ABC)(D) so what we are trying to say is I was solving this (ABCD) now what I'll do is I'll try to break the problem down into smaller problems
// how can the smaller problems be it can be - (AB)(CD) or (A)(BCD) or (ABC)(D) so what we did was we tokk the entire problem (ABCD) and broke it down into something smaller and try to solve it and whichever way gives me the minimum will be my answer

// so we will always start with the entire portion and we can always mark them by (i,j) where i is the start point and j is the end point

// so in our example- entire block is (ABCD) so i will be this 'A' and j will be 'D' matrix and when we break it in smaller problems like we have (AB)(CD) so here for portion (AB) - i is A and j is B and for portion (CD) - i is C and j is D, for subproblem - (A)(BCD)- for portion (A) we have i and j both is on A and for portion (BCD) - i is on B and j is on D because(A) is itself a problem and  (BCD) is itself a problem to solve  similarly on other subproblem we can mark (i,j)

// Rule ii)- Try all partitions - run a loop to try out all partitions

// how do we figure out which partitions are possible?
// let's see here we have (ABCD) so here i) we have partition after A by this we have two portion like - (AB)(CD) ii) we can have partition after B by this we have two portion like - (A)(BCD) iii) we can have partition after C by this we have two portion like - (ABC)(D), so there are three partitions, we cannot solve entire array by once so probably we can run a loop to try out all partitions

// Rule iii)- Return the best possible two partitions

// what do you mean by two partitions?
// if we take first subproblem here we have (AB)(CD) so here we have two partition- one is (AB) and second is (CD)
//  in (A)(BCD) two partitions are (A) and (BCD)
// in (ABC(D) in this two partitions are (ABC) and (D)
// so which two partition is the best we return it

// so these three rules we have to follow to solve the partition dp problem
// so we take the entire problem, break it down into every possible smaller subproblems and try to solve it and we return the best possible partition that was like the best possible subproblem

// so we start with
// f(i,j)

// we knew that we have ABCD but we cannot think in terms of ABCD, we have to think in terms of array so we have an array like
// arr[]=[10,20,30,40,50]
// and we know A was nothing but 10*20, B was 20*30, C was 30*40, D was 40*50

// Can I say if I am start from like we have an array
// index-[0,1,2,3,4]
//    [10,20,30,40,50]
//         A, B, C, D
// where if I am looking for A's size it is current guy where A is and the previous guy similarly for B,C,D something the formula we decoded : for ith we have arr[i-1]*arr[i], thereby we can say if we are resembling ABCD because that is what I'm looking to solve

// so my i start from where we have A that's the starting point and j is at D will be the ending point  rather I can say my starting point is index 1 and my ending point is index=n-1
// f(1,n-1) which is here f(1,4) so it say solve the matrix 1 to 4 and return the minimum multiplication to multiply the (matrix 1 to matrix 4)
// so we got the starting point is index=1 and ending point is index=n-1 i.e f(1,n-1) so everytime the problem will start over here with f(1,n-1) so i lie at index=1 and j lie at index=n-1 here in some problem i might start from other index and j from other, so we have to figure where does our entire block lies once we figure that out it becomes very easy

// so we understood what is f(i,j)- it states this is the block give me the minimum operations required, first rule done

// next is the base case
// what I am solving? I am having an entire set of matrix for which I am asking minimum operations. What will happen to this (i,j)?  (i,j) actually shrinks whenever we will do partition they will shrink initially we have an entire array for an above example initially we have ABCD then we break it so (i,j) shrink for an example we have subproblem (AB)(CD) so know for partion (AB) we have i at A and j at B so (i,j) shrink again we break partition so again (i,j) shrink so What the minimum that we will go? the minimum we will go is when i and j both are at same matrix that's we have a single matrix and when we have a single matrix then there is no operation so we retrun 0

// base case
// if(i==j)retrun 0; // means we have single matrix so there is no multiplication so there is no operation so retrun 0

// second rule: try all partitions
// so initially  we have
//             i        j
//        [10,20,30,40,50]
//        [    A, B, C, D]
// so can I partition the array like-(A)(BCD) and solve each partition and add them or (AB)(CD) and solve each partition and add them or (ABC)(D) and solve each partition and add them
// so Can I say if I run a loop k because there can be so may partition so we run the loop so we can cover each parttion so Can I say if I run a loop k = (from i to j-1) so the first time the partition is f(i,k) and f(k+1,j). Why we go till j-1?
// let's take above example and try to write the values
// initially i is at index=1 and j is at index=4 so we run loop k from 1 to 3 so
// i) when k=1 partition is f(1,1) and f(2,4) which is (A)(BCD)
// ii) when k=2 partition is f(1,2) and f(3,4) which is (AB)(CD)
// iii) when k=3 partition is f(1,3) and f(4,4) which is (ABC)(D)
// so these are the one of the ways in which we can go from i to j-1 that's why we go till j-1 now we understand because if we go till j means till n-1 then there will be no one in the right so that's why we go till j-1 because for right partition we have f(k+1,j) if we go till j then there is no valid k+1 so that's why we go till j-1

// or other way we run loop k = (from i+1 to j) so the partitions are f(i,k-1) and f(k,j) then the partitions can be
// i) when k=2 partition is f(1,2-1) and f(2,4) which is (A)(BCD)
// ii) when k=3 partition is f(1,3-1) and f(3,4) which is (AB)(CD)
// iii) when k=4 partition is f(1,4-1) and f(4,4) which is (ABC)(D)

// it's a same way either we run loop from (i to j-1) or run a loop from (i+1 to j) only there is slight change in partition so both ways are correct

// mini=1e9;  // because we want minimal of all steps
// so in order to do the partition we run a loop
// for(int k=i;k<j;k++){
// now we have to figure out the number of operations/steps
// when we run loop there is two partitions and we want best possible two partitions
// so like we have f(1,1) and f(2,4) two partitions and we have A=10*20, B=20*30, C=30*40, D=40*50 so for f(1,1) it is A which is of 10*20 and f(2,4) is (BCD) so if we multiply BCD at the end of the day we get 20*50 matrix after multiply (BCD) in any way like either (BC)(D) or (B)(CD) we get 20*50 in last so from f(1,1) we get 10*20 and from f(2,4) we get (20*50) so now what is the number of operations?  it is 10*20*50 so where is 10 actually comes can I say if we remember our given array then i is at 20 and j is at 50 and for this case k is also at 20 where is 10 Can I say whenever we try to multiply (A) and (BCD) where is 10? 10 is right before i that is 10 is at i-1 index and where is 20 can I say 20 is at k it is at k not at i  and where is 50 Can I say 50 is at j so basically that signifies that we have two paths so when we combine them number of steps required will be arr[i-1]*arr[k]*arr[j], now we have two partitions - f(i,k) and f(k+1,j) because (BCD) in itself will take some number of steps to get multiplied so I can say okay we add them also so because f(i,k) will take some steps and f(k+1,j) will also take some steps so total steps/operations we get is
// number of operations/steps required if I do a partition on k =arr[i-1]*arr[k]*arr[j]+f(i,k)+f(k+1,j)
// what I can say is I need the minimal of all steps so
// mini=min(mini,steps)
//}

// third rule- return mini(of all steps)
// return mini

// so for understanding the formula let's take the same thing [10,20,30,40,50] now i is at 20 , k is at 30 and j is at 50 so we have partition like (AB)(CD) and we know the dimension of each matrix  and I know (AB) gives me 10*30 and (CD) gives me 30*50 and together I get 10*50 of matrix so Can I say the number of steps if we take (AB)(CD) will be 10*30*50 so again we can relate what is 10 - arr[i-1], 30 is arr[k] , 50 is arr[j] so arr[i-1]*arr[k]*arr[j] so this is how the number of steps can be easily found and what we can do is we can solve this (AB) by calling the function f(i,k) and we can solve this (CD) by calling the function f(k+1,j) so total number of steps are arr[i-1]*arr[k]*arr[j]+f(i,k)+f(k+1,j)

// so that's we solve the problem

// so for every partition dp problem - loop k is very important, k from i to j-1 , we will always have to do a partition, computation will be depend on the problem for like here in MCM problem computation is (arr[i-1]*arr[k]*arr[j]) but the left portion f(i,k) and the right portion f(k+1,j) will be solved by calling the recursion

#include <bits/stdc++.h>
using namespace std;

// recursion
// t.c for recursion - exponential- very very very high because we are going across every partition and it will be tough to complete so we will just call it exponential
// s.c-O(n) auxiliary stack space
int f1(int i, int j, vector<int> &arr, int n)
{
  // base case  means when we have single matrix so there is no multiplication so there is no operation so retrun 0
  if (i == j)
    return 0;
  int mini = 1e9;
  // try out all partition
  for (int k = i; k < j; k++)
  {
    int steps = arr[i - 1] * arr[k] * arr[j] + f1(i, k, arr, n) + f1(k + 1, j, arr, n);
    mini = min(mini, steps);
  }
  return mini;
}
// there can be overlapping subproblems so we apply memoization
// what is the state/parameters represented by? the states/parameters are represented by i and j
// we have two changing parameters i and j
// what is the value of i? i is from 0 to n-1 so at max n and what is the value of j? j is also atmax n so we declare dp[n][n] then we can easily store the answer of that state for an example if we say (CD) then whatt is CD it is like C is at index=3 and D is at index=4 so dp[3][4] that's CD

// t.c for memoization-
// O(n*n)(because i and j will have n and n states at maximum) but we are also running a partition loop k for every state because for every state we will do a multiple partition so at max k loop runs n times, it is not exactly n times the loop runs but we can say near about
// so total t.c-O(n*n)*n = approx. O(n^3)
// s.c-O(n*n)(for dp)+O(n)(for auxiliary stack space )

int f2(int i, int j, vector<int> &arr, int n, vector<vector<int>> &dp)
{ // base case  means when we have single matrix so there is no multiplication so there is no operation so retrun 0
  if (i == j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int mini = 1e9;
  // try out all partition
  for (int k = i; k < j; k++)
  {
    int steps = arr[i - 1] * arr[k] * arr[j] + f1(i, k, arr, n) + f1(k + 1, j, arr, n);
    mini = min(mini, steps);
  }
  return dp[i][j] = mini;
}

// tabulation
// rules for tabulation
// 1. Copy the base case
// as we have dp[n][n]
// in recursion we have base case that - if(i==j)return 0; means when we have single array then there is no multiplication means there is no operation so here we can also say for every i when i==j i.e dp[i][i]=0 so we run loop from 1 to n-1 for every i, why we don't take i=0 because here we have dimension of matrices so if given array size is n then we have n-1 matrices and we start from index=1 to get dimension so for first array the dimension is arr[0]*arr[1]
// f(1,1) signifies that minimum cost/operation to multiply (matrix1 to matrix1)

// 2. write down the changing parameters/states so we have two changing parameters - i and j
// 3. copy the recurrence

// now for changing paramteres as in recursion for i we go from i= 1 to some index because we shrink the array  and for j we go from n-1 to some index and we know j is always in right of i i. i is always left of j
// if we talk about what is top-down? in top-down we go from bigger problems to smaller paroblems so in reucrsion we go from entire block/array to smaller subproblems
// what is bottom-up? in bottom-up we go from smaller problems to bigger problems
// so now in tabulation we go on opposite fashion of recursion
// so in tabulation - i go from n-1 to 0  because we'll go from the bottom so if i is n-1 to 0 then what about j? in recursion we initially start from f(1,n-1) so ideally j is running from n-1 till 0 so in tabulation we do opposite which is 0 to n-1 but does that make sense? answer is no because we know one thing i is something which will always be on the left of j so how can we start j from 0 to n-1 so Can I say I have to start j from the right of i so  j go from i+1 to n-1 instead of 0 to n-1 because j is always in right of i

// t.c-O(n^3) in worst case approx.
// s.c-O(n^2) for dp
int f3(vector<int> &arr, int n)
{
  // declare dp
  vector<vector<int>> dp(n, vector<int>(n, 0));
  // base case when i==j return 0
  for (int i = 1; i < n; i++)
    dp[i][i] = 0;
  // for remaining
  // i in tabulation go in opposite fashion of recursion so in tabulation i go from 1 to some index so in tabulation i go from n-1 to 1
  for (int i = n - 1; i >= 1; i--)
  {
    // we know j is always in right of i so j go from i+1 to n-1 instead of 0 to n-1
    for (int j = i + 1; j < n; j++)
    {
      // copy the recurrence
      int mini = 1e9;
      // try out all partition
      for (int k = i; k < j; k++)
      {
        int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
        mini = min(mini, steps);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][n - 1];
}

int matrixMultiplication(vector<int> &arr, int n)
{
  // recursion
  //  intially we have an entire block or array and i is at 1 and j is at n-1
  // return f1(1, n - 1, arr, n);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // return f2(1, n - 1, arr, n, dp);

  // tabulation
  return f3(arr, n);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n); // here array denotes the dimensions of n-1 matrices
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << matrixMultiplication(arr, n);
  return 0;
}