// Problem Statement: Given a valid infix expression, Your task is to convert the given infix expression to a prefix expression.

// Examples
// Example 1:
// Input:
//  x + y * z / w + u
// Output:
//  ++x/*yzwu
// Explanation:

// The infix expression "x + y * z / w + u" is converted to prefix form as "++x/*yzwu" by applying the rules of infix to prefix conversion.

// Example 2:
// Input:
//  a + b
// Output:
//  +ab
// Explanation:

// The infix expression "a + b" is converted to prefix form as "+ab".

#include <bits/stdc++.h>
using namespace std;

// Approach to Convert Infix Expression to Prefix:

// Reverse the given infix expression.
// Scan the expression from left to right.
// When an operand is encountered, print it directly.
// If the operator is encountered and the stack is empty, push the operator into the stack.
// If the incoming operator has higher precedence than the top of the stack, push it into the stack.
// If the incoming operator has the same precedence as the top of the stack, push it into the stack.
// If the incoming operator has lower precedence than the top of the stack, pop and print the top of the stack. Then, test the incoming operator against the top of the stack again and continue popping operators from the stack until it finds an operator with lower or the same precedence.
// If the incoming operator has the same precedence as the top of the stack and the incoming operator is '^', pop the top of the stack until the condition is met. If not, push the '^' operator.
// If the operator is ')', push it into the stack.
// If the operator is '(', pop all operators from the stack until a ')' is encountered.
// If the top of the stack is ')', push the operator onto the stack.
// At the end of the expression, pop and print all remaining operators from the stack.
// Finally, reverse the output and print it as the prefix expression.

// approach:
// first reverse the given infix expression
// second convert the reverse infix expression into postfix but with some changes
// third again reverse and we get answers

// example: given infix: (A+B)*C-D+F
// first we reverse it so we get: F+D-C*)B+A(
// now we convert open bracket into closed bracket and vice versa
// so we get reverse infix= F+D-C*(B+A)
// now we convert this reverse infix into postfix with the some changes
// so we iterate over the reverse infix string with i=0

// i                         stack                       ans
// F                                                      F
// +                          +                           F
// D                          +                           FD
// here next we get '-' which has same priority like '+' so we directly push it in stack here , but in actual infix to postfix we pop out the '+' and add it in ans and then push '-' but here we push '-' directly without popping '+' so this is change here
// -                          +-                          FD
// C                          +-                          FDC
// *                          +-*                         FDC
// (                          +-*(                        FDC
// B                          +-*(                        FDCB
// +                          +-*(+                       FDCB
// A                          +-*(+                       FDCBA
// )                          +-*                         FDCBA+
//                                                        FDCBA+*-+

// so we get postfix here : FDCBA+*-+
// now we reverse it to get prefix : +-*+ABCDF so this is our answer

// function to check if a character is an operator, not an operand
bool isOperator(char ch)
{
  return (!isalpha(ch) && (!isdigit(ch))); // If the character is neither alphabetic nor numeric, it's an operator
}

// function to return the precedence(priority) of operators
int getPriority(char ch)
{
  if (ch == '^')
    return 3; // Exponent operator has highest precedence
  else if (ch == '*' || ch == '/')
    return 2; // Multiplication and division have higher precedence than addition
  else if (ch == '+' || ch == '-')
    return 1; // Addition and subtraction have lowest precedence
  else
    return -1;
}

// function to convert infix to postfix expression
string infixToPostfix(string infix)
{
  infix = '(' + infix + ')'; // add parentheses to handle edge cases
  int n = infix.size();
  stack<char> st; // stack to store operators
  string output;  // string to store the resulting postfix expression

  // traverse give string
  for (int i = 0; i < n; i++)
  {
    // if the scanned character is an operand, add it to the output
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    // if the scanned character is '(', push it to the stack
    else if (infix[i] == '(')
    {
      st.push('(');
    }
    // if the scanned character is ')',pop and add in output from the stack until an '(' is encountered
    else if (infix[i] == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        output += st.top();
        st.pop();
      }
      st.pop(); // remove '(' from the stack
    }
    // if an operator is found
    // there is changes from the infix to postfix  actual code  that we write in its file
    else
    {
      if (isOperator(st.top()))
      {

        if (infix[i] == '^')
        {
          while (!st.empty() && getPriority(infix[i]) <= getPriority(st.top()))
          {
            output += st.top();
            st.pop();
          }
        }
        else
        {
          // in infix to postfix file we check for <= but here we check only for < means suppose in stack at top we have '+' and current we have '-' then we push '-' without pop '+' here but in infix to postfix file we pop '+' then we push '-' so here we push the current when they have equal or less priority
          while (!st.empty() && getPriority(infix[i]) < getPriority(st.top()))
          {
            output += st.top();
            st.pop();
          }
        }
        // push current operator on stack
        st.push(infix[i]);
      }
    }
  }
  // pop all remaining elts from the stack
  while (!st.empty())
  {
    output += st.top();
    st.pop();
  }
  return output;
}

// function to convert infix to prefix expression
// t.c-O(n/2)(for reverse)+O(n)(for convert brackets)+O(2n)(for infix to postfix)+O(n/2)(again reverse)=O(n)
// Time Complexity: O(n), where n is the length of the infix expression. Each character is processed once.

// Space Complexity: O(n), where n is the length of the infix expression. The stack can hold at most N characters in the worst case

string infixToPrefix(string infix)
{
  int n = infix.size();
  // reverse the given infix expression
  // t.c-O(n/2) , done by two pointers, here we use built-in function
  reverse(infix.begin(), infix.end());
  // suppose we have : infix=(A+B)*C-D+F then after reverse we get this : F+D-C*)B+A( , so here we convert the ')' (i.e closed bracket) with '(' (open bracket) this and convert '(' this to ')' i.e closed to open bracket and open bracket to closed bracket
  // Replace '(' with ')' and vice versa
  // t.c-O(n)
  for (int i = 0; i < n; i++)
  {
    if (infix[i] == '(')
    {
      infix[i] = ')';
      i++;
    }
    else if (infix[i] == ')')
    {
      infix[i] = '(';
      i++;
    }
  }
  // t.c-O(2n),not O(n^2)
  string prefix = infixToPostfix(infix); // convert the modified (i.e reverse) infix to postfix

  // reverse the postfix expression to get the prefix
  // t.c-O(n/2), done by two pointers, here we use built-in function
  reverse(prefix.begin(), prefix.end());
  return prefix;
}

int main()
{
  string s = "(p+q)*(c-d)"; // infix expression
  cout << "Infix expression: " << s << endl;
  cout << "Prefix expression: " << infixToPrefix(s) << endl;
  return 0;
}