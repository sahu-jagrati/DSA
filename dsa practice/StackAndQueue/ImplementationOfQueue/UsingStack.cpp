// implementing queue using stack
// implementing  queue using stack means we have queue as an stack and we have to perform the push,pop,top operation on the  queue stack

// we know queue is FIFO

// previously we implementing queue using array and LinkedList and we are using two variables/pointers which are start and end so here also for implementing queue using stack we use two stack

#include <bits/stdc++.h>
using namespace std;

// approach 1: Using two stacks where push operation is O(N)
// Use Two Stacks: Maintain two stacks, stack1 and stack2.
// Push Operation:
// Transfer all elements from stack1 to stack2.
// Add the new element to stack1.
// Transfer all elements back from stack2 to stack1.
// This ensures the new element is always at the front for the next pop operation.
// Pop Operation: Remove and return the top element from stack1.
// Top Operation: Return the top element of stack1 without removing it.
// Size Operation: Return the size of stack1.

// Queue implementation using stack
// Time Complexity: O(2n) for push operation, O(1) for pop and peek operations.

// Space Complexity: O(2n) for storing elements in the stacks.
class StackQueue
{
private:
  // we use built-in library of stack
  stack<int> st1, st2;

public:
  // empty constructor
  StackQueue() {}
  // push function
  // s1 to s2 push all elts
  // then push x into s1
  // then s2 to s1 push all elts
  // This ensures the new element is always at the front for the next pop operation.
  void push(int x)
  {
    /* Pop out elements from the first stack
       and push on top of the second stack */
    while (!st1.empty())
    {
      st2.push(st1.top());
      st1.pop();
    }
    // insert the new elt in st1
    st1.push(x);
    /* Pop out elements from the second stack
and push back on top of the first stack */
    while (!st2.empty())
    {
      st1.push(st2.top());
      st2.pop();
    }
  }

  // pop function
  int pop()
  {
    // edge case
    if (st1.empty())
    {
      cout << "Stack is empty";
      return -1;
    }
    // get the top elt
    int topElt = st1.top();
    st1.pop();
    return topElt;
  }
  // to get the front elt
  int peek()
  {
    // Edge case
    if (st1.empty())
    {
      cout << "Stack is empty";
      return -1; // Representing empty stack
    }
    return st1.top();
  }
  bool isEmpty()
  {
    return st1.empty();
  }
};

// approach 2: Using Two Stacks Where Push Operation is O(1) but top and pop take O(n)
// Use Two Stacks: Maintain two stacks, inputStack and outputStack.
// Push Operation:
// Add the element to inputStack. This operation is efficient and always takes O(1) time.
// Pop Operation:
// If the outputStack is empty, move all elements from inputStack to outputStack. This reversal of order ensures that the oldest element is on top of the outputStack.
// Remove and return the top element from outputStack. This represents the oldest element in the queue.
// Top Operation:
// If the outputStack is empty, move all elements from inputStack to outputStack to access the oldest element.
// Return the top element of outputStack without removing it. This gives the element that has been in the queue the longest.
// Size Operation:
// Return the sum of the sizes of both stacks. This total gives the number of elements currently in the queue.

// Time Complexity: O(1) for push operation, O(n) for pop and O(n) peek operations in the worst case when elements need to be shifted. so O(2n)

// Space Complexity: O(2n) for storing elements in the two stacks.
class Stackqueue
{
public:
  stack<int> input, output;
  // empty constructor
  Stackqueue() {}

  // push function
  // push elt in input stack
  void push(int x)
  {
    input.push(x);
  }
  // pop function
  // Removes the element from in front of queue and returns that element
  int pop()
  {
    // shift input stack to output stack if output stack is empty
    if (output.empty())
    {
      while (!input.empty())
      {
        output.push(input.top());
        input.pop();
      }
    }
    // If queue is still empty, return -1
    // edge case
    if (output.empty())
    {
      cout << "Queue is empty, cannot pop." << endl;
      return -1;
    }
    int popped = output.top();
    output.pop();
    return popped;
  }
  // get the front elt
  int peek()
  {
    // shift input stack to output stack if output stack is empty
    if (output.empty())
    {
      while (!input.empty())
      {
        output.push(input.top());
        input.pop();
      }
    }
    // If queue is still empty, return -1
    // edge case
    if (output.empty())
    {
      cout << "Queue is empty, cannot peek." << endl;
      return -1;
    }
    return output.top();
  }
  // check empty
  // Returns true if the queue is empty, false otherwise
  bool isEmpty()
  {
    return input.empty() && output.empty(); // we check both because in pop and peek function we push elt from input stack to output stack and make input stack empty but we have an elt in output stack so we check both stack
  }
};

int main()
{
  // StackQueue q;
  Stackqueue q;

  // List of commands
  vector<string> commands = {"StackQueue", "push", "push",
                             "pop", "peek", "isEmpty"};
  // List of inputs
  vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

  for (int i = 0; i < commands.size(); ++i)
  {
    if (commands[i] == "push")
    {
      q.push(inputs[i][0]);
      cout << "null ";
    }
    else if (commands[i] == "pop")
    {
      cout << q.pop() << " ";
    }
    else if (commands[i] == "peek")
    {
      cout << q.peek() << " ";
    }
    else if (commands[i] == "isEmpty")
    {
      cout << (q.isEmpty() ? "true" : "false") << " ";
    }
    else if (commands[i] == "StackQueue")
    {
      cout << "null ";
    }
  }

  return 0;
}