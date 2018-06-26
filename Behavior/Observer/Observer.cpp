#include<iostream>
#include<string>
#include<set>

using namespace std;
using std::cout;
using std::endl;

class Subject;
/* 为哪些在目标发生改变时需获得通知的对象定义一个更新接口。
 */
class Observer {
public:
    Observer() {}
    virtual ~Observer() {}
    //当被观察的目标发生变化时，通知调用该方法
    //来自被观察者pSj, 扩展参数为pArg
    virtual void Update(Subject *pSj, void *pArg = NULL) = 0;
};


/* 目标知道它的观察者。可以有任意多个观察者观察同一个目标。
 * 提供注册和删除观察者对象的接口。
 */
class Subject {
public:
    Subject():m_bChanged(false) {}
    void Attach(Observer *pObs) //注册观察者
    {
        if (!pObs) return;
        m_setObs.insert(pObs);
    }
    void Detach(Observer *pObs) //注销观察者
    {
        if (!pObs) return;
        m_setObs.erase(pObs);
    }
    void DetachAll() //注销所有观察者
    {
        m_setObs.clear();
    }
    void Notify(void *pArg = NULL) //若状态变化，则遍历观察者，逐个通知更新
    {
        if (!HasChanged()) return;
        cout << "notify observers…" << endl;
        ClearChanged();
        set<Observer*>::iterator itr = m_setObs.begin();
        for (; itr != m_setObs.end(); itr++){
            (*itr)->Update(this, pArg);
        }
    }
    bool HasChanged() //测试目标状态是否变化
    {
         return m_bChanged;
    }
    int GetObserversCount()  //获取观察者数量 
    {
        return m_setObs.size();
    }
    virtual void Publish(const string &strContent) = 0;
protected:
    void SetChanged() //设置状态变化!!!必须继承Subject才能设置目标状态
    {
        m_bChanged = true;
    }
    void ClearChanged() //初始化目标为未变化状态
    {
        m_bChanged = false;
    }
private:
    bool m_bChanged; //状态
    set<Observer *> m_setObs; //set保证目标唯一性
};

/* 当它的状态发生改变时，向它的各个观察者发出通知。
 */
class ConcreteSubjectA:public Subject {
public:
    void Publish(const string &strContent)
    {
        cout << "ConcreteSubjectA publish, content: " << strContent << endl;
        SetChanged();
        Notify(const_cast<char*>(strContent.c_str()));
    }
};

class ConcreteSubjectB:public Subject {
public:
    void Publish(const string &strContent)
    {
        cout << "ConcreteSubjectB publish, content: " << strContent << endl;
        SetChanged();
        Notify(const_cast<char*>(strContent.c_str()));
    }
};

/* 具体观察者。
 */
class ConcreteObserverA:public Observer {
public:
    ConcreteObserverA(const string &strName):m_strName(strName) {}
    virtual void Update(Subject *pSj, void *pArg = NULL)
    {
       char *pContent = static_cast<char *>(pArg);

       //观察多个目标
       if (dynamic_cast<ConcreteSubjectA *>(pSj)) {
           cout << m_strName << " updated from ConcreteSubjectA, content: " << pContent << endl;      
       } else if (dynamic_cast<ConcreteSubjectB *>(pSj)) { 
           cout << m_strName << " updated from ConcreteSubjectB, content: " << pContent << endl;      
       }
    }
private:
    string m_strName;
};

class ConcreteObserverB:public Observer {
public:
    ConcreteObserverB(const string &strName):m_strName(strName) {}
    virtual void Update(Subject *pSj, void *pArg = NULL)
    {
       char *pContent = static_cast<char *>(pArg);

       //观察多个目标
       if (dynamic_cast<ConcreteSubjectA *>(pSj)) {
           cout << m_strName << " updated from ConcreteSubjectA, content: " << pContent << endl;      
       } else if (dynamic_cast<ConcreteSubjectB *>(pSj)) { 
           cout << m_strName << " updated from ConcreteSubjectB, content: " << pContent << endl;      
       }
    }
private:
    string m_strName;
};
int main(int argc, char *argv[])
{
    ConcreteSubjectA *pConA = new ConcreteSubjectA();
    ConcreteSubjectB *pConB = new ConcreteSubjectB();
    
     //观察者. 一个观察者可以观察多个目标
    ConcreteObserverA *pConObsA = new ConcreteObserverA("ConcreteObserverA reader");
    ConcreteObserverB *pConObsB = new ConcreteObserverB("ConcreteObserverB reader");
    pConA->Attach(pConObsA);
    pConB->Attach(pConObsA);
    pConA->Attach(pConObsB);
    pConB->Attach(pConObsB);
    pConB->Publish(" B:observer design patterns");
    pConA->Publish(" A:observer design patterns");
    
    return 0;
}
