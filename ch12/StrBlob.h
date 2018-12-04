#ifndef STRBLOB_H
#define STRBLOB_

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;

// 实现一个可以共享底层数据的类
class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob(): m_ptrData(std::make_shared<std::vector<std::string>> ()) {}
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return m_ptrData->size(); }
    bool empty() const { return m_ptrData->empty(); }

    // 添加和删除元素
    void push_back(const std::string &t) { m_ptrData->push_back(t); }
    void pop_back();

    // 元素访问
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    // 使用标准库容器来管理元素
    std::shared_ptr<std::vector<std::string>> m_ptrData;
    // 检查访问是否合法，如果不合法抛出异常
    void check(size_type i, const std::string &msg) const;
};

// 实现一个伴随指针类
class StrBlobPtr
{
public:
    StrBlobPtr(): m_curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        m_wptr(a.m_ptrData), m_curr(sz) {}
    // 解引用
    std::string& deref() const;
    // 前缀递增
    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> m_wptr;
    std::size_t m_curr;
};

inline StrBlob::StrBlob(std::initializer_list<std::string> il):
            m_ptrData(std::make_shared<std::vector<std::string>> (il)) {}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, m_ptrData->size());
}


inline void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= m_ptrData->size())
        throw std::out_of_range(msg);
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    m_ptrData->pop_back();
}

inline std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return m_ptrData->back();
}

inline const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return m_ptrData->back();
}

inline std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return m_ptrData->front();
}

inline const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return m_ptrData->front();
}

inline std::shared_ptr<std::vector<std::string>>
    StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = m_wptr.lock();
    if (!ret)
    {
        throw std::runtime_error("unbound StrBlobPtr");
    }

    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }

    return ret;
}

inline std::string& StrBlobPtr::deref() const
{
    auto p = check(m_curr, "dereference past end");
    return (*p)[m_curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(m_curr, "increment past end of StrBlobPtr");
    ++m_curr;
    return *this;
}

#endif
