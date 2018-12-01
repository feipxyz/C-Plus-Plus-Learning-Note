#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    Employee() { m_num = m_baseNum++; }
    Employee(string name)
    {
        m_name = name;
        m_num = m_baseNum++;
    }
    Employee(const Employee &rhs)
    {
        m_name = rhs.m_name;
        m_num = m_baseNum++;
    }

    Employee& operator = (Employee& rhs)
    {
        m_name = rhs.m_name;
        m_num = m_baseNum++;
        return *this;
    }

    void PrintNum() { cout << m_num << endl; }

private:
    string m_name;
    int m_num;
    static int m_baseNum;
};

int Employee::m_baseNum = 1;

int main()
{
    Employee ep0;
    Employee ep1("Bob");
    Employee ep2("Tom");
    ep0.PrintNum();
    ep1.PrintNum();
    ep2.PrintNum();

    ep2 = ep1;
    return 0;
}
