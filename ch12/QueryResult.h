//
// Created by pengfei on 18-12-3.
//
#ifndef CH12_QUERYRESULT_H
#define CH12_QUERYRESULT_H

#include <vector>
#include <string>
#include <memory>
#include <set>

class QueryResult
{
public:
    friend std::ostream& Print(std::ostream&, const QueryResult&);
    using LINENO = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<LINENO>> p, std::shared_ptr<std::vector<std::string>> f):
                m_queryWord(s), m_wordFile(f), m_lines(p) {}

private:
    std::string m_queryWord;
    std::shared_ptr<std::vector<std::string>> m_wordFile;
    std::shared_ptr<std::set<LINENO>> m_lines;
};

std::ostream& Print(std::ostream&, const QueryResult&);

#endif //CH12_QUERYRESULT_H
