#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
using std::cout;
using std::endl;

/* 描述一个接口，通过这个接口Flyweight可以接受并作用于外部状态
 */
class Flyweight {
public:
    virtual void Operation(string color) = 0;
    void SetColor(string color) { m_color = color; }
    string Getcolor() { return this->m_color; }
protected:
    string m_color;
};

/* 实现Flyweight接口，并为内部状态增加存储空间
 */
class ConcreateFlyweight:public Flyweight {
public:
    void Operation(string color)
    {
        cout<<"ConcreateFlyweight:"<<color<<endl;
    }
};

/* find_if 的仿函数
 */
class Find_Func {
public:
    Find_Func(const string color):m_color(color) {}
    bool operator()(Flyweight *fly)
    {
        if (fly->Getcolor() == m_color)
        {
            return true;
        }
        return false;
    }
private:
    string m_color;
};

/* 创建并管理Flyweight对象
 * 确保合理共享Flyweight。当用户请求一个Flyweight时，FlyweightFactory对象
 * 提供一个已创建的实例或者创建一个
 */
class FlyweightFactory {
public:
    Flyweight *GetFlyweight(string color)
    {
        vector<Flyweight*>::iterator it = std::find_if(m_fly.begin(), m_fly.end(), Find_Func(color));
        if (it != m_fly.end()) 
        {
            return *it;
        }
        
        Flyweight *fly = new ConcreateFlyweight();
        fly->SetColor(color);
        m_fly.push_back(fly);
        return fly;
    }
private:
    vector<Flyweight*> m_fly;
};

int main(int argc, char *argv[])
{
    string colors[] = {"Red", "Green", "Blue", "Red"};
    FlyweightFactory * fc = new FlyweightFactory();
    for (int i = 0; i < 4; i++)
    {
        Flyweight *fly = fc->GetFlyweight(colors[i]);
        fly->Operation(colors[i]);
    }
    return 0;
}
