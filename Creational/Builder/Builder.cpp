#include<iostream>
#include<string>

using namespace std;
using std::cout;
using std::endl;
using std::string;

/* 产品角色 抽象类
 */
class Product {
protected:
    string age;
    string stature;
    string weight;
public:
    virtual ~Product() {}
    virtual void SetAge(string age) = 0;
    virtual void SetStature(string stature) = 0;
    virtual void SetWeight(string weight) = 0;
    string GetAge() { return age; }
    string GetStature() { return stature; }
    string GetWeight() { return weight; }
};

/* 实现产品角色类
 */
class ConcreateProduct:public Product {
public:
    void SetAge(string age)
    {
        this->age = age;
    }
    void SetStature(string statue)
    {
        this->stature = stature;
    }
    void SetWeight(string weight)
    {
        this->weight = weight;
    }
};

/*抽象建造者
 */
class Builder {
protected:
    Product *m_product;
    Builder() 
    {
        m_product = new ConcreateProduct();
    }
public:
    virtual ~Builder() {}
    virtual void BulidAge() = 0;
    virtual void BulidStature() = 0;
    virtual void BuildWeight() = 0;
    Product *GetProduct() { return this->m_product; }
};

/*具体建造者-child
 */ 
class ConcreteBuilderChild:public Builder {
public:
    void BulidAge() 
    {
        m_product->SetAge("8岁");        
    }
    void BulidStature()
    {   
        m_product->SetStature("身高1米");        
    }
    void BuildWeight()
    {
        m_product->SetWeight("体重33kg");        
    }
};

/*具体建造者-man
 */
class ConcreteBuilderMan:public Builder {
public:
    void BulidAge() 
    {
        m_product->SetAge("38岁");        
    }
    void BulidStature()
    {   
        m_product->SetStature("身高1.8米");        
    }
    void BuildWeight()
    {
        m_product->SetWeight("体重80kg");        
    }
};

/*指挥者
 */
class Director {
public:
   Product *Build(Builder *builder)
   {
       builder->BulidAge();
       builder->BulidStature();
       builder->BuildWeight();
       return builder->GetProduct();
   }
};

int main(int argc, char *argv)
{

    ConcreteBuilderChild *builderChild = new ConcreteBuilderChild();
    ConcreteBuilderMan *builderMan = new ConcreteBuilderMan();
    Director *director = new Director();
    Product *child = director->Build(builderChild);
    Product *man = director->Build(builderMan);
    cout<<child->GetAge()<<endl;
    cout<<man->GetAge()<<endl;
    return 0;
}
