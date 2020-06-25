// 赋值运算符函数: 
// 为CMyString类添加赋值运算符函数
#include "stdafx.h"
class CMyString {
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
private:
    char* m_pData;
}

CMyString& CMyString::operator = (const CMyString & str) {
    if (this == &str)  return *this;

    delete[] m_pData;
    m_pData = nullptr;
    // 注意, new可能会失败, 抛出异常, 因此在成功申请内存前不应释放原对象的空间
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}

// 可能会更好的方法: 
CMyString& CMyString::operator = (const CMyString & str) {
    if (&str != this) {
        CMyString tmpobj(str);
        char* tmpstr = tmpobj.m_pData;
        tmpobj.m_pData = m_pData;
        m_pData = tmpstr;
    }
    return *this;
}