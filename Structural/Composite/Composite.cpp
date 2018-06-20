#include<iostream>
#include<vector>

using namespace std;
using std::cout;
using std::endl;

/* 为组合中的对象声明接口
 * 在适当的情况下，实现所有类共有接口的缺省行为
 * 声明一个接口用于访问和管理Component的子组件
 */
class Component {
public:
    virtual void Operation() = 0;
    virtual void Add(Component *component) { }
    virtual void Remove(Component* component) { }
    virtual Component* GetChild(int index) { return NULL; }
};


/* 定义有子部件的那些部件的行为
 * 在Component接口中实现与子部件有关的操作
 */
class Composite:public Component {
public:
    virtual void Operation() 
    {
        for (vector<Component*>::iterator it = m_comVec.begin(); it != m_comVec.end(); it++)
        {
            (*it)->Operation();
        }
    }
    void Add(Component *component)
    {
        m_comVec.push_back(component);
    }
    void Remove(Component* component)
    {
        cout<<"vector erase"<<endl;
    }
    Component* GetChild(int index)
    {
        return m_comVec[index];
    }
private:
    vector<Component*> m_comVec;
};

/* 在组合中表示叶子节点对象，叶子点没有子节点
 * 在组合中定义图元对象的行为
 */
class Leaf:public Component {
public:
    void Operation()
    {
        cout<<"Leaf operation....."<<endl;
    }

};

int main(int argc, char *argv[])
{
    
    Leaf *leaf = new Leaf();
    Composite *composite = new Composite();
    composite->Add(leaf);
    Component *component = composite->GetChild(0);
    component->Operation();

    return 0;
}
