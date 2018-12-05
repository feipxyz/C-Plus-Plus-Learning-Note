//
// Created by pengfei on 18-12-5.
//

#ifndef CH12_STRVEC_H
#define CH12_STRVEC_H

#include <string>
#include <memory>
#include <vector>



class StrVec
{
public:
    StrVec(): m_elements(nullptr), m_first_free(nullptr), m_cap(nullptr) {}
    StrVec(const std::initializer_list<std::string>&);  // 通过一个列表构造
    StrVec(const StrVec&);              // 拷贝构造函数
    StrVec(StrVec&&) noexcept;          // 移动构造函数，不应该抛出任何异常
    StrVec& operator=(const StrVec&);   // 拷贝赋值运算符
    StrVec& operator=(StrVec &&) noexcept;   // 移动赋值运算符
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return m_first_free - m_elements; }
    size_t capacity() const { return m_cap - m_elements; }
    std::string* begin() const { return m_elements; }
    std::string* end() const { return m_first_free; }

    void reverse(size_t);
    void resize(size_t);
    void resize(size_t, const std::string&);


    void PrintDebug() const;

private:
    // 检查空间是否足够，如不足重新分配
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();                // 销毁原始并释放内存
    void reallocate();          // 获得更多内存并拷贝已有元素
    void reallocate(size_t);

    std::allocator<std::string> m_alloc;     // 分配元素
    std::string *m_elements;     // 指向数组首元素的指针
    std::string *m_first_free;  // 指向数组第一个空闲元素的指针
    std::string *m_cap;           // 指向数组尾后位置的指针
};

inline StrVec::StrVec(const std::initializer_list<std::string> &il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    m_elements = newdata.first;
    m_first_free = newdata.second;
    m_cap = newdata.second;
}

inline StrVec::StrVec(StrVec &&s) noexcept:    // 移动构造函数，不应该抛出任何异常
m_elements(s.m_elements),
m_first_free(s.m_first_free),
m_cap(s.m_cap)
{
    s.m_elements = nullptr;
    s.m_first_free = nullptr;
    s.m_cap = nullptr;
}

#endif //CH12_STRVEC_H
