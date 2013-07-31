#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct A
{
    virtual void show() const = 0;
    virtual ~A() {}
};
struct B : A
{
    int n;
    B(int i) : n(i) {}
    void show() const { cout << n << endl; }
};
struct C : A
{
    string str;
    C(const string& s) : str(s) {}
    void show() const { cout << str << endl; }
};
struct D : A
{
    double db;
    D(const double i) : db(i) {}
    void show() const { cout << db << endl; }
};
int main()
{
    vector<unique_ptr<A>> list;
    list.emplace_back(new B(1));
    list.emplace_back(new C("test"));
    list.emplace_back(new D(12.78));
    for(auto i = list.cbegin(); i!=list.cend(); ++i)
        (*i)->show();
    return 0;
}