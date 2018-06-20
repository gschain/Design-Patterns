#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/*定义抽象类接口
 */
class Abstraction {
public:
    virtual void Operation() = 0;
};

/*定义实现类接口
 */
class AbstractionImp {
public:
    virtual ~AbstractionImp() {}
    virtual void Operation() = 0;
};

/*扩充由Abstaction定义的接口
 */
class RefinedAbstraction:public Abstraction {
public:
    RefinedAbstraction(AbstractionImp* imp)
    {
        m_imp = imp;   
    }
    void Operation() 
    {
        m_imp->Operation();
    }
private:
    AbstractionImp* m_imp;
};

/*实现AbstractionImp接口并定义它具体的实现
 */
class ConcreteAbstractionImpA:public AbstractionImp {
public:
    virtual void Operation()
    {
        cout<<"AbstractionImpA....imp"<<endl;
    }
};

class ConcreteAbstractionImpB:public AbstractionImp {
public:
    virtual void Operation()
    {
        cout<<"AbstractionImpB....imp"<<endl;
    }
};

int main(int argc, char *argv[])
{
    AbstractionImp *imp = new ConcreteAbstractionImpA();
    Abstraction *abs = new RefinedAbstraction(imp);
    abs->Operation();
    return 0;
}
