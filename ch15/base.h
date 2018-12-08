#include <iostream>

class Pal;
class Base
{
    friend class Pal;
public:
    void PubMem();
    static void statmen()
    {
        std::cout << "Base static fun" << std::endl;
    }

protected:
    int m_protMem;

private:
    char m_privMem;
};


class Derived: public Base
{
public:
    void fun(const Derived &obj)
    {
        std::cout << "Derived fun" << std::endl;
        Base::statmen();
        Derived::statmen();
        obj.statmen();
        statmen();
    }
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

class Pal
{
public:
    int f1(Base b) { return b.m_protMem; }
    int f2(Sneaky s) { return s.m_protMem; }
    // 也是正确的，对基类的访问由基类本身控制，即使对派生类中的基类部分也是如此
    int f3(Sneaky s) { return s.m_privMem; }
};

void clobber(Sneaky& s);
// 派生类的成员或友元只能通过派生类对象来访问积累的受保护成员。
// void clobber(Base& b) { b.m_protMem = 0; }
