// check LL is palindrome or not

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

// naive solution- by checking data one by one
// t.c-O(2N)
// s.c-O(N)for stack
// where N is length of LL
bool checkPalindrome(Node *head)
{
  if (head == NULL || head->next == NULL)
    return true;
  Node *temp = head;
  stack<int> st;
  while (temp != NULL)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL)
  {
    if (temp->data != st.top())
    {
      return false;
    }
    st.pop();
    temp = temp->next;
  }
  return true;
}

// optimized solution- no extra space used, we do in single traversal
// by breaking LL in two half because for palindrome first half should be match with second half
// and then we use two pointer to compare
// but in singly LL we have no back pointer so how we move back
// so we change the links of second half for move back for this we want middle of LL
// we find middle of LL by Tortoise and Hare algo-
// and then use two pointer to compare
// also in last second half that we reverse, reverse it again beacuse we cann't change the input
Node *reverseSinglyLL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL)
  {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;

    temp = front;
  }
  return prev;
}
// t.c-O(N/2)(step-1 find mid)+O(N/2)(step-2 reverse second half)+O(N/2)(step-3 two pointer we move half array because first pointer move first half and second pointer move second half together)+O(N/2)(again reverse second half)
// total t.c-O(2N)
// s.c-O(1) we use iterative way of reverse or if we use recursive way then s.c-O(N)recorsion stack space
bool isPalindrome(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  // step-1 find mid of LL
  //  slow and fast are two pointer initially point head and slow jump by 1 and fast jump by 2 together
  Node *slow = head;
  Node *fast = head;
  while (fast->next != NULL && fast->next->next != NULL)
  {
    // slow jump by 1 and fast jump by 2, both move simulatneously together
    slow = slow->next;
    fast = fast->next->next;
  }
  // mid is slow but we want to reverse second half so reverse from slow->next
  // head of reverse second half
  // step-2
  Node *newHead = reverseSinglyLL(slow->next);
  // step-3 two pointer
  Node *first = head;     // head of first half
  Node *second = newHead; // head of second half
  while (second != NULL)
  {
    if (first->data != second->data)
    {
      // we have to in last second half that we reverse, reverse it again beacuse we cann't change the input
      reverseSinglyLL(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
  // in last second half that we reverse, reverse it again beacuse we cann't change the input
  reverseSinglyLL(newHead);
  return true;
}

int main()
{
  vector<int> arr = {1, 2, 3, 2, 1};
  vector<int> arr1 = {1, 2};
  Node *head = convertArrToLL(arr1);
  traverselInLL(head);
  cout << endl;
  cout << "Check LL is palindrome is or not: ";
  // cout << checkPalindrome(head) << endl;
  cout << isPalindrome(head) << endl;
  return 0;
}