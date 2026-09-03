// You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

// You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

// Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

// In case there is no path, return [0, 0].

// Example 1:

// Input: board = ["E23","2X2","12S"]
// Output: [7,1]
// Example 2:

// Input: board = ["E12","1X1","21S"]
// Output: [4,2]
// Example 3:

// Input: board = ["E11","XXX","11S"]
// Output: [0,0]

// Constraints:

// 2 <= board.length == board[i].length <= 100

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

vector<int> pathWithMaxScore(vector<string> &board)
{
  int n = board.size();
  const int NEG = -1; // unreachable
  // we define two dp matrix one for storing max score upto that cell and one for counting number of ways to reach that cell
  vector<vector<int>> score(n, vector<int>(n, NEG));
  vector<vector<int>> ways(n, vector<int>(n, 0));

  // question mention we have to start from (n-1,n-1) cell and we know last cell have value 'S' so for that score value=0 and ways=1
  score[n - 1][n - 1] = 0;
  ways[n - 1][n - 1] = 1;

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (board[i][j] == 'X')
      {
        continue; // that is skip that route
      }
      // also skip the (n-1,n-1) cell
      if (i == n - 1 && j == n - 1)
        continue;

      int bestScore = NEG;
      // as we go from bottom to top so for calculating top values we take bottom values
      // when we move to up so we go to (i-1,j) cell so for that we want values (i,j) cell so for (i,j) cell we want values of (i+1,j)
      if (i + 1 < n)
        bestScore = max(bestScore, score[i + 1][j]);

      // when we go right so for (i,j) cell we want values of(i,j+1)
      if (j + 1 < n)
        bestScore = max(bestScore, score[i][j + 1]);
      // when we go diagonally so for(i,j)cell we want values of (i+1,j+1)
      if (i + 1 < n && j + 1 < n)
        bestScore = max(bestScore, score[i + 1][j + 1]);

      if (bestScore == NEG)
        continue; // skip that path

      int value = 0;
      if (board[i][j] != 'E')
        value = board[i][j] - '0';

      score[i][j] = value + bestScore;

      // for number of ways
      if (i + 1 < n && score[i + 1][j] == bestScore)
        ways[i][j] = (ways[i][j] + ways[i + 1][j]) % MOD;
      if (j + 1 < n && score[i][j + 1] == bestScore)
        ways[i][j] = (ways[i][j] + ways[i][j + 1]) % MOD;
      if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] == bestScore)
        ways[i][j] = (ways[i][j] + ways[i + 1][j + 1]) % MOD;
    }
  }
  if (ways[0][0] == 0)
    return {0, 0};
  return {score[0][0], ways[0][0]};
}

int main()
{
  int n;
  cin >> n;
  vector<string> board(n);
  for (int i = 0; i < n; i++)
  {
    cin >> board[i];
  }

  vector<int> ans = pathWithMaxScore(board);
  cout << ans[0] << " " << ans[1];
  return 0;
}