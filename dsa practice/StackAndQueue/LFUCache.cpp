// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3

// Constraints:

// 1 <= capacity <= 10^4
// 0 <= key <= 10^5
// 0 <= value <= 10^9
// At most 2 * 10^5 calls will be made to get and put.

#include <bits/stdc++.h>
using namespace std;

// for solving this problem, there is a prerequisite of LRU(least recently used)

// now What ts LFU Cache?
// The problem states that we have to design a datat structur which gives us two functionality: i) get function ii) put function

// i) get(key) function : says if the key already exists in the data structure then return the value or if it does not exist then return -1.

// put(key,value) function: it says that if the key already exists then updates its value with the new value or if it is not presente then insert the key with its value into our cache or data structure

// and definitely our cache or data structure has a size
// when the cache is full, it removes the LFU one means the guy who was least frequently used means having less frequency and if tie then the LRU one means the gus who are least recently used

// that is we have to design both the functions in a O(1) complexity

// for an example: Suppose size=2 so at max cache can store 2 not more than that

// i) put(1,10): first we see it exist or not so it doesn't exist so we take it and its frequency is 1
// ii) put(2,20): also not exist so take it and its frequency is 1 so in frequency 1 list now we add (2,20) from the front so
// freq=1: (2,20),(1,10) where (2,20) in front and (1,10) in last

// iii) get(1): exist returns the value 10 but there was (1,10) which is previously having a frequency 1 now we called a get(1) so now its frequency is increased by 1 now its frequency is 2
// freq=1: (2,20)
// freq=2:(1,10)

// iv) put(3,30): what happens? we see the cache size is 2 and the cache is already full so we have to remove the least frequenly used . Which is the least frequently guy? so least frequently guy is (2,20) with freq=1 so we remove it and we put(3,30) it is not exist already so its freq. now 1
// freq=1: (3,30)
// freq=2:(1,10)
// v) get(2): not exist so return -1
// vi) get(3): exist return value=30 ,(3,30) having a freq=1 previously now we called a get(3) so now its frequency is increased by 1 now its frequency is 2, now we have only freq=2 elts and we add(3,30) from front
// freq=2: (3,30),(1,10)  where (3,30) in front and (1,10) in last
// vii) put(4,4): what happens? we see the cache size is 2 and the cache is already full so we have to remove the least frequenly used . Which is the least frequently guy? least frequency is 2 and both guys having freq=2 so there is a tie then the guy who was least recently used(LRU) will be removed so obivously (1,10) will remove after that we put (4,4) in freq=1
// freq=1: (4,4)
// freq=2:(3,30)
// viii) get(1): not exist return -1
// ix) get(3): key=3 exist return value=30,(3,30) having a freq=2 previously now we called a get(3) so now its frequency is increased by 1 now its frequency is 3
// freq=1:(4,4)
// freq=2: null
// freq=3: (3,30)
// x) get(4): key=4 exist return value=4, (4,4) having a freq=1 previously now we called a get(4) so now its frequency is increased by 1 now its frequency is 2
// freq=1: null
// freq=2:(4,4)
// freq=3:(3,30)

// so that's how our data structure wil look and work

// Now we implement the LFU cache but for that we have an idea about LRU Cache

// in order to implement least recently used we was using a doubly linked list and whenever we was saying put(1,10), we just took this and put it into the right just after the dummy head suppose currently this list is having only one elt that is (1,10) so we have list like this: dummuHead->(1,10)->dummyTail suddenly someone else comes up and says put(2,20) so this goes just after the head so now our list becomes: dummyHead->(2,20)->(1,10)->dummyTail and if we remember in order to find least recently used we are looking from the back just before the dummy tail so the guy just befor ethe dummy tail was our least recently used . so this is the concept of LRU cache , so this concept we will be using in order to implement the LFU cache.

// So in order to implement the lFU cache we will be requiring couple of hashmaps:
// i) first hashmap stores the <int,frequencylist> and this list is a doubly linked list so we have map<int,List*>freqList, where list is doubly linked list and int denotes the frequency of that list
// ii) second hashmap stores the <key,node address> that we used in LRU cache so map<int,Node*>keyNode, where Node* gives the address of the key and int denotes the key

// then we will require a couple of variables:
// i) capacity: which counts how many elts are in our data structure
// ii) minFreq: which keeps a track of the least frequency
// both are initialized with 0

