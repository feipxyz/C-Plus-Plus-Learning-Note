//
// Created by pengfei on 18-12-7.
//
#include <iostream>
#include "student.h"
#include "quote.h"
#include "base.h"
#include "basket.h"

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

void TestBasket()
{
    Quote book1("no1", 10.0), book2("no2", 12), book3("no1", 10.0);
    BulkQuote book4("no4", 20, 10, 0.1);
    Basket basket;
    basket.AddItem(book1);
    basket.AddItem(book2);
    basket.AddItem(book3);
    basket.AddItem(book4);

    basket.TotalReceipt(cout);
}
