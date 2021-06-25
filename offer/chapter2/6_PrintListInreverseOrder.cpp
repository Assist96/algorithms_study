#include<stack>
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int m_nKey;
    ListNode *m_pNext;
};
vector<int> res;
vector<int>& list_print_reverse_r(ListNode *Head){
    
    if (Head==nullptr)return res;
    ListNode *p=Head;
    if(p!=nullptr){
        if(p->m_pNext!=nullptr) list_print_reverse_r(p->m_pNext);
        res.push_back(p->m_nKey);
    }
    return res;

}
void list_print_reverse(ListNode *Head){
    if(Head==nullptr){
        return ;
    }
    ListNode *ptr=Head;
    stack<int> st;
    while(ptr!=nullptr){
        st.push(ptr->m_nKey);
        ptr=ptr->m_pNext;
    }
    while(!st.empty()){
        int val=st.top();
        st.pop();
        cout<<val<<endl;
    }
}
ListNode * createList_h(vector<int> vec){
    ListNode* l=new ListNode;
    l->m_pNext=nullptr;
    for (auto i :vec){
        ListNode *p=new ListNode;
        p->m_nKey=i;
        p->m_pNext=l->m_pNext;
        l->m_pNext=p;
    }
    return l;
}
ListNode * createList_T(vector<int> vec){
    ListNode* l=new ListNode;
    l->m_pNext=nullptr;
    ListNode *r=l;
    for (auto i :vec){
        ListNode *p=new ListNode;
        p->m_nKey=i;
        p->m_pNext=nullptr;
        r->m_pNext=p;
        r=r->m_pNext;
    }
    return l;
}
int main(){
vector<int> a={1,2,3,4,5,6};
vector<int> b;
vector<int> c={7,8,9};

auto la=createList_h(a);
auto lb=createList_h(b);
auto lc=createList_T(c);

list_print_reverse(la->m_pNext);
list_print_reverse(lb->m_pNext);
list_print_reverse(nullptr);
list_print_reverse(lc->m_pNext);
cout<<"end"<<endl;
}