// suppose for an example:
// initially the size of the cache at maximum can be 3 so maxCapacity=3

// size=3
// i) put(1,10): what we will do is before puttinh this check it what does it exist previously? it does not exist so that means this is the first time it is coming, next we will check is there space in our cache so now capacity=0 so there is space in our cache so now we take this and put into our cache and first time it is coming so what will be its frequency? freq=1 so we'll say that map that is our freq=1 and since we don not have a doubly linked list so create a doubly linked list on a list as of now with freq=1 and we store this (1,10) and we know how to implement doubly linked list, we have already taught this in LRU cache so we have:
// freq=1 and in this list we have : dummyHead->(1,10)->dummy tail
// and for now my least frequency change so minFreq=1 because as of now my cache is having a least frequency of 1 and we also having a single elt
// and we say that (1,10) is present at position=x so in keyNode map we have: (1,x)
// and now capacity=1

// ii) put(2,20): again the same step, does not exist already and the next step is there a scapacity? yes we have space in our cache so we will take this (2,20) now since it did not exist so the frequency will be 1 and the frequency=1 we already have a list so we put it just after the dummy head so we will follow the LRU cache logic so
// freq=1 and in this list we have:  dummyHead->(2,20)->(1,10)->dummy tail
// and for now our  least frequency does not change so minFreq=1 as it is
// and we say that (2,20) is present at position=y so in keyNode map we have: (2,y),(1,x)
// and now capacity=2

// iii) put(3,30): again the same step, does not exist already and the next step is there is a capacity? yes we have space in our cache so we will take this (3,30) now since it did not exist so the frequency will be 1 and the frequency=1 we already have a list so we put it just after the dummy head so we will follow the LRU cache logic so
// freq=1 and in this list we have:  dummyHead->(3,30)->(2,20)->(1,10)->dummy tail
// and for now our  least frequency does not change so minFreq=1 as it is
// and we say that (3,30) is present at position=z so in keyNode map we have: (3,z),(2,y),(1,x)
// and now capacity=3

// iv) put(4,40): What we will do is? we will go and check ldoes it exist in our keyNode? it does not exist then we check is there a capacity in our cache ? No, our cache is full so we have to remove a guy whith a least frequency, so Who is the least frequently used guy? What is the least frequency? freq=1 is the least frequency and that list having 3 elts in it so 3 elts are occuring at freq=1 so the LRU guy will be removes since there is a tie in frequency between 3 elts so we remove the lRU guy so we removed the elt just before the dummyTail in that list so we remove the (1,10) from the list after that we have made space so we put (4,40) in that list just after the dummyHead because (4,40) also not exist previously so this is its first time so having freq=1 so put in this list so now we have: dummyHead->(4,40)->(3,30)->(2,20)->dummy tail
// and for now our  least frequency does not change so minFreq=1 as it is
// and we say that (4,40) is present at position=w so in keyNode map we have: (4,w),(3,z),(2,y)
// and now capacity=3

// so this is how we put (4,40) by removing LFU and if there was a tie then we remove the LRU

// v) get(3): we check in keyNode map : Is this exist or not? so this is exist where it is? it is at position=z so we ccess the node and return the value=30 but we need to delete the node from the list of freq=1 because we call the get function so now its frequency is increased by 1 so there will be another list of freq=2 and we put (3,30) here with new address so now we have two list in our freqList map:
// these are in our freqlIst map:
// freq=1: we have:  dummyHead->(4,40)->(2,20)->dummy tail
// freq=2: we have another list: dummyHead->(3,30)->dummyTail
// and for now our  least frequency does not change so minFreq=1 as it is
// and we say that (3,30) is now present at new position=r so in keyNode map we have: (4,w),(3,r),(2,y)
// and now capacity=3

// vi) get(2): key=2 check in keyNode map is this exist or not? it does exist at position=y so we go there and return the value=20 but we need to delete the node from the list of freq=1 because we call the get function so now its frequency is increased by 1 so it will be put in  list of freq=2 and we put (2,20) here with new address so now we have two list in our freqList map:
// these are in our freqlIst map:
// freq=1: we have:  dummyHead->(4,40)->dummy tail
// freq=2: we have another list: dummyHead->(2,20)->(3,30)->dummyTail
// and for now our  least frequency does not change so minFreq=1 as it is
// and we say that (2,20) is now present at new position=s so in keyNode map we have:(4,w),(3,r),(2,s)
// and now capacity=3

