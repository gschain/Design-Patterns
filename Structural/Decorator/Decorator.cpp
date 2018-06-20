#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 定义一个对象接口，可以给这些对象动态的添加职责
 */
class Component {
public:
    virtual void Operation() = 0;
};

/* 定义一个对象，可以给这个对象添加一些职责。
 */
class ConcreateComponent:public Component {
public:
    void Operation()
    {
        cout<<"ConcreateComponent::Operation..."<<endl;
    }
};

/* 抽象构件类的子类，用于给具体构件增加职责，但是具体职责在其子类中实现。
 */
class Decorator:public Component {
public:
    Decorator(Component *com):m_com(com) {}
    void Operation() {}    
protected:
    Component *m_com;
};

/* 抽象装饰类的子类，负责向构件添加新的职责
 */
class ConcreateDecorator:public Decorator {
public:
    ConcreateDecorator(Component *com):Decorator(com) {}
    void AddedBehavior()
    {
        cout<<"ConcreateDecorator::AddedBehavior..."<<endl;
    }
    void Operation()
    {
        m_com->Operation();
        this->AddedBehavior();
    }
};

int main(int argc, char *argv[])
{
    Component *com = new ConcreateComponent();
    Decorator *dec = new ConcreateDecorator(com);
    dec->Operation();

    return 0;
}
