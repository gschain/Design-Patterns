#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 优点： 
 * 线程安全 
 * 实现简单，容易维护
 * 缺点： 
 * 不适合部分场景。如：因为性能问题，希望懒加载；需要运行时才能知道，是否生成实例 
 * 由于在main开始前就必须初始化，几乎不可能给类传入任何参数。
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
};

Singleton *Singleton::m_Instance = new Singleton;
Aingleton *Singleton::GetInstance() 
{
    return m_Instance;
}


int main(int argc, char *argv[])
{
    Singleton *p1 = Singleton::GetInstance();
    return 0;
}
