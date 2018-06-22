#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 知道如何实施与执行一个请求的操作。
 */
class Receiver {
public:
    void Action()
    {
        cout << "Receiver::Action" << endl;
    }
};

/* 声明执行操作的接口
 */
class Command {
public:
    virtual ~Command() {}
    virtual void Excute() = 0;
};

/* 将一个接收者对象绑定于一个动作。
 * 调用接收者相应的操作，以实现Excute。
 */
class ConcreteCommand:public Command {
public:
    ConcreteCommand(Receiver *pRev) { m_pRev = pRev; }
    void Excute()
    {
        m_pRev->Action(); 
    }
private:
    Receiver *m_pRev;
};

/* 要求该命令执行这个请求。
 */
class Invoker {
public:
    Invoker(Command *pCmd) { m_pCmd = pCmd; }
    void Invoke()
    {
        m_pCmd->Excute();
    }
private:
    Command *m_pCmd;
};
int main(int argc, char *argv[])
{
    //创建具体命令对象pCmd并设定它的接收者pRev  
    Receiver *pRev = new Receiver();  
    Command *pCmd = new ConcreteCommand(pRev);  
    //请求绑定命令  
    Invoker* pInv = new Invoker(pCmd);  
    pInv->Invoke();  
    return 0;
}
