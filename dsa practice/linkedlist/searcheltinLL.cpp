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

// t.c-O(N)in worst case or O(1) in best case or O(N/2) in average case
// where N is lengthofLL
bool searchEltInLL(Node *head, int val)
{
  Node *temp = head;
  while (temp)
  {
    /* code */
    if (temp->data == val)
    {
      return true;
    }
    else
    {
      temp = temp->next;
    }
  }
  return false;
}

int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToLL(arr);
  int val;
  cout << "Enter search elt: ";
  cin >> val;
  cout << "Elt is LL or not: " << searchEltInLL(head, val);
  return 0;
}