// Problem Statement: A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix of size n*n where matrix[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.

// Note that matrix[i][i] is always 0 means diagonal elt are always zero because in that case we have [i][i] means I cannot know myself

// Note: There exist only one celebrity or not exist any celebrity, two or more than two celebrity never exists because we say celebrity is a person known by everyone and don't know anyone so if there are two celebrity then it is not possible because we say a celebrity known by everyone so 1st celebrity should be known by second celebrity to become celebrity but second one is also celebrity which dont know anyone so this is not possible

// Only one celebrity or no celebrity exist
// minimum celebrity=0
// maximum celebrity=1

// Example 1:
// Input:
//  M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]
// Output:
//  1
// Explanation:
//  Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.

// Example 2:
// Input:
//  M = [ [0, 1], [1, 0] ]
// Output:
//  -1
// Explanation:
//  Both persons know each other, so there is no celebrity.

#include <bits/stdc++.h>
using namespace std;

// problem stating that we will be given a n*n matrix where the matrix will have values 0/1 in it and also it means that we have n people and the people are numbered from 0 to n-1

// if matrix[i][j] = 1 represents that person i knows person j
// or if matrix[i][j]=0 means person i doesn't know person j

// and given that diagonal elts are always 0 because in that case we have [i][i] , means I cannot know myself

// suppose for an example we have :

//            j:   0 1 2 3
// matrix :i=0   [[0,1,1,0],
//         i=1    [0,0,0,0],
//         i=2    [0,1,0,0],
//         i=3    [1,1,,0]]

// if we talk about matrix[0][2]=1 means person 0 knows the person 2
// matrix[2][0]=0 means person 2 does not know person 0

// it also a case that person i knows person j but person j may not know person i

// now our task is to figure out the celebrity

// Who is celebrity?
// A person that is known by everyone but he should know no one

// How do we figure out that?
// in above example : matrix[1][0]=matrix[1][2]=matrix[1][3]=0 means person 1 does not know anyone
// but if we see matrix[0][1]=matrix[2][1]=matrix[3][1]=1 means everyone know person 1
// here celebrity is 1 because person 1 is known by everyone but person 1 does not know anyone

// we have total n person

// Who is celebrity?
// Two condition has to be statisfied:

// i) how many people would know him? Can I say
// the people knowing the celebrity will be (n-1) because itself not count so remaining everyone all knows him so n-1 when there are n people everyone else would be knowing me that is n-1

// ii) and a celebrity i.e I should be knowing 0 people means I don't know anyone

// and entire diagonal is 0 because it is [i][1]  means I cannot know myself

// brute force:

// Create two arrays to track how many people each person knows and how many people know each person
// Iterate  through the matrix, updating the counters based on whether a person knows another person
// After populating the counters, iterate through the arrays to find a person who is known by everyone else but knows no one
// If such a person is found, return their index as the celebrity
// If no such person exists, return -1 indicating there is no celebrity

// example we have :

//            j:   0 1 2 3
// matrix :i=0   [[0,1,1,0],
//         i=1    [0,0,0,0],
//         i=2    [0,1,0,0],
//         i=3    [1,1,,0]]

// we take two arrays of size n=4
// knowsMe=[]
// Iknow=[]  initially both are initialized with 0

// we travel each cell  after traversing matrix we get:
// knowsMe=[1,3,2,0]
// IKnow=[2,0,2,2]

// Now we iterate on arrays and check which knowsMe index has n-1 means 4-1=3 and IKnow=0 for same index

// for index 0 we have knowsMe[0]=1 and Iknow[0]=2 so cannot be celebrity because it know someone and it doesnot known by all
// for index 1 we have knowsMe[1]=3 and IKnow[1]=0 condition matched return index=1

// function to find the index od celebrity
// t.c-O(n^2)+O(n)=O(n^2)
// s.c-O(2n)
int celebrity(vector<vector<int>> &matrix)
{
  int n = matrix.size(); // n*n
  // to store count of people who know person of index i
  vector<int> knowMe(n, 0);
  // to store count of people who the person of index i knows
  vector<int> Iknow(n, 0);
  // traverse on given matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // if person i knows person j
      if (matrix[i][j] == 1)
      {
        knowMe[j]++;
        Iknow[i]++;
      }
    }
  }
  // traverse for all persons to find the celebrit
  for (int i = 0; i < n; i++)
  {
    // return the index of celebrity
    if (knowMe[i] == n - 1 && Iknow[i] == 0)
    {
      return i;
    }
  }
  // return -1 if no celebrity is found
  return -1;
}

