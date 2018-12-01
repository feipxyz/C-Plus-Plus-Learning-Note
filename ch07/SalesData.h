#include <string>
#include <fstream>

using std::istream;
using std::string;

class SalesData
{
public:
    SalesData() = default;
    SalesData(const string& s, unsigned int n, double p):
            m_bookNo(s), m_unitsSold(n), m_price(p) {}

    // 委托构造函数
    SalesData(string s): SalesData(s, 0, 0) {}
    // 委托构造函数
    SalesData(istream &is): SalesData() {}
    // 拷贝构造函数
    SalesData(const SalesData&);

    string Isbn() const { return m_bookNo; }
    SalesData& Combine(const SalesData&);
    double AvgPrice() const;



private:
    string m_bookNo;
    double m_unitsSold = 0.0;
    double m_price = 0.0;
    double m_revenue = 0.0;
    double m_average = 0.0;
};
