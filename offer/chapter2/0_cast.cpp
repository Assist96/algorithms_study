#include<iostream>
#include<string>
using namespace std;
//http://c.biancheng.net/view/410.html
void print(const string& str ){
    cout<<"const str is :"<<str<<endl;
}
void print(string& str ){
    cout<<"nonconst str is :"<<str<<endl;
}
class A{
public:
    A(){};
    A(int n):i(n),j(0){};
    int get_i() const {
        return i;
    }
    int get_j() const{
        return j;
    }
public:
    int i;
    int j;
};
 inline ostream& operator <<(ostream &os,const A& a){
       return  os<<a.get_i()<<"  "<<a.get_j()<<endl;
    }

class Base{
    virtual int vfunc(){};
};
class Derived:public Base{};

int main(){
    int a=10;
    double b=0;
    cout<<a<<"  "<<b<<endl;
    b=static_cast<double>(a);
    cout<<b<<endl;
    string str="non const obj";
    print(str);
    const string * str2=const_cast<const string *>(&str);
    print((*str2));
    A aa(100);
    int &ref=reinterpret_cast<int&>(aa);
    ref=200;
    cout<<aa<<endl;
    int c=10;
    A *p=reinterpret_cast<A*>(&c);
    p->i=20;
    cout<<(*p)<<endl;
    cout<<c<<endl;


    Base base;
    Derived d;
    Derived* pd;
    pd=reinterpret_cast<Derived*> (&base);
    if (pd==NULL){
        cout<<"unsafe reinterpret_cast"<<endl;
    }
    // pd=dynamic_cast<Derived*>(&base);
    // if (pd==NULL){
    //     cout<<"unsafe reinterpret_cast"<<endl;
    // }
    ////报错不会执行成功
    pd=dynamic_cast<Derived*>(&d);
    if (pd==NULL){
        cout<<"unsafe reinterpret_cast"<<endl;
    }
}