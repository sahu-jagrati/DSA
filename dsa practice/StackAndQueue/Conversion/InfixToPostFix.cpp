// Problem Statement: Given a valid infix expression, Your task is to convert the given infix expression to a postfix expression.

// Examples
// Example 1:
// Input:
//  a + b * (c^d - e) ^ (f + g * h) - i
// Output:
//  abcd^e-fgh*+^*+i-
// Explanation:

// The infix expression "a + b * (c^d - e) ^ (f + g * h) - i" is converted to postfix form as "abcd^e-fgh*+^*+i-" by applying the rules of infix to postfix conversion.

// Example 2:
// Input:
//  (p + q) * (m - n)
// Output:
//  pq+mn-*
// Explanation:

// The infix expression "(p + q) * (m - n)" is converted to postfix form as "pq+mn-*".

// approach:

// What is an infix expression?
// The traditional way of writing mathematical expressions is called infix expressions, where the operator is placed between two operands (e.g., A + B, (A * B) / Q).
// Infix expressions are easy for humans to understand, but computers find them difficult to parse because they require knowledge of operator precedence, associativity rules, and parentheses.
// To make it easier for computers, we use postfix and prefix notations.

// What is a postfix expression?
// A postfix expression has the operator placed after the operands (e.g., PQ-C/). It is written as .
// In postfix expressions, the precedence of operators is determined by the order in which they appear in the expression. The operator that appears first is applied to the operands.
// Postfix expressions do not require parentheses, making them easier for computers to evaluate.

// Approach to Convert Infix Expression to Postfix:

// Start by scanning the infix expression from left to right.
// If the scanned character is an operand, print it immediately.
// If the scanned character is an operator:
// If the precedence(priority) of the operator is greater than the operator in the stack, or the stack is empty, or the stack contains a ‘(’, push the operator into the stack.
// Otherwise, pop all operators from the stack with higher or equal precedence(priority) than the scanned operator, then push the scanned operator into the stack.
// If the scanned character is a ‘(’, push it into the stack.
// If the scanned character is a ‘)’, pop the stack and output the operators until a ‘(’ is encountered, and discard both parentheses.
// Repeat steps 2-5 until the entire infix expression has been scanned.
// Print the output.
// Finally, pop and print all remaining operators in the stack until it is empty.

// example: infix=:  a+b*(c^d-e)
// infix to postfix
// i start from 0
//  i(iteration)           stack                       ans string
//    a                                                 a
//    +                     +                           a
//    b                     +                           ab
//    *                     +*                          ab
//    (                     +*(                         ab
//    c                     +*(                         abc
//    ^                     +*(^                        abc
//    d                     +*(^                        abcd
//    -                     +*(-                        abcd^
//    e                     +*(-                        abcd^e
//    )                     +*                          abcd^e-
//                                                      abcd^e-*+

// so our postfix espression is : abcd^e-*+

#include <bits/stdc++.h>
using namespace std;

// function to return precedence(priority) of operators
int prec(char ch)
{
  if (ch == '^')
    return 3; // Exponent operator has highest precedence
  else if (ch == '/' || ch == '*')
    return 2; // Multiplication and division have higher precedence than addition
  else if (ch == '+' || ch == '-')
    return 1; // Addition and subtraction have lowest precedence
  else
    return -1;
}

// function to convert infix expression to postfix expression

// t.c-O(N)(for for loop)+O(N)(for inner while loops inside the for loop because in worst case it can be and throughout the whole journey they travel N, not for each i) +O(N)(for outer while loop when we pop remaining elts in worst case)=O(N)
// Time Complexity: O(N), where N is the length of the infix expression. Each character in the expression is processed once.

// s.c-O(N(for stack in worst case)+O(N)(for ans strind which is required)=O(N)
// Space Complexity: O(N), where N is the length of the infix expression. The stack can hold at most N operators and parentheses in the worst case.

void infixToPostfix(string s)
{
  stack<char> st; // Stack to hold operators and parentheses
  string ans;     // String to hold the resulting postfix expression

  // traverse string
  for (int i = 0; i < s.size(); i++)
  {
    char ch = s[i];
    // If the scanned character is an operand, add it to the result string
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
      ans += ch;
    // If the scanned character is an ‘(‘, push it to the stack
    else if (ch == '(')
      st.push('(');
    // If the scanned character is a ‘)’, pop from stack until an ‘(‘ is encountered
    else if (ch == ')')
    {
      while (st.top() != '(')
      {
        ans += st.top();
        st.pop();
      }
      st.pop(); // Pop the ‘(‘ from the stack
    }
    // If an operator is scanned
    else
    {
      // pop until the top has lowest priority then coming character
      while (!st.empty() && prec(ch) <= prec(st.top()))
      {
        ans += st.top();
        st.pop();
      }
      st.push(ch); // Push the current operator to the stack
    }
  }
  // Pop all the remaining elements from the stack when iteration finish
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }
  cout << "Postfix expression: " << ans << endl;
}

int main()
{
  string exp = "(p+q)*(m-n)"; // infix
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp); // return postfix
  return 0;
}