// vii) get(4): key=4 check in keyNode map is this exist or not? it does exist at position=w so we go there and return the value=40 but we need to delete the node from the list of freq=1 because we call the get function so now its frequency is increased by 1 so it will be put in  list of freq=2 and we put (4,40) here with new address so now we have two list in our freqList map:
// these are in our freqlIst map:
// freq=1: null
// freq=2: we have another list: dummyHead->(4,40)->(2,20)->(3,30)->dummyTail
// and for now our  least frequency  change because there is no elt in freq=1, we have all elts in freq=2 so minFreq=2 as of now
// and we say that (4,40) is now present at new position=u so in keyNode map we have: (4,u),(3,r),(2,s)
// and now capacity=3

// viii) put(5,50): we check it exist or not? it does not exist then we check our cache space and it is full so we have to remove  a guy whith a least frequency, so Who is the least frequently used guy? What is the least frequency? freq=2 is the least frequency and that list having 3 elts in it so 3 elts are occuring at freq=2 so the LRU guy will be removes since there is a tie in frequency between 3 elts so we remove the lRU guy so we removed the elt just before the dummyTail in that list so we remove the (3,30) from the list after that we have made space so we put (5,50) in  list with freq=1 just after the dummyHead because (5,50) also not exist previously so this is its first time so having freq=1 so put in  list of freq=1 so now we have:
// these are in our freqlIst map:
// freq=1: dummyHead->(5,50)->dummyTail
// freq=2: we have another list: dummyHead->(4,40)->(2,20)->dummyTail
// and for now our  least frequency  change because there is  elt in freq=1, so minFreq=1 as of now
// and we say that (5,50) is now present at  position=v so in keyNode map we have: (5,v),(4,u),(2,s)
// and now capacity=3

// ix) put(2,25): check this is exist or not in keyNode map? so yes this is already exist in keyNode map so we have to update only its value so we go its address and checng its value =25 but we accessed it so its frequency is increased by 1 so now its freq=3 so we'll create another list with freq=3 and put (2,25) so we delet the node (2,s) from the keyNode and store it with new address suppose its address = t so (2,t)in keyNode now in it just after the dummy head node so now we have:
// these are in our freqlIst map:
// freq=1: dummyHead->(5,50)->dummyTail
// freq=2: we have another list: dummyHead->(4,40)->dummyTail
// freq=3: we have another list: dummyHead->(2,25)->dummyTail
// and for now our  least frequency does not change because there is  elt in freq=1, so minFreq=1 as of now
// and we say that (2,25) is now present at new position=v so in keyNode map we have: (5,v),(4,u),(2,t)
// and now capacity=3

// this is the entire logic that we have to implement
// We have used a frequency list(doubly linked list) basically for every frequency like 1,2,3..  and for each frequency list  individual LRU has been implemented
// nothing special, every time an elt is accessed what I do is I just take out from the current frequency and increase its frequency by 1 and put it into the next frequency list and right just after the dummyHead so that's how we have implemented the entire LFU cache using the LRU cache

// doubly linked list node contains the (key,value,next pointer,prev,pointer,freq=cnt)
struct Node
{
  int key;
  int val;
  int cnt; // represent the frequency of the node means in which frequency list it is present
  Node *next;
  Node *prev;
  // constructor initialize the node with freq=1
  Node(int _key, int _val)
  {
    key = _key;
    val = _val;
    cnt = 1;
  }
};

// doubly linked list define
struct List
{
  int size;
  Node *head; // dummyHead
  Node *tail; // dummyTail
  // constructor initialize the List with dummyhead node and dummyTail node with size of list=0
  List()
  {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  // add the node just after the dummyHead
  void addNodeJustAfterHead(Node *newNode)
  {
    Node *temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
    // as we add the node in the list so size of that list increase
    size++;
  }

  // remove the node from the list just before the dummyTail
  void removeNode(Node *delNode)
  {
    Node *delPrev = delNode->prev;
    Node *delNext = delNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
    // as we remove the node from the list so size of that list decrease
    size--;
  }
};

// class to implement the LFU
class LFUCache
{
  // map that store the (key,node address) determine where the key exist so Node* is the address of that node and int denotes the key
  map<int, Node *> keyNode;
  // map store the (freq,freqList) determine the list with frequency i.e suppose for freq=1 this is a list we have
  map<int, List *> freqListMap;
  // maximum capacity of LFU cache
  int maxSizeCache;
  // store the least frequecny of our LFU cache
  int minFreq;
  // current size of our cache
  int currSize;

public:
  // constructor to initialize a LFU cache with maximum capacity and initially minfreq=0 and currsize=0
  LFUCache(int capacity)
  {
    maxSizeCache = capacity;
    minFreq = 0;
    currSize = 0;
  }

