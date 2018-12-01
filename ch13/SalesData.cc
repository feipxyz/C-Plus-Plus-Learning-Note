#include "SalesData.h"
#include <iostream>

double SalesData::AvgPrice() const
{
    if (m_unitsSold)
    {
        return m_revenue / m_unitsSold;
    }
    else
    {
        return 0;
    }
}

SalesData::SalesData(const SalesData& orign):
m_bookNo(orign.m_bookNo),
m_unitsSold(orign.m_unitsSold),
m_price(orign.m_price)
{}
