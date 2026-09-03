// You are given two non-empty singly linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// given two linked list and reverse it to get number and add them after adding return the result in form of LL in reverse order

// we start addition from unit place and take carry and move forward to tenth place and so on.

// in given linked lists, unit place is head because we reverse linked list then add

// also good thing is we have to return sumlist also in reverse order so we start add from heads and take carry forward and store it

// Why we use dummy node?
// it make very clean, easier & does not mess us up our implementation

// here we use dummynode to store head of sumlist. When we add temp1 and temp2 in starting we have to know about head of sumLL and store it for which I have to create new node which get messier, we need to write temp1 and temp2 equal to equal to something something...

// Note- Whenever we need to create a newlist where we store the result or something always prefer the concept of dummynode.
// we can always point it and then get the next or rather get the head by dummynode->next

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

// t.c-O(max(N1,N2)) where N1 and N2 are length of LL1 and LL2
// s.c-O(max(N1,N2)) only for storing the answer, not for solving the problem
Node *addTwoNumbers(Node *head1, Node *head2)
{
  Node *temp1 = head1;
  Node *temp2 = head2;
  Node *dummyNode = new Node(-1);
  Node *curr = dummyNode; // that move forward in sumLL and dummyNode stay as it to get head of sumLL
  int carry = 0;
  // run until both get NULL
  while (temp1 != NULL || temp2 != NULL)
  {
    int sum = carry;
    if (temp1 != NULL)
      sum += temp1->data;
    if (temp2 != NULL)
      sum += temp2->data;
    Node *newNode = new Node(sum % 10); // because we store in reverse in sumLL
    carry = sum / 10;
    curr->next = newNode;
    curr = newNode;
    if (temp1 != NULL)
      temp1 = temp1->next;
    if (temp2 != NULL)
      temp2 = temp2->next;
  }
  // in last when carry only left create a node for it
  if (carry)
  {
    Node *newNode = new Node(carry);
    curr->next = newNode;
  }
  return dummyNode->next; // head of sumLL
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
int main()
{
  vector<int> arr1 = {3, 5};
  vector<int> arr2 = {4, 5, 9, 9};
  Node *head1 = convertArrToLL(arr1);
  Node *head2 = convertArrToLL(arr2);
  Node *headOfSumLL = addTwoNumbers(head1, head2);
  cout << "Sum LL is: ";
  traverselInLL(headOfSumLL);
  cout << endl;
  return 0;
}