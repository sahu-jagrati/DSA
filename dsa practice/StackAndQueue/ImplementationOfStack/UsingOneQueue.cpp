// implementing stack using queue
// implementing stack using queue means we have stack as an queue and we have to perform the push,pop,top operation on the stack queue

// we know satck is LIFO

// previously we implementing stack using array and LinkedList and we are using only one variable/pointer which is top so here also for implementing stack using Queue we use one queue

// approach
// Data Structure Used: A single queue will be used to store the elements.
// Push(x): Insert the element x into the queue. To maintain the stack order:
// Run a loop that iterates size() - 1 times, where size() is the current number of elements in the queue.
// In each iteration, remove the front element and add it back to the rear of the queue. This ensures that the most recently added element is always at the front of the queue.
// Pop(): Remove and return the front element of the queue, which corresponds to the top of the stack.
// isEmpty(): Return true if the queue is empty, and false otherwise.

// suppose we have
// Example 1:
// Input:

// ["QueueStack", "push", "push", "pop", "top", "isEmpty"]
// [[], [4], [8], [], [], []]
// Output:
//   [null, null, null, 8, 4, false]
// Explanation:
//   QueueStack stack = new QueueStack();
// - stack.push(4);
// - stack.push(8);
// - stack.pop(); // returns 8
// - stack.top(); // returns 4
// - stack.isEmpty(); // returns false

// we have queue - [] empty initially
// now there is a push(4)
// so queue is empty so we push it [4]
// again push(8)
// but in stack there is LIFO so what we do is first take the current size of queue before pushing the elt =size which is 1 and then push the 8 so we have queue=[4,8] now from index 0 to size-1 and take the q front and put it in queue again so we get now [8,4] // // we push the front elts into back of new elt so we get the last push elt in top
// now pop() now if pop we get 8
// top() we get 4

#include <bits/stdc++.h>
using namespace std;

// Stack implementation using Queue
// Time Complexity:
// Push operation: O(n) (where n is the number of elements in the queue at that time) because every time an element is pushed, all the elements in the queue are popped from the front and pushed in the back again.
// Pop operation: O(1) as constant operations are performed.
// Top operation: O(1) as constant operations are performed.
// IsEmpty operation: O(1) as constant operations are performed.

// Space Complexity: O(k) for storing k elements in the queue.
class QueueStack
{
  // we use built in queue library for queue
  queue<int> q;

public:
  // empty constructor
  QueueStack() {}
  // push function
  void push(int x)
  {
    // get the size of current queue before pushing the elt
    int size = q.size();
    // now we add the elt in queue
    q.push(x);
    // move elements before new elt to back
    for (int i = 0; i < size; i++)
    {
      q.push(q.front()); // we push the front elts into back of new elt so we get the last push elt in top
      q.pop();
    }
  }
  // pop function
  // pop elt from stack
  int pop()
  {
    // edge case
    if (q.empty())
    {
      cout << "Queue is empty";
      return -1;
    }
    // get front elt
    int elt = q.front();
    q.pop();
    return elt;
  }
  // return top elt
  int top()
  {
    // edge case
    if (q.empty())
    {
      cout << "Queue is empty";
      return -1;
    }
    return q.front();
  }
  // check empty
  bool isEmpty()
  {
    return q.empty();
  }
};

int main()
{
  // make object of class QueueStack
  QueueStack st;
  // List of commands
  vector<string> commands = {"QueueStack", "push", "push",
                             "pop", "top", "isEmpty"};
  // List of inputs
  vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

  for (int i = 0; i < commands.size(); ++i)
  {
    if (commands[i] == "push")
    {
      st.push(inputs[i][0]);
      cout << "null ";
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
    else if (commands[i] == "QueueStack")
    {
      cout << "null ";
    }
  }

  return 0;
}