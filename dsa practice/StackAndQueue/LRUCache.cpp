// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 10^4
// 0 <= value <= 10^5
// At most 2 * 10^5 calls will be made to get and put.

#include <bits/stdc++.h>
using namespace std;

// LRU(Least Recently Used) is a Page Replacement Algorithm for storing data into cache memory we spilt the data into pages and we store pages in the memory

// here we have to implement LRU Cache class
// we initialized cache memory with limited capacity
// here we have two functions: i) get(key) ii)put(key,value)

// i) get(key): this function takes a key and if that key exist in cache memory then  returns the value of it when we returns the value of it means we recently used it so we place that key-value pair in front because it is recently used otherwise   return -1 when key not already exist.

// ii) put(key,value): this function takes a key and value as an argument , if that key already exist in memory then put() function update the key-value with new value and place it in front because it is recently used or if the key does not exist in memory then put() function insert the key-value pair in the cache memory but there we need to check is cache capacity == given capacity or not because if it is full means cache capacity == given capacity then in that case we have to delete the key-value pair from the cache which is not recently used so that key-value pair exists in last because recently used pair exist in front so we delete the last pair and insert the new pair in front or if cache capacity != given capacity then we insert the new pair simply in front

// so always remember whenever we call get() function and key exist then we put that key-val pair in front and also when we call put() function thena also we put key-val pair in front because that key-val pair is recently used and when capacity fullfill we delete the pair that is not recently used which means we delete the last key-value pair and we add new pair in front

// The intuition behind an LRU(Least Recently Used) Cache is that we want to store only a fixed number of items in memory and quickly evict the item that hasn't been used for the longest time means the item that has not been used for the longest time is existing in last of the memeory so we removed that item and when we add new item it is put in front of the memory. This is useful when memory is limited and we want to keep the most relevant data available for fast retrieval. The key idea is to maintain quick lookups to check if a value exists in the cache, and also maintain the usage order so we can remove the least recently used item(i.e item that is not used for longest time means item jo recent me kam use hua hai) efficiently when the cache is full.

// To implement it efficiently, we combine two data structures: a Hashmap for O(1) lookup of keys, and a Doubly Linked List to maintain the order of usage. The most recently used items (i.e item that are used in recent) are kept at one end(head), and the least recently used items(i.e item that are not used for the longest time) kept at the other end(tail). When we access or insert a key, we move it to the right after the dummy head node means  move the item right after the head node means it is recently used whereas when the cache is full, we remove the node which is just before the dummy tail node means we remove the item that is not used for the longest time means it is in last . This combination ensures both O(1) access and O(1) insertion/deletion for LRU operations.

// we use unoredered map so it takes O(1) at average for insertion/deletion/access
// in hashmap we store the (key,node address) means mpp[key]=node address means where the key exist in doubly linked list

// in doubly linked list, a node store the (key,value,previous pointer, next pointer)

// initially we initialized doubly linked list with two dummy nodes: i) head dummy node with key = -1 and value = -1 and tail dummy node with key = -1 and value = -1 where head->next=tail and tail->prev=head and head->prev=null and tail->next=null

// when we access or insert a key , we move the node right after the head node means it is recently used
// and when cache is full, we remove the node previous of tail node means it is in last but prev of dummy tail node and also delete its entry from hashamp.

// also when we access or update the value of existing key-value in that case we delete that pair and add it in right after the head because it is recently used so in that case we don't delete that node permanently, we reuse that node means we delete that node from previous place by shifting the prev and next pointer only and add that same node right after the head with same address by shifting the prev and next pointer means we only change pointers not the address of the node

// Algorithm:
// Use a Hashmap to store key-value pairs for direct access to elts in the cache and in hashmap we store (key,node address) where the key-value pair store in cache and hashmap size also help in to determine cache is full or not.
// Maintain a Doubly Linked List to track the usage order, with the most recently used node right after the dummy head node and the least recently used just before the dummy tail node.
// On a get(key) opeartion, if the key exists, move the corresponding node to the right after the dummy head node by changing pointers only, not by deleting the node and making a new node and returns its value, otherwise, return  -1.

// On a put(key,value) operation, it the key exists, update the value and move it to the right after the dummy head node by changing pointers only, not by deleting the node and making a new node. If it does not exist, create a new node, insert it at right after the dummy head node, and store it in the hashmap.

// If the cache exceeds capacity after an insertion, remove the node just before the dummy tail node and delete its entry from the hashmap also.

// So here we notice one thing that we reuse the node when we access/update an value by changing only pointers prev and next , not deleting it permanenlty and making a new node for them so by changing pointers we have same address so no change in hashmap but when cache is full then remove a node from list by changing only pointers not permanently means we remove it from list but not from memory and also delete it from hashmap when cache is full

// dry run:
// initially we have dummy head and tail node with key = -1 and value =-1 and head->next=tail and tail->prev=head

