//
// Created by pengfei on 18-12-3.
//

#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

TextQuery::TextQuery(ifstream &is): m_wordsFile(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        m_wordsFile->push_back(text);
        int n = m_wordsFile->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &linesPtr = m_wordsLines[word];
            if (!linesPtr)
            {
                linesPtr.reset(new set<LINENO>);
            }
            linesPtr->insert(n);
        }
    }
}

QueryResult TextQuery::Query(const std::string &word) const
{
    // 如果未找到单词，返回一个指向此set的指针
    static shared_ptr<set<LINENO>> nodata(new set<LINENO>);

    auto loc = m_wordsLines.find(word);
    if (loc == m_wordsLines.end())
        return QueryResult(word, nodata, m_wordsFile);
    else
        return QueryResult(word, loc->second, m_wordsFile);
}

