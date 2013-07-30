#include <iostream>
#include <string>

class Exception
{
	public:
	std::string message;

	Exception() {}
	Exception(const std::string& a)
	{message = a;}
};

class EraseException : public Exception {public:	EraseException(const std::string& a)
	{message = a;}};
class IteratorException : public Exception {public:	IteratorException(const std::string& a)
	{message = a;}};
class EmptyListException : public Exception {public:	EmptyListException(const std::string& a)
	{message = a;}};

struct DLLNode
   {
   int data;
   DLLNode* next;
   DLLNode* prev;

   DLLNode() : next(nullptr), prev(nullptr) {}
   };

class DoublyLinkedList
   {
   private:
      DLLNode* front;
      DLLNode* back;
      DLLNode* cur;
      unsigned int size;

   protected:
   public:
      //Base constructor and copy constructor (pointers can't persist across copies)
      DoublyLinkedList() : front(nullptr), back(nullptr), cur(nullptr), size(0)  {}
      DoublyLinkedList(const DoublyLinkedList& a)
         {
         *this = a;
         }

      //Moves the current pointer to the front or back of the list
      void goFront() {cur = front;}
      void goBack() {cur = back;}

      //Moves the current pointer to the next or previous item of the list
      void goNext()
         {
         if(cur == back)
            throw(IteratorException("Already at end, cannot move forward"));
         cur = cur->next;
         }

      void goPrev()
         {
         if(cur == front)
            throw(IteratorException("Already at front, cannot move back"));
         cur = cur->prev;
         }

      //Gets or sets the value within current item
      int getValue() const 
         {
         if(!cur)
            throw(EmptyListException("Cannot get value, list is empty"));
         return cur->data;
         }
      void setValue(int d)
         {
         if(!cur)
            throw(EmptyListException("Cannot set value at present position"));
         cur->data = d;
         }

      //Insert a new node before or after the current item
      void insertBefore(int d)
         {
         auto n = new DLLNode();
         n->data = d;
         size++;

         if(!cur)
            front = back = cur = n;
         else
            {
            if(cur == front)
               {
               n->next = front;
               front->prev = n;
               front = n;
               }
            else
               {
               n->prev = cur->prev;
               n->next = cur;
               cur->prev = n;
               n->prev->next = n;
               }
            }
         }
      void insertAfter(int d)
         {
         auto n = new DLLNode();
         n->data = d;
         size++;

         if(!cur)
            front = back = cur = n;
         else
            {
            if(cur == back)
               {
               n->prev = back;
               back->next = n;
               back = n;
               }
            else
               {
               n->prev = cur;
               n->next = cur->next;
               cur->next = n;
               cur->prev->next = n;
               }
            }
         }

      //Remove the current item
      void erase()
         {
         auto t = cur;
         if(!cur)
            throw(EmptyListException("Cannot erase value at present position"));
         if(cur == front)
            front = cur->next;
         else
            cur->prev->next = cur->next;
         if(cur == back)
            {
            back = cur->prev;
            cur = back;
            }
         else
            {
            cur->next->prev = cur->prev;
            cur = cur->next;
            }

         delete t;
         size--;
         }

      //checks if the list is empty
      bool isEmpty() const {return !size;}

      //returns the size of the list
      unsigned int getSize() const {return size;}

      //Add a new item to the beginning or end of the list
      void pushFront(int d)
         {
         auto n = new DLLNode();
         n->data = d;

         if(!cur)
            front = back = cur = n;
         else
            {
            n->next = front;
            front->prev = n;
            front = n;
            }
         size++;
         }
      void pushBack(int d)
         {
         auto n = new DLLNode();
         n->data = d;

         if(!cur)
            front = back = cur = n;
         else
            {
            n->prev = back;
            back->next = n;
            back = n;
            }
         size++;
         }

      //Remove the first or last item in the list
      void popFront()
         {
         if(!cur)
            throw(EmptyListException("Cannot pop from list; list empty"));
         if(front == back)
            {
            delete front;
            front = back = cur = nullptr;
            }
         else if(front == cur)
            {
            cur = cur->next;
            cur->prev = nullptr;
            delete front;
            front = cur;
            }
         else
            {
            auto t = front->next;
            t->prev = nullptr;
            delete front;
            front = t;
            }
         size --;
         }
      void popBack()
         {
         if(!cur)
            throw(EmptyListException("Cannot pop; list empty"));
         if(front == back)
            {
            delete front;
            front = back = cur = nullptr;
            }
         else if(back == cur)
            {
            cur = cur->prev;
            cur->next = nullptr;
            delete back;
            back = cur;
            }
         else
            {
            auto t = back->prev;
            t->next = nullptr;
            delete back;
            back = t;
            }
         size --;

         }

      //Assignment operator (pointers can't persist across copies)
      DoublyLinkedList& operator=(const DoublyLinkedList& a)
         {
         auto c = a.front;
         for(unsigned int i = 0; i < a.getSize(); i++)
            {
            pushBack(c->data);
            c = c->next;
            }
         return *this;
         }

      //Destuctor destroys all nodes in the list
      ~DoublyLinkedList()
         {
         while(getSize())
            popBack();
         }
   };