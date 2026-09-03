// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false

// Constraints:

// 1 <= s.length <= 10^4
// s consists of parentheses only '()[]{}'.

// we solve it using stack
// valid paranthesis is an application of stack

#include <bits/stdc++.h>
using namespace std;

bool isValidParanthesis(string s)
{
  int n = s.size();
  if (n <= 1)
    return false; // s="{"
  stack<char> st;
  for (int i = 0; i < n; i++)
  {
    char ch = s[i];
    // if ch is open bracket then push it in stack
    if (ch == '(' || ch == '{' || ch == '[')
      st.push(ch);
    // if ch is close bracket then
    else
    {
      // stack is empty then no open bracket in it so false
      if (st.empty())
        return false;
      // get top of stack and match it pair with ch
      char top = st.top();
      st.pop();
      if (top == '(' && ch == ')')
      {
      }
      else if (top == '{' && ch == '}')
      {
      }
      else if (top == '[' && ch == ']')
      {
      }
      else
        return false;
    }
  }
  return st.empty(); // means if stack is empty then all valid paranthesis else there is a bracket in stack which has no pair
}

int main()
{
  string s; // s consists of parentheses only '()[]{}'.
  cin >> s;
  bool answer = isValidParanthesis(s);
  cout << answer << endl;
  return 0;
}