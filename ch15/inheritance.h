#include <iostream>


class Base
{
public:
    void PubMem();

protected:
    int m_protMem;

private:
    char m_privMem;
};

class PubDerv: public Base
{
public:
    int FunA() { return m_protMem; }
    // 私有成员对于派生类来说不可访问
    // char FunB() { return m_privMem; }
};

class PrivDerv: private Base
{
public:
    // private不影响派生类的访问权限
    int FunC() { return m_protMem; }
};

class DerivedFromPublic: public PubDerv
{
public:
    int UseBase() { return m_protMem; }
};

class DerivedFromPrivate: public PrivDerv
{
public:
    // 错误，m_protMem 在 PrivDerv 中是私有的
    // int UseBase() { return m_protMem; }
};

class Sneaky: public Base
{
    friend void clobber(Sneaky&);
    //friend void clobber(Base&);
public:
    void PrintMem() { std::cout << m_protMem << std::endl; }
private:
    int m_i;
};

void clobber(Sneaky& s) { s.m_i = s.m_protMem = 0; }
// 派生类的成员或友元只能通过派生类对象来访问积累的受保护成员。
// void clobber(Base& b) { b.m_protMem = 0; }
