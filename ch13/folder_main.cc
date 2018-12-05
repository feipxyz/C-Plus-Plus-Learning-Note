//
// Created by pengfei on 18-12-4.
//
#include "folder.h"
#include <iostream>

using namespace std;

int main()
{
    Message msg_a("I Love You");
    Message msg_b("I am a student");
    Folder fld_one;

    msg_a.save(fld_one);
    msg_b.save(fld_one);

    Folder fld_two = fld_one;

    fld_one.DebugPrint();
    fld_two.DebugPrint();

    return 0;
}