  // whenever we call the put or get function then there is an update in freqList map so for that
  void updateFreqListMap(Node *node)
  {

    // when we call either get or put function the frequency of the node increased by 1 so it move to the new list so it have the new address so we remove that node from the keyNode map with old address
    keyNode.erase(node->key);
    // and also remove from the old list with its current frequency then after we increased its freq by 1 and move it in a next list
    freqListMap[node->cnt]->removeNode(node);
    // if the current  frequency of node before increasing by 1 = minfreq and we already remove it from the old list above we write a code for that so after removing it if the  old list become empty means it is only one node with minfreq so now minfreq is also increased by 1
    if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
    {
      minFreq++;
    }
    // when we increased the freq by 1 means new list is create
    List *nextHigherFreqList = new List();
    // if the new list already exist means suppose we have initially freq=1 now freq increased by 1 then we have freq=2 if we have already list with freq=2 then new list = that list otheriwse it is simply a new list
    if (freqListMap.find(node->cnt + 1) != freqListMap.end())
    {
      // means new list is already exist in freqList map so  new list is equal to that
      nextHigherFreqList = freqListMap[node->cnt + 1];
    }
    // increased the current node frequency by 1
    node->cnt += 1;
    // add that node in new list just after the dummy head
    nextHigherFreqList->addNodeJustAfterHead(node);
    // also update in freqList map
    freqListMap[node->cnt] = nextHigherFreqList;
    // and also update its address in keyNode map because its position change from one list to other list
    keyNode[node->key] = node;
  }

  // get function
  int get(int key)
  {
    // if key exist in our keyNode map then we return its value and update that key by increased its frequency by 1
    if (keyNode.find(key) != keyNode.end())
    {
      // access the key address
      Node *node = keyNode[key];
      // store its value
      int answer = node->val;
      // increased its freq. by 1 so it move in next list
      updateFreqListMap(node);
      // return the value
      return answer;
    }
    // if not exist then return -1
    return -1;
  }

  // put function
  void put(int key, int value)
  {
    // if maximum capacity of our cache =0 means it cannot take any elt so return
    if (maxSizeCache == 0)
      return;

    // if key already exist then we update its value and also increased its freq. by 1
    if (keyNode.find(key) != keyNode.end())
    {
      Node *node = keyNode[key];
      // update its value
      node->val = value;
      // increased its freq. by 1 so it move in next list
      updateFreqListMap(node);
    }
    // when it does not exist already
    else
    {
      // if our cache is full then we remove elt with least frrequency and if there is a tie the n LRU guy return
      if (currSize == maxSizeCache)
      {
        // least frequency list we access then from that list we remove the guy just before the dummyTail
        List *list = freqListMap[minFreq];
        // also remove the node of that guy from the keyNode map
        keyNode.erase(list->tail->prev->key);
        // and remove that guy from minimum frequency list
        freqListMap[minFreq]->removeNode(list->tail->prev);
        // so current size of our cache is decrease by 1
        currSize--;
      }
      // after removing we have space so we insert current elt so increase teh current size of our cache by 1
      currSize++;
      // and when we insert new (key,value) means its insert first time so its freq=1 means now our least frequency=1 so
      minFreq = 1;
      // create a new list
      List *listFreq = new List();
      // if the least frequency list i.e freq=1 list already exist in freqList map then new list is equal to that freq=1 list and we add new node(key,value) in that list
      if (freqListMap.find(minFreq) != freqListMap.end())
      {
        listFreq = freqListMap[minFreq];
      }
      // make a new node for current insert node
      Node *node = new Node(key, value);
      // and add it in new list=minfreq=1 list
      listFreq->addNodeJustAfterHead(node);
      // also add new node in keyNode map
      keyNode[key] = node;
      // and now minfreq list = new list
      freqListMap[minFreq] = listFreq;
    }
  }
};

int main()
{
  LFUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;

  return 0;
}