#include<iostream>

using namespace std;
using std::cout;
using std::endl;

class Element;
/* 访问者
 * 为该对象结构中ConcreteElement的每一个类声明一个Visit操作。
 */
class Visitor {
public:
    virtual ~Visitor() {}
    virtual void VisitConcreteElementA(Element *elm) = 0;
    virtual void VisitConcreteElementB(Element *elm) = 0;
protected:
    Visitor() {}
};

/* 实现每个Visitor声明的操作。
 */
class ConcreteVisitorA:public Visitor {
public:
    void VisitConcreteElementA(Element *elm)
    { 
        cout<<"ConcreteVisitorA i will visit ConcreteElementA..."<<endl;
    }
    void VisitConcreteElementB(Element *elm)
    {
        cout<<"ConcreteVisitorA i will visit ConcreteElementB..."<<endl;
    }
};

class ConcreteVisitorB:public Visitor {
public:
    void VisitConcreteElementA(Element *elm)
    { 
        cout<<"ConcreteVisitorB i will visit ConcreteElementA..."<<endl;
    }
    void VisitConcreteElementB(Element *elm)
    {
        cout<<"ConcreteVisitorB i will visit ConcreteElementB..."<<endl;
    }
};

/* 定义一个Accept操作，它以一个访问者为参数。
 */
class Element {
public:
   virtual ~Element() {}
   virtual void Accept(Visitor *vis) = 0;
};

/* 实现Accept操作，该操作以一个访问者为参数。
 */
class ConcreteElementA:public Element {
public:
   void Accept(Visitor *vis)
   {
        vis->VisitConcreteElementA(this);
        cout<<"visiting ConcreteElementA..."<<endl;
   }
};

class ConcreteElementB:public Element {
public:
   void Accept(Visitor *vis)
   {
        vis->VisitConcreteElementB(this);
        cout<<"visiting ConcreteElementB..."<<endl;
   }
};
int main(int argc, char *argv[])
{   
    Visitor *pVis = new ConcreteVisitorA();
    Element *pElm = new ConcreteElementA();
    pElm->Accept(pVis);
    
    return 0;
}
