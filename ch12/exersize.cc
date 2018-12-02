#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<int>* new_vector(void)
{
    return new (nothrow) vector<int>;
}

void read_input(vector<int> *pv)
{
    int v;
    while (cin >> v)
    {
        pv->push_back(v);
    }
}

void print_input(vector<int> *pv)
{
    for (const auto &v : *pv)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vt{1, 2, 3};
    vector<int> *pv = new_vector();
    if (!pv)
    {
        cout << "内存不足" << endl;
        return -1;
    }

    read_input(pv);
    print_input(pv);
    delete pv;
    pv = nullptr;
    return 0;
}
