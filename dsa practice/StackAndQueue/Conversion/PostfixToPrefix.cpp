// Problem Statement: You are given a valid postfix expression as a string, where:
// Operands are single lowercase English letters ('a' to 'z')
// Operators are binary: '+', '-', '*', '/'
// The expression contains no spaces and is guaranteed to be valid.

// Write a function to convert the postfix expression into a prefix expression, also as a string without spaces.

// Examples
// Example 1:
// Input:
//  expression = "ab+"
// Output:
//  "+ab"
// Explanation:
//  Postfix → Prefix

// Example 2:
// Input:
//  expression = "abc*+d-"
// Output:
//  "-+a*bcd"

#include <bits/stdc++.h>
using namespace std;

// approach:

// as in prefix operators are before operands
// and in postfix operators are after operands

// Traverse the postfix expression from left to right.
// Use a stack to store operands.
// For each operator, pop two operands, combine them with the operator in prefix order, and push the result back.
// The final item in the stack will be the prefix expression.

// here in postfix, operators are after operands so we traverse from left to right
// and when we get operators, we pop two operands from the stack and put the operator before  them so if t1 is first top and t2 is second top then we put operator like operator+t2+t1  and push back in stack so operator+t2+t1   , here we don't wrapped them with parentheses

// example: postfix=AB-DE+F*/
// // we start iteration from  left to right
// and we have stack in that we put operands as a string
// here size=9
// so we start from i=0

//  i                             stack
// i=0 we have 'A' put it in stack
//  A                               A
// i=1 we have 'B' put it in stack
// B                                A,B
// i=2 we have '-' operator so we pop two operands from the stack so we get t1=B and t2=A so we combine them like operator+t2+t1 so we get -AB and push it back in stack
//  -                               -AB
// i=3 we have 'D' put it in stack
//  D                               -AB,D
// i=4 we have 'E' put it in stack
//  E                                -AB,D,E
// i=5 we have '+' operator so we pop two operands from the stack so we get t1=E and t2=D so we combine them like operator+t2+t1 so we get +DE and push it back in stack
//  +                                 -AB,+DE
// i=6 we have 'F' put it in stack
//  F                                  -AB,+DE,F
// i=7 we have '*' operator so we pop two operands from the stack so we get t1=F and t2=+DE so we combine them like operator+t2+t1 so we get *+DEF and push it back in stack
//  *                                  -AB,*+DEF
// i=8 we have '/' operator so we pop two operands from the stack so we get t1=*+DEF and t2=-AB so we combine them like operator+t2+t1 so we get /-AB*+DEF and push it back in stack
//  /                                 /-AB*+DEF

// we finish our iteration and we get our answer which is st.top()= /-AB*+DEF

// function to convert postfix to prefix
// Time Complexity: O(n), single pass through the expression.

// Space Complexity: O(n), stack space for storing intermediate results.
string postfixToPrefix(string postfix)
{
  // stack to store operands as a string
  stack<string> st;
  int n = postfix.size();
  // traverse the postfix expression from left to right
  for (int i = 0; i < n; i++)
  {
    char ch = postfix[i];
    // if the character is an operand, push it to the stack
    if (isalnum(ch))
    {
      st.push(string(1, ch)); // here we convert ch into string and 1 denotes that in string, ch is only 1 time
    }
    // if the character is operator
    else
    {
      // pop two operands from the stack
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      // form the new prefix expression
      string str = ch + t2 + t1;
      // push back to stack
      st.push(str);
    }
  }
  // the final elt in the stack is our answer
  return st.top();
}

int main()
{
  string postfix;
  cin >> postfix;
  cout << "Postfix Expression: " << postfix << endl;
  cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
  return 0;
}