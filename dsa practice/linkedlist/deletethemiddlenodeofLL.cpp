// for odd length LL we have only one middle so delete it
// but for even length LL is we have two middle so delete the second middle node

// our task is to delete the middle node and connect previous of it to it next
// so I want to reach the node that is just before the middle and change the links

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

// naive solution- by calculating length of LL
// so node just before the middle is at floor(N/2)

// t.c-O(N + (N/2)) where N is length of LL
//  s.c-O(1)
Node *deleteMiddle(Node *head)
{
  if (head == NULL || head->next == NULL)
    return NULL;
  Node *temp = head;
  int N = 0;
  // step-1 calculating length of LL
  while (temp != NULL)
  {
    N++;
    temp = temp->next;
  }
  // step-2 node just before the middle
  int beforeMidNode = N / 2;
  temp = head;
  while (temp != NULL)
  {
    beforeMidNode--;
    if (beforeMidNode == 0)
    {
      Node *deleteMiddleNode = temp->next;
      temp->next = temp->next->next;
      free(deleteMiddleNode);
      break;
    }
    temp = temp->next;
  }
  return head;
}

// optimized solution- do in one traversal-tortoise and Hare algo
// but we do slight change in algo here because we want node just befor the middle node, not middle node
// as in algo slow points to middle node
// so slow point node just before the middle node we skip only 1 step for slow in initial so we get node just before middle

// t.c-O(N/2) where N is length of LL
//  s.c-O(1)
Node *deletemiddleNode(Node *head)
{
  if (head == NULL || head->next == NULL)
    return NULL;
  Node *slow = head;
  Node *fast = head;
  // skip 1 step for slow in initial
  fast = fast->next->next;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  // now slow point node just before middle node
  Node *deleteMiddleNode = slow->next;
  slow->next = slow->next->next;
  free(deleteMiddleNode);
  return head;
}

int main()
{
  vector<int> arr1 = {1, 2, 3, 4, 5};
  vector<int> arr2 = {1, 2, 3, 4, 5, 6};
  Node *head = convertArrToLL(arr1);
  cout << "After deleting middle node of LL: ";
  // head = deleteMiddle(head);
  head = deletemiddleNode(head);
  traverselInLL(head);
  cout << endl;
  return 0;
}