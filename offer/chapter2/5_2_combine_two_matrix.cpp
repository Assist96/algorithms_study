#include<vector>
#include<iostream>
using namespace std;
void combineMatrix(vector<int> &a,const vector<int> &b){
    int old_length_a=a.size();
    int length_b=b.size();
    int new_length=old_length_a+length_b;
    a.resize(new_length);
    if(old_length_a==0){
        a=b;
        return;
    }
    if(length_b==0){
        return ;
    }
    int p1=old_length_a-1,p2=length_b-1,p3=new_length-1;
    while(p1>=0&&p2>=0&&p3!=p1){
        if(a[p1]>b[p2]){
            a[p3--]=a[p1--];
        }else{
            a[p3--]=b[p2--];
        }
    }
}

int main(){
    vector<int>a={1,3,5};
    vector<int>b={2,3,6};
    combineMatrix(a,b);
    for (auto i :a)
    {
        cout<<i<<" ";
    }
    cout<<endl;

     vector<int>a1={ };
    vector<int>b1={2,3,6};
    combineMatrix(a1,b1);
    for (auto i :a1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
     vector<int>a3={1,1,1 };
    vector<int>b3={ };
    combineMatrix(a3,b3);
    for (auto i :a3)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>a2={1,1,1 };
    vector<int>b2={2,2};
    combineMatrix(a2,b2);
    for (auto i :a2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}