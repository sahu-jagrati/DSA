// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// we can reverse the group of nodes if only it size is k, if it is less than k, connect it as it is
// first we reverse one group then go to next group
// we reverse only the whole linked list not only part of linked list so make each group of size k individually linked list

// process-
// first find kthnode of group if there is group of size k then we have kthnode, else if group's size is less than k then kthNode=NULL and connect it as it is
// make that group individually linked list and now reverse that group
// if it is first group then head will be updated and head is the kthNode of that group and after reversing memorize last node of the group to connect with next group
// also before reversing memorize Node of the next group and do process so on
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

Node *reverseSinglyLL(Node *node)
{
  if (node == NULL || node->next == NULL)
    return node;
  Node *temp = node;
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

Node *getKthNode(Node *temp, int k)
{
  k = k - 1; // count temp also;
  while (temp != NULL && k > 0)
  {
    k--;
    temp = temp->next;
  }
  return temp; // kthnode
}

// s.c-O(1)
// t.c-O(N)(for reverse each group of size k, join them make N)+O(N)(for finding kth node fo reach group of size k, join them make N)=O(2N) where N is length of LL
Node *reverseNodesInKGroup(Node *head, int k)
{
  Node *temp = head;
  Node *prevLast = NULL; // this is used to connect previous group to next group after reversing the group
  while (temp != NULL)
  {
    Node *kthNode = getKthNode(temp, k);

    // it is when size of next group is less than k then kthNode=NULL and connect it as it is don't reverse it
    if (kthNode == NULL)
    {
      // if prevLast is not NULL then
      if (prevLast != NULL)
      {
        prevLast->next = temp;
      }
      break;
    }
    Node *nextNode = kthNode->next; // node next to group of size k, remember to connect it later
    // for reversing we have to make each group as individual linked list because we cannot reverse part of linked list so
    kthNode->next = NULL;
    reverseSinglyLL(temp); // reverse the group of size K, return updated head

    // after reverse
    if (temp == head)
    {                 // means Ist group
      head = kthNode; // after reversing
    }
    else
    { // connect reverse group to next group
      prevLast->next = kthNode;
    }

    // update temp and prevLast for go to next group
    prevLast = temp;
    temp = nextNode;
  }
  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  int k;
  cout << "Enter the value of group of size: ";
  cin >> k;

  cout << "After reverse nodes in k group size of LL is: ";
  head = reverseNodesInKGroup(head, k);
  traverselInLL(head);
  cout << endl;
  return 0;
}