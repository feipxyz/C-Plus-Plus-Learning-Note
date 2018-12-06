//
// Created by pengfei on 18-12-5.
//

#include "folder.h"
#include <iostream>
#include "strvec.h"
#include "demo.h"
#include "hasptr.h"
#include "X.h"

using namespace std;

void TestMessage()
{
    Message msg_a("I Love You");
    Message msg_b("I am a student");
    Folder fld_one;

    msg_a.save(fld_one);
    msg_b.save(fld_one);

    Folder fld_two = fld_one;

    fld_one.DebugPrint();
    fld_two.DebugPrint();
}


void TestHasPtr()
{
    HasPtr hp1("abc");
    HasPtr hp2;
    hp2 = hp1;
}

void TestStrVec()
{
    StrVec sv1;
    sv1.push_back("I");
    sv1.push_back("am");
    sv1.push_back("a");
    sv1.push_back("student");
    sv1.PrintDebug();

    StrVec sv2{"Are", "you", "Okay"};
    sv2.PrintDebug();

    initializer_list<int> l = {1, 2, 3};

}

void TestX()
{
//    X x1("abc");
//    X x2;
    X x3 = string("abc");
    X x2 = x3;
//    string str = "name";
//    x2.test(str);
}
