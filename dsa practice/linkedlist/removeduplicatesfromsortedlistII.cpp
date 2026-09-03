// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// here we have to delete the node that have duplicate in LL and leave only distinct number that have no duplicate in LL
// i.e example we have {1,2,3,3,4,4,5} there is duplicate of 3 and duplicate of 4 so we have to delete all 3 and 4 from LL no one want in LL and answer is {1,2,5}

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

// here we have to delete the node that have duplicate in LL and leave only distinct number that have no duplicate in LL
// i.e example we have {1,2,3,3,4,4,5} there is duplicate of 3 and duplicate of 4 so we have to delete all 3 and 4 from LL no one want in LL and answer is {1,2,5}
Node *removeDuplicatesProperly(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  // by using concept of dummyNode we reuse the same nodes and don't create new list
  Node *dummyNode = new Node(-1);
  Node *curr = dummyNode;
  dummyNode->next = head; // initially
  Node *temp = head;
  while (temp != NULL&&temp->next!=NULL)
  {
    bool isDuplicate = false;
    Node *nextNode = temp->next;
    while (nextNode != NULL && nextNode->data == temp->data)
    {
      isDuplicate = true;
      Node *duplicate = nextNode;
      nextNode = nextNode->next;
      delete duplicate;
    }
    if (isDuplicate)
    {
      Node *duplicate = temp;
      temp->next = nextNode;
      temp = temp->next;
      curr->next = temp;
      delete duplicate;
    }
    else
    {
      curr = temp;
      temp->next = nextNode;
      temp = temp->next;
    }
  }
  return dummyNode->next; // head of updated LL
}
int main()
{
  vector<int> arr = {1, 2, 3, 3, 4, 4, 5};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  cout << "After deleting the duplicates: ";
  head = removeDuplicatesProperly(head);
  traverselInLL(head); // we want {1,2,5} because we want all entities of duplicates
  cout << endl;
  return 0;
}