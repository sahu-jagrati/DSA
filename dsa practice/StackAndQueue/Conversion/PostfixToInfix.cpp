// Problem Statement: Given a valid postfix expression (a string), convert it into an equivalent infix expression. The postfix expression is evaluated from left to right. The infix expression should have the proper parentheses to ensure correct operator precedence.

// Write a function to perform this conversion.

// Examples
// Example 1:
// Input:
//  "ab+c*"
// Output:
//  "(a+b)*c"

// Example 2:
// Input:
//  "ab*cd/+"
// Output:
//  "(a*b)+(c/d)"

#include <bits/stdc++.h>
using namespace std;

// approach:

// Traverse the postfix expression from left to right.
// Use a stack to store operands.
// For each operator, pop two operands, combine them in infix order with parentheses, and push the result back.
// The final item in the stack will be the infix expression.

// so this time we does not use answer string and this time we push operands in stack
// and whenever an operators come we pop out two top elts from the stack and put the operator between them and around them with parenthesis and put back in stack
// and in last whatever in the stack is our answer

// example: postfix="AB-CD+E*/"

// start from i=0 and we stack that takes operands
// i                        stack
// i=0 'A' put in stack
// A                         A
// i=1 'B' put in stack
// B                         A,B
// i=2 '-' this is an operator so we pop out two top elts from the stack and put operator between them so at top we have 'A' and 'B' so we get (A-B) and push it back in stack
// -                         (A-B),
// i=3 'c' put in stack
// C                         (A-B),C
// i=4 'D' put in stack
// D                          (A-B),C,D
// i=5 '+' this is an operator so we pop out two top elts from the stack and put operator between them so at top we have 'C' and 'D' so we get (C+D) and push it back in stack
// +                          (A-B),(C+D)
// i=6 'E' put in stack
// E                          (A-B),(C+D),E
// i=7 '*' this is an operator so we pop out two top elts from the stack and put operator between them so at top we have '(C+D)' and 'E' so we get ((C+D)*E) and push it back in stack
// *                          (A-B),((C+D)*E)
// i=8 '/' this is an operator so we pop out two top elts from the stack and put operator between them so at top we have '((C+D)*E)' and '(A-B)' so we get ((A-B)/((C+D)*E)) and push it back in stack
// /                          ((A-B)/((C+D)*E))
// expression finish so in stack we have :"((A-B)/((C+D)*E))" this is our infix expression

// function to convert postfix to infix

// t.c-O(n),  a single pass over the postfix expression and in some languages there can be a t.c for adding(concatenating) the string so in that cases: + O(n) extra
// s.c-O(n) in worst case for stack
string postfixToInfix(string postFix)
{
  // stack for storing operands
  stack<string> st; // in stack we store as a string
  int n = postFix.size();
  // traverse the postfix expression from left to right
  for (int i = 0; i < n; i++)
  {
    char ch = postFix[i];
    // if the character is an operand , push it into the stack
    if (isalnum(ch))
    {
      st.push(string(1, ch)); // here we convert ch into string and 1 denotes that in string, ch is only 1 time
    }
    // if the character is operator
    else
    {
      // pop two operands from the stack
      string op2 = st.top(); //
      st.pop();
      string op1 = st.top();
      st.pop();
      // form the new infix expression and push back to stack
      string expression = '(' + op1 + ch + op2 + ')'; // in expression op1 and op2 you can understand by taking an example
      st.push(expression);
    }
  }
  // the final elt in the stack is the result
  return st.top();
}

int main()
{
  string postfix;
  cin >> postfix;
  cout << "Postfix Expression: " << postfix << endl;
  cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
  return 0;
}