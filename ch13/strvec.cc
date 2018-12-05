//
// Created by pengfei on 18-12-5.
//
#include "strvec.h"
#include <memory>
#include <iostream>
#include <string>

using namespace std;

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    m_elements = newdata.first;
    m_first_free = newdata.second;
    m_cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    m_elements = newdata.first;
    m_first_free = newdata.second;
    m_cap = newdata.second;
    return *this;
}

void StrVec::push_back(const string & s)
{
    chk_n_alloc();      // 确保有空间容纳新元素
    m_alloc.construct(m_first_free++, s);
}
void StrVec::reallocate()
{
    // 新的内存空间为当前空间的两倍
    auto newcapacity = size() ? 2 * size() : 1;
    // 分配新内存
    auto newdata = m_alloc.allocate(newcapacity);
    // 将数据从旧内存移动到新内存
    auto dest = newdata;
    auto elem = m_elements;

    for (size_t i = 0; i != size(); i++)
    {
        m_alloc.construct(dest++, std::move(*elem++));
    }
    free();

    m_elements = newdata;
    m_first_free = dest;
    m_cap = m_elements + newcapacity;
}

pair<string*, string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = m_alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::PrintDebug() const
{
    cout << "StrVec Content: " << endl;
    for (string* p = m_elements; p != m_first_free; p++)
        cout << *p << endl;
    cout << endl;
}

void StrVec::free()
{
    if (m_elements)
    {
        for (auto p = m_first_free; p != m_elements;)
            m_alloc.destroy(--p);
        m_alloc.deallocate(m_elements, m_cap - m_elements);
    }
}