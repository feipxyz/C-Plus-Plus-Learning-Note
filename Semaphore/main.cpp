#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

class semaphore
{
public:
    semaphore(int value = 1): m_count(value) { }
    semaphore(const semaphore&) = delete;
    semaphore& operator =(const semaphore&) = delete;

    void wait()
    {
        unique_lock<mutex> lck(m_mtx);
        if (--m_count < 0)
            m_cdvar.wait(lck);
    }

    void single()
    {
        unique_lock<mutex> lck(m_mtx);
        if (++m_count <= 0)
            m_cdvar.notify_one();
    }

private:
    int m_count;
    condition_variable m_cdvar;
    mutex m_mtx;
};

semaphore plate(1), apple(0), orange(0);

void father()
{
    while (true)
    {
        plate.wait();
        cout << "往盘中放一个苹果" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        apple.single();
    }
}

void mother()
{
    while (true)
    {
        plate.wait();
        cout << "往盘中放一个橘子" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        orange.single();
    }
}

void son()
{
    while (true)
    {
        apple.wait();
        cout << "儿子吃一个苹果" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        plate.single();
    }
}

void daughter()
{
    while (true)
    {
        orange.wait();
        cout << "女儿吃一个橘子" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        plate.single();
    }
}

int main() {
    thread f(father), m(mother), d(daughter), s(son);
    f.join();
    m.join();
    d.join();
    s.join();
    return 0;
}