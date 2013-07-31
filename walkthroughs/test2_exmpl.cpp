//_This walk through is saved into a file called walks.cpp
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void w1(){
  int a = 12345;
  int b = ~a + 1;
  cout<<"~a = "<< ~a << endl;
  cout<< b + a<<endl;
}
void w2(unsigned int a, int b){
  a = a | (1<<b);
  printf("%X\n", a);
}
template <class T>
struct pk{
  pk<T>* _n;
  T _d;
  pk(T d, pk<T>*n):_n(n),_d(d){}
};
void w3(){
  pk<double>* p = 
     new pk<double>(2.0, 
        new pk<double>(4.0,
           new pk<double>(6.0,(pk<double>*)0
                         )
                      )
                   );
  pk<double>* t;
  while(p){
    t = p;
    cout<<p->_d<<" ";
    p = p->_n;
    delete t;
  }
  cout<<endl;
}

void w4(){
  char ch;
  fstream f("walks.cpp", ios::in|ios::binary);
  f.seekg(3);
  f.read(&ch, 1);
  cout<<ch;
  f.seekg((ios::off_type)-4,ios::end);
  f.read(&ch, 1);
  cout<<ch<<endl;
}
class A{
private:
  char _d;
public: 
  A(char d = 'X'):_d(d){  }
  void p(){cout<<_d;}
};
class B:virtual  public A{
private:
  char _d;
public: 
  B(char d):_d(d){}
  void p(){
    A::p();
    cout<<_d;
  }
};
class C:virtual public A{
private:
  char _d;
public: 
  C(char d = 'C'):A(d+3),_d(d){}
  void p(){ A::p(); cout<<_d;}
};
class D:public B, public C{
private:
  char _d;
public: 
  D(char d):B(d+1),_d(d){}
  void p(){ B::p(); C::p(); cout<<_d; }
};
void w5(){
  D d('D');
  d.p();
  cout<<endl;
}
void w6(){
  cout<<"OOP344"[2]<<endl;
}
char w7(void){
  int 
    i=4;
  double d = 2.2;
  while(i--){
    try{
      if(i){
        throw "C";
      }
      else if(i%2 == 0){
        throw i;
      }
      else{
        d += 2;
        throw d;
      }
      cout<<"X"<<endl;
    }
    catch(int a){
      cout<<a<<endl;
    }
    catch(double b){
      cout<<b<<endl;
    }
  }
}
int main(){
  unsigned int x = 0x8;
  w1();
  w2(x,2);
  w3();
  w4();
  w5();
  w6();
  w7();
  return 0;
}