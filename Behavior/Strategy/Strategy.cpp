#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/*Strategy 通过“组合”(委托)方式实现算法(实现)的异构，而Template模式则采取的是继承的方式 
 * 这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
 */
class Strategy {
public:
    virtual ~Strategy() {}
    virtual void AlgrithmInterface() = 0;
};

/* 具体策略 以Strategy接口实现某具体算法
 */
class ConcreteStrategyA:public Strategy {
public:
    void AlgrithmInterface()
    {
        cout<<"test ConcreteStrategyA....."<<endl;   
    }
};

class ConcreteStrategyB:public Strategy {
public:
    void AlgrithmInterface()
    {
        cout<<"test ConcreteStrategyB....."<<endl;   
    }
};

/* 上下文
 * 用一个ConcreteStrategy对象列配置。
 * 可定义一个接口来让Strategy访问它的数据。
 */
class Context {
public:
    Context(Strategy *stg):m_pStg(stg) {}
    ~Context() { if (m_pStg) delete m_pStg; }
    void DoAction()
    {
        m_pStg->AlgrithmInterface();
    }
private:
    Strategy *m_pStg;
};

int main(int argc, char *argv[])
{
    Strategy *pStg = new ConcreteStrategyA();
    Context *pCon = new Context(pStg);
    pCon->DoAction();
    
    return 0;
}
