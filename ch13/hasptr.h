#include <string>

// 类值版本的 HasPtr
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        m_ps(new std::string(s)), m_i(0) {}

    HasPtr(const HasPtr &orign):
        m_ps(new std::string(*orign.m_ps)), m_i(orign.m_i) {}

    HasPtr& operator= (const HasPtr &orign)
    {
        // 现将对象拷贝到一个临时对象中。这样可以避免拷贝的对象是自身时出现错误。
        auto newp = new std::string(*orign.m_ps);
        delete m_ps;
        m_ps = newp;
        m_i = orign.m_i;
        return *this;
    }

    ~HasPtr() { delete m_ps; }

private:
    std::string *m_ps;
    int m_i;
};

// 类指针版本的 HasPtrP
class HasPtrP
{
public:
    HasPtrP(const std::string &s = std::string()):
        m_ps(new std::string(s)), m_i(0), m_use(new std::size_t(1)) {}
    HasPtrP(const HasPtrP &p):
        m_ps(p.m_ps), m_i(p.m_i), m_use(p.m_use) { ++(*m_use); }
    HasPtrP& operator=(const HasPtrP& rhs)
    {
        ++(*rhs.m_use);
        if (--(*m_use) == 0)
        {
            delete m_ps;
            delete m_use;
        }
        m_ps = rhs.m_ps;
        m_i = rhs.m_i;
        m_use = rhs.m_use;
        return *this;
    }
    ~HasPtrP()
    {
        if (--(*use) == 0)
        {
            delete m_ps;
            delete m_use;
        }
    }

private:
    std::string *m_ps;
    int m_i;
    std::size_t *m_use;     // 记录有多少对象共享*m_ps
};