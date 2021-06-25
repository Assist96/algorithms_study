#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
struct BinaryTree{
    int m_nValue;
    BinaryTree *m_pLeft;
    BinaryTree *m_pRight;
};

BinaryTree* construct_btree(vector<int>& in_order,vector<int>& mid_order){
    if (in_order.size()==0||mid_order.size()==0){
        return nullptr;
    }
    int root_value=in_order[0];
    BinaryTree * b_tree=new BinaryTree;
    b_tree->m_nValue=root_value;
    int index_mid=0,index_in=1;
    for(int i :mid_order){
        if (i==root_value){break;}
        ++index_mid;
        ++index_in;
    }
    if (index_mid>mid_order.size()) throw ("error");
    auto in_begin=in_order.begin();
    auto mid_begin=mid_order.begin();
    if(in_begin+1!=in_begin+index_in){
        vector<int>new_left(in_begin+1,in_begin+index_in);//begin +1 =第二个数
        vector<int>new_right(mid_begin,mid_begin+index_mid);
        b_tree->m_pLeft=construct_btree(new_left,new_right);
    }
   if(in_begin+index_in!=in_order.end()){
        vector<int>new_left2(in_begin+index_in,in_order.end());
        vector<int>new_right2(mid_begin+index_mid+1,mid_order.end());
        b_tree->m_pRight=construct_btree(new_left2,new_right2);
   }
    return b_tree;
}

class Solution{
public:

BinaryTree * construct_btree(vector<int>&preorder,vector<int>&inorder){
    int pre_l=preorder.size();
    int in_l=inorder.size();
    if (pre_l<=0||in_l<=0){
        return nullptr;
    }
    for (int i =0;i<in_l;i++){
        inorder_map[inorder[i]]=i;
    }
    BinaryTree *btree=recursion(preorder,0,pre_l-1,0,in_l-1);
    return btree;
}
BinaryTree *recursion(vector<int>&preorder,
                    int preorder_left,int preorder_right,
                    int inorder_left,int inorder_right){
        if(preorder_left>preorder_right){
            return nullptr;
        }
        int rootval=preorder[preorder_left];
        BinaryTree * root;
        root->m_nValue=rootval;
        int index=inorder_map[rootval];
        int left_tree_n=index-inorder_left;
        root->m_pLeft=recursion(preorder,preorder_left+1,preorder_left+left_tree_n,inorder_left,inorder_left+left_tree_n-1);
        root->m_pRight=recursion(preorder,preorder_left+1+left_tree_n,preorder_right,inorder_left+left_tree_n+1,inorder_right);
}
private :
unordered_map<int ,int>inorder_map;
};

int main(){
    vector<int>in_order={1,2,4,7,3,5,6,8};
    vector<int>mid_order={4,7,2,1,5,3,8,6};
    BinaryTree * b_tree=construct_btree(in_order,mid_order);
    cout<<"end"<<endl;
    vector<int>in_order1={1,2,4,7};
    vector<int>mid_order1={4,7,2,1};
    BinaryTree * b_tree1=construct_btree(in_order1,mid_order1);
    cout<<"end"<<endl;
    vector<int>in_order2={1, 3,5,6,8};
    vector<int>mid_order2={ 1,5,3,8,6};
    BinaryTree * b_tree2=construct_btree(in_order2,mid_order2);
    cout<<"end"<<endl;
    //vector<int>in_order3={1, 3,5,6,8};
    vector<int>in_order3={1 };
    vector<int>mid_order3={ 1 };
    BinaryTree * b_tree3=construct_btree(in_order3,mid_order3);
    cout<<"end"<<endl;
}
