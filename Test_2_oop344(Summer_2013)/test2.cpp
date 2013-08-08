/*OOP344 Test 2 V1
First Name: _______________
Last Name: _______________
Date: _______________
Section: ______________
Student ID: _______________

Please answer each question as concisely as possible in the test booklet provided. This test is worth 15% of your final mark. Please print your answers as neatly as possible, you will not be given a mark if I cannot read your answers. You may have 3 reference materials, which can be any combination of class textbook, class notes (bound together in a binder), and/or a double sided cheat sheet.

Section 1 - Coding (25 Marks)

1) Templated Doubly Linked List Node [2 Marks]
Write a Node struct for a templated doubly linked list. Include all the require member variables, only function that must be written is a constructor that ensure all variable are set to a safe null value.


2)  Templated Doubly Linked List Class Definition [2 Marks]
Re-write the DoublyLinkedList class (provided below) so that it will accept any variable as opposed to simply ints. Assume you will be using the node from the previous question. You do not need to implement any of the functions, their declarations will suffice.


*/
class DoublyLinkedList
   {
   private:
      Node *front, *back, *cur;
      unsigned int size;
   public:
      DoublyLinkedList();

      void goFront();
      void goBack();
      void goNext();
      void goPrev();
      int getValue() const; 
      void setValue(int d);
      void insertBefore(int d);
      void insertAfter(int d);
      void erase();
      bool isEmpty() const;
      unsigned int getSize() const;
      void pushFront(int d);
      void pushBack(int d);
      void popFront();
      void popBack();
      ~DoublyLinkedList();
   };
/*
 *3) Templated Type Counter [5 Marks]
 *Write a type counter class which can be inherited by any class that will keep count of the number of live instances (yet to be destroyed) of that particular class. This class will need to be templated and take the child class’s class name as its template parameter. It will contain a single private static unsigned int that will keep track of the number of allocated objects there are. The class will have the following public functions:
 */
	TypeCounter();//ctor
	~TypeCounter();//dtor
	static unsigned int getCount();
/*
 *Write the class definition and all function definitions for this class. You must initialize the classes static variable in your answer.
 *
 *4) Type Counter Usage [3 Marks]
 *Write a basic class called A which will use the TypeCounter class to keep track of the number of instantiations of class A. Class A will not have any member variables or functions. Additionally, write a simple main function that make an makes 2 A objects and execute getCount() to find the number of A objects created.
 *
 *5) Diamond Inheritance Resolutions [4 Marks]
 *Four classes are defined as follows:
 */
class A {public: int i;};
class B : public A {};
class C : public A {};
class D : public B, public C {};
/*
 *This definition has resulted in redundant data and tricky scope resolution. Re-write these class definitions so that class D only has a single instance of A’s int i, but still inherits from A, B, and C, and so that B and C both still inherit from A.
 *
 *[BONUS 1 MARK]
 *There are two effective ways at tackling this issue, for a bonus mark, re-write these definitions with both methods.
 *
 *6) Heterogenous Arrays [5 Marks]
 *Our Heterogenous Array and Exception classes have the following definition:
 */
struct Exception 
   {
   char msg[100];
   Exception(char* m) {strcpy_s(msg, m);}
   }/*


*/
class HArray
   {
   private:
      std::vector<char> data;
      std::vector<uint> index;
   protected:
   public:
  	HArray ();//automatically inserts 0 into index
               //so size doesn’t need to kept

     template <class T>
  	void push_back(T d);//Adds a variable to the end
  	const char* operator[](uint i) const;//return pointer to element
  	unsigned int dataSize() const;//return total size in bytes

     //get the size of an element in bytes, taking an index
     unsigned int getElementSize(unsigned int) const;
     
	template <class T>
     T& getValue(unsigned int index) const;
   };
/*
Code the getValue() function so that it returns the element in the heterogeneous array indicated by the incoming unsigned int index. The returning type (defined by the template) must have the same size as the element that is going to be returned or the function should throw an Exception object with the appropriate message. Please use any member functions of HArray that will assist you in your coding (assume they are all implemented correctly).



7) Bit-wise Operations [4 Marks]
Our Permission enum and PermissionHolder class is defined as follows:
*/
enum Permission
   {
   NONE,
   VIEW,
   EDIT = 1 << 1,
   NEW = 1 << 2,
   DELETE = 1 << 3,
   EDIT_ALL = 1 << 4,
   DELETE_ALL = 1 << 5
   };

class PermissionHolder
   {
   public:
   unsigned char perm;
   };
