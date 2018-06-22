#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 定义RealSubject和Proxy的共有接口，这样就在任何使用RealSubject的地方都可以
 * 使用Proxy。
 */
class Subject {
public:
    virtual void Request() = 0;
};

/* 定义Subject实现类
 */
class ConcreteSubject:public Subject {
public:
    void Request() 
    {
        cout<<"ConcreteSubject::Request..."<<endl;
    }
};

/* 代理类
 */
class Proxy:public Subject {
public:
    Proxy(Subject *sub)
    {
        m_sub = sub;
    }
    
    void Request()
    {
        cout<<"Proxy::Request..."<<endl;
        m_sub->Request();
    }
private:
    Subject *m_sub;

};

int main(int argc, char *argv[])
{

    Subject *sub = new ConcreteSubject();
    Proxy *pro = new Proxy(sub);
    pro->Request();

    return 0;
}
