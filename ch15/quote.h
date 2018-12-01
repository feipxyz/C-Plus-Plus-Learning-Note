#include <string>
#include <vector>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price): m_strBookNo(book), m_price(sales_price){};
    std::string isbn() const { return m_strBookNo; }

    //返回给定数量书籍的销售总额，派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const { return n * m_price; }
    //对析构函数进行动态绑定
    virtual ~Quote() = default;

private:
    std::string m_strBookNo; // ISBN编号

protected:
    double m_price = 0.0; //普通状态下不打折的价格
};

class DiscQuote: public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const std::string& book, double price, std::size_t qty, double disc):
                Quote(book, price), m_quantity(qty), m_discount(disc){};
    // 定义一个纯虚函数
    double net_price(std::size_t t) const = 0;

protected:
    std::size_t m_quantity = 0; //适用折扣的最低数量
    double m_discount = 0.0; //以小数表示的折扣额
};

class BulkQuote : public DiscQuote
{
public:
    BulkQuote() = default;
    // using DiscQuote::DiscQuote;     // 继承DiscQuote的构造函数
    BulkQuote(const std::string& book, double price, std::size_t qty, double disc):
                DiscQuote(book, price, qty, disc) {}
    //覆盖基类的函数版本
    double net_price(std::size_t n) const override;
};

class Base
{
public:
    static void statmem();
};

class Derived: public Base
{
    void fun(const Derived&);
};
