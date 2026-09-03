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
// t.c-O(N) // where N is lengthofLL
int lenghtOfLL(Node *head)
{
  int cnt = 0;
  Node *temp = head;
  while (temp) // not nullptr run
  {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}
int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  cout << "Length of LL: " << lenghtOfLL(head);
  return 0;
}