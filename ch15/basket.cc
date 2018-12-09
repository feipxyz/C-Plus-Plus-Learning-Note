//
// Created by pengfei on 18-12-9.
//

#include "basket.h"
#include <iostream>

using namespace std;

double Basket::TotalReceipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = m_items.cbegin(); iter != m_items.cend();
         iter = m_items.upper_bound(*iter))
    {
        sum += PrintTotal(os, **iter, m_items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}
