// we have doubly linked list
// we have to traverse each and every node and check if it is same to key value then delete it

// solution is simple traverse DLL and check

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

// t.c-O(N) where N is length of DLL
// s.c-O(1)
Node *deleteAllOccurences(Node *head, int key)
{
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == key)
    {
      // if this is the head of the DLL then head will be updated
      if (temp == head)
      {
        head = head->next;
      }
      Node *nextNode = temp->next;
      Node *prevNode = temp->back;

      if (nextNode != NULL)
        nextNode->back = prevNode;
      if (prevNode != NULL)
        prevNode->next = nextNode;

      free(temp);
      temp = nextNode;
    }
    else
    { // if not match with key then
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  vector<int> arr = {10, 4, 10, 10, 6, 10};
  Node *head = convertArrToDLL(arr);
  traverseDLL(head);
  cout << endl;
  int key;
  cout << "Enter the value of key: ";
  cin >> key;
  cout << "DLL after deleting all occurences of key: ";
  head = deleteAllOccurences(head, key);
  traverseDLL(head);
  cout << endl;
  return 0;
}