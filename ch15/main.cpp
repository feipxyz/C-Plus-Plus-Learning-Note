#include "quote.h"
#include <iostream>

using namespace std;

int main()
{
    Quote basic("no1172", 10.0);
    PrintTotal(cout, basic, 20);
    BulkQuote bulk("no1172", 10, 20, 0.15);
    PrintTotal(cout, bulk, 25);

    return 0;
}
