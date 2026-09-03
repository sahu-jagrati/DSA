// given sorted DLL - delete all duplicates from it
// we have sorted DLL so duplicates are also in contiguous manner
// so we do traversal and delete duplicates

#include <bits/stdc++.h>
using namespace std;

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

void traverseDLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// what is nextNode?
// nextNode is the first elt that is not equivalent to the current node
// when temp reaches to last node or if it reaches NULL we stop there is nothing in the next

// t.c-O(N), not O(N^2) because outer while loop(i.e temp) covers those node that are not duplicates and inner while loop(i.e nextNode)covers those node that are duplicates, so both combine travel whole node of DLL, so t.c-O(N) where N is length of DLL
// s.c-O(1)
Node *deleteDuplicates(Node *head)
{
  Node *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    Node *nextNode = temp->next;
    // if there is nextNode and move it until it is not equivalent to current node
    while (nextNode != NULL && nextNode->data == temp->data)
    {
      // when nextNode->data==temp->data then delete it
      Node *duplicate = nextNode;
      nextNode = nextNode->next;
      free(duplicate);
    }
    temp->next = nextNode; // when they are not equivalent
    // if there is nextnode
    if (nextNode != NULL)
    {
      nextNode->back = temp;
    }
    temp = temp->next; // means to nextNode which is not equivalent to temp
  }
  return head;
}

int main()
{
  vector<int> arr = {1, 1, 1, 2, 3, 3, 4}; // sorted
  Node *head = convertArrToDLL(arr);
  traverseDLL(head);
  cout << endl;
  cout << "After deleting duplicates from DLL: ";
  head = deleteDuplicates(head);
  traverseDLL(head);
  cout << endl;
  return 0;
}