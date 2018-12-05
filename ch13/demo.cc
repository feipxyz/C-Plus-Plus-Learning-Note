//
// Created by pengfei on 18-12-5.
//

#include "folder.h"
#include <iostream>
#include "strvec.h"
#include "demo.h"

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

void TestStrVec()
{
    StrVec sv1;
    sv1.push_back("I");
    sv1.push_back("am");
    sv1.push_back("a");
    sv1.push_back("student");
    sv1.PrintDebug();

}
