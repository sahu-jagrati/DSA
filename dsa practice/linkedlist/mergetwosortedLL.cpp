// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list

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

// naive solution- travel both LLs and store it in any data structure, sort it and return merge LL
// first travers LL1 then LL2

// let N=N1+N2
// t.c-O(N1)(traverse LL1)+O(N2)(traverse LL2)+O(NlogN)(sort array)+O(N)(convert array to LL)
// s.c-O(N)(for array)+O(N)(for merge LL only for store answer not solving problem)

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
  vector<int> arr;
  Node *temp1 = head1;
  Node *temp2 = head2;
  // traverse LL1
  while (temp1 != NULL)
  {
    arr.push_back(temp1->data);
    temp1 = temp1->next;
  }
  // traverse LL2
  while (temp2 != NULL)
  {
    arr.push_back(temp2->data);
    temp2 = temp2->next;
  }
  // sort array
  sort(arr.begin(), arr.end());
  // convert arr to LL
  Node *head = convertArrToLL(arr);
  return head;
}

// optimized solution-
// we have sorted LL so we use two pointer approach this optimize t.c
// and we reuse the same node by changing the links so this optimize s.c also
// we just change the links not creating new list so for this we use concept of dummyNode

// t.c-O(N1+N2)// in worst case when both temp1 and temp2 travel whole their LL
// s.c-O(1) because we reuse same nodes, we only change the links
Node *mergeSortedLLs(Node *head1, Node *head2)
{
  Node *temp1 = head1;
  Node *temp2 = head2;
  Node *dummyNode = new Node(-1);
  Node *curr = dummyNode;

  // in worst case when both temp1 and temp2 travel whole their LL
  while (temp1 != NULL && temp2 != NULL)
  {
    if (temp1->data < temp2->data)
    {
      curr->next = temp1;
      curr = temp1;
      temp1 = temp1->next;
    }
    else
    {
      curr->next = temp2;
      curr = temp2;
      temp2 = temp2->next;
    }
  }
  // when only LL1 nodes remain
  if (temp1 != NULL)
    curr->next = temp1;
  // when only LL2 nodes remain
  else
    curr->next = temp2;

  return dummyNode->next; // head of merge list
}

int main()
{
  // sorted array
  vector<int> arr1 = {2, 4, 8, 10};
  vector<int> arr2 = {1, 3, 3, 6, 11, 14};
  Node *head1 = convertArrToLL(arr1);
  Node *head2 = convertArrToLL(arr2);
  cout << "After merge two sorted LL: ";
  // Node *head = mergeTwoSortedLL(head1, head2);
  Node *head = mergeSortedLLs(head1, head2);
  traverselInLL(head);
  cout << endl;
  return 0;
}