#include<iostream>

/* 为一类产品对象声明一个接口
 */
class AbstractProductA {
public:
    virtual ~AbstractProductA() {}
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
};

/* 实现产品的类
 */
class ProductA1:public AbstractProductA {
public:
     ProductA1(){}
};

class ProductA2:public AbstractProductA {
public:
     ProductA2(){}
};

class ProductB1:public AbstractProductB {
public:
     ProductB1(){}
};

class ProductB2:public AbstractProductB {
public:
     ProductB2(){}
};

/* 声明一个创建抽象产品对象的操作接口
 */
class AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA() = 0;
    virtual AbstractProductB *CreateProductB() = 0;
};

/* 实现创建具体产品对象的操作
 */
class ConcreteFactory1:public AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA()
    {
        return new ProductA1();
    }
    virtual AbstractProductB *CreateProductB() 
    {
        return new ProductB1();
    }
};

class ConcreteFactory2:public AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA()
    {
        return new ProductA2();
    }
    virtual AbstractProductB *CreateProductB() 
    {
        return new ProductB2();
    }
};

int main(int argc, char *argv[])
{
    AbstractFactory *f1 = new ConcreteFactory1();
    f1->CreateProductA();
    f1->CreateProductB();
    AbstractFactory *f2 = new ConcreteFactory2();
    f2->CreateProductA();
    f2->CreateProductB();
    return 0;
}
