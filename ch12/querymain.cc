//
// Created by pengfei on 18-12-3.
//

#include <iostream>
#include "QueryResult.h"
#include "TextQuery.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream file(".././StrBlob.h", ios::in);
    TextQuery tqr(file);
    string s;
    getline(file, s);
    file.close();
    return 0;
}


