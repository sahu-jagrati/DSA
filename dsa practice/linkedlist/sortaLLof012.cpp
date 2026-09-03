// sort a singly LL of 0's,1's and 2's

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

// naive solution- data replacement- in two traversal-
// step-1 we take cnt0,cnt1 and cnt2 and traverse the LL
// step-2 again traverse the LL and replace by using cnts

// t.c-O(2N), where N is length of LL
// s.c-O(1)
Node *sort012(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *temp = head;
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  // step-1
  while (temp != NULL)
  {
    if (temp->data == 0)
    {
      cnt0++;
    }
    else if (temp->data == 1)
    {
      cnt1++;
    }
    else
    {
      cnt2++;
    }
    temp = temp->next;
  }
  // step-2 again traverse and replace
  temp = head;
  while (temp != NULL)
  {
    if (cnt0)
    {
      temp->data = 0;
      cnt0--;
    }
    else if (cnt1)
    {
      temp->data = 1;
      cnt1--;
    }
    else
    {
      temp->data = 2;
      cnt2--;
    }
    temp = temp->next;
  }
  return head;
}

// optimized solution- single traversal by not data replacement but by changeing links
//  whenever we need to create newList we use dummynode
//  here we use 3 dummynode-one for 0 list-zeroHead, one for 1 list-oneHead, one for 2 list-twoHead with their initial pointers also zero,one,two
//  we do not create new node, we only change the links

// t.c-O(N), where N is length of LL
// s.c-O(1)
Node *sort012LL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  // create 3 dummynode
  Node *zeroHead = new Node(-1);
  Node *oneHead = new Node(-1);
  Node *twoHead = new Node(-1);
  // their pointers also
  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == 0)
    {
      zero->next = temp;
      zero = zero->next; // or say temp
    }
    else if (temp->data == 1)
    {
      one->next = temp;
      one = one->next; // or say temp
    }
    else
    {
      two->next = temp;
      two = two->next; // or say temp
    }
    temp = temp->next;
  }
  // in last connect 0's list with 1's list and 1's list with 2's list
  // ask if there is 1's then zero->next=oneHead->next else zero->next=twoHead->next also if there is nor 1's neither 2's then twoHead->next=nullptr so one->next=nullptr automatically
  zero->next = (oneHead->next) ? oneHead->next : twoHead->next;

  // if there is 2's okay if not then it point to nullptr, also if there is no 1's then also it point to twoHead->next at that time one=oneHead is
  one->next = twoHead->next;
  two->next = NULL;

  Node *newHead = zeroHead->next; // if not0's then it will give oneHead->next or if not 1's then it will give twoHead->next automatically

  // free all dummynodes
  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return newHead;
}

int main()
{
  // array has only 0,1 and 2 not other numbers
  vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  // head = sort012(head);
  head = sort012LL(head);
  cout << "After sort 0,1 and 2: ";
  traverselInLL(head);
  cout << endl;
  return 0;
}