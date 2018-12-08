//
// Created by pengfei on 18-12-7.
//

#ifndef CH15_STUDENT_H
#define CH15_STUDENT_H

#include <string>
#include <iostream>

/* 说明虚函数与普通函数在调用的时候的区别 */
class Student
{
public:
    Student() = default;
    void display()
    {
        std::cout << "call Student display" << std::endl;
    }
    virtual void print()
    {
        std::cout << "call Student print" << std::endl;
    }
};

class Graduate: public Student
{
public:
    Graduate() = default;

    void display()
    {
        std::cout << "call Graduate display" << std::endl;
    }
    void print()
    {
        std::cout << "call Gradute print" << std::endl;
    }
};

#endif //CH15_STUDENT_H
