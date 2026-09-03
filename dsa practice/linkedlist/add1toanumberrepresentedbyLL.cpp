// given a singly LL that represent a number
// add 1 to that number
// here unit place is last node of LL

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

Node *reverseSinglyLL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *temp = head;
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

// naive solution- we start add from unit place here unit place is last node of LL
// but in singly LL we have no back pointer
// so we have to first reverse the LL
// then add 1 to newHead
// again reverse the LL
// here if in last if we have still carry which means there is a new node, we add this newNode after again reverse of LL

// t.c-O(N)(step-1 reverse)+O(N)(step-2)+O(N)(again reverse)=total=O(3N)
// s.c=O(1)  we use iterative way of reverse or if we use recursive way then s.c-O(N)recorsion stack space
Node *addOne(Node *head)
{
  // step-1 reverse the LL
  head = reverseSinglyLL(head);
  // step-2 add 1 to the number now the LL is represent
  int carry = 1; // initially because w ehave to add 1 only
  Node *temp = head;
  while (temp != NULL)
  {
    temp->data = temp->data + carry;
    if (temp->data < 10)
    { // no change in node data
      carry = 0;
      break;
    }
    // when temp->data>10 in that case we only add one to our number so
    else
    {
      temp->data = 0;
      carry = 1;
    }
    temp = temp->next;
  }
  // step-3
  // in last still carry =1 then there is new node first we reverse LL then add newNode
  if (carry == 1)
  {
    Node *newNode = new Node(1);
    head = reverseSinglyLL(head); // first reverse then add node
    newNode->next = head;
    head = newNode;
    return head;
  }
  // if carry =0 then reverse LL and return
  head = reverseSinglyLL(head);
  return head;
}

// optimized solution- without reversing
// for adding 1, we want to move back but this is done by reversing
// if we don't reverse then recursion is the way to go back
// first we call recursion for first node of LL then second and so on
// base case call recursion until we get NULL
// when we get NULL take carry =1 and do backtracking
// add carry to the node by backtrack and so on
// if in last carry =0 no newnode or if carry =1 there is newnode create it

// return last carry either 0 or 1
int addHelperReturnCarry(Node *temp)
{
  // base case
  if (temp == NULL)
    return 1; // that is carry=1
  // call recursion for next node until get base case
  int carry = addHelperReturnCarry(temp->next);
  temp->data = temp->data + carry;
  if (temp->data < 10)
  {
    return 0; // i.e carry =0 and no change in temp-data
  }
  // if temp-data>10
  temp->data = 0; // because we add only 1
  return 1;       // i.e carry =1
}
// t.c-O(N)
// s.c-O(N) recursive stack space
// where N is length of LL
Node *addOneToNumberLL(Node *head)
{
  int carry = addHelperReturnCarry(head); // say in last carry is 0 or 1
  if (carry == 1)
  {
    // create newNode
    Node *newNode = new Node(1);
    newNode->next = head;
    head = newNode;
  }
  return head;
}

int main()
{
  vector<int> arr = {1, 5, 9};
  vector<int> arr1 = {9, 9, 9, 9};
  Node *head = convertArrToLL(arr1);
  traverselInLL(head);
  cout << endl;
  cout << "After add 1: ";
  head = addOne(head);
  traverselInLL(head);
  cout << endl;
  return 0;
}