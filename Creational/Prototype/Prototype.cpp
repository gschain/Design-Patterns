#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/*声明一个克隆自身的接口
 */
class Prototype {
public:
    virtual ~Prototype() {}
    virtual Prototype *clone() const = 0;
};

/*实现一个克隆自身的操作
 */
class ConcreatePrototype:public Prototype {
public:
    ConcreatePrototype() {}
    ConcreatePrototype(const ConcreatePrototype &cp)
    {
        cout<<"ConcreatePrototype copy "<<endl;
    }
    Prototype *clone() const 
    {
        return new ConcreatePrototype(*this);
    }
};
int main(int argc, char *argv[])
{
    Prototype *p = new ConcreatePrototype();
    Prototype *p1 = p->clone();
    return 0;   
}
