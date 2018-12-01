#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        m_ps(new std::string(s)), m_i(0) {}

    HasPtr(const HasPtr &orign)
    {
        m_i = orign.m_i;
        m_ps = new std::string(*orign.m_ps);
    }

    HasPtr& operator= (const HasPtr &orign)
    {
        m_i = orign.m_i;
        auto newps = new std::string(*orign.m_ps);
        delete m_ps;
        m_ps = newps;
        return *this;
    }

    ~HasPtr() { delete m_ps; }

private:
    std::string *m_ps;
    int m_i;
};
