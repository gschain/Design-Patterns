#include<iostream>
#include<string>

using namespace std;
using std::cout;
using std::endl;

/*定义工厂方法所创建的对象的接口
 * 抽象类
 */
class Product {
public:
    virtual void disp() = 0;
    virtual ~Product() {};
protected:
    Product() {}
};

class AppleProduct:public Product {
public:
    void disp() 
    {
        cout<<"apple"<<endl;
    }
};

class BananaProduct:public Product {
public:
    void disp() 
    {
        cout<<"banana"<<endl;
    }
};

/* 所创建工厂的对象的接口
 * 抽象类
 */
class Factory {
public:
    virtual ~Factory() {}
    virtual Product *CreateProduct(string str) = 0;
};

/* 重定义工厂方法已返回ConcreteProduct实例
 */
class ConcreteFactory:public Factory {
public:
    Product *CreateProduct(string str)
    {
       if ("apple" == str) {
           return new AppleProduct();       
       } else if ("banana" == str) {
           return new BananaProduct();
       }
    }
};

int main(int argc, char *argv[])
{
    Factory *fac = new ConcreteFactory();
    Product *pro = fac->CreateProduct("apple");
    pro->disp();
    return 0;   
}
