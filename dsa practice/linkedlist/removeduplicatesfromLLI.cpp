// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well

// given sorted LL - delete all duplicates from it
// we have sorted LL so duplicates are also in contiguous manner
// so we do traversal and delete duplicates
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

// t.c-O(N)
// s.c-O(1)

// what is nextNode?
// nextNode is the first elt that is not equivalent to the current node
// when temp reaches to last node or if it reaches NULL we stop there is nothing in the next

// t.c-O(N), not O(N^2) because outer while loop(i.e temp) covers those node that are not duplicates and inner while loop(i.e nextNode)covers those node that are duplicates, so both combine travel whole node of DLL, so t.c-O(N) where N is length of DLL
// s.c-O(1)
Node *removeDuplicatesFromSortedLL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    Node *nextNode = temp->next;
    // if there is null,move next node until it is not equivalent to current node
    while (nextNode != NULL && nextNode->data == temp->data)
    {
      Node *duplicate = nextNode;
      nextNode = nextNode->next;
      free(duplicate);
    }
    temp->next = nextNode; // when they are not equivalent
    temp = temp->next;
  }
  return head;
}
int main()
{
  vector<int> arr = {1, 1, 2, 3, 3, 4, 5, 5};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  cout << "After removing dulpicates: ";
  // head = removeDuplicates(head);
  head = removeDuplicatesFromSortedLL(head);
  traverselInLL(head);
  cout << endl;
  return 0;
}