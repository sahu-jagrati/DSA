// we have to find middle elt of LL
// for odd length middle is easily get
// but for even lenth middle lie btw to node so we get two mid in that case return second mid then

// you have to return entire node, not only value

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

// naive solution-  first by calculating length of LL say it N
// then mid node is (N/2)+1 in both case odd and even length LL

// t.c-O(N)(for traversal)+O(N/2)(for finding mid)
// s.c-O(1)
Node *middle(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  // step-1 calculating length of LL
  int N = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    N++;
    temp = temp->next;
  }
  int midNode = (N / 2) + 1;
  temp = head;
  // findinf midnode
  while (temp != NULL)
  {
    midNode--;
    if (midNode == 0)
    {
      break;
    }
    temp = temp->next;
  }
  return temp; // temp is middle node
}

// optimized solution- do in single traversal
// Tortoise and Hare Algo
// here we have two pointer slow and fast both initially point head
// slow jump by 1 and fast jump by 2 both move simultaneously together
// in last slow is the pointer that point to midNode

// when length of LL is even-fast go to last
// when length of LL is odd- fast go to NULL

// t.c-O(N/2) we move only half LL
// s.c-O(1)
Node *middleNode(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    // slow jump by 1 and fast jump by 2, both move together
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow; // is the middle Node in both case even and odd, in even case slow is second middle
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr1 = {1, 2, 3, 4, 5, 6};
  Node *head = convertArrToLL(arr1);
  traverselInLL(head);
  cout << endl;
  cout << "Middle Node is: ";
  Node *midNode = middle(head);
  cout << midNode->data << endl;
  return 0;
}