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

// in case of array we return array but in linkedlist we don't return linked list we return head pointer by that we traverse whole linked list

// where N is lengthofLL
// t.c-O(arr size) for conversion
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
int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToLL(arr);
  cout << head->data << endl; // o/p=12 for next elt traverse in linked list
  // Never ever move the head because if we move head, we forgot the starting point so we take temp which also point head and we move temp not head
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}