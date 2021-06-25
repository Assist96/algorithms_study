#include<iostream>
#include<cstdlib>
using namespace std;
class A{
public:
    A(){}
    A(int a){}
    ~A(){}
};
class B{
public:
    B(){}
    virtual int vfunc1(){};
    B(int a){}
    ~B(){}
};
int main(){
    A a;
    B b;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
}