// and hashmap is empty, storing (key, node*)
// capacity=3
// i) first operation : put(1,10) so key=1 not exist now so we create a new node suppose having an address = x so we insert (1,x) in hashmap and add node with key=1 and value=10 just right after the head node so head->next=x and tail->prev=x and x->next=tail and x->prev=head
// ii) second operation: put(3,15) so key=3 not exist now so we create a new node suppose having an address = y so we insert (3,y) in hashmap and add node with key=3 and value=15 just right after the head node so head->next=y and y->next=x and x->prev=y and y->prev=head
// third operation:  put(2,12) so key=2 not exist now so we create a new node suppose having an address = z so we insert (2,z) in hashmap and add node with key=2 and value=12 just right after the head node so head->next=z and z->next=y and y->prev=z and z->prev=head
// fourth operation: get(3) so key=3 exist so we move the corresponding node to the just right after the head node by changing the pointers only not by deleting it permanently, address remain same only pointers change so address of key=3 is y so now head->next=y and y->prev=head and z->prev=y and y->next=z and we return the value=15
// fifthe operation: put(4,25) so key=4 not exist but now cache is already full so we have to remove the node just before the dummy tail node so we delete the node with key=1 and value=10 and address=x, we delete it permanently and also delete it from hashmap then we add a new node with key=4 and suppose address = r just right after the head node so head->next=r and r->prev=head and r->next=y and y->prev=r

// finish

// Time Complexity: get() function: O(1), accessing a value in the HashMap is O(1) on average because we use unoredered map
// put() function: O(1), checking and removing from the map as well as inserting into the doubly linked list is O(1).
// Space Complexity: O(capacity) , for storing up to capacity nodes in the doubly linked list and map.

// class representing the LRU Cache
class LRUCache
{
public:
  // Doubly linked list node class
  class Node
  {
  public:
    int key;
    int val;
    Node *next;
    Node *prev;
    // constructor to initialize node
    Node(int _key, int _val)
    {
      key = _key;
      val = _val;
    }
  };
  // head tail dummy nodes with key=-1 and value=-1
  Node *head = new Node(-1, -1);
  Node *tail = new Node(-1, -1);
  // capacity of cache
  int cap;
  // hashmap to store (key,node(address)) mapping
  unordered_map<int, Node *> mpp;
  // constructor to initialize LRU Cache with given capacity
  LRUCache(int capacity)
  {
    cap = capacity;
    head->next = tail;
    tail->prev = head;
    mpp.clear(); // because we initialize new cache so new mpp should be empty initially
  }
  // function to add a node just right after the dummy head node
  void addNodeRightAfterHead(Node *newNode)
  {
    Node *temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
  }
  // function to remove a node from list by changing only pointers not permanently means we remove it from list but not from memory
  void deleteNode(Node *delNode)
  {
    Node *delPrev = delNode->prev;
    Node *delNext = delNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
  }
  // function to get value from cache
  int get(int key_)
  {
    // if key exists in cache
    if (mpp.find(key_) != mpp.end())
    {
      Node *resNode = mpp[key_];
      int answer = resNode->val;
      // move the node to the right after the head by changing the pointers because it is recently used , so we only move the node not delete it so it remain in the mpp as it is with the same address because we reuse the node
      deleteNode(resNode); // from the current place we delete it and add it to the right after the head
      addNodeRightAfterHead(resNode);
      return answer;
    }
    // if not found
    return -1;
  }
  // function to put key-value into cache
  void put(int key_, int value)
  {
    // if key already exists then update the value
    if (mpp.find(key_) != mpp.end())
    {
      Node *existingNode = mpp[key_];
      // update its value
      existingNode->val = value;
      // and  move the node to the right after the head by changing the pointers because it is recently used, so we only move the node not delete it so it remain in the mpp as it is with the same address because we reuse the node
      deleteNode(existingNode); // from the current place we delete it and add it to the right after the head
      addNodeRightAfterHead(existingNode);
    }
    // else when it is not existing or capacity is full
    else
    {
      // if capacity reached
      if (mpp.size() == cap)
      {
        // delete the node just before the tail node and also we delete it from the mpp
        Node *node = tail->prev;
        mpp.erase(node->key);
        deleteNode(node);
      }
      // now we insert the new node just after the head node
      Node *newNode = new Node(key_, value);
      // also insert it in mpp
      mpp[key_] = newNode;
      addNodeRightAfterHead(newNode);
    }
  }
};

int main()
{
  // create cache with capacity 2
  LRUCache cache(2); // where cache is an object
  // put values in cache
  cache.put(1, 1);
  cache.put(2, 2);
  // get value for key 1
  cout << cache.get(1) << endl;

  // Insert another key(evicts key 2 because of capacity)
  cache.put(3, 3);

  // Key 2 should be evicted
  cout << cache.get(2) << endl;

  // Insert another key (evicts key 1)
  cache.put(4, 4);

  // Key 1 should be evicted
  cout << cache.get(1) << endl;

  // Key 3 should be present
  cout << cache.get(3) << endl;

  // Key 4 should be present
  cout << cache.get(4) << endl;

  return 0;
}