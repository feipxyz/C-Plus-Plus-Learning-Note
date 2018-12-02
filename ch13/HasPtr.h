#include <string>

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
