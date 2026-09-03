// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

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
// t.c-O(N)(for reverse each group of size k, join them make N)+O(N)(for finding kth node fo reach group of size k, join them make N)=O(2N) where N is length of LL and k=2
Node *swapPairs(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *temp = head;
  Node *prevLast = NULL;
  while (temp != NULL)
  {
    Node *kthNode = getKthNode(temp, 2); // here k=2
    if (kthNode == NULL)                 // when we don't get pair only one node left so connect it as it is
    {
      if (prevLast != NULL)
      {
        prevLast->next = temp;
      }
      break;
    }
    Node *nextNode = kthNode->next;
    kthNode->next = NULL;
    reverseSinglyLL(temp);
    if (temp == head)
    {
      head = kthNode;
    }
    else
    {
      prevLast->next = kthNode;
    }
    prevLast = temp;
    temp = nextNode;
  }
  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4};
  vector<int> arr1 = {1, 2, 3};
  Node *head = convertArrToLL(arr1);
  traverselInLL(head);
  cout << endl;
  cout << "After swap pairs in LL: ";
  head = swapPairs(head);
  traverselInLL(head);
  cout << endl;
  return 0;
}