#include <string>
#include <vector>
#include <iostream>


class X
{
public:
//    X() = default;
    X(std::string name)
    {
        std::cout << "普通构造" << std::endl;
    }

    X(const X &rhs)
    {
        std::cout << "拷贝构造" << std::endl;
        m_strName = rhs.m_strName;
    }

    ~X()
    {
        std::cout << "析构" << std::endl;
    }

    X& operator = (const X &rhs)
    {
        std::cout << "拷贝赋值运算符" << std::endl;
        m_strName = rhs.m_strName;
        return *this;
    }

    void test(const X &t)
    {
        std::cout << "test" << std::endl;
    }

private:
    std::string m_strName;
};


