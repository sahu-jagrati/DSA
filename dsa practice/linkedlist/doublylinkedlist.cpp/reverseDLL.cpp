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

// naive solution- generally we store data so if we reverse data then we get reverse DLL-data replacement
// we do this in 2 traversal
// t.c-O(2N) stpe-1+step-2
// s.c-O(N) stack space
// where N is length of DLL

Node *reverseDLL(Node *head)
{
  // when DLL is empty or having only 1 elt
  if (head == NULL || head->next == NULL)
    return head;
  // step-1
  Node *temp = head;
  stack<int> st;
  while (temp != NULL)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  // step-2 replace
  temp = head;
  while (temp != NULL)
  {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}
// optimized solution- we do in sigle traversal without extra space
//  we cann't swap data now, we swap links means swap next and back pointer
// swap links
//  like when we swap two numbers-a=4 and b=5
//  temp=a
// a=b
// b=temp
// similarly we swap links

// in interview start with thought process, not jump directly in last
// we start with swapping link of one node then we swap whole DLL in one traversal and with one variable
// more details of solution see notes-L-4

// t.c-O(N)single traversal
// s.c-O(1)
Node *reverseDll(Node *head)
{
  // when DLL is empty or having only 1 elt
  if (head == NULL || head->next == NULL)
    return head;

  Node *prev = NULL;
  Node *curr = head;
  while (curr != NULL)
  {
    prev = curr->back;
    curr->back = curr->next;
    curr->next = prev;
    curr = curr->back; // it update the curr means move to next node
  }
  return prev->back; // newhead when curr=NULL
}

int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToDLL(arr);
  traverseDLL(head);
  cout << "\nAfter reverse: ";
  // head = reverseDLL(head);
  head = reverseDll(head);
  traverseDLL(head);
  cout << endl;
  return 0;
}