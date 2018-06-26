#include<iostream>
#include<string>
#include<list>

using namespace std;
using std::cout;
using std::endl;

/* 备忘录存储原发器对象的内部状态。
 * 防止原发器以外的其他对象访问备忘录。
 */
class Memento {
private: 
    // 这是最关键的地方，将Originator为friend类，可以访问内部信息，但是其他类不能访问
    friend class Originator;
    string m_sdt;

    Memento(const string &sdt):m_sdt(sdt) {}
    void SetState(const string &sdt) { m_sdt = sdt; }
    string GetState() { return m_sdt; }
};

/* 原发器创建一个备忘录，用于记录当前时刻它的内部状态。
 * 使用备忘录恢复内部状态。
 */
class Originator {
public:
    Originator() {}
    Originator(const string &sdt):m_sdt(sdt) {}
    Memento* CreateMemento() { return new Memento(m_sdt); }
    void RestoretoMemento(Memento *pMt)
    {
       this->m_sdt = pMt->GetState(); 
    }
    string GetState() { return m_sdt; }
    void SetState(const string &sdt) { m_sdt = sdt; }
    void PrintState() { cout<<m_sdt<<endl; }
private:
    string m_sdt;
    Memento *m_pMt;
};

/* 负责保存好备忘录。
 * 不能对备忘录的内容进行操作或检查。
 */
class Caretaker {
public:
    list<Memento> mementoList;
};

/* Memento模式的关键就是friend class Originator;我们可以看到，Memento的接口都声明
 * 为private，而将Originator声明为Memento的友元类。我们将Originator的状态保存在Memento类中，而将Memento接口private起来，也就达到了封装的功效。
 */
int main(int argc, char *argv[])
{
    Originator *pOg = new Originator();
    pOg->SetState("old");  //备忘录状态
    pOg->PrintState();

    Memento *pMt = pOg->CreateMemento();
    pOg->SetState("new");  //修改状态
    pOg->PrintState();
    pOg->RestoretoMemento(pMt);  //修复修改前状态
    pOg->PrintState();

    return 0;
}
