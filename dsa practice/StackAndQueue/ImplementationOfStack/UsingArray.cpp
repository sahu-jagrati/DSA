// here we implement stack using array
// so stack is of fixed size no dynamic size

// implementing stack using array means we have stack as an array and we have to perform the push,pop,top operation on the stack array

// approach
// Declare an Array of Particular Size: Initialize an array that will hold the elements of the stack. The size of the array is defined when the stack is created.
// Define a Variable “Top” and Initialize It as -1: The "top" variable keeps track of the index of the last added element in the stack. Initializing it to -1 indicates that the stack is empty.
// Push Operation (push(int x)): To push an element onto the stack:
// Increment the top index by one and insert the element at this position in the array.
// If the stack is full (top is equal to the last index of the array), throw a stack overflow exception.
// Pop Operation (pop()): To pop an element from the stack:
// Check if the stack is not empty by ensuring top is not equal to -1. If the stack is empty, throw a stack underflow exception.
// If the stack is not empty, return the element at the top index and then decrement the top index by one.
// Top Operation (top()): To get the top element without removing it:
// Check if the stack is not empty. If it is empty, throw an exception.
// If the stack is not empty, return the element at the top index.
// IsEmpty Operation (isEmpty()): To check if the stack is empty:
// Check if the top index is -1.
// Size Operation (size()): To get the current size of the stack:
// Return top + 1.

#include <bits/stdc++.h>
using namespace std;

// stack- LIFO
// Time Complexity: O(1) for all operations (push, pop, top, isEmpty).

// Space Complexity: O(N), where N is the maximum capacity of the stack, as we are using an array to store the elements.
class ArrayStack
{
  // array to hold elements
  int *stackArray;
  // maximum capacity
  int capacity;
  // index of top elt
  // stack is LIFO here we want only one index  because we push at the end and also pop from the end
  int topIndex;

public:
  // constructor
  ArrayStack(int size = 1000) // size=1000 by default if we don't give
  {
    capacity = size;
    stackArray = new int[capacity]; // update the size of an array
    // initialize stack as empty
    topIndex = -1; // means stack is empty
  }
  // Destructor
  ~ArrayStack()
  {
    delete[] stackArray;
  }
  // function to push elt
  void push(int x)
  {
    if (topIndex >= capacity - 1)
    {
      cout << "Stack Overlfow" << endl;
      return;
    }
    topIndex++; // first we increase topIndex because it initialize with -1
    stackArray[topIndex] = x;
  }
  // pop function
  int pop()
  {
    // first check stack is not empty
    if (topIndex == -1)
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return stackArray[topIndex--]; // means first return stackArray[topIndex] then decrease index
  }
  // returns top elt
  int top()
  {
    // first check stack is not empty
    if (topIndex == -1)
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return stackArray[topIndex];
  }
  // return true if stack is empty otherwise false
  bool isEmpty()
  {
    return topIndex == -1;
  }
};

int main()
{
  // make object of class ArrayStack
  ArrayStack st;
   // List of commands
  vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
   // List of inputs
  vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}}; // according to above commands
  for (size_t i = 0; i < commands.size(); i++)
  {
    if (commands[i] == "push")
    {
      st.push(inputs[i][0]);
      cout << "null" << " ";
    }
    else if (commands[i] == "pop")
    {
      cout << st.pop() << " ";
    }
    else if (commands[i] == "top")
    {
      cout << st.top() << " ";
    }
    else if (commands[i] == "isEmpty")
    {
      cout << (st.isEmpty() ? "true" : "false") << " ";
    }
    else if (commands[i] == "ArrayStack")
    {
      cout << "null" << " ";
    }
  }
  return 0;
}