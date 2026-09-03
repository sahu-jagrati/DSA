// Problem Statement: You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.
// Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.

// Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

// Examples
// Example 1:
// Input:
//  expression = "+ab
// Output:
//  (a+b)

// Example 2:
// Input:
//  expression = "*+ab-cd
// Output:
//  ((a+b)*(c-d))

#include <bits/stdc++.h>
using namespace std;

// approach:

// Traverse the prefix expression from right to left.
// Use a stack to store operands.
// For each operator, pop two operands from the stack, wrap them in parentheses, and push the resulting expression back.
// The final item in the stack will be the infix expression.

// here in prefix, operators are before  operands so we traverse from right to left
// and when we get operators, we  pop two operands from the stack and put the operator between them so if t1 is first top and t2 is second top then we put operator like t1 + operator + t2  and wrapped them in parentheses and push back in stack so (t1+operator+t2)

// example: prefix: *+PQ-MN
// we start iteration from right to left
// and we have stack in that we put operands as a string
// here size=7
// so we start from i=6

//   i                             stack
// i=6 we have 'N' put in stack
//   N                               N
// i=5 we have 'M' put in stack
//   M                               N,M
// i=4 we have '-' so this is operator so we pop from stack t1=M and t2=N so we get after wrapped in parentheses (M-N) push back it in stack
//  -                                (M-N)
// i=3 we have 'Q' put in stack
//   Q                                (M-N),Q
// i=2 we have 'P' put in stack
//   P                                 (M-N),Q,P
// i=1 we have '+' so this is operator so we pop from stack t1=P and t2=Q so we get after wrapped in parentheses (P+Q) push back it in stack
//   +                                 (M-N),(P+Q)
//  i=0 we have '*' so this is operator so we pop from stack t1=(P+Q) and t2=(M-N) so we get after wrapped in parentheses ((P+Q)*(M-N)) push back it in stack
//   *                                 ((P+Q)*(M-N))
// we finish iteration so our answer is st.top()=((P+Q)*(M-N)) 

// function to convert prefix to infix
// Time Complexity: O(n) where n is the length of the prefix expression (only one pass).

// Space Complexity: O(n) for the stack used to store operands.
string prefixToInfix(string prefix)
{
  // stack to store operands as a string
  stack<string> st;
  int n = prefix.size();
  // traverse the prefix expression from right to left
  for (int i = n - 1; i >= 0; i--)
  {
    char ch = prefix[i];

    // if the character is an operand, push it into the stack
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
      // form the new infix expression
      string str = "(" + t1 + ch + t2 + ")";
      // push back to stack
      st.push(str);
    }
  }
  // the final elt in the stack is the result
  return st.top();
}

int main()
{
  string prefix;
  cin >> prefix;
  cout << "Prefix Expression: " << prefix << endl;
  cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
  return 0;
}