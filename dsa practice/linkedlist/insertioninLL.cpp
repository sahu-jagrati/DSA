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
// where N is lengthofLL
// t.c-O(N) for conversion
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
// t.c-O(N) for traverse
void traverselInLL(Node *head)
{
  Node *temp = head;
  while (temp) // not nullptr run
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// insert at the head of the LL
// we do not want to replace old head, we want to create new Node whose next is old head and new node become head of current LL

// t.c-O(1)
Node *insertBeforeHead(Node *head, int elt)
{
  // create new Node and temp->next = head
  // automatically cover empty LL
  Node *temp = new Node(elt, head);
  return temp;
  // or direct return new Node(elt,head);
}

// insert at the last of the LL
// t.c-O(N)
Node *insertAfterTail(Node *head, int elt)
{
  // empty LL
  if (head == NULL)
    return new Node(elt, head); // same insert to head where head is NULL
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  Node *newNode = new Node(elt); // by constructor it's next is nullptr
  temp->next = newNode;
  return head;
}

// inserting at the kth elt of LL means insert before k or after k-1
// if k==1 then insert before Head or if K>=2 means insert after (k-1) then it is kth elt of LL
// if k==N insert before tail
// k is btw (1-N+1) always if exceed then print some message

// t.c-O(1) when head or O(K) when middle or O(N) in worst case when last
Node *insertAtK(Node *head, int elt, int K)
{
  // LL is empty
  if (head == NULL)
  {
    // and k==1 means create new node
    if (K == 1)
    {
      return new Node(elt);
    }
    // k>1 and LL is empty
    else
    {
      return NULL;
    }
  }
  // insert at head k==1
  if (K == 1)
  {
    Node *temp = new Node(elt, head);
    return head;
  }
  // when k>=2 and upto N
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == K - 1)
    {
      Node *newNode = new Node(elt, temp->next);
      temp->next = newNode;
      break; // or return head
    }
    temp = temp->next;
  }
  return head;
}

// insert elt before the value x
// val always in LL if not print message
// t.c-O(1) when before head or O(N) in worst case when befor last
Node *insertBeforVal(Node *head, int elt, int val)
{
  // if LL is empty then we never have val
  if (head == NULL)
    return NULL;
  bool found = false; // when val not present
  // befor head insert
  if (head->data == val)
  {
    Node *temp = new Node(elt, head);
    return temp;
  }
  // insert befor tail or any
  Node *temp = head;
  while (temp->next != NULL)
  {
    // because we want insert before val
    if (temp->next->data == val)
    {
      Node *newNode = new Node(elt, temp->next);
      temp->next = newNode;
      found = true;
      break;
    }
    temp = temp->next;
  }
  if (found == false)
    cout << "Insertion not possible because x not present in LL" << endl;
  return head;
}

int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  int elt;
  cout << "Enter the value that has to be insert: ";
  cin >> elt;
  // head = insertBeforeHead(head, elt);
  // // or direct call for insert head
  // // head=new Node(elt,head);
  // traverselInLL(head);
  // cout << endl;
  head = insertAfterTail(head, elt);
  traverselInLL(head);
  cout << endl;
  int K;
  cout << "Enter the value of K: ";
  cin >> K;
  head = insertAtK(head, elt, K);
  traverselInLL(head);
  cout << endl;
  int val;
  cout << "Enter the value that from before we have to insert: ";
  cin >> val;
  head = insertBeforVal(head, elt, val);
  traverselInLL(head);
  cout << endl;
  return 0;
}