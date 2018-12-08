//
// Created by pengfei on 18-12-7.
//
#include "student.h"
#include "quote.h"
#include <iostream>
#include "base.h"

using namespace std;

void TestStudent()
{
    Student s1;
    Graduate g1;

    Student *pt;
    pt = &s1;
    pt->display();
    pt->print();

    pt = &g1;
    pt->display();
    pt->print();
}

void TestQuote()
{
    Quote basic("no1172", 10.0);
    PrintTotal(cout, basic, 20);
    BulkQuote bulk("no1172", 10, 20, 0.15);
    PrintTotal(cout, bulk, 25);
}

void TestBase()
{
    Derived d1;
    d1.fun(d1);
}
