#ifndef CH15_QUOTE_H
#define CH15_QUOTE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price): m_strBookNo(book), m_price(sales_price) {};
    // 对析构函数进行动态绑定
    virtual ~Quote() = default;

    // 返回当前对象的一份动态分配的拷贝
    virtual Quote* Clone() const & { return new Quote(*this); }
    virtual Quote* Clone() && { return new Quote(std::move(*this)); }

    std::string isbn() const { return m_strBookNo; }

    // 返回给定数量书籍的销售总额，派生类负责改写并使用不同的折扣计算算法
    virtual double NetPrice(std::size_t n) const
    {
        std::cout << "Quote net price fun" << std::endl;
        return n * m_price;
    }

    virtual void Debug() const;

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
    DiscQuote(const DiscQuote &rhs):
        Quote(rhs), m_quantity(rhs.m_quantity), m_discount(rhs.m_discount) {}


    void Debug() const override;
    // 定义一个纯虚函数
    double NetPrice(std::size_t t) const = 0;

protected:
    std::size_t m_quantity = 0; //适用折扣的最低数量
    double m_discount = 0.1; //以小数表示的折扣额
};

class BulkQuote : public DiscQuote
{
public:
    BulkQuote() = default;
    // using DiscQuote::DiscQuote;     // 继承DiscQuote的构造函数
    BulkQuote(const std::string &book, double price, std::size_t qty, double disc):
                DiscQuote(book, price, qty, disc) {}
    BulkQuote* Clone() const & { return new BulkQuote(*this); }
    BulkQuote* Clone() && { return new BulkQuote(std::move(*this)); }
    //覆盖基类的函数版本
    double NetPrice(std::size_t n) const override;
};

// 计算并打印销售给定数量的某种书籍所用的费用
double PrintTotal(std::ostream &os, const Quote &item, size_t n);

#endif
