#include<iostream>

/* 优点：实现简单，用的时候才创建，比较节省。
 * 缺点:
 * 在多线程下不安全。
 * 如果存在多个单例对象的析构顺序有依赖时，可能会出现程序崩溃的危险。
 * C++11规定，在一个线程开始local static 对象的初始化后完成初始化前，
 * 其他线程执行到这个local static对象的初始化语句就会等待，直到该local static 对象初始化完成。
 * C++11，保证静态局部变量的初始化是线程安全的
 */

class Singleton {
public:
    static Singleton &GetInstance();
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);
};

Singleton &Singleton::GetInstance()
{
    static Singleton instance;
    return instance;
}

int main(int argc, char *argv[])
{
    Singleton& p1 = Singleton::GetInstance();
    return 0;
}