/*
Write 3 classes named Admin, User, Anon. Each inherit from PermissionHolder. Write each class a constructor, in the constructor, using bit-wise operators, assign each class its proper permissions using the Permission enum above. The permissions are as follows:

Admin - View, Edit, New, Delete, Edit all, Delete all
User - View, Edit, New, Delete
Anon - View

Additionally, write a Validate function that returns true if the passed in PermissionHolder has the passed in Permissions enum (you must use bit-wise operators). The function prototype is as follows:

bool Validate(PermissionHolder* ph, Permission p);

(For example, if an Admin is passed in and a DELETE permission is passed in, it will return true, but if a Anon is passed in and a DELETE permission is passed in, it will return false).
Section 2 - Walkthrough (15 Marks)
Walkthrough the following code and write out the EXACT output of the program:
*/
#include <string>
#include <iostream>
#include <stack>
#include <cstring>

class Exception 
   {
   public:
      char msg[100];
      Exception() {strcpy_s(msg, "Base Exception Thrown");}
   };

class SmallException : public Exception 
   {
   public: SmallException() 
      {strcpy_s(msg, "Small Exception Thrown");}
   };

class BigException : public Exception
   {
   public: BigException() 
      {strcpy_s(msg, "Big Exception Thrown");}
   };

class DeadlyException : public BigException
   {
   public: DeadlyException() 
      {strcpy_s(msg, "Deadly Exception Thrown");}
   };

template <class T>
T collect(T* pkg, int size)
   {
   if(size < 0)
      throw(SmallException());
   T ret = 0;
   if(size)
      ret += collect(pkg + 1, size - 1) + *pkg;
   return ret;
   }

int chopUp(int in, int pos)
   {
   if(pos < 0 || pos > 3)
      throw(BigException());
   char* c = reinterpret_cast<char*>(&in);
   return static_cast<int>(c[pos]);
   }

std::string STLMadness(std::stack<int>& s)
   {
   if(s.empty())
      throw(DeadlyException());
   std::string ret = "STL Madness ";
   while(!s.empty())
      {
      if(s.top() > 7)
         ret += "! ";
      else
         ret += "Sunday";
      s.pop();
      }
   return ret;
   }

int crash()
   {
   throw(Exception());
   return 0;
   }

int main()
   {
   bool active = true;
   float far[5] = {0.0f, 20.0f, 13.0f, 16.0f, 31.0f};
   int iar[5] = {18, 13, 12, 2, 1};
   int testCount = 9;

   std::stack<int> s;
   s.push(10);
   s.push(5);
   s.push(15);
   s.push(0);

   std::cout << "Welcome to the test..." << std::endl;
   while(active)
      {
      try
         {
         if(testCount == 9)
            std::cout << "Test #" << testCount-- << ": We collected " << collect(far, 5) << " of Float" << std::endl;
         if(testCount == 8)
            std::cout << "Test #" << testCount-- << ": We collected " << collect(far, 3) << " of Float" << std::endl;
         if(testCount == 7)
            std::cout << "Test #" << testCount-- << ": We collected " << collect(iar, 4) << " of Int" << std::endl;
         if(testCount == 6)
            std::cout << "Test #" << testCount-- << ": We collected " << collect(iar, -4) << " of Int" << std::endl;
         if(testCount == 5)
            std::cout << "Test #" << testCount-- << ": ChopUp! " << chopUp(18, 0) << " " << chopUp(18, 1) << " " << chopUp(18, 2) << " " << chopUp(18, 3) << std::endl;
         if(testCount == 4)
            std::cout << "Test #" << testCount-- << ": ChopUp! " << chopUp(18, 0) << " " << chopUp(18, -1) << " " << chopUp(18, -2) << " " << chopUp(18, -3) << std::endl;
         if(testCount == 3)
            std::cout << "Test #" << testCount-- << ": " << STLMadness(s) << std::endl;
         if(testCount == 2)
            std::cout << "Test #" << testCount-- << ": " << STLMadness(s) << std::endl;
         if(testCount == 1)
            std::cout << "Test #" << testCount-- << ": " << crash() << std::endl;
         if(testCount == 0)
            active = false;
         }
      catch(SmallException a)
         {std::cout << "Catch Small: " << a.msg << std::endl;}
      catch(BigException a)
         {std::cout << "Catch Big: " << a.msg << std::endl;}
      catch(DeadlyException a)
         {std::cout << "Catch Deadly: " << a.msg << std::endl;}
      catch(Exception a)
         {std::cout << "Catch Base: " << a.msg << std::endl;}

      }
   return 0;
   }



