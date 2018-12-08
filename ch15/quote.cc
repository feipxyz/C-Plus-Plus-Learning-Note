#include <fstream>
#include <iostream>
#include "quote.h"

using namespace std;

void Quote::Debug() const
{
    cout << "price: " << m_price << "\tbook_no" << m_strBookNo << endl;
}

double BulkQuote::NetPrice(std::size_t n) const
{
    if (n >= m_quantity)
    {
        return n * (1 - m_discount) * m_price;
    }
    else
    {
        return n * m_price;
    }
}

void DiscQuote::Debug() const
{
    Quote::Debug();
    cout << "discount: " << m_discount << "\tquantity: " << m_quantity << endl;
}

double PrintTotal(ostream &os, const Quote &item, size_t n)
{
    double ret = item.NetPrice(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
       << endl;
    return ret;
}

// void Derived::fun(const Derived &derived_obj)
// {
//     Base::statmem();
//     Derived::statmem();
//
//     derived_obj.statmem();
//     statmem();
// }
