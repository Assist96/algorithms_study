#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool duplicate(int numbers[],int length,int & duplication){
    if(numbers==nullptr||length<=0){//小于0都不行
        return false;
    }
    for(int i=0;i<length;++i){
        if(numbers[i]<0||numbers[i]>=length){
            return false;
        }
    }
    int i=0;
    while(i<length){
        if(numbers[i]!=i){
            int tmp=numbers[i];
            if (tmp==numbers[tmp]){
                duplication=numbers[i];
                return true;
            }
            numbers[i]=numbers[tmp];
            numbers[tmp]=tmp;
            continue;
        }
        else{
            ++i;
        }
    }
    return false;
}
int duplicate_2(vector<int> nums){
    unordered_set<int> hash_set;
    for(auto num :nums){
        if (hash_set.find(num)!=hash_set.end()){
            return num;
        }
        hash_set.insert(num);
    }
    return -1;
}
int countRange(int nums[],int length,int start,int end){
    if(nums==nullptr) return 0;
    int count=0;
    for (int i=0;i<length;++i){
        if(nums[i]<=end&&nums[i]>=start){
            ++count;
        }
    }
    return count;
}
int duplicate_3(int nums[],int length){
    if(nums==NULL||length<=0){
        return -1;
    }
    for (int i=0;i<length;++i){
        if(nums[i]>=length||nums[i]<0){
            return -1;
        }
    }
    int start=0;
    int end=length-1;
    while(start<=end){
        int middle=(start+end)/2;
        int count_left=countRange(nums,length,start,middle);
        if(start==end){
            if(count_left>1) return start;
            else break;
        }
        if(count_left>(middle-start+1)){
            end=middle;
        }else{
            start=middle+1;
        }
        
       
    }
    return -1;
}

int main(){
    int a[3]={0,0,1};
    int b[6]={4,1,2,3,5,0};
    int * c;
    int d[3]={2,3,4};
    int dup=0;
    auto t1=duplicate_3(a,3);
    cout<<t1<<(dup)<<endl;
    auto t2=duplicate_3(b,6);
    cout<<t2<<(dup)<<endl;
    auto t3=duplicate_3(c,0);

    cout<<t3<<(dup)<<endl;
    auto t4=duplicate_3(d,3);
    cout<<t4<<(dup)<<endl;

}