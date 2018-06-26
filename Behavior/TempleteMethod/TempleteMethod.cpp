#include<iostream>

using namespace std;
using std::cout;
using std::endl;


/* 抽象类
 * 定义抽象的原语操作，具体的子类将重定义它们以实现一个算法的各步骤。
 */
class AbstractClass {
public:
    virtual ~AbstractClass() {}
    void TemplateMethod()
    {
        this->PrimitiveOperation1();
        this->PrimitiveOperation2();
    }
protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

/* 实现原语操作以完成算法与特定子类相关的步骤。
 */
class ConcreteClass1:public AbstractClass {
public:
    void PrimitiveOperation1()
    {
        cout<<"ConcreteClass1...PrimitiveOperation1"<<endl; 
    }
    void PrimitiveOperation2()
    {
        cout<<"ConcreteClass1...PrimitiveOperation2"<<endl;
    }
};

class ConcreteClass2:public AbstractClass {
public:
    void PrimitiveOperation1()
    {
        cout<<"ConcreteClass2...PrimitiveOperation1"<<endl; 
    }
    void PrimitiveOperation2()
    {
        cout<<"ConcreteClass2...PrimitiveOperation2"<<endl;
    }
};

/* ConcreteClass靠AbstractClass来实现算法中不变的步骤。
 */
int main(int argc, char *argv[])
{
    ConcreteClass1 *pCon1 = new ConcreteClass1();
    ConcreteClass2 *pCon2 = new ConcreteClass2();
    pCon1->TemplateMethod();
    pCon2->TemplateMethod();
    return 0;

}
