// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head

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

// t.c-O(N) where N is length of LL
// s.c-O(1) we reuse the same nodes by using concept of dummynodes and not create new list
Node *removeElts(Node *head, int key)
{

  Node *dummyNode = new Node(-1);
  dummyNode->next = head; // initially next point to head
  Node *curr = dummyNode;
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == key)
    {
      curr->next = temp->next;
      delete temp;
      temp = curr->next;
    }
    else
    {
      curr = temp;
      temp = temp->next;
    }
  }
  head = dummyNode->next;
  delete dummyNode;
  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 3};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  int key;
  cout << "Enter the value that has to be deleted from LL: ";
  cin >> key;
  head = removeElts(head, key);
  cout << "After deleting all occurences of key: ";
  traverselInLL(head);
  cout << endl;
  return 0;
}