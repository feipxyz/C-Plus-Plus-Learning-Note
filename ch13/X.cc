#include <string>
#include <vector>
#include <iostream>

using namespace std;

class X
{
public:
    X() = default;
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

    X& operator = (const X& rhs)
    {
        std::cout << "拷贝赋值运算符" << std::endl;
        m_strName = rhs.m_strName;
        return *this;
    }

private:
    std::string m_strName;
};

void Fun1(X x)
{

}

void Fun2(X &x)
{

}

int main()
{
    X x;
    cout << "调用Fun1" << endl;
    Fun1(x);
    cout << endl;

    cout << "调用Fun2" << endl;
    Fun2(x);
    cout << endl;

    cout << "动态分配" << endl;
    X *px = new X("bob");
    cout << endl;

    cout << "添加到容器中" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "释放动态分配的对象" << endl;
    delete px;
    cout << endl;

    cout << "间接初始化和赋值" << endl;
    X y = x;
    y = x;
    cout << endl;

    {
        cout << "进入内嵌作用域" << endl;
        X zx("bob");
    }
    cout << "离开内嵌作用域" << endl;
    cout << endl;

    cout << "程序结束" << endl;

    return 0;
}
