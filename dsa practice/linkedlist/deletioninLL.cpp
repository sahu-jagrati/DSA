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

//  in cpp we have free() or delete but in java we have no free() or delete, in this we have garbage collector which runs in interval of time and see which is no longer use in the program
//  so when it see temp has no reference in the program so after sometime it remove temp automatically. It might not be immediate operation but it happens sometime in future
// t.c-O(1)
// delete the head of LL
Node *removeHead(Node *head)
{
  // edge case when LL is empty
  if (head == NULL)
    return head;
  Node *temp = head;
  head = head->next;
  delete temp; // or free(temp) if we don't delete or free temp and update the head we get updated linked list but temp is still in heap memory but we want to delete so use it
  return head;
}

// t.c-O(N)
// delete the tail of LL
Node *removeTail(Node *head)
{
  // edge case when LL is empty or have 1 elt only
  if (head == NULL || head->next == NULL)
    return NULL;
  Node *temp = head;
  // we need to stop before the last elt i.e at second last
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }
  // loop over when we get second last
  delete temp->next;
  temp->next = nullptr;
  return head;
}

// delete kth elt of the LL. it can be head or tail or any node so it combine all cases
// t.c-O(K)
Node *removeK(Node *head, int K)
{
  // when LL is empty
  if (head == NULL)
    return head;
  // if k==1 means delete head
  if (K == 1)
  {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  // if k is any node, can be greater than size of LL or tail of LL
  int cnt = 0;
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == K)
    {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

// deletion by given value, similar to Kth elt delete in that we have index here we have value
// t.c-O(N) in worst case or O(1) in best
// delete the value if it is in LL
Node *removeVal(Node *head, int val)
{
  // when LL is empty
  if (head == NULL)
    return head;
  // if val is head data then delete head
  if (head->data == val)
  {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  // if val is tail or any other or not in LL then
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL)
  {

    if (temp->data == val)
    {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
int main()
{
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  // head = removeHead(head); // we get updated head
  // traverselInLL(head);
  // cout << endl;
  // head = removeTail(head);
  // traverselInLL(head);
  int K;
  cout << "Enter the value of K that has to be deleted: ";
  cin >> K;
  head = removeK(head, K);
  traverselInLL(head);
  cout << endl;
  int val;
  cout << "Enter the value that has to be delete: ";
  cin >> val;
  head = removeVal(head, val);
  traverselInLL(head);
  cout << endl;

  return 0;
}