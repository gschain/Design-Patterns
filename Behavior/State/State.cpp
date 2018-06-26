#include<iostream>

using namespace std;
using std::cout;
using std::endl;


class Context;

/* 定义一个接口以封装Context的一个特定状态相关的行为。
*/
class State {
public:
    /* 抽象的接口，每个子类去实现这个接口
     * 根据自己的逻辑执行任务或者转换状态。
     */
    virtual void Handle(Context *context) = 0;
    //获得当前的状态
    virtual void GetState() = 0;
};

/* 定义客户感兴趣的接口。
 */
class Context{
public:
    Context(State *state):m_pState(state) {}
    State *GetState() { return m_pState; }
    void SetState(State *state) { m_pState = state; }
    void Request()  //执行状态类实现的方法
    {
        m_pState->Handle(this);
    }
public:
    State *m_pState;
};

/* 具体状态子类。
 * 每一子类实现一个与Context的一个状态相关的行为。
 */
class ConcreteStateA:public State {
public:
    void Handle(Context *context);
    void GetState()
    {
         cout<<"当前状态是A"<<endl; 
    }
};

class ConcreteStateB:public State {
public:
    void Handle(Context *context)
    {
        context->m_pState = new ConcreteStateA;
        cout<<"当前状态是B，下一状态是.."<<endl;
    }
    void GetState()
    {
         cout<<"当前状态是B"<<endl; 
    }
};

void ConcreteStateA::Handle(Context *context)
{
    context->m_pState = new ConcreteStateB;
    cout<<"当前状态是A，下一状态是B"<<endl;
}

int main(int argc, char *argv[])
{
    Context* context = new Context(new ConcreteStateA);
    context->Request();
    context->Request();

    return 0;
}
