// remove Nth node from the end of the singly LL

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

// naive solution- using cnt variable to calculate length of LL
// we want to delete Nth node from end means from starting delete (cnt-N+1) node and connect (cnt-N) to deletenode->next

// t.c-O(length of LL)+O(lengthofLL-N), in worst case it is O(2N)
// s.c-O(1)
Node *removeNthnodeFromEnd(Node *head, int N)
{
  // cover all cases
  int cntLength = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cntLength++;
    temp = temp->next;
  }
  // edge case when N=length of LL then delete head and newhead is head->next
  if (cntLength == N)
  {
    Node *newHead = head->next;
    free(head);
    return newHead;
  }
  int prevIndex = cntLength - N;
  temp = head;
  while (temp != NULL)
  {
    prevIndex--;
    if (prevIndex == 0)
    {
      break;
    }
    temp = temp->next;
  }
  Node *delNode = temp->next;
  temp->next = temp->next->next;
  free(delNode);
  return head;
}

// one more brute solution-
// 1. reverse the LL
// 2. delete teh nth node
// 3. again reverse the LL

// optimized solution- we want delete Nth node from end

// details of solution in notes in L-8

// t.c-O(N)(for fast loop)+O(length of LL-N)(for while loop)=O(N)
// s.c-O(1)
Node *removeNthNodeFromEnd(Node *head, int N)
{
  Node *fast = head;
  Node *slow = head;
  for (int i = 0; i < N; i++)
  {
    fast = fast->next;
  }
  // means N=length of LL i.e delete head
  if (fast == NULL)
  {
    Node *newHead = head->next;
    free(head);
    return newHead;
  }
  // it cover all case except N=length of LL that we cover above
  // initially we do not move slow node only we move fast upto N-1. now, we move both together
  while (fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }
  Node *delNode = slow->next;
  slow->next = slow->next->next;
  free(delNode);
  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;

  int N;
  cout << "Enter the index that has to be delete: ";
  cin >> N;
  // head = removeNthnodeFromEnd(head, N);
  head = removeNthNodeFromEnd(head, N);
  cout << "After delete Nth node from end: ";
  traverselInLL(head);
  cout << endl;
  return 0;
}