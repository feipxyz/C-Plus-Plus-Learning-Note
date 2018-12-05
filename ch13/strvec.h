//
// Created by pengfei on 18-12-5.
//

#ifndef CH12_STRVEC_H
#define CH12_STRVEC_H

#include <string>
#include <memory>

class StrVec
{
public:
    StrVec(): m_elements(nullptr), m_first_free(nullptr), m_cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return m_first_free - m_elements; }
    size_t capacity() const { return m_cap - m_elements; }
    std::string* begin() const { return m_elements; }
    std::string* end() const { return m_first_free; }

    void PrintDebug() const;

private:
    // 检查空间是否足够，如不足重新分配
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();        // 销毁原始并释放内存
    void reallocate();  // 获得更多内存并拷贝已有元素

    std::allocator<std::string> m_alloc;     // 分配元素
    std::string *m_elements;     // 指向数组首元素的指针
    std::string *m_first_free;  // 指向数组第一个空闲元素的指针
    std::string *m_cap;           // 指向数组尾后位置的指针
};

#endif //CH12_STRVEC_H
