//
// Created by pengfei on 18-12-3.
//

#ifndef CH12_TEXTQUERY_H
#define CH12_TEXTQUERY_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include "QueryResult.h"
#include <fstream>

class QueryResult;

class TextQuery
{
public:
    using LINENO = std::vector<std::string>::size_type;
    explicit TextQuery(std::ifstream&);
    QueryResult Query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> m_wordsFile;
    std::map<std::string, std::shared_ptr<std::set<LINENO>>> m_wordsLines;
};

#endif //CH12_TEXTQUERY_H
