//
// Created by pengfei on 18-12-3.
//
#include "QueryResult.h"
#include <fstream>
#include <memory>

using namespace std;

ostream& Print(std::ostream& os, const QueryResult& qr)
{
    os << qr.m_queryWord << " occurs " << qr.m_lines->size() << endl;

    for (auto num : *qr.m_lines)
    {
        os << "\t(line " << num + 1 << ") " << *(qr.m_wordFile->begin() + num) << endl;
    }
    return os;
}

