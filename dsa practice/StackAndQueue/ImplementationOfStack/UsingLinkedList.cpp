// here we implement stack using linked list


// implementing stack using LL means we have stack as an LL and we have to perform the push,pop,top operation on the stack LL

// approach

// Node Structure:
// Define a node with:
// An integer to store data.
// A pointer to the next node.
// A constructor to initialize the data and the next pointer.
// Stack Structure:
// Define a stack with:
// A pointer to the top node.
// An integer to keep track of the size.
// A constructor to initialize the top pointer and size.
// Push Operation:
// Create a new node with the given data and set the new node's next pointer to the current top node.
// Update the top pointer to the new node and increment the size.
// Pop Operation:
// Check if the stack is empty. If it is, return an error value (e.g., -1).
// Store the data of the top node and update the top pointer to the next node.
// Delete the old top node and decrement the size. Return the stored data.
// Peek Operation:
// Check if the stack is empty. If it is, return an error value (e.g., -1).
// Otherwise, return the data of the top node.
// Is Empty Operation:
// Check if the top pointer is null. Return true if it is, otherwise false.
// Size Operation:
// Return the size of the stack.
// Print Stack:
// Traverse from the top node and print each node's data until reaching the end of the list.

#include <bits/stdc++.h>
using namespace std;

// Linked List structure
struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

// Time Complexity: O(1) for push, pop, size, isEmpty, peek operations.

// Space Complexity: O(N) because the stack requires space proportional to the number of elements it stores.

// stack is LIFO  
class LinkedListStack
{
private:
// stack is LIFO here we want only one pointer head because we push at the end and also pop from the end
  Node *head; // top of stack
  int size; // size of the stack

public:
  // constructor
  LinkedListStack()
  {
    head = NULL; // initially head == NULL means top elt =NULL
    size = 0;    // means we have no elt
  }
  // push function
  void push(int x)
  {
    // create a new node
    Node *elt = new Node(x);
    // we know stack is LIFO so coming elt become head and its next is old head
    elt->next = head; // updating the pointers
    head = elt;       // updating the top
    // size increase
    size += 1;
  }
  // pop
  int pop()
  {
    // check empty
    if (head == NULL)
    {
      return -1;
    }
    // pop elt is the head value
    int value = head->data;
    Node *temp = head; // store the top temporaily
    head = head->next; // Update top to next node
    delete temp;       // Delete old top node
    size--;            // Decrement size
    return value;      // Return data
  }
  // top
  int top()
  {
    // check empty
    if (head == NULL)
      return -1;
    return head->data;
  }
  // empty
  bool isEmpty()
  {
    return size == 0;
  }
};

int main()
{
  // make object of class LinkedListStack
  LinkedListStack st;
  // List of commands
  vector<string> commands = {"LinkedListStack", "push", "push", "pop", "top", "isEmpty"};
  // List of inputs
  vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}}; // according to above commands
  for (int i = 0; i < commands.size(); i++)
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
    else if (commands[i] == "LinkedListStack")
    {
      cout << "null" << " ";
    }
  }
  return 0;
}