bool find(int *martix,int rows,int columns,int target){
    bool Found=false;
    if(martix!=nullptr&&rows>0&&columns>0){
        int row=0;
        int column=columns-1;
        while(row<rows &&columns>-0){
            if(martix[row*columns+column]==target){
                Found=true;
                break;
            }
            else if(martix[row*columns+column]>target){
                --column;
            }
            else
            {
                ++row;
            }
        }
    }
    return Found;
}

#include<vector>
#include<iostream>
using namespace std;
bool find(vector<vector<int>> & matrix,int target){
      if(matrix.size()<=0||matrix[0].size()<=0){
            return false;
        }
        int rows=matrix.size();
        int columns=matrix[0].size();
        int row=0;
        int column=columns-1;
        while(row<rows&& column>=0){
            if(matrix[row][column]==target){
                return true;
            }
            else if (matrix[row][column]>target){
                --column;

            }
            else{
                ++row;
            }
        }
         return false;
    }



int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1,1});
    bool res=find(matrix,2);
    cout<<res<<endl;
}