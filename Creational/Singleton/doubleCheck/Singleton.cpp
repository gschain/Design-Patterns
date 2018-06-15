#include<iostream>
#include <mutex>

using namespace std;
using std::mutex;

/* 双检测锁定（double-check),即提高性能,又防止多线程带来的问题
 * c++11 std::mutex
 */

class Singleton {
    public:
        static Singleton *GetInstance();
    private:
        Singleton() {}
        Singleton(const Singleton &);
        Singleton& operator=(const Singleton &);
        ~Singleton() { delete m_Instance; }  // 防止内存泄漏
    private:
        static Singleton *m_Instance;
        static mutex m_mt;
};

Singleton *Singleton::m_Instance = NULL;
mutex Singleton::m_mt;
Singleton *Singleton::GetInstance()
{
    if (NULL == m_Instance)
    {
        lock_guard<mutex> lock(m_mt);
        if (NULL == m_Instance)
        {
            m_Instance = new Singleton;
        }
    }
    return m_Instance;
}


int main(int argc, char *argv[])
{
    Singleton *p1 = Singleton::GetInstance();
    return 0;
}
