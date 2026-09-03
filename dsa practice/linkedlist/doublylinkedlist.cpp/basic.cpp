// in singly LL we know about data and next pointer, what is in next, not know about previous
// while in doubly linked list we have data,next pointer and prev pointer where prev pointer points to  what is previous

// starting point is always head and end point is always tail
#include <bits/stdc++.h>
using namespace std;

// you can use struct also
class Node
{
public:
  int data;
  Node *next;
  Node *back;
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

// t.c-O(arr size)
Node *convertArrToDLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void traverselDLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
int main()
{
  vector<int> arr = {1, 3, 2, 4};
  Node *head = convertArrToDLL(arr);
  cout << head->data << endl;
  traverselDLL(head);
  cout << endl;
  return 0;
}
