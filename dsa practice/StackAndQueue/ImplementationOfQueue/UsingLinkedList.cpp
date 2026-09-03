// here we implement queue using linked list

// implementing queue using LL means we have queue as an LL and we have to perform the push,pop,top operation on the queue LL

// approach
// Node Structure: Define a node that holds data and a pointer to the next node. This node acts as the building block of the linked list used in the queue.
// Queue Initialization: Initialize the queue with pointers to both the front and rear of the queue. Set these pointers to null initially, indicating an empty queue. Also, maintain a counter to track the number of elements in the queue.
// Enqueue Operation (Adding an Element):
// Create a new node with the given data.
// If the queue is empty, set both the front and rear pointers to this new node.
// If the queue is not empty, link the current rear node to the new node and update the rear pointer to point to the new node.
// Dequeue Operation (Removing an Element):
// Check if the queue is empty. If it is, return an appropriate message or handle the empty condition.
// If the queue is not empty, move the front pointer to the next node and delete the old front node.
// If the queue becomes empty after removal, set the rear pointer to null.
// Peek Operation (Accessing the Front Element):
// Check if the queue is empty. If it is, return an appropriate message or handle the empty condition.
// If the queue is not empty, return the data of the front node without removing it.
// Size Operation: Return the value of the counter tracking the number of elements in the queue.
// IsEmpty Operation: Check if the front pointer is null. If it is, the queue is empty; otherwise, it is not.

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

// Space Complexity: O(N) because the queue requires space proportional to the number of elements it stores.

class LinkedListQueue
{
private:
  // queue is FIFO so we want start and end two pointers to maintain because we push at the end but pop out from the front 
  Node *start; // start of the queue
  Node *end;   // end of the queue
  int size;    // size of the queue

public:
  // constructor
  LinkedListQueue()
  {
    start = end = NULL; // initially bot start and end == NULL
    size = 0;           // means we have no elt
  }
  // push function
  void push(int x)
  {
    // create a new node
    Node *elt = new Node(x);
    // we know queue is  FIFO so first we check it is first elt being pushed if it is first elt then both pointer start and end move otherwise only end move
    if (start == NULL)
    {
      start = end = elt;
    }
    else
    {
      end->next = elt; // Updating the pointers
      end = elt;       // Updating the end
    }
    // size increase
    size += 1;
  }
  // pop
  int pop()
  {
    // check empty
    if (start == NULL)
    {
      return -1;
    }
    // pop elt is the start value because FIFO
    int value = start->data;
    Node *temp = start;  // store the front temporaily
    start = start->next; // Update start to next node
    delete temp;         // Delete old start node
    size--;              // Decrement size
    return value;        // Return data
  }
  // top
  int peek()
  {
    // check empty
    if (start == NULL)
      return -1;
    return start->data;
  }
  // empty
  bool isEmpty()
  {
    return size == 0;
  }
};

int main()
{
  // make object of class LinkedListQueue
  LinkedListQueue q;
  // List of commands
  vector<string> commands = {"LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"};
  // List of inputs
  vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}}; // according to above commands
  for (int i = 0; i < commands.size(); i++)
  {
    if (commands[i] == "push")
    {
      q.push(inputs[i][0]);
      cout << "null" << " ";
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
    else if (commands[i] == "LinkedListQueue")
    {
      cout << "null" << " ";
    }
  }
  return 0;
}