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

#include <bits/stdc++.h>
using namespace std;

// intuition:
// We have to keep track of previous as well as most recent opening brackets and also keep in mind the sequence (i.e order), as after opening of the bracket there should be opposite pairs of brackets.

// Also handle the corner cases like [ ) ( ] where closing bracket occurs first and opening bracket after it, which is an invalid sequence, as well as [ ( ] ) where the most recent opening didn't get its opposite pair hence it will also not be valid.

// So we have to use a data structure that will keep track of first in and last out, hence we will use the stack.

// approach:
// Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
// Whenever we get the closing bracket we will check if the stack is non-empty or not.
// If the stack is empty we will return false, else if it is nonempty then we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.
// If it is not the opposite pair of the closing bracket then return false, else move ahead.
// After we move out of the string the stack has to be empty if it is non-empty then return it as invalid else it is a valid string.

// example: str="()[{}()]"
// we start traversing the string from i=0
// and we have stack that store char

//  i                                stack
// i=0 we have'(' open bracket so push it in stack
//  (                                 (
// i=1 we have ')' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '(' corresponding open brackets so it is valid
// )                                      empty
// i=2 we have'[' open bracket so push it in stack
// [                                    [
// i=3 we have'{' open bracket so push it in stack
// {                                      [{
// i=4 we have '}' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '{' corresponding open brackets so it is valid
// }                                      [
// i=5 we have'(' open bracket so push it in stack
// (                                      [(
// i=6 we have ')' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '(' corresponding open brackets so it is valid
// )                                        [
// i=7 we have ']' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '[' corresponding open brackets so it is valid
// ]                                       empty
// so we traverse whole string and in last we have stack empty so given string is valid

// example- string="()[{}(])"
// we start traversing the string from i=0
// and we have stack that store char

//  i                                stack
// i=0 we have'(' open bracket so push it in stack
//  (                                 (
// i=1 we have ')' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '(' corresponding open brackets so it is valid
// )                                      empty
// i=2 we have'[' open bracket so push it in stack
// [                                    [
// i=3 we have'{' open bracket so push it in stack
// {                                      [{
// i=4 we have '}' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '{' corresponding open brackets so it is valid
// }                                      [
// i=5 we have'(' open bracket so push it in stack
// (                                      [(
// i=6 we have ']' closed bracket so we check stack is empty or not so for now stack is not empty so we pop out top and we get '(' which is not corresponding to ']' this closed bracket so this is not valid we return false

// function to check the given string has valid parentheses

// t.c-O(n) we traverse each char in string once
// s.c-O(n) in worst case when all brackets are open so this is stack space

bool isValid(string s)
{
  int n = s.size();
  if (n <= 1)
    return false;
  // stack to store opening brackets as a character
  // we store only open brackets in stack because whenever we get closed bracket we try to get its corresponding open bracket from stack and if we don't get then given string is invalid
  stack<char> st;
  // traverse given string
  for (int i = 0; i < n; i++)
  {
    char ch = s[i];
    // if current character is open brackets push it in the stack
    if (ch == '(' || ch == '{' || ch == '[')
      st.push(ch);
    // if current character is closed bracket
    else
    {
      // it stack is empty then there is no open bracket for current closed bracket so invalid string
      if (st.empty())
        return false;
      // pop out top elt of the stack
      char elt = st.top();
      st.pop();
      // check for matching pair
      if ((ch == ')' && elt == '(') || (ch == ']' && elt == '[') || (ch == '}' && elt == '{'))
        continue; // skip that because it is valid
      else
        return false; // means when we don't get corresponding open bracket
    }
  }
  return st.empty(); // true if all brackets matched means stack is empty
}

int main()
{
  string s;
  cin >> s;
  cout << isValid(s);
  return 0;
}