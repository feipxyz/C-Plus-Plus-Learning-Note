#include <fstream>
#include <iostream>
#include "quote.h"

using namespace std;

double BulkQuote::net_price(std::size_t n) const
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

double PrintTotal(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
        << endl;
    return ret;
}

void Derived::fun(const Derived &derived_obj)
{
    Base::statmem();
    Derived::statmem();

    derived_obj.statmem();
    statmem();
}
