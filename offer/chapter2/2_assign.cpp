#ifndef __CMYSTRING__
#define __CMYSTRING__
#include<cstdlib>
#include<cstring>
using namespace std;
class CMyString{
public:
    CMyString(char *pData=nullptr);
    CMyString(const CMyString& str);
    CMyString & operator=(const CMyString & str);
    ~CMyString(void);
private:
    char* m_pData;
};
// CMyString& CMyString::operator=(const CMyString& str){
//     if(str.m_pData!=this->m_pData){
//         delete this->m_pData;//错误1   delete []this->m_pData;
//         this->m_pData=str.m_pData;//错误2 删除之后，需要再次分配空间拷贝
                                     //要不然相当于两个实力都指向同一地址，这显然是不对的。

//     }
//     return *this;
// }

CMyString& CMyString::operator=(const CMyString& str){
    if (this!=&str){
        delete[] this->m_pData;
        m_pData=nullptr;
        this->m_pData=new char[strlen(str.m_pData)+1];
        strcpy(this->m_pData,str.m_pData);
    }
    return *this;
}
CMyString& CMyString::operator=(const CMyString& str){
    if(this!=&str){
       CMyString strTemp(str);
       char* pTemp=strTemp.m_pData;
       strTemp.m_pData=this->m_pData;
       this->m_pData=pTemp;
    }
    return *this;
}



#endif