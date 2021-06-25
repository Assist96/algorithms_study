#include<vector>
#include<iostream>
#include<string>
using namespace std;


struct BTreeNode{
    int val;
    BTreeNode * left;
    BTreeNode *right;
    BTreeNode *parent;
    BTreeNode(int value=0):val(value),left(nullptr),right(nullptr),parent(nullptr){}
};
//=================================寻找下一个算法====================
BTreeNode * next(BTreeNode * node){
    if(node ==nullptr) return nullptr;
    if(node->right!=nullptr){
        BTreeNode *pNode=node->right;
        while(pNode->left!=nullptr){
            pNode=pNode->left;
        }
        return pNode;
    }
    if (node->right==nullptr){
        if (node->parent!=nullptr){
            if(node->parent->left==node){
                return node->parent;

            }
            else{
                 BTreeNode *pNode=node;
                 while(pNode->parent->parent!=nullptr){
                     pNode=pNode->parent;
                 }
                 if(pNode->parent->right==pNode){
                     return nullptr;
                 }
                 return pNode->parent;
            }
        }
        else return nullptr;
    }
}
BTreeNode * next_2(BTreeNode * node){
    if(node ==nullptr){ return  nullptr;}
    BTreeNode *nextNode=nullptr;
    if(node->right!=nullptr){
        BTreeNode * pNode=node->right;
        while(pNode->left!=nullptr){
            pNode=pNode->left;
        }
        nextNode=pNode;
    }
    else if(node->parent!=nullptr){
        BTreeNode *pNode=node;
        BTreeNode *parent=pNode->parent;
        while(parent!=nullptr&&pNode==parent->right){
            pNode=parent;
            parent=parent->parent;
        }
        nextNode=parent;
    }
    return nextNode;
}
//=================================构建二叉树========================
void connect_BT(BTreeNode* left,BTreeNode* right,BTreeNode* parent){
    if (parent!=nullptr){
        parent->left=left;
        parent->right=right;
    }
    if (left!=nullptr){
        left->parent=parent;
    }
    if(right!=nullptr){
        right->parent=parent;
    }
}
void PrintBTreeNode(BTreeNode* BTNode){
    if(BTNode==nullptr){
     cout<<"this node  is null"<<endl;
    }
    else
    {
        cout<<"value of this node is :"<<BTNode->val<<endl;
        if(BTNode->left!=nullptr){
        cout<<"value of this node's left is :"<<BTNode->left->val<<endl;
        }
        else{
             cout<<" this node's left is null"<<endl;
        }
         if(BTNode->right!=nullptr){
        cout<<"value of this node's right is :"<<BTNode->right->val<<endl;
        }
        else{
             cout<<" this node's right is null"<<endl;
        }
    }
}
void PrintBTree(BTreeNode* root){
    PrintBTreeNode(root);
    if(root!=nullptr){
       if (root->left!=nullptr){
           PrintBTree(root->left);
       }
       if (root->right!=nullptr){
           PrintBTree(root->right);
       }
    }

}
void DestroyTree(BTreeNode *root){
    if(root!=nullptr){
        BTreeNode * left=root->left;
        BTreeNode * right=root->right;
        delete root;
        root=nullptr;
        DestroyTree(left);
        DestroyTree(right);
    }
}
void Test(string testName,BTreeNode* pNode,BTreeNode* excepted){
if  (testName.size()>0){
    cout<<testName<<" begins:"<<endl;
}
BTreeNode *nextNode=next_2(pNode);
if(nextNode==excepted){
    cout<<"success"<<endl;
}
else{
    cout<<"fail"<<endl;
}
}

void test_1(){
    BTreeNode * n1=new BTreeNode(8);
    BTreeNode * n2=new BTreeNode(6);
    BTreeNode * n3=new BTreeNode(10);
    BTreeNode * n4=new BTreeNode(5);
    BTreeNode * n5=new BTreeNode(7);
    BTreeNode * n6=new BTreeNode(9);
    BTreeNode * n7=new BTreeNode(11);
    connect_BT(n2,n3,n1);
    connect_BT(n4,n5,n2);
    connect_BT(n6,n7,n3);
    Test("Test1",n1,n6);
    Test("Test2",n2,n5);
    Test("Test3",n3,n7);
    Test("Test4",n4,n2);
    Test("Test5",n5,n1);
    Test("Test6",n6,n3);
    Test("Test7",n7,nullptr);
    DestroyTree(n1);
}
void test_2(){
    BTreeNode * n1=new BTreeNode(2);
    BTreeNode * n2=new BTreeNode(3);
    BTreeNode * n3=new BTreeNode(4);
    BTreeNode * n4=new BTreeNode(5);
    connect_BT(nullptr,n2,n1);
    connect_BT(nullptr,n3,n2);
    connect_BT(nullptr,n4,n3);
    Test("Test2_1",n1,n2);
    Test("Test2_2",n2,n3);
    Test("Test2_3",n3,n4);
    Test("Test2_4",n4,nullptr);
    DestroyTree(n1);

}
void test_3(){
    BTreeNode * n1=new BTreeNode(2);
    BTreeNode * n2=new BTreeNode(3);
    BTreeNode * n3=new BTreeNode(4);
    BTreeNode * n4=new BTreeNode(5);
    connect_BT(n2,nullptr,n1);
    connect_BT(n3,nullptr,n2);
    connect_BT(n4,nullptr,n3);
    Test("Test3_1",n1,nullptr);
    Test("Test3_2",n2,n1);
    Test("Test3_3",n3,n2);
    Test("Test3_4",n4,n3);
    DestroyTree(n1);

}

void test_4(){
    BTreeNode * n1=new BTreeNode(2);
   
    connect_BT(nullptr,nullptr,n1);
    Test("Test4_1",n1,nullptr);
    DestroyTree(n1);
}

int main(){
test_1();
test_2();
test_3();
test_4();
}