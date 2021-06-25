#include<iostream>
#include<string>
using namespace std;
void ReplaceSpace(char string[] ,int length){
    if (length<=0) return;
    int space_count=0;
    for (int i=0;i<length;++i){
        if(string[i]==' '){
            ++space_count;
        }
    }
    int new_length=length+2*space_count;
    int p1=length;
    int p2=new_length;
    while(p1>=0){
        if(string[p1]==' '){
            string[p2--]='0';
            string[p2--]='2';
            string[p2--]='%';
            --p1;
        }
        else{
            string[p2--]=string[p1--];
        }
    }    

}
string ReplaceSpace(const string &s){
    string res;
    for (auto c :s){
        if (c==' ') res+="%20";
        else res=c;
    }
    return res;
}
string ReplaceSpace(string s){
   int orignal_length=s.size();
        if (s=="") return s;
        int space_count=0;
        for (auto c:s){
            if(c==' '){
                ++space_count;
            }
        }
        int new_length=orignal_length+2*space_count;
        s.resize(new_length);

        int p1=orignal_length-1;
        int p2=new_length-1;
        while(p1>=0){
            if(s[p1]==' '){
                s[p2--]='0';
                s[p2--]='2';
                s[p2--]='%';
            }
            else{
                s[p2--]=s[p1];
            }
            --p1;
        }
        return s;
}
int main(){
    string s="1234";
    cout<<s.size()<<endl;
//    auto  a=s[4];
char str1[30]="hello world 1";
char str2[30]=" hello";
char str3[30]="hello ";
char str4[30]="hello";
char str5[30]="he  llo";
char str6[30]="";
char char7[30]="   ";
char char8[30]=" ";
ReplaceSpace(str1,14);
cout<<str1<<endl;
ReplaceSpace(str2,7);
cout<<str2<<endl;
ReplaceSpace(str3,7);
cout<<str3<<endl;
ReplaceSpace(str4,6);
cout<<str4<<endl;
ReplaceSpace(str5,8);
cout<<str5<<endl;
ReplaceSpace(str6,1);
cout<<str6<<endl;
ReplaceSpace(char7,3);
cout<<char7<<endl;
ReplaceSpace(char8,2);
cout<<char8<<endl;


}