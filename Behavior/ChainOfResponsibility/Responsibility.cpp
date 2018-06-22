#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 定义一个处理请求接口 实现后继链
 */
class Handler {
public:
     virtual void HandleRequest() = 0;
     void SetSuccessor(Handler* succ)  { m_succ = succ; }
     Handler *GetSuccessor() { return m_succ; }
private:
    Handler *m_succ;
};

/* 处理它所负责的请求
 * 如果可处理该请求，就处理之；否则将该请求转发给它的后继者。
 */
class ConcreteHandlerA:public Handler {
public:
    void HandleRequest()
    {
        if (this->GetSuccessor() != 0) {
            cout<<"ConcreteHandlerA 我把处理权给后继节点....."<<endl;
            this->GetSuccessor()->HandleRequest(); 
        }
        else {
            cout<<"ConcreteHandlerA 没有后继了，我必须自己处理...."<<endl; 
        }
    }

};

class ConcreteHandlerB:public Handler {
public:
    void HandleRequest()
    {
        if (this->GetSuccessor() != 0) {
            cout<<"ConcreteHandlerB 我把处理权给后继节点....."<<endl;
            this->GetSuccessor()->HandleRequest();
        }
        else {
            cout<<"ConcreteHandlerB 没有后继了，我必须自己处理...."<<endl;
        }
    }
};
int main(int argc, char *argv[])
{
    /* ConcreteHandlerA 的对象和h1拥有一个后继ConcreteHandlerB的对象h2,当一个请求到来时候，
     * h1 检查看自己有后继，于是 h1 直接将请求传递给其后继h2进行处理，h2因为没有后继，
     * 当请求到来时候，就只有自己提供响应了。
     */
    Handler *h1 = new ConcreteHandlerA();
    Handler *h2 = new ConcreteHandlerB();
    h1->SetSuccessor(h2);
    h1->HandleRequest();
    return 0;
}
