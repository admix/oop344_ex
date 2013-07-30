#include "dll.h"
#include <iostream>
#include <fstream>

void saveToFile(int a, char* name);
void readFromFile(char* name);
void testReadFile(char* name);
using namespace std;
int main(int argc, char* argv[]){
  //save
  DLList dl;
  dl.insertAfter(10);
  dl.goNext();
  //dl.insertBefore(20);
  dl.insertAfter(30);
  //dl.insertBefore(40);
  /*dl.goHead();
  dl.goNext();
  dl.insertAfter(5);
  dl.goHead();
  dl.insertAfter(1);*/
  dl.goHead();
  
  while (!dl.end()) {
    cout << dl.get().out()<<' ';
    dl.goNext();
  }
  cout<<endl;
  
	return 0;
}
void testReadName(char* name){
  char str[1025];
  char* p = str;
  
  ifstream f(name, ios::in | ios::binary);
  
  while (f) {
    f.read(p++, 1);
  }
  *--p = '\0';
  
  cout<<str<<endl;
}

void saveToFile(int a, char* name){
  DLList df;
  df.insertAfter(a);
  fstream st(name, ios::out | ios::binary | ios::trunc);
  while(!df.end()){
    int i = df.get().out();
    st.write((char*)&i,sizeof(i));
    //(char*)(&ttt), sizeof(ttt));
    //cout<<dl.get().out()<<' ';
    df.goNext();
  }
}

void readFromFile(char name){
  char str[1025];
  char* p = str;
  fstream f(&name, ios::in | ios::binary);
  while (f)
    f.read(p++, 1);
  *--p = '\0';
  
  cout << str << endl;
}