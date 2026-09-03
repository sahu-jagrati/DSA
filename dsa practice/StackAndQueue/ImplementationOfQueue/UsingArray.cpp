// here we implement queue using array
// so queue is of fixed size no dynamic size

// implementing queue using array means we have queue as an array and we have to perform the push,pop,top operation on the queue array

// approach

// Declare an Array of a Particular Size: Declare an array to store the elements of the queue. The size of this array is determined when the queue is initialized.
// Define Variables:
// start: Tracks the index of the front element.
// end: Tracks the index of the last element.
// size: Keeps the current number of elements in the queue.
// capacity: The maximum number of elements the queue can hold.
// Push Operation (push(int x)):
// Check if the queue is full by comparing size with capacity. If not full:
// Increment the end using modular arithmetic to wrap around if necessary.
// Insert the element at the rear index.
// Increment the size.
// Pop Operation (pop()):
// Check if the queue is empty by comparing size with 0. If not empty:
// Return the element at the front index.
// Increment the start using modular arithmetic to wrap around if necessary.
// Decrement the size.
// Peek Operation (peek()):
// Check if the queue is empty. If not empty, return the element at the front index.
// IsEmpty Operation (isEmpty()):
// Check if size is 0 to determine if the queue is empty.

// queue: FIFO

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1) for all operations (push, pop, peek, isEmpty) since they involve simple index manipulations and array accesses.

// Space Complexity: O(1) since we are using a fixed-size array and a few variables.
// if user give the size s.c-O(N) where N is the maxSize given by user
class ArrayQueue
{
  // Array to store queue elements
  int *queueArray;
  // Indices for start and end of the
  int start, end;
  // Current size and maximum size of the queue
  int currSize, maxSize;

public:
  // Constructor
  // i didn't take any size from user I fixed it
  ArrayQueue()
  {
    queueArray = new int[10]; // fixed the size of queuearray
    // initialy start and end both are at -1
    // queue is FIFO so we want start and end two index to maintain because we push at the end but pop out from the front 
    start = -1;
    end = -1;
    currSize = 0;
    maxSize = 10;
  }
  // push function
  void push(int x)
  {
    // if queue is full
    if (currSize == maxSize)
    {
      cout << "Queue is full" << endl;
      exit(1);
    }
    // first check if queue array is empty this by if end==-1, intialize start and end both
    if (end == -1)
    {
      start = 0;
      end = 0;
    }
    // if queue is not empty then we increase only end because start is for top elt which first elt that we inser
    else
    {
      // circular increment of end means suppose we reach the last index of array but in queue is FIFO so when we pop it remove from start so there can empty indeices in starting so we push in them so
      end = (end + 1) % maxSize;
    }
    // above first we increse the end index then we push because end intitialize with -1
    queueArray[end] = x;
    currSize += 1;
  }
  // pop function
  int pop()
  {
    // check queue is empty
    if (start == -1)
    {
      cout << "Queue is empty" << endl;
      exit(1);
    }
    // in queue FIFO so we pop start index elt so for that first we store that elt then we increase start by circularly
    int popped = queueArray[start];
    // if the queue has only one elt, then reset both start and end
    if (currSize == 1)
    {
      start = -1;
      end = -1;
    }
    else
    {
      // circular increment of start
      start = (start + 1) % maxSize;
    }
    currSize--;
    return popped;
  }
  // top elt
  int peek()
  {
    // if queue is empty
    if (start == -1)
    {
      cout << "Queue is empty" << endl;
      exit(1);
    }
    return queueArray[start];
  }
  // queue is empty or not
  bool isEmpty()
  {
    return currSize == 0;
  }
};

int main()
{
  // make object of class ArrayQueue
  ArrayQueue q;
   // List of commands
  vector<string> commands = {"ArrayQueue", "push", "push", "peek", "pop", "isEmpty"};
   // List of inputs
  vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}}; // according to above commands
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
    else if (commands[i] == "ArrayQueue")
    {
      cout << "null" << " ";
    }
  }
  return 0;
}