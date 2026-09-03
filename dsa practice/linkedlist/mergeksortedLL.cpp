// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it

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

// naive solution-put all data in one array and sort it and convert arr to LL

// k is no.of sorted LL and N is length of each LL
//  t.c-O(k*N)(for traverse each LL)+O((k*N)log(k*N))(for sort)+O(k*N)(convert array into LL)
//  s.c-O(k*N)(for array)+O(k*N)(for creating new list not solving problem)

Node *mergekSortedLL(vector<Node *> &listArray) // list of k LL heads means having head of all k LL from which we can travel whole LL by that head
{
  vector<int> arr;
  // for taking head of each LL
  for (int i = 0; i < listArray.size(); i++)
  {
    Node *temp = listArray[i]; // points to head
    while (temp != NULL)
    {
      arr.push_back(temp->data);
      temp = temp->next;
    }
  }
  sort(arr.begin(), arr.end());
  Node *head = convertArrToLL(arr);
  return head; // head of merge list
}

// optimize solution-Ist
// we have sorted list so we use two pointer approach and we reuse same nodes not creating new list, by using concept of dummyNode
// first we solve 2 LL and merge them then go for more no.of LL by recursion
// similar to flattening a LL

Node *merge2LL(Node *temp1, Node *temp2) // head of 2 LL
{
  Node *dummyNode = new Node(-1); // initially next point to null
  Node *curr = dummyNode;
  // when both LL is not empty
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
  // when only LL1 nodes remain,connect it as it is
  if (temp1 != NULL)
    curr->next = temp1;
  // when only LL2 nodes remain,connect it as it is
  else
    curr->next = temp2;

  return dummyNode->next; // head of merge list
}

// for t.c-first we merge 2 list so (N1+N2) then merge it with third list so (N1+N2+N3) then merge it with next list so (N1+N2+N3+N4)
// assume if each LL is of size N so
// time is N+2N+3N+4N+...+kN because we have k LL
// so total t.c- it is N*((k*(k+1))/2) which is approx=(N^3) if k=N, where N is length of each LL and k is no.of LL
// s.c-O(1) because we reuse same nodes but there is recursive stack space O(k) we call merge 2list function k times

Node *mergeKsortedLL(vector<Node *> &listArray) // list of k LL heads means having head of all k LL from which we can travel whole LL by that head
{
  Node *head = listArray[0];
  for (int i = 1; i < listArray.size(); i++)
  {
    head = merge2LL(head, listArray[i]);
  }
  return head; // head of merge k list
}

// optimize solution IInd-
//  we use min-heap(priority-queue) so at top we have always smallest elt we store node->value and Node itself
// initially we put head of all k linked list and from which we put next of them

// listarray size is k which is no.of sorted LL
// so pq.push initially take logk
// so for loop that run initially will take time-k*logk
// now while loop in this we have 3 operation-top(),pop(),push() so take time-3*logk
// assume each LL is of size N so while loop run-k*N times so t.c-k*N*3*logk
// total t.c -O(k*logk + 3*k*N*logk)
// s.c-O(k) pq space always have k elts in it

Node *mergeKSortedLL(vector<Node *> &listArray) // list of k LL heads means having head of all k LL from which we can travel whole LL by that head
{
  priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;
  // initially we put head of all k linked list and from which we put next of them
  for (int i = 0; i < listArray.size(); i++)
  {
    // if not null
    if (listArray[i])
      pq.push({listArray[i]->data, listArray[i]}); //{data,Node itself}
  }
  Node *dummyNode = new Node(-1); // initially next point to null
  Node *curr = dummyNode;
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    if (it.second->next != NULL)
    {
      pq.push({it.second->next->data, it.second->next});
    }
    curr->next = it.second;
    curr = curr->next;
  }
  return dummyNode->next; // head of merge k list
}
Node *insertAtTail(Node *head, int data)
{
  if (head == NULL)
    return new Node(data);
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new Node(data);
  return head;
}
int main()
{
  int k;
  cout << "Enter the number of LL: ";
  cin >> k;
  vector<Node *> listArray(k); // storing head of all k LL from which we can travel whole LL by that head
  for (int i = 0; i < k; i++)
  {
    int n;
    cout << "Enter number of nodes in LL " << i + 1 << ": ";
    cin >> n;
    Node *head = NULL; // initially
    cout << "Enter elements(sorted): ";
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      head = insertAtTail(head, x);
    }
    listArray[i] = head; // store head of ith LL
  }

  // Node *mergedHead = mergekSortedLL(listArray);
  // Node *mergedHead = mergeKsortedLL(listArray);
  Node *mergedHead = mergeKSortedLL(listArray);
  cout << "After merge k sorted list: ";
  traverselInLL(mergedHead);
  cout << endl;
  return 0;
}