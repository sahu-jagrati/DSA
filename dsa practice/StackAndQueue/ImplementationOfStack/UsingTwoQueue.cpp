// Implementation of stack using two queue is similar to implementation of queue using two stack

#include <bits/stdc++.h>
using namespace std;

// for the push operation we do : first we push all elts of q1 into q2 then we push new elt into q1 then we push all elts of q2 into q1
class MyStack
{
  queue<int> q1;
  queue<int> q2;

public:
  MyStack()
  {
  }

  void push(int x)
  {
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    q1.push(x);
    while (!q2.empty())
    {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop()
  {
    if (q1.empty())
      return -1;
    int elt = q1.front();
    q1.pop();
    return elt;
  }

  int top()
  {
    if (q1.empty())
      return -1;
    return q1.front();
  }

  bool isEmpty()
  {
    return q1.empty();
  }
};

int main()
{
  // make object of class QueueStack
  MyStack st;
  // List of commands
  vector<string> commands = {"MyStack", "push", "push",
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
    else if (commands[i] == "MyStack")
    {
      cout << "null ";
    }
  }

  return 0;
}