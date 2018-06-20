#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/*定义Client使用的与特定领域相关的接口
 */
class Target {
public:
    virtual void Request() 
    {
        cout<<"Target::Request"<<endl;
    }
};

/*定义一个已经存在的接口，这个接口需要适配器
 */
class Adaptee {
public:
    void SpecificRequest()
    {
        cout<<"Adaptee::SpecificRequest"<<endl;
    }
};

/*一对Adaptee的接口与Target接口进行适配
 * 接口继承和实现继承是面向对象领域的两个重要的概念，
 * 接口继承指的是通过继承,子类获得了父类的接口,而实现继承指的是通过继承子类获得了父类的实现
 * 我们可以通过 private 继承获得实现继承的效果 (private 继承后，父类中的接口都变为 private，当然只能是实现继承了。）
 */
class Adapter:public Target,private Adaptee {
public:
    void Request()
    {
        this->SpecificRequest();
    }
};

int main(int argc, char *argv[])
{
    Target *target = new Adapter();
    target->Request();
    return 0;
}
