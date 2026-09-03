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

// delete the head of the DLL
// t.c-O(1)
Node *removeHead(Node *head)
{
  // edge case- when DLL is empty and when DLL has only 1 elt then in both case return null
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;
  delete prev;

  return head;
}
// delete the tail of the DLL
// t.c-O(N) where N is length of DLL
Node *removeTail(Node *head)
{
  // edge case - when DLL is empty and when DLL has only 1 elt then in both case return null
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  Node *tail = head; // initial and move forward
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  Node *newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;
  free(tail);
  return head;
}

// delete the kth elt of DLL
// K can be from 1 to N
// when K=1 it is head to be delete
// when K=N it is tail to be delete
// or K can be any middle
// when K>N code return NULL automatically
// t.c-O(1) when k=1 or O(N) when k=N or O(K) k can be from (1 to N)
Node *removeKthElt(Node *head, int K)
{
  // DLL is empty
  if (head == NULL)
    return NULL;
  // temp is start from head and go to Kth node by cnt
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == K)
      break;
    temp = temp->next;
  }
  Node *prev = temp->back;
  Node *front = temp->next; // front denote next node after temp
  // if DLL has only 1 elt and K=1
  if (prev == NULL && front == NULL)
  {
    delete temp;
    return NULL;
  }
  // if k=1 but elt in DLL is more than one
  // delete head of DLL
  else if (prev == NULL)
  {
    return removeHead(head);
  }
  // if K=N means delete tail of DLL
  else if (front == NULL)
  {
    return removeTail(head);
  }
  // when K is anyth elt means else
  prev->next = front; // i.e temp->next
  front->back = prev; // i.e temp->back
  temp->next = nullptr;
  temp->back = nullptr;
  free(temp);
  return head;
}

// delete the value if it's in the DLL
// also value can never be head->data in question because question does not want to change the head
// value can be from head->next to tail

// temp is the value node and never be head val

// t.c-O(1) because we direct get deleteNode we don't want to travel DLL
void removeNode(Node *temp)
{
  Node *prev = temp->back;
  Node *front = temp->next;
  // prev can never be NULL because we never take temp is head
  // so if temp is tail
  if (front == NULL)
  {
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return; // void function so does not return anything
  }
  // when temp is not tail and temp is any middle val then
  prev->next = front;
  front->back = prev;
  temp->next = temp->back = nullptr;
  free(temp);
}
int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToDLL(arr);
  traverseDLL(head);
  cout << endl;
  // head = removeHead(head);
  // traverseDLL(head);
  // cout << endl;
  // head = removeTail(head);
  // traverseDLL(head);
  // cout << endl;
  // int K;
  // cout << "Enter the value of K: ";
  // cin >> K;
  // head = removeKthElt(head, K);
  // traverseDLL(head);
  // cout << endl;
  removeNode(head->next); // delete by value,according to question in this we don't pass head because question does not want to change the head
  traverseDLL(head);
  cout << endl;
  removeNode(head->next->next);
  traverseDLL(head);
  cout << endl;
  return 0;
}