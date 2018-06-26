#include<iostream>
#include<string>

using namespace std;
using std::cout;
using std::endl;

/* 中介者定义一个接口用于各同事对象通信
 */
class Mediator {
public:
    virtual ~Mediator() {}
    virtual void DoActionFromAtoB() = 0;
    virtual void DoActionFromBtoA() = 0;
protected:
    Mediator() {}
};

/* 同事类
 * 每一个同事类都知道它的中介者对象。
 * 每一个同事对象在需要与其他的同事通信的时候，与它的中介者通信。
 */
class Colleage {
public:
    virtual ~Colleage() {}
    virtual void Action() = 0;
    virtual void SetState(const string &sdt) = 0;
    virtual string GetState() = 0;
protected:
    Colleage() {}
    Colleage(Mediator *pMdt):m_pMdt(pMdt) {}
    Mediator *m_pMdt;
};

/* 同事类实现。
 */
class ConcreteColleageA:public Colleage {
public:
    ConcreteColleageA(Mediator *pMdt):Colleage(pMdt) {}
    void Action()
    {
        m_pMdt->DoActionFromAtoB();
        cout<<"State of ConcreteColleageB:"<<" "<<this->GetState()<<endl;
    }
    void SetState(const string &sdt)
    {
        m_sdt = sdt;
    }
    string GetState() { return m_sdt; }
private:
    string m_sdt;
};

class ConcreteColleageB:public Colleage {
public:
    ConcreteColleageB(Mediator *pMdt):Colleage(pMdt) {}
    void Action()
    {
        m_pMdt->DoActionFromBtoA();
        cout<<"State of ConcreteColleageA:"<<" "<<this->GetState()<<endl;
    }
    void SetState(const string &sdt)
    {
        m_sdt = sdt;
    }
    string GetState() { return m_sdt; }
private:
    string m_sdt;
};


/* 具体中介者通过协调各同事对象实现协作行为。
 * 了解并维护它的各同事。
 */
class ConcreteMediator:public Mediator {
public:
    ConcreteMediator() {}
    ConcreteMediator(ConcreteColleageA *pClgA, ConcreteColleageB *pClgB):m_pClgA(pClgA), m_pClgB(pClgB) {}
    void SetConcreteColleageA(Colleage *pClgA) { m_pClgA = pClgA; }
    void SetConcreteColleageB(Colleage *pClgB) { m_pClgB = pClgB; }
    Colleage* GetConcreteColleageA() { return m_pClgA; }
    Colleage* GetConcreteColleageB() { return m_pClgB; }
    void IntroColleage(Colleage *pClgA, Colleage *pClgB)
    {
        m_pClgA = pClgA;
        m_pClgB = pClgB;
    }
    void DoActionFromAtoB()
    {
        m_pClgB->SetState(m_pClgA->GetState()); 
    }
    void DoActionFromBtoA()
    { 
        m_pClgA->SetState(m_pClgB->GetState()); 
    }
private:
    Colleage *m_pClgA;
    Colleage *m_pClgB;
};

/* 同事向一个中介者对象发送和接收请求。中介者在各同事间是当地转发请求以实现协作行为。
 */
int main(int argc, char *argv[])
{
    ConcreteMediator *m = new ConcreteMediator();
    ConcreteColleageA *c1 = new ConcreteColleageA(m); 
    ConcreteColleageB *c2 = new ConcreteColleageB(m);
    m->IntroColleage(c1,c2);
    c1->SetState("old"); 
    c2->SetState("old"); 
    c1->Action(); 
    c2->Action();
    cout<<endl;

    c1->SetState("new"); 
    c1->Action(); 
    c2->Action(); 
    cout<<endl;

    c2->SetState("old"); 
    c2->Action(); 
    c1->Action();
    return 0;
}

