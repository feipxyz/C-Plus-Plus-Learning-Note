#include <string>
#include <iostream>
#include "StrBlob.h"
#include <vector>

using namespace std;

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"are", "you", "okay"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    auto it = b1.begin();
    cout << it.deref() << endl;
    it.incr();
    cout << it.deref() << endl;
    return 0;
}
