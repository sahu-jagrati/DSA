// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:

// 1 <= n <= 8

#include <bits/stdc++.h>
using namespace std;

// we do this problem by bfs
// # For the breadth-first search approach, you'll use a queue to track different states as you build the parentheses combinations. Each state will be represented as a tuple containing three elements:

// # The current string being built
// # The number of opening parentheses used so far
// # The number of closing parentheses used so far
// # Create a variable named queue and initialize it with a list containing one tuple: ('', 0, 0). This represents the starting state with an empty string and zero parentheses used.

vector<string> generateParenthesis(int n)
{
  vector<string> ans;
  // when n<1 return empty list
  if (n < 1)
    return ans;

  // initialized queue for bfs and to store - string store parenthesis , int store number of open bracket, second int store number of close bracket
  queue<tuple<string, int, int>> q;
  // initially
  q.push({"", 0, 0});
  while (!q.empty())
  {
    // auto [str, x, y] = q.front();
    // or you can write
    string str = get<0>(q.front());
    int x = get<1>(q.front());
    int y = get<2>(q.front());
    q.pop();

    if (str.size() == 2 * n)
    { // means when we have equal number of open and closed brackets so if n is number of open brackets then number of closed brackets also =n so total string size=2*n
      ans.push_back(str);
    }
    else
    {
      // if number of open brackets less than n then
      if (x < n)
      {
        q.push({str + '(', x + 1, y});
      }
      // if number of closed brackets less than  number of open brackets
      if (y < x)
      {
        q.push({str + ')', x, y + 1});
      }
    }
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<string> ans = generateParenthesis(n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}