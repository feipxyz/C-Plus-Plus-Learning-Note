//
// Created by pengfei on 18-12-9.
//

#ifndef CH15_BASKET_H
#define CH15_BASKET_H


#include <map>
#include <memory>
#include <set>
#include <iostream>
#include "quote.h"

/*定义一个表示购物篮的类*/
class Basket
{
public:
    // 使用合成的默认构造函数和拷贝控制成员

    void AddItem(const std::shared_ptr<Quote> &sale) { m_items.insert(sale); }
    void AddItem(const Quote& sale)        // 拷贝给定对象
    {
        m_items.insert(std::shared_ptr<Quote>(sale.Clone()));
    }
    void AddItem(Quote&& sale)              // 移动给定对象
    {
        m_items.insert(std::shared_ptr<Quote>(std::move(sale).Clone()));
    }

    // 打印每本书的总价和购物篮中所有书的总价
    double TotalReceipt(std::ostream&) const;

private:
    // 该函数用于比较shared_ptr， multiset成员会用到它
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> m_items{compare};
};

#endif //CH15_BASKET_H
