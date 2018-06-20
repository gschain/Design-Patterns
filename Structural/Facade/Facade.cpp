#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 实现子系统功能
 * 处理由Facade对象指派的任务
 */
class Subsystem1 {
public:
    void Operation() 
    {
        cout<<"Subsystem1::Operation..."<<endl;
    }
};

class Subsystem2 {
public:
    void Operation() 
    {
        cout<<"Subsystem2::Operation..."<<endl;
    }
};

/* 知道哪些子系统类负责处理请求
 * 将客户的请求代理给适当的子系统对象
 */
class Facade {
public:
    void OperationWrapper()
    {
        m_sub1->Operation();
        m_sub2->Operation();
    }
private:
    Subsystem1 *m_sub1;
    Subsystem2 *m_sub2;
};

int main(int argc, char *argv[])
{
    Facade *fac = new Facade();
    fac->OperationWrapper();

    return 0;
}
