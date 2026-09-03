#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *back;
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *convertArrToDLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void traverseDLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// here we insert before the node, you also try with after the node

// insert before the head of DLL
// t.c-O(1)
Node *insertBeforeHead(Node *head, int val)
{
  // if DLL is empty
  if (head == NULL)
    return new Node(val);
  Node *newHead = new Node(val, head, nullptr);
  head->back = newHead;
  return newHead;
}

// insert before the tail of the DLL
// t.c-O(N) where N is length of DLL
Node *insertBeforeTail(Node *head, int val)
{
  // if DLL is empty
  if (head == NULL)
    return new Node(val);
  // when DLL has only 1 elt
  if (head->next == NULL)
  {
    return insertBeforeHead(head, val);
  }
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  Node *newNode = new Node(val, tail, tail->back);
  Node *prev = tail->back;
  prev->next = newNode;
  tail->back = newNode;
  return head;
}

// insert before kth elt of LL
Node *insertBeforeKthElt(Node *head, int K, int val)
{
  // if DLL is empty and k==1
  if (head == NULL)
  {
    if (K == 1)
    {
      return new Node(val);
    }
    // k>1
    else
    {
      return NULL;
    }
  }
  // if k=1 but DLL has more than 1 elt
  if (K == 1)
    return insertBeforeHead(head, val);
  // when k>=2
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == K)
      break;
    temp = temp->next;
  }
  Node *prev = temp->back;
  Node *newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;

  return head;
}

// insert elt before value x in DLL
// x is always in DLL but x!=head->data because according to question they don't want to change the head

// here node is where we have to insert before and val that has to be insert

// t.c-O(1) because we direct get node
void insertBeforeNode(Node *node, int val)
{
  // if DLL is empty then we never have node
  Node *prev = node->back;
  Node *newNode = new Node(val, node, prev);
  prev->next = newNode;
  node->back = newNode;
}

// insert after tail of DLL
// t.c-o(N) where N is length of DLL
Node *insertAfterTail(Node *head, int val)
{
  // if DLL is empty
  if (head == NULL)
    return new Node(val);
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  Node *newNode = new Node(val, nullptr, tail);
  tail->next = newNode;
  return head;
}

int main()
{
  vector<int> arr = {12, 5, 8, 9, 7};
  Node *head = convertArrToDLL(arr);
  traverseDLL(head);
  cout << endl;
  int val;
  cout << "Enter the value that has to be insert: ";
  cin >> val;
  // head = insertBeforeHead(head, val);
  // traverseDLL(head);
  // cout << endl;
  // head = insertBeforeTail(head, val);
  // traverseDLL(head);
  // cout << endl;
  // int k;
  // cout << "Enter the value of k: ";
  // cin >> k;
  // head = insertBeforeKthElt(head, k, val);
  // traverseDLL(head);
  // cout << endl;
  // insertBeforeNode(head->next, val); // don't say insert before head because question don't want to change the head
  // traverseDLL(head);
  // cout << endl;
  head = insertAfterTail(head, val);
  traverseDLL(head);
  cout << endl;
  return 0;
}