// Problem Statement: You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.

// Prefix (Polish) notation places the operator before operands.
// Postfix (Reverse Polish) notation places the operator after operands.

// Examples
// Example 1:
// Input:
//  expression = "+ab
// Output:
//  ab+

// Example 2:
// Input:
//  expression = "*+ab-cd
// Output:
//  ab+cd-*

#include <bits/stdc++.h>
using namespace std;

// approach:
// Traverse the prefix expression from right to left.
// Use a stack to store operands.
// For each operator, pop two operands from the stack, combine them with the operator, and push the result back.
// The final item in the stack will be the postfix expression.

// here in prefix, operators are before operands so we traverse from right to left
// and when we get operators, we pop two operands from the stack and put the operator after them so if t1 is first top and t2 is second top then we put operator like t1 + t2 + operator  and push back in stack so t1+t2+operator   , here we don't wrapped them with parenthese

// example: prefix: /-AB*+DEF
// // we start iteration from right to left
// and we have stack in that we put operands as a string
// here size=9
// so we start from i=8

// i                           stack
// i=8 we have 'F' put it in stack
//  F                            F
// i=7 we have 'E' put it in stack
//  E                            F,E
// i=6 we have 'D' put it in stack
//  D                            F,E,D
// i=5 we have '+' operator so we pop two operands from stack say t1=D and t2=E so we get t1+t2+operator so DE+ and push it back on stack without wrapped in parentheses
// +                              F, DE+
// i=4 we have '*' operator so we pop two operands from stack say t1=DE+ and t2=F so we get t1+t2+operator so DE+F* and push it back on stack without wrapped in parentheses
//  *                           DE+F*
// i=3 we have 'B' put in stack
// B                            DE+F*,B
// i=2 we have 'A' put in stack
// A                            DE+F*,B,A
// i=1 we have '-' operator so we pop two operands from stack say t1=A and t2=B so we get t1+t2+operator so AB- and push it back on stack without wrapped in parentheses
//  -                           DE+F*,AB-
// i=0 we have '/' operator so we pop two operands from stack say t1=AB- and t2=DE+F* so we get t1+t2+operator so AB-DE+F*/ and push it back on stack without wrapped in parentheses
//  /                          AB-DE+F*/

// we finish our iteration and get our answer which is st.top()=AB-DE+F*/

// function to convert prefix to postfix
// Time Complexity: O(n), single pass through the expression.

// Space Complexity: O(n), stack space for storing intermediate results.
string prefixToPostFix(string prefix)
{
  // stack to store operands as a string
  stack<string> st;
  int n = prefix.size();
  // traverse the prefix expression from right to left
  for (int i = n - 1; i >= 0; i--)
  {
    char ch = prefix[i];
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

      // form the new postfix expression without wrapped in parentheses
      string str = t1 + t2 + ch;
      // push back in stack
      st.push(str);
    }
  }
  // the final elt in the stack is our answer
  return st.top();
}

int main()
{
  string prefix;
  cin >> prefix;
  cout << "Prefix Expression: " << prefix << endl;
  cout << "Postfix Expression: " << prefixToPostFix(prefix) << endl;
  return 0;
}