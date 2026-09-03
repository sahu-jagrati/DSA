// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity

// return newhead of LL after storing group of odd indexes first together then group of even indexes together

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

// naive solution- data replacment- in this we are not reorder the list, we only rearrange the data and return list
// odd index is start from head itself and for next odd index we have to jump by 2 and so on
// even index is  start from head->next and for next even index we have to jump by two
// we first iterate all odd index and store in array
// then in step2 we iterate all even index and store in same array after traversing odd indexes value
// and in last we go through given LL and replace data with array data and return the list

// t.c-O(N/2)(for odd iteration)+O(N/2)(for even iteration)+O(N)(for replace iteartion)=O(2N)
// s.c-O(N) for arr
Node *oddEven(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  vector<int> arr;
  // step-1 iterate all odd indexes and store them in array
  Node *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    arr.push_back(temp->data);
    temp = temp->next->next; // jump by 2 for next odd index
  }
  // when length of LL is odd because temp->next == NULL for that so why loop not run
  if (temp != NULL)
  {
    arr.push_back(temp->data);
  }

  // step-2 iterate all even indexes and store them in array
  temp = head->next;
  while (temp != NULL && temp->next != NULL)
  {
    arr.push_back(temp->data);
    temp = temp->next->next; // jump by 2 for next even index
  }
  // when length of LL is even because temp->next == NULL for that so why loop not run
  if (temp != NULL)
  {
    arr.push_back(temp->data);
  }

  // step-3 replacement
  int i = 0;
  temp = head;
  while (temp != NULL)
  {
    temp->data = arr[i];
    i++;
    temp = temp->next;
  }
  return head;
}

// optimized solution- by changing links and do in single traversal without extra space
// we change the links example
// odd index start from head then next odd index link is
// odd->next=odd->next->next

// and even index start from head->next then next even index link is
// even->next=even->next->next

// in last we want last odd index points first even index so store first even index by evenHead
// and odd->next = evenHead in last

// also in while there is no need of write condition on odd also because odd is always behind of even index i.e even is ahead of odd index so if we know about even condition then odd will automatically consider. no need to think odd index condition

// we do in single traversal without extra space
// t.c-O((N/2)*2)because we run jump by 2 together for even and odd, not rum two while loop like naive solution but we change two links togetheri.e two operation so (N/2)*2=O(N)
// s.c-O(1 that we optimized)
// t.c slightly low then naive but almost same
Node *OddEven(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  Node *odd = head;
  Node *even = head->next;
  Node *evenHead = head->next;

  // no need to check odd condition
  while (even != NULL && even->next != NULL)
  {
    odd->next = odd->next->next;
    even->next = even->next->next;

    odd = odd->next;
    even = even->next;
  }
  // in last join odd index to first even index
  odd->next = evenHead;
  return head;
}

int main()
{
  vector<int> arr = {2, 3, 1, 4, 5, 6};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  cout << "After oddeven LL is: ";
  // head = oddEven(head);
  head = OddEven(head);
  traverselInLL(head);
  cout << endl;
  return 0;
}
