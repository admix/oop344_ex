#include <iostream>

using namespace std;

class Data {
  int data;
public:
  Data (int d = 0):data(d){}
  int out() const{
    return data;
  }
};

struct Node {
  Data data;
  Node* next;
  Node* previous;
  Node (const Data& d, Node* n, Node* p): data(d), next(n), previous(p) {}
  
};

class DLList {
  Node* head;
  Node* tail;
  Node* current;
public:
  DLList(): head(NULL), tail(NULL), current(NULL) {}
  ~DLList() {
    while ((current = head)){
      head = head->next;
      delete current;
    }
  }
  void goHead() {
    current = head;
  }
  void goNext() {
    if(current)
      current = current->next;
  }
  void remove() {
    if(current) {
      Node* p = current;
      if(current == head) {
        head = head->next;
      }
      else {
        current->next->previous = current->previous;
        current->previous->next = current->next;
        current = current->next;
      }
      delete p;
    }
  }
  bool end() {
    return !current;
  }
  Data get() const {
    return current ? current->data : Data();
  }
  void insertBefore(const Data& a) {
    if(current) {
      Node* p = new (nothrow) Node(a, current, current->previous);
      if(p) {
        if(current->previous)
          current->previous->next = p;
        else
          head = p;
        current->previous = p;
      }
    }
    else {
      Node* p = new (nothrow) Node(a, NULL, NULL);
      if(p)
        head = tail = current = p;
    }
  }
  void insertAfter(const Data& a) {
    if(current) {
      Node* p = new (nothrow) Node(a, current->next, current);
      if(p) {
        if(current->next)
          current->next->previous = p;
        else
          tail = p;
        current->next = p;
      }
    }
    else {
      Node* p = new (nothrow) Node(a, NULL, NULL);
      if(p)
        head = tail = current = p;
    }
  }
};




