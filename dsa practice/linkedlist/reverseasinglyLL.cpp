#include <bits/stdc++.h>
using namespace std;

class Node
{ // or you can use struct
public:
  int data;
  Node *next;
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

Node *convertArrToLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp; // or mover=mover->next because mover->next = temp now
  }
  return head;
}

void traverselInLL(Node *head)
{
  Node *temp = head;
  while (temp) // not nullptr run
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// naive solution-data replacement
// t.c-O(2N)
// s.c-O(N)for stack
// where N is length of LL
Node *reverseLL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  // step-1
  Node *temp = head;
  stack<int> st;
  while (temp != NULL)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  // step-2
  temp = head;
  while (temp != NULL)
  {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

// optimized solution-by changing links and do in one traverse
// Ist-iterative way-
// t.c-O(N)
// s.c-O(1)
// where N is length of LL
Node *reverseSinglyLL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL)
  {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;

    temp = front;
  }
  return prev;
}

// IInd recursive way
// t.c-O(N)
// s.c-O(N) recursive stack space
// where N is length of LL
Node *reversesinglyLL(Node *head)
{
  // base case
  if (head == NULL || head->next == NULL)
    return head;
  Node *newHead = reversesinglyLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}
int main()
{
  vector<int> arr = {1, 2, 3, 5};
  vector<int> arr1 = {1};
  Node *head = convertArrToLL(arr1);
  traverselInLL(head);
  cout << endl;
  cout << "After reverse the singly LL: ";
  // head = reverseLL(head);
  // head = reverseSinglyLL(head);
  head = reversesinglyLL(head);
  traverselInLL(head);

  cout << endl;
  return 0;
}