// optimized solution:
// in previous solution what I was doing? I was going through each and every elt and I stored like how many people know me and I know how many people I stored it, I need to avoud that method how can I avoid that before that I ask you how many minimum celebrities we can have? 0 because if the matrix is filled will all 1 , we can never have a celebrity because the definition of celebrity is known by all and knows no one
// and maximum number of celebrities we could have is 1. Can we have two celebrities? No we cannot have, imagine we have two celebrities x and y , the definition of celebrity is he cannot know anyone but everyone should know him if everyone knows him how can the other person be a celebrity so at max we have 1 celebrity

// I know a fact that I do have a celebrity from 0 till n-1 there's a celebrity between somewhere between 0 to n-1 and that we used

// example we have :

//            j:   0 1 2 3
// matrix :i=0   [[0,1,1,0],
//         i=1    [0,0,0,0],
//         i=2    [0,1,0,0],
//         i=3    [1,1,,0]]

// we take two pointer top and down initially top points at index i=0 and down points index n-1 here 3
// I'll check I am at top=0 and down=3 now tell me who cannot be a celebrity I'll check it acorss 0 does he know 3 lte's check matrix[0][3]=0 it does not knows 3 okay so if it does not knows 3 that means 0 doesn't know anyone so 0 may be a celebrity may be , let's check out the other way does 3 know 0 I'll check matrix[3][0]=1 yes 3 knows 0 so I'm very sure that this person 3 cannot be celebrity because a celebrity cannot know anyone so I can actually end up we know 3 cannot be celebrity so eliminate 3 so down-- now top still 0 and down =2
// check does 0 know 2 I'll check matrix[0][2]=1 yes 0 knows 2 means 0 cannot be celebrity because a celebrity cannot know anyone so I can actually end up we know 0 cannot be celebrity so eliminate 0 so top++ now top=1 0 and down =2
// let's check does 1 know 2 matrix[1][2]=0 no 1 does not know 2 then we check does 2 know 1 so I'll check matrix[2][1]=1 yes 2 know 1 so 2 cannot be celebrity because a celebrity cannot know anyone so I can actually end up we know 2 cannot be celebrity so eliminate 2 so down-- now top still 1 and down =1

// so eventually the top pointer and the down pointer will be pointing to a particular person i.e top==down in this case that person is 1 in order to confirm that this is the celebrity  so next what we will be doing is we will be scanning through the entire row and that should be entirely 0 and scanning through the entire column that should be 1 except the diagonal

// once we done and condition sattisfy then it is our celebrity otherwise it is not our celebrity

// ALgorithm
// Initialize two pointers, one at the top(start) and one at the bottom(end) of the matrix
// Compare the individuals at the top and bottom pointers
// If the person at the top pointer knows the person at the bottom pointer, move the top pointer down (the top person cannot be the celebrity)
// If the person at the bottom pointer knows the person at the top pointer, move the bottom pointer up (the bottom person cannot be the celebrity)
// If neither knows the other i.e matrix[top][bottom]=matrix[bottom][top]=0, increment both pointers(neither can be the celebrity)  because two people cannot be celebrity
// After the traversal, the remaining candidate at the top pointer is the potential celebrity here top==down so either say top or down
// Check if the candidate is a valid celebrity by ensuring that everyone knows this person and this person knows no one by scanning row and column of that person
// If the candidate is valid, return the index; otherwise, return -1 indicating no celebrity

// t.c-O(n)(for while loop)+O(n)(for scanning)=O(2n)
// s.c-O(1)
int celebrityIndex(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  // top and down pointers
  int top = 0, down = n - 1;
  // traverse for all the people
  while (top < down)
  {
    // if the top knows down, it cannot be a celebrity
    if (matrix[top][down] == 1)
    {
      top++;
    }
    // if down knows top, it cannot be a celebrity
    else if (matrix[down][top] == 1)
    {
      down--;
    }
    // if both does not know each other, both cannot be the celebrity because two people cannot be celebrity
    // when matrix[top][down]=matrix[down][top]=0
    else
    {
      top++;
      down--;
    }
  }
  // return -1 if no celebrity is found
  if (top > down)
    return -1;

  // when top==down
  // check if the person pointed by top/down is celebrity
  for (int i = 0; i < n; i++)
  {
    // diagonal elt skip
    if (i == top)
      continue;
    // check if it is not a celebrity
    if (matrix[top][i] == 1 || matrix[i][top] == 0)
    {
      return -1;
    }
  }
  // return the index of celebrity
  return top; // either down both are equal
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  cout << celebrity(matrix) << endl;
  cout << celebrityIndex(matrix);
  return 0;
}