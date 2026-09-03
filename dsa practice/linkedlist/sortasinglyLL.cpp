// Given the head of a linked list, return the list after sorting it in ascending order.

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

// naice solution-data replacement
// t.c-O(N)(for traverse)+O(NlogN)(sort)+O(N)(again traverse)
// s.c-O(N)for array where N is length of LL
Node *sortLL(Node *head)
{
  vector<int> arr;
  Node *temp = head;
  // put all data in array
  while (temp != NULL)
  {
    arr.push_back(temp->data);
    temp = temp->next;
  }
  // sort array
  sort(arr.begin(), arr.end());
  // replace data of LL with sorted array data
  temp = head;
  int i = 0;
  while (temp != NULL)
  {
    temp->data = arr[i];
    i++;
    temp = temp->next;
  }
  return head;
}

// optimized solution- we know for sorting optimize algo are merge sort and quick sort but quick sort is difficult to implement so we try to implement merge sort in LL
// i) base case
// ii) we find middle of LL to divide LL in two half we use tortoise and hare algo but we know this algo for even length LL give middle2 so we slightly change it
// iii) left portion is denoted by head and
// right portion is denoted by middle->next
// iv) separate left and right LL by middle->next = NULL
// v) merge them back after sorting, we know how to merge2List
// and return head of merge2list

// in LL we have to return the head of updated LL while in array we don't return because array was reference based so whatever changes we do it was done on the memory location itself.

Node *findMiddle(Node *head)
{
  Node *slow = head;
  Node *fast = head->next; // this is slight change in tortoise and hare algo
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow; // middle
}
Node *merge2List(Node *temp1, Node *temp2)
{
  Node *dummyNode = new Node(-1); // initially next point to null
  Node *curr = dummyNode;
  // when both list are not empty
  while (temp1 != NULL && temp2 != NULL)
  {
    if (temp1->data < temp2->data)
    {
      curr->next = temp1;
      curr = temp1;
      temp1 = temp1->next;
    }
    else
    {
      curr->next = temp2;
      curr = temp2;
      temp2 = temp2->next;
    }
  }
  // if only list1 has nodes
  if (temp1 != NULL)
  {
    curr->next = temp1;
  }
  // if only list2 has nodes
  else
  {
    curr->next = temp2;
  }
  return dummyNode->next; // head of updated merge list
}

// N is length of LL
// recursive tree depth is logN
// we merge2list so (N1+N2)=approx.=N
// finding middle take here N/2
// so total t.c-O((logN)*(N+N/2))
// s.c-O(logN) recursive stack space we have slways half array in stack space
Node *sortedLinkedList(Node *head)
{
  // base case
  if (head == NULL || head->next == NULL)
    return head;
  // find middle
  Node *middle = findMiddle(head);
  // left and right portion
  Node *left = head;
  Node *right = middle->next;
  // separate left and right portion
  middle->next = nullptr;
  // recursive call to left and right portion
  left = sortedLinkedList(left);
  right = sortedLinkedList(right);

  return merge2List(left, right); // return updated head of sort list
}

int main()
{
  vector<int> arr = {3, 4, 2, 1, 5};
  Node *head = convertArrToLL(arr);
  // head = sortLL(head);
  head = sortedLinkedList(head);
  cout << "After sort LL: ";
  traverselInLL(head);
  cout << endl;
  return